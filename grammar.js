/**
 * @file Kon grammar for tree-sitter
 * @author akonwi
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// match rule at least once, with separator
// o
const sepBy1 = (rule, separator) => seq(rule, repeat(seq(separator, rule)));

// match 0 or more of rule, with separator
const sepBy = (rule, separator) => optional(sepBy1(rule, separator));

// underscore prefix is used to hide rules from the syntax tree
module.exports = grammar({
  name: "kon",

  precedences: ($) => [
    [
      "unary",
      "member",
      "call",
      "multiply",
      "divide",
      "plus",
      "minus",
      "comparison",
      "and",
      "or",
    ],
    ["member", "call", "_expression"],
  ],

  conflicts: ($) => [[$.map_value, $.list_value]],

  rules: {
    program: ($) => repeat($.statement),

    statement: ($) =>
      choice(
        $.while_loop,
        $.do_while_loop,
        $.if_statement,
        $.variable_definition,
        $.function_definition,
        $.reassignment,
        $.compound_assignment,
        $._expression_statement,
      ),

    //// definitions
    variable_definition: ($) =>
      seq(
        field("binding", $.variable_binding),
        field("name", $.identifier),
        field("type", optional($._type_declaration)),
        $._assign,
        field("value", choice($.primitive_value, $.list_value, $.map_value)),
      ),

    _type_declaration: ($) =>
      seq($._colon, choice($.list_type, $.map_type, $.primitive_type)),

    variable_binding: ($) => choice("let", "mut"),

    function_definition: ($) =>
      seq("fn", $.identifier, $.parameters, optional($.return_type), $.block),

    function_call: ($) =>
      prec(
        "call",
        seq(
          field("target", choice($.identifier, $.member_access)),
          field("arguments", $.paren_arguments),
        ),
      ),

    paren_arguments: ($) => seq("(", sepBy($._expression, ","), ")"),

    parameters: ($) => seq("(", sepBy($.param_def, ","), ")"),

    param_def: ($) => seq($.identifier, $._colon, $.primitive_type),

    return_type: ($) => $.primitive_type,

    block: ($) => seq("{", optional(repeat($.statement)), "}"),

    //// Statements
    while_loop: ($) => seq("while", field("condition", $._expression), $.block),

    do_while_loop: ($) =>
      seq("do", "while", field("condition", $._expression), $.block),

    if_statement: ($) =>
      seq(
        "if",
        field("condition", $._expression),
        $.block,
        optional($.else_statement),
      ),

    else_statement: ($) => seq("else", choice($.if_statement, $.block)),

    reassignment: ($) => seq($.identifier, $._assign, $._expression),
    compound_assignment: ($) =>
      seq($.identifier, choice($.increment, $.decrement), $._expression),

    _expression_statement: ($) => $._expression,

    //// Expressions
    _expression: ($) =>
      choice(
        $.identifier,
        $.primitive_value,
        $.binary_expression,
        $.member_access,
        $.function_call,
      ),

    member_access: ($) => seq($._expression, ".", $.identifier),

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
          [$.equal, "comparison"],
          [$.not_equal, "comparison"],
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
    equal: ($) => "==",
    not_equal: ($) => "!equal",
    and: ($) => "and",
    or: ($) => "or",

    // assignment operators
    increment: ($) => "=+",
    decrement: ($) => "=-",

    ///// types
    list_type: ($) => seq("[", field("inner", $.primitive_type), "]"),
    map_type: ($) =>
      seq(
        "[",
        field("key", $.primitive_type),
        $._colon,
        field("value", $.primitive_type),
        "]",
      ),
    primitive_type: ($) => choice("Str", "Num", "Bool"),

    ///// values
    list_value: ($) => seq("[", sepBy($.primitive_value, ","), "]"),
    map_value: ($) =>
      choice(seq("[", ":", "]"), seq("[", sepBy($.map_pair, ","), "]")),
    map_pair: ($) =>
      seq(
        field("key", $.primitive_value),
        ":",
        field("value", $.primitive_value),
      ),
    primitive_value: ($) => choice($.string, $.number, $.boolean),
    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
    string: ($) => seq('"', /[^"]*/, '"'),
    number: ($) => /\d+(\.\d+)?/,
    boolean: ($) => choice("true", "false"),
    _colon: ($) => ":",
    _assign: ($) => "=",
  },
});
