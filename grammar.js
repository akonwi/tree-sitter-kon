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
        $.print_statement, // remove
        $.while_loop,
        $.if_statement,
        $.for_loop,
        $.variable_definition,
        $.function_definition,
        $.reassignment,
        $.compound_assignment,
        $._expression_statement,
        $.struct_definition,
        $.enum_definition,
      ),

    //// definitions
    struct_definition: ($) =>
      seq(
        "struct",
        field("name", $.identifier),
        "{",
        sepBy(field("field", $.struct_property), ","),
        "}",
      ),

    struct_property: ($) =>
      seq(
        field("name", $.identifier),
        $._colon,
        field("type", choice($.primitive_type, $.identifier)),
      ),

    enum_definition: ($) =>
      seq(
        "enum",
        field("name", $.identifier),
        "{",
        sepBy1(field("variant", $.enum_variant), ","),
        "}",
      ),

    // todo: struct/tuple variants
    enum_variant: ($) => field("variant", choice($.identifier)),

    enum_struct_variant: ($) =>
      seq(field("name", $.identifier), "{", sepBy($.struct_property, ","), "}"),

    type_declaration: ($) =>
      field(
        "type",
        choice($.list_type, $.map_type, $.primitive_type, $.void, $.identifier),
      ),

    variable_definition: ($) =>
      seq(
        field("binding", $.variable_binding),
        field("name", $.identifier),
        optional(seq($._colon, field("type", $.type_declaration))),
        $._assign,
        field("value", $.expression),
      ),

    variable_binding: ($) => choice("let", "mut"),

    function_definition: ($) =>
      seq(
        "fn",
        field("name", $.identifier),
        field("parameters", $.parameters),
        optional(field("return", $.type_declaration)),
        field("body", $.block),
      ),

    anonymous_function: ($) =>
      seq(
        seq(
          $._left_paren,
          sepBy(field("parameter", $.anonymous_parameter), ","),
          $._right_paren,
        ),
        field("return", optional($.type_declaration)),
        field("body", $.block),
      ),

    anonymous_parameter: ($) =>
      choice(
        seq(
          field("name", $.identifier),
          $._colon,
          field("type", $.type_declaration),
        ),
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
      seq("(", sepBy(field("argument", $.expression), ","), ")"),

    parameters: ($) =>
      seq("(", sepBy(field("parameter", $.param_def), ","), ")"),

    param_def: ($) =>
      seq(
        field("name", $.identifier),
        $._colon,
        field("type", $.type_declaration),
      ),

    block: ($) => seq("{", optional(repeat($.statement)), "}"),

    //// Statements
    print_statement: ($) => seq("print", field("arguments", $.paren_arguments)),
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
        field("else", optional($.else_statement)),
      ),

    else_statement: ($) =>
      seq("else", choice(field("if", $.if_statement), field("body", $.block))),

    reassignment: ($) =>
      prec(
        "assignment",
        seq(
          field("name", $.identifier),
          $._assign,
          field("value", $.expression),
        ),
      ),
    compound_assignment: ($) =>
      prec(
        "assignment",
        seq(
          field("name", $.identifier),
          field("operator", choice($.increment, $.decrement)),
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
            $.static_member_access,
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
        "match",
        field("expr", $.expression),
        $._left_brace,
        sepBy1(field("case", $.match_case), $._comma),
        $._right_brace,
      ),

    match_case: ($) =>
      seq(
        field("pattern", $.static_member_access),
        "=>",
        field("body", choice($.block, $.expression)),
      ),

    struct_instance: ($) =>
      seq(
        field("name", $.identifier),
        "{",
        sepBy(field("field", $.struct_prop_pair), ","),
        "}",
      ),

    member_access: ($) =>
      prec.right(
        "member",
        seq(
          field("target", $.identifier),
          ".",
          field(
            "member",
            choice($.member_access, $.identifier, $.function_call),
          ),
        ),
      ),

    static_member_access: ($) =>
      prec.right(
        "member",
        seq(
          field("target", $.identifier),
          $.double_colon,
          field(
            "member",
            choice($.static_member_access, $.identifier, $.function_call),
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
    list_type: ($) =>
      seq(
        "[",
        field(
          "inner",
          choice($.primitive_type, $.map_type, $.list_type, $.identifier),
        ),
        "]",
      ),
    map_type: ($) =>
      seq(
        "[",
        field("key", $.str),
        $._colon,
        field("value", $.primitive_type),
        "]",
      ),
    primitive_type: ($) => choice($.str, $.num, $.bool),

    ///// values
    list_value: ($) =>
      seq(
        "[",
        sepBy(
          field(
            "inner",
            choice(
              $.number,
              $.string,
              $.boolean,
              $.identifier,
              $.struct_instance,
            ),
          ),
          ",",
        ),
        "]",
      ),
    map_value: ($) =>
      choice(seq("[", ":", "]"), seq("[", sepBy1($.map_pair, ","), "]")),
    map_pair: ($) =>
      seq(
        field("key", choice($.string)),
        ":",
        field("value", choice($.string, $.number, $.boolean)),
      ),
    struct_prop_pair: ($) =>
      seq(
        field("name", $.identifier),
        ":",
        // todo?: just allow expressions
        field(
          "value",
          choice($.string, $.number, $.boolean, $.static_member_access),
        ),
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
            choice(alias(/[^"${}]+/, $.string_content), $.string_interpolation),
          ),
        ),
        '"',
      ),
    string_interpolation: ($) =>
      seq("${", field("expression", $.expression), "}"),
    number: ($) => /\d+(\.\d+)?/,
    boolean: ($) => choice("true", "false"),
    _colon: ($) => ":",
    double_colon: ($) => "::",
    _assign: ($) => "=",
    _left_paren: ($) => "(",
    _right_paren: ($) => ")",
    _left_brace: ($) => "{",
    _right_brace: ($) => "}",
    _comma: ($) => ",",
    str: ($) => "Str",
    num: ($) => "Num",
    bool: ($) => "Bool",
    void: ($) => "Void",
    comment: ($) =>
      token(
        choice(seq("//", /[^\n]*/), seq("/*", /[^*]*\*+([^/*][^*]*\*+)*\//)),
      ),
  },
});
