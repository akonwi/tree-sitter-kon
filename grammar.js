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

	precedences: ($) => [
		[
			"unary",
			"call",
			"multiply",
			"divide",
			"plus",
			"minus",
			"comparison",
			"and",
			"or",
		],
		["call", "_expression"],
	],

	rules: {
		source_file: ($) => repeat($.statement),

		statement: ($) =>
			choice($.while_loop, $.variable_definition, $.function_definition),

		//// definitions
		variable_definition: ($) =>
			seq(
				$.variable_binding,
				$.identifier,
				optional($._type_declaration),
				$._assign,
				$.primitive_value,
			),

		_type_declaration: ($) => seq($._colon, $.primitive_type),

		variable_binding: ($) => choice("let", "mut"),

		function_definition: ($) =>
			seq("fn", $.identifier, $.parameters, optional($.return_type), $.block),

		parameters: ($) =>
			// equivalent to ( (param_def)? (, param_def)* )?
			seq("(", optional(seq($.param_def, repeat(seq(",", $.param_def)))), ")"),

		param_def: ($) => seq($.identifier, $._colon, $.primitive_type),

		return_type: ($) => $.primitive_type,

		block: ($) => seq("{", "}"),

		//// Statements
		while_loop: ($) => seq("while", field("condition", $._expression), $.block),

		//// Expressions
		_expression: ($) =>
			choice($.identifier, $.primitive_value, $.binary_expression),

		binary_expression: ($) =>
			choice(
				...[
					[$.multiply, "multiply"],
					[$.divide, "divide"],
					[$.plus, "plus"],
					[$.minus, "minus"],
					[$.greater_than, "comparison"],
					[$.greater_than_or_equal, "comparison"],
					[$.less_than, "comparison"],
					[$.less_than_or_equal, "comparison"],
					[$.or, "or"],
					[$.and, "and"],
				].map(([operator, precedence]) =>
					prec.left(
						// @ts-expect-error precedence is definitely a string
						precedence,
						seq(
							field("left", $._expression),
							field("operator", operator),
							field("right", $._expression),
						),
					),
				),
			),

		//// operators
		multiply: ($) => "*",
		divide: ($) => "/",
		plus: ($) => "+",
		minus: ($) => "-",
		greater_than: ($) => ">",
		greater_than_or_equal: ($) => ">=",
		less_than: ($) => "<",
		less_than_or_equal: ($) => "<=",
		and: ($) => "and",
		or: ($) => "or",

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
