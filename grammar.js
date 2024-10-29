/**
 * @file Kon grammar for tree-sitter
 * @author akonwi
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// underscore prefix is used to hide rules from the syntax tree
module.exports = grammar({
	name: "kon",

	rules: {
		source_file: ($) =>
			repeat(choice($.variable_definition, $.function_definition)),

		variable_definition: ($) =>
			seq(
				$.variable_binding,
				$.identifier,
				optional($._type_declaration),
				$._assign,
				$.primitive_value,
			),

		function_definition: ($) =>
			seq("fn", $.identifier, $.parameters, optional($.return_type), $.block),

		parameters: ($) =>
			seq("(", optional(seq($.param_def, repeat(seq(",", $.param_def)))), ")"),

		param_def: ($) => seq($.identifier, $._colon, $.primitive_type),

		return_type: ($) => $.primitive_type,

		block: ($) => seq("{", "}"),

		_type_declaration: ($) => seq($._colon, $.primitive_type),

		variable_binding: ($) => choice("let", "mut"),
		primitive_type: ($) => choice("Str", "Num", "Bool"),
		primitive_value: ($) => choice($.string, $.number, $.boolean),
		identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
		string: ($) => seq('"', /[^"]*/, '"'),
		number: ($) => /\d+(\.\d+)?/,
		boolean: ($) => choice("true", "false"),
		_colon: ($) => ":",
		_assign: ($) => "=",
	},
});
