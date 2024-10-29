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
		source_file: ($) => repeat($.variable_definition),

		variable_definition: ($) =>
			seq(
				$.variable_binding,
				$.identifier,
				optional($._type_declaration),
				$.assign,
				$.primitive_value,
			),

		function_definition: ($) =>
			seq("fn", $.identifier, $.function_parameters, $.block),

		function_parameters: ($) => seq("(", /* TODO */ ")"),

		block: ($) => seq("{", "}"),

		_type_declaration: ($) => seq($.colon, $.primitive_type),

		variable_binding: ($) => choice("let", "mut"),
		primitive_type: ($) => choice("Str", "Num", "Bool"),
		primitive_value: ($) => choice($.string, $.number, $.boolean),
		identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
		string: ($) => seq('"', /[^"]*/, '"'),
		number: ($) => /\d+(\.\d+)?/,
		boolean: ($) => choice("true", "false"),
		colon: ($) => ":",
		assign: ($) => "=",
	},
});
