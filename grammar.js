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
    ["function_call", "expression"],
    [$.expression, $.struct_instance],
  ],

  conflicts: ($) => [
    [$.function_call, $.expression],
    [$._expression_statement, $.binary_expression],
    [$.binary_expression, $.variable_definition],
    [$.anonymous_parameter, $.expression],
  ],

  extras: ($) => [/\s/, $.comment],

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
        $._expression_statement,
        $.struct_definition,
        $.enum_definition,
      ),

    //// definitions
    struct_definition: ($) =>
      seq(
        $._struct,
        field("name", $.identifier),
        $._left_brace,
        sepBy(field("field", $.struct_property), $._comma),
        $._right_brace,
      ),

    struct_property: ($) =>
      seq(field("name", $.identifier), $._colon, field("type", $.type)),

    enum_definition: ($) =>
      seq(
        $._enum,
        field("name", $.identifier),
        $._left_brace,
        sepBy1(field("variant", $.enum_variant), $._comma),
        $._right_brace,
      ),

    // todo: struct/tuple variants
    enum_variant: ($) => field("variant", choice($.identifier)),

    enum_struct_variant: ($) =>
      seq(
        field("name", $.identifier),
        $._left_brace,
        sepBy($.struct_property, $._comma),
        $._right_brace,
      ),

    variable_definition: ($) =>
      seq(
        field("binding", $.variable_binding),
        field("name", $.identifier),
        optional(seq($._colon, field("type", $.type))),
        $.assign,
        field("value", $.expression),
      ),

    variable_binding: ($) => choice("let", "mut"),

    function_definition: ($) =>
      seq(
        $._fn,
        field("name", $.identifier),
        field("parameters", $.parameters),
        optional(field("return", $.type)),
        field("body", $.block),
      ),

    anonymous_function: ($) =>
      seq(
        seq(
          $._left_paren,
          sepBy(field("parameter", $.anonymous_parameter), $._comma),
          $._right_paren,
        ),
        field("return", optional($.type)),
        field("body", $.block),
      ),

    anonymous_parameter: ($) =>
      choice(
        seq(field("name", $.identifier), $._colon, field("type", $.type)),
        field("name", $.identifier),
      ),

    function_call: ($) =>
      prec(
        "function_call",
        seq(
          field("target", $.identifier),
          field("arguments", $.paren_arguments),
        ),
      ),

    paren_arguments: ($) =>
      seq(
        $._left_paren,
        sepBy(field("argument", $.expression), $._comma),
        $._right_paren,
      ),

    parameters: ($) =>
      seq(
        $._left_paren,
        sepBy(field("parameter", $.param_def), $._comma),
        $._right_paren,
      ),

    param_def: ($) =>
      seq(field("name", $.identifier), $._colon, field("type", $.type)),

    block: ($) =>
      seq($._left_brace, optional(repeat($.statement)), $._right_brace),

    //// Statements
    while_loop: ($) =>
      seq(
        optional(field("do", "do")),
        "while",
        field("condition", $.expression),
        field("body", $.block),
      ),

    for_loop: ($) =>
      seq(
        "for",
        field("cursor", $.identifier),
        "in",
        // limit what can be used as a range
        field("range", $.expression),
        field("body", $.block),
      ),

    if_statement: ($) =>
      seq(
        "if",
        field("condition", $.expression),
        field("body", $.block),
        optional(field("else", $.else_clause)),
      ),

    else_clause: ($) =>
      seq("else", choice(field("if", $.if_statement), field("body", $.block))),

    reassignment: ($) =>
      prec(
        "assignment",
        seq(
          field("name", $.identifier),
          field("operator", choice($.assign, $.increment, $.decrement)),
          field("value", $.expression),
        ),
      ),

    _expression_statement: ($) => $.expression,

    //// Expressions
    expression: ($) =>
      choice(
        field(
          "expr",
          choice(
            $.identifier,
            $.primitive_value,
            $.list_value,
            $.map_value,
            $.unary_expression,
            $.binary_expression,
            $.member_access,
            $.function_call,
            $.struct_instance,
            $.paren_expression,
            $.match_expression,
            $.anonymous_function,
          ),
        ),
      ),
    paren_expression: ($) =>
      seq($._left_paren, field("expr", $.expression), $._right_paren),

    match_expression: ($) =>
      seq(
        $._match,
        field("expr", $.expression),
        $._left_brace,
        sepBy1(field("case", $.match_case), $._comma),
        $._right_brace,
      ),

    match_case: ($) =>
      seq(
        field("pattern", $.member_access),
        $._fat_arrow,
        field("body", choice($.block, $.expression)),
      ),

    struct_instance: ($) =>
      seq(
        field("name", $.identifier),
        $._left_brace,
        sepBy(field("field", $.struct_prop_pair), $._comma),
        $._right_brace,
      ),

    member_access: ($) =>
      prec.right(
        "member",
        seq(
          field("target", choice($.identifier, $.primitive_value)),
          field("operator", choice($.period, $.double_colon)),
          field(
            "member",
            choice($.member_access, $.identifier, $.function_call),
          ),
        ),
      ),

    unary_expression: ($) =>
      prec(
        "unary",
        choice(
          seq(field("operator", $.minus), field("operand", $.expression)),
          seq(field("operator", $.bang), field("operand", $.expression)),
        ),
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
          [$.inclusive_range, "range"],
          [$.or, "or"],
          [$.and, "and"],
        ].map(([operator, precedence]) =>
          prec.left(
            // @ts-expect-error precedence is definitely a string
            precedence,
            seq(
              field("left", $.expression),
              field("operator", operator),
              field("right", $.expression),
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
    inclusive_range: ($) => "..",

    // assignment operators
    increment: ($) => "=+",
    decrement: ($) => "=-",

    ///// types
    type: ($) =>
      choice($.map_type, $.list_type, $.primitive_type, $.identifier),

    list_type: ($) =>
      seq($._left_bracket, field("element_type", $.type), $._right_bracket),
    map_type: ($) =>
      seq(
        $._left_bracket,
        field("key", $.str),
        $._colon,
        field("value", $.type),
        $._right_bracket,
      ),
    primitive_type: ($) => choice($.str, $.num, $.bool, $.void),

    ///// values
    list_value: ($) =>
      seq(
        $._left_bracket,
        sepBy(
          field(
            "element",
            choice(
              $.number,
              $.string,
              $.boolean,
              $.identifier,
              $.struct_instance,
            ),
          ),
          $._comma,
        ),
        $._right_bracket,
      ),
    map_value: ($) =>
      choice(
        seq($._left_bracket, $._colon, $._right_bracket),
        seq(
          $._left_bracket,
          sepBy1(field("entry", $.map_pair), $._comma),
          $._right_bracket,
        ),
      ),
    map_pair: ($) =>
      seq(
        field("key", choice($.string)),
        $._colon,
        field("value", $.primitive_value),
      ),
    struct_prop_pair: ($) =>
      seq(
        field("name", $.identifier),
        $._colon,
        // todo?: just allow expressions
        field("value", $.primitive_value),
      ),
    primitive_value: ($) =>
      field("primitive", choice($.string, $.number, $.boolean)),
    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
    string: ($) =>
      seq(
        '"',
        repeat(
          field(
            "chunk",
            choice(alias(/[^"{}]+/, $.string_content), $.string_interpolation),
          ),
        ),
        '"',
      ),
    string_interpolation: ($) =>
      seq(
        $._left_brace,
        $._left_brace,
        field("expression", $.expression),
        $._right_brace,
        $._right_brace,
      ),
    /// comments
    comment: ($) =>
      token(
        choice(seq("//", /[^\n]*/), seq("/*", /[^*]*\*+([^/*][^*]*\*+)*\//)),
      ),
    number: ($) => /\d+(\.\d+)?/,

    /// keywords
    boolean: ($) => choice("true", "false"),
    str: ($) => "Str",
    num: ($) => "Num",
    bool: ($) => "Bool",
    void: ($) => "Void",
    _enum: ($) => "enum",
    _struct: ($) => "struct",
    _match: ($) => "match",
    _fn: ($) => "fn",

    /// symbols + punctuation
    _colon: ($) => ":",
    double_colon: ($) => "::",
    assign: ($) => "=",
    _dollar: ($) => "$",
    _left_paren: ($) => "(",
    _right_paren: ($) => ")",
    _left_brace: ($) => "{",
    _right_brace: ($) => "}",
    _left_bracket: ($) => "[",
    _right_bracket: ($) => "]",
    _comma: ($) => ",",
    period: ($) => ".",
    _fat_arrow: ($) => "=>",
  },
});
