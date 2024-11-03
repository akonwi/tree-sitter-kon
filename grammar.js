/**
 * @file Kon grammar for tree-sitter
 * @author akonwi
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// match rule at least once, with separator
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
      "modulo",
      "comparison",
      "range",
      "and",
      "or",
      "assignment",
    ],
    ["function_call", "_expression"],
    [$._expression, $.struct_instance],
  ],

  conflicts: ($) => [
    [$.function_call, $._expression],
    [$._expression_statement, $.binary_expression],
    [$.binary_expression, $.variable_definition],
  ],

  rules: {
    program: ($) => repeat($.statement),

    statement: ($) =>
      choice(
        $.while_loop,
        $.if_statement,
        $.for_loop,
        $.variable_definition,
        $.function_definition,
        $.reassignment,
        $.compound_assignment,
        $._expression_statement,
        $.struct_definition,
      ),

    //// definitions
    struct_definition: ($) =>
      seq("struct", $.identifier, "{", sepBy($.struct_property, ","), "}"),

    struct_property: ($) => seq($.identifier, $._colon, $.primitive_type),

    variable_definition: ($) =>
      seq(
        field("binding", $.variable_binding),
        field("name", $.identifier),
        optional($.type_declaration),
        $._assign,
        field("value", choice($._expression)),
      ),

    type_declaration: ($) =>
      seq(
        $._colon,
        field("type", choice($.list_type, $.map_type, $.primitive_type)),
      ),

    variable_binding: ($) => choice("let", "mut"),

    function_definition: ($) =>
      seq(
        "fn",
        field("name", $.identifier),
        field("parameters", $.parameters),
        field("return_type", optional($.return_type)),
        field("body", $.block),
      ),

    function_call: ($) =>
      prec(
        "function_call",
        seq(
          field("target", choice($.identifier, $.member_access)),
          field("arguments", $.paren_arguments),
        ),
      ),

    paren_arguments: ($) => seq("(", sepBy($._expression, ","), ")"),

    parameters: ($) => seq("(", sepBy($.param_def, ","), ")"),

    param_def: ($) =>
      seq(
        field("name", $.identifier),
        $._colon,
        field("type", $.primitive_type),
      ),

    return_type: ($) => $.primitive_type,

    block: ($) => seq("{", optional(repeat($.statement)), "}"),

    //// Statements
    while_loop: ($) =>
      seq(
        optional(field("do", "do")),
        "while",
        field("condition", $._expression),
        field("statement_block", $.block),
      ),

    for_loop: ($) =>
      seq(
        "for",
        field("cursor", $.identifier),
        "in",
        field("range", $._expression),
        field("statement_block", $.block),
      ),

    if_statement: ($) =>
      seq(
        "if",
        field("condition", $._expression),
        field("body", $.block),
        field("else", optional($.else_statement)),
      ),

    else_statement: ($) =>
      seq("else", choice($.if_statement, field("body", $.block))),

    reassignment: ($) =>
      prec(
        "assignment",
        seq(
          field("name", $.identifier),
          $._assign,
          field("value", $._expression),
        ),
      ),
    compound_assignment: ($) =>
      prec(
        "assignment",
        seq(
          field("name", $.identifier),
          field("operator", choice($.increment, $.decrement)),
          field("value", $._expression),
        ),
      ),

    _expression_statement: ($) => $._expression,

    //// Expressions
    _expression: ($) =>
      choice(
        $.identifier,
        $.primitive_value,
        $.unary_expression,
        $.binary_expression,
        $.member_access,
        $.function_call,
        $.struct_instance,
        seq("(", $._expression, ")"),
      ),

    struct_instance: ($) =>
      seq(
        field("name", $.identifier),
        "{",
        sepBy($.struct_prop_pair, ","),
        "}",
      ),

    member_access: ($) => prec("member", seq($._expression, ".", $.identifier)),

    unary_expression: ($) =>
      prec(
        "unary",
        choice(seq($.minus, $._expression), seq($.bang, $._expression)),
      ),

    binary_expression: ($) =>
      choice(
        ...[
          [$.multiply, "multiply"],
          [$.divide, "divide"],
          [$.plus, "plus"],
          [$.minus, "minus"],
          [$.modulo, "modulo"],
          [$.greater_than, "comparison"],
          [$.greater_than_or_equal, "comparison"],
          [$.less_than, "comparison"],
          [$.less_than_or_equal, "comparison"],
          [$.equal, "comparison"],
          [$.not_equal, "comparison"],
          [$.bang, "comparison"],
          [$.inclusive_range, "range"],
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
    modulo: ($) => "%",
    greater_than: ($) => ">",
    greater_than_or_equal: ($) => ">=",
    less_than: ($) => "<",
    less_than_or_equal: ($) => "<=",
    equal: ($) => "==",
    not_equal: ($) => "!=",
    and: ($) => "and",
    or: ($) => "or",
    bang: ($) => "!",
    inclusive_range: ($) => "...",

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
    list_value: ($) =>
      seq("[", sepBy(choice($.number, $.string, $.boolean), ","), "]"),
    map_value: ($) =>
      choice(seq("[", ":", "]"), seq("[", sepBy1($.map_pair, ","), "]")),
    map_pair: ($) =>
      seq(
        field("key", choice($.string, $.number)),
        ":",
        field("value", choice($.string, $.number, $.boolean)),
      ),
    struct_prop_pair: ($) =>
      seq(
        field("name", $.identifier),
        ":",
        field("value", choice($.string, $.number, $.boolean)),
      ),
    primitive_value: ($) =>
      choice($.string, $.number, $.boolean, $.map_value, $.list_value),
    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
    string: ($) => seq('"', /[^"]*/, '"'),
    number: ($) => /\d+(\.\d+)?/,
    boolean: ($) => choice("true", "false"),
    _colon: ($) => ":",
    _assign: ($) => "=",
  },
});
