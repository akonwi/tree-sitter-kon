#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 56
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 0
#define TOKEN_COUNT 29
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 3

enum ts_symbol_identifiers {
  anon_sym_let = 1,
  anon_sym_mut = 2,
  anon_sym_fn = 3,
  anon_sym_LPAREN = 4,
  anon_sym_COMMA = 5,
  anon_sym_RPAREN = 6,
  anon_sym_LBRACE = 7,
  anon_sym_RBRACE = 8,
  anon_sym_while = 9,
  anon_sym_Str = 10,
  anon_sym_Num = 11,
  anon_sym_Bool = 12,
  sym_identifier = 13,
  anon_sym_DQUOTE = 14,
  aux_sym_string_token1 = 15,
  sym_number = 16,
  anon_sym_true = 17,
  anon_sym_false = 18,
  anon_sym_COLON = 19,
  anon_sym_EQ = 20,
  sym_multiply = 21,
  sym_divide = 22,
  sym_plus = 23,
  sym_minus = 24,
  sym_greater_than = 25,
  sym_greater_than_or_equal = 26,
  sym_less_than = 27,
  sym_less_than_or_equal = 28,
  sym_source_file = 29,
  sym_statement = 30,
  sym_variable_definition = 31,
  sym__type_declaration = 32,
  sym_variable_binding = 33,
  sym_function_definition = 34,
  sym_parameters = 35,
  sym_param_def = 36,
  sym_return_type = 37,
  sym_block = 38,
  sym_while_loop = 39,
  sym__expression = 40,
  sym_binary_expression = 41,
  sym_primitive_type = 42,
  sym_primitive_value = 43,
  sym_string = 44,
  sym_boolean = 45,
  sym__colon = 46,
  sym__assign = 47,
  aux_sym_source_file_repeat1 = 48,
  aux_sym_parameters_repeat1 = 49,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_let] = "let",
  [anon_sym_mut] = "mut",
  [anon_sym_fn] = "fn",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_while] = "while",
  [anon_sym_Str] = "Str",
  [anon_sym_Num] = "Num",
  [anon_sym_Bool] = "Bool",
  [sym_identifier] = "identifier",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [sym_number] = "number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [sym_multiply] = "multiply",
  [sym_divide] = "divide",
  [sym_plus] = "plus",
  [sym_minus] = "minus",
  [sym_greater_than] = "greater_than",
  [sym_greater_than_or_equal] = "greater_than_or_equal",
  [sym_less_than] = "less_than",
  [sym_less_than_or_equal] = "less_than_or_equal",
  [sym_source_file] = "source_file",
  [sym_statement] = "statement",
  [sym_variable_definition] = "variable_definition",
  [sym__type_declaration] = "_type_declaration",
  [sym_variable_binding] = "variable_binding",
  [sym_function_definition] = "function_definition",
  [sym_parameters] = "parameters",
  [sym_param_def] = "param_def",
  [sym_return_type] = "return_type",
  [sym_block] = "block",
  [sym_while_loop] = "while_loop",
  [sym__expression] = "_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_primitive_type] = "primitive_type",
  [sym_primitive_value] = "primitive_value",
  [sym_string] = "string",
  [sym_boolean] = "boolean",
  [sym__colon] = "_colon",
  [sym__assign] = "_assign",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_mut] = anon_sym_mut,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_Str] = anon_sym_Str,
  [anon_sym_Num] = anon_sym_Num,
  [anon_sym_Bool] = anon_sym_Bool,
  [sym_identifier] = sym_identifier,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [sym_number] = sym_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_multiply] = sym_multiply,
  [sym_divide] = sym_divide,
  [sym_plus] = sym_plus,
  [sym_minus] = sym_minus,
  [sym_greater_than] = sym_greater_than,
  [sym_greater_than_or_equal] = sym_greater_than_or_equal,
  [sym_less_than] = sym_less_than,
  [sym_less_than_or_equal] = sym_less_than_or_equal,
  [sym_source_file] = sym_source_file,
  [sym_statement] = sym_statement,
  [sym_variable_definition] = sym_variable_definition,
  [sym__type_declaration] = sym__type_declaration,
  [sym_variable_binding] = sym_variable_binding,
  [sym_function_definition] = sym_function_definition,
  [sym_parameters] = sym_parameters,
  [sym_param_def] = sym_param_def,
  [sym_return_type] = sym_return_type,
  [sym_block] = sym_block,
  [sym_while_loop] = sym_while_loop,
  [sym__expression] = sym__expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_primitive_type] = sym_primitive_type,
  [sym_primitive_value] = sym_primitive_value,
  [sym_string] = sym_string,
  [sym_boolean] = sym_boolean,
  [sym__colon] = sym__colon,
  [sym__assign] = sym__assign,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mut] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Str] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Num] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Bool] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_multiply] = {
    .visible = true,
    .named = true,
  },
  [sym_divide] = {
    .visible = true,
    .named = true,
  },
  [sym_plus] = {
    .visible = true,
    .named = true,
  },
  [sym_minus] = {
    .visible = true,
    .named = true,
  },
  [sym_greater_than] = {
    .visible = true,
    .named = true,
  },
  [sym_greater_than_or_equal] = {
    .visible = true,
    .named = true,
  },
  [sym_less_than] = {
    .visible = true,
    .named = true,
  },
  [sym_less_than_or_equal] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__type_declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_variable_binding] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_param_def] = {
    .visible = true,
    .named = true,
  },
  [sym_return_type] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_while_loop] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_primitive_type] = {
    .visible = true,
    .named = true,
  },
  [sym_primitive_value] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym__colon] = {
    .visible = false,
    .named = true,
  },
  [sym__assign] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_condition = 1,
  field_left = 2,
  field_operator = 3,
  field_right = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_condition] = "condition",
  [field_left] = "left",
  [field_operator] = "operator",
  [field_right] = "right",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_condition, 1},
  [1] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(26);
      ADVANCE_MAP(
        '"', 47,
        '(', 30,
        ')', 32,
        '*', 58,
        '+', 60,
        ',', 31,
        '-', 61,
        '/', 59,
        ':', 56,
        '<', 64,
        '=', 57,
        '>', 62,
        'B', 14,
        'N', 22,
        'S', 21,
        'f', 3,
        'l', 7,
        'm', 24,
        't', 17,
        'w', 8,
        '{', 33,
        '}', 34,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(47);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 't') ADVANCE(43);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 2:
      if (lookahead == ')') ADVANCE(32);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(10);
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(35);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 8:
      if (lookahead == 'h') ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == 'i') ADVANCE(12);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(38);
      END_STATE();
    case 12:
      if (lookahead == 'l') ADVANCE(6);
      END_STATE();
    case 13:
      if (lookahead == 'm') ADVANCE(37);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(11);
      END_STATE();
    case 16:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 18:
      if (lookahead == 's') ADVANCE(5);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(28);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(16);
      END_STATE();
    case 22:
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 23:
      if (lookahead == 'u') ADVANCE(4);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(51);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_Str);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_Num);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_Bool);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(49);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_multiply);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_divide);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_plus);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_minus);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_greater_than);
      if (lookahead == '=') ADVANCE(63);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_greater_than_or_equal);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_less_than);
      if (lookahead == '=') ADVANCE(65);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_less_than_or_equal);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 48},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_mut] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_Str] = ACTIONS(1),
    [anon_sym_Num] = ACTIONS(1),
    [anon_sym_Bool] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_multiply] = ACTIONS(1),
    [sym_divide] = ACTIONS(1),
    [sym_plus] = ACTIONS(1),
    [sym_minus] = ACTIONS(1),
    [sym_greater_than] = ACTIONS(1),
    [sym_greater_than_or_equal] = ACTIONS(1),
    [sym_less_than] = ACTIONS(1),
    [sym_less_than_or_equal] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(47),
    [sym_statement] = STATE(6),
    [sym_variable_definition] = STATE(24),
    [sym_variable_binding] = STATE(49),
    [sym_function_definition] = STATE(24),
    [sym_while_loop] = STATE(24),
    [aux_sym_source_file_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_let] = ACTIONS(5),
    [anon_sym_mut] = ACTIONS(5),
    [anon_sym_fn] = ACTIONS(7),
    [anon_sym_while] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(13), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(11), 12,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_LBRACE,
      anon_sym_while,
      sym_multiply,
      sym_divide,
      sym_plus,
      sym_minus,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [19] = 2,
    ACTIONS(17), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(15), 12,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_LBRACE,
      anon_sym_while,
      sym_multiply,
      sym_divide,
      sym_plus,
      sym_minus,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [38] = 2,
    ACTIONS(21), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(19), 12,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_LBRACE,
      anon_sym_while,
      sym_multiply,
      sym_divide,
      sym_plus,
      sym_minus,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [57] = 7,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(28), 1,
      anon_sym_fn,
    ACTIONS(31), 1,
      anon_sym_while,
    STATE(49), 1,
      sym_variable_binding,
    ACTIONS(25), 2,
      anon_sym_let,
      anon_sym_mut,
    STATE(5), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(24), 3,
      sym_variable_definition,
      sym_function_definition,
      sym_while_loop,
  [83] = 7,
    ACTIONS(7), 1,
      anon_sym_fn,
    ACTIONS(9), 1,
      anon_sym_while,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
    STATE(49), 1,
      sym_variable_binding,
    ACTIONS(5), 2,
      anon_sym_let,
      anon_sym_mut,
    STATE(5), 2,
      sym_statement,
      aux_sym_source_file_repeat1,
    STATE(24), 3,
      sym_variable_definition,
      sym_function_definition,
      sym_while_loop,
  [109] = 6,
    ACTIONS(36), 1,
      sym_identifier,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    ACTIONS(42), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
    STATE(8), 3,
      sym__expression,
      sym_binary_expression,
      sym_primitive_value,
  [132] = 8,
    ACTIONS(44), 1,
      anon_sym_LBRACE,
    ACTIONS(46), 1,
      sym_multiply,
    ACTIONS(48), 1,
      sym_divide,
    ACTIONS(50), 1,
      sym_plus,
    ACTIONS(52), 1,
      sym_minus,
    STATE(27), 1,
      sym_block,
    ACTIONS(54), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(56), 2,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [159] = 6,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    ACTIONS(58), 1,
      sym_identifier,
    ACTIONS(42), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
    STATE(14), 3,
      sym__expression,
      sym_binary_expression,
      sym_primitive_value,
  [182] = 6,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    ACTIONS(60), 1,
      sym_identifier,
    ACTIONS(42), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
    STATE(15), 3,
      sym__expression,
      sym_binary_expression,
      sym_primitive_value,
  [205] = 6,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    ACTIONS(62), 1,
      sym_identifier,
    ACTIONS(42), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
    STATE(17), 3,
      sym__expression,
      sym_binary_expression,
      sym_primitive_value,
  [228] = 6,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    ACTIONS(64), 1,
      sym_identifier,
    ACTIONS(42), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
    STATE(16), 3,
      sym__expression,
      sym_binary_expression,
      sym_primitive_value,
  [251] = 6,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    ACTIONS(66), 1,
      sym_identifier,
    ACTIONS(42), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
    STATE(18), 3,
      sym__expression,
      sym_binary_expression,
      sym_primitive_value,
  [274] = 2,
    ACTIONS(70), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(68), 7,
      anon_sym_LBRACE,
      sym_multiply,
      sym_divide,
      sym_plus,
      sym_minus,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [288] = 3,
    ACTIONS(46), 1,
      sym_multiply,
    ACTIONS(70), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(68), 6,
      anon_sym_LBRACE,
      sym_divide,
      sym_plus,
      sym_minus,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [304] = 4,
    ACTIONS(46), 1,
      sym_multiply,
    ACTIONS(48), 1,
      sym_divide,
    ACTIONS(70), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(68), 5,
      anon_sym_LBRACE,
      sym_plus,
      sym_minus,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [322] = 5,
    ACTIONS(46), 1,
      sym_multiply,
    ACTIONS(48), 1,
      sym_divide,
    ACTIONS(50), 1,
      sym_plus,
    ACTIONS(70), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(68), 4,
      anon_sym_LBRACE,
      sym_minus,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [342] = 6,
    ACTIONS(46), 1,
      sym_multiply,
    ACTIONS(48), 1,
      sym_divide,
    ACTIONS(50), 1,
      sym_plus,
    ACTIONS(52), 1,
      sym_minus,
    ACTIONS(70), 2,
      sym_greater_than,
      sym_less_than,
    ACTIONS(68), 3,
      anon_sym_LBRACE,
      sym_greater_than_or_equal,
      sym_less_than_or_equal,
  [364] = 5,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    STATE(28), 1,
      sym_primitive_value,
    ACTIONS(72), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
  [382] = 5,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      sym_number,
    STATE(22), 1,
      sym_primitive_value,
    ACTIONS(72), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym_string,
      sym_boolean,
  [400] = 5,
    ACTIONS(44), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      sym_block,
    STATE(42), 1,
      sym_return_type,
    STATE(50), 1,
      sym_primitive_type,
    ACTIONS(74), 3,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [418] = 1,
    ACTIONS(76), 5,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_while,
  [426] = 1,
    ACTIONS(78), 5,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_while,
  [434] = 1,
    ACTIONS(80), 5,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_while,
  [442] = 5,
    ACTIONS(82), 1,
      anon_sym_COLON,
    ACTIONS(84), 1,
      anon_sym_EQ,
    STATE(19), 1,
      sym__assign,
    STATE(32), 1,
      sym__colon,
    STATE(41), 1,
      sym__type_declaration,
  [458] = 1,
    ACTIONS(86), 5,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_while,
  [466] = 1,
    ACTIONS(88), 5,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_while,
  [474] = 1,
    ACTIONS(90), 5,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_while,
  [482] = 1,
    ACTIONS(92), 5,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
      anon_sym_fn,
      anon_sym_while,
  [490] = 1,
    ACTIONS(94), 4,
      anon_sym_LBRACE,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [497] = 1,
    ACTIONS(96), 4,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_EQ,
  [504] = 2,
    STATE(53), 1,
      sym_primitive_type,
    ACTIONS(74), 3,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [513] = 1,
    ACTIONS(98), 4,
      anon_sym_LBRACE,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [520] = 1,
    ACTIONS(100), 4,
      anon_sym_LBRACE,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [527] = 2,
    STATE(46), 1,
      sym_primitive_type,
    ACTIONS(74), 3,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [536] = 3,
    ACTIONS(102), 1,
      anon_sym_RPAREN,
    ACTIONS(104), 1,
      sym_identifier,
    STATE(38), 1,
      sym_param_def,
  [546] = 3,
    ACTIONS(106), 1,
      anon_sym_COMMA,
    ACTIONS(108), 1,
      anon_sym_RPAREN,
    STATE(39), 1,
      aux_sym_parameters_repeat1,
  [556] = 3,
    ACTIONS(106), 1,
      anon_sym_COMMA,
    ACTIONS(110), 1,
      anon_sym_RPAREN,
    STATE(37), 1,
      aux_sym_parameters_repeat1,
  [566] = 3,
    ACTIONS(112), 1,
      anon_sym_COMMA,
    ACTIONS(115), 1,
      anon_sym_RPAREN,
    STATE(39), 1,
      aux_sym_parameters_repeat1,
  [576] = 2,
    ACTIONS(117), 1,
      anon_sym_LPAREN,
    STATE(21), 1,
      sym_parameters,
  [583] = 2,
    ACTIONS(119), 1,
      anon_sym_EQ,
    STATE(20), 1,
      sym__assign,
  [590] = 2,
    ACTIONS(44), 1,
      anon_sym_LBRACE,
    STATE(29), 1,
      sym_block,
  [597] = 1,
    ACTIONS(115), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [602] = 2,
    ACTIONS(104), 1,
      sym_identifier,
    STATE(43), 1,
      sym_param_def,
  [609] = 2,
    ACTIONS(121), 1,
      anon_sym_COLON,
    STATE(35), 1,
      sym__colon,
  [616] = 1,
    ACTIONS(123), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [621] = 1,
    ACTIONS(125), 1,
      ts_builtin_sym_end,
  [625] = 1,
    ACTIONS(127), 1,
      aux_sym_string_token1,
  [629] = 1,
    ACTIONS(129), 1,
      sym_identifier,
  [633] = 1,
    ACTIONS(131), 1,
      anon_sym_LBRACE,
  [637] = 1,
    ACTIONS(133), 1,
      anon_sym_DQUOTE,
  [641] = 1,
    ACTIONS(135), 1,
      anon_sym_RBRACE,
  [645] = 1,
    ACTIONS(137), 1,
      anon_sym_EQ,
  [649] = 1,
    ACTIONS(139), 1,
      sym_identifier,
  [653] = 1,
    ACTIONS(141), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 19,
  [SMALL_STATE(4)] = 38,
  [SMALL_STATE(5)] = 57,
  [SMALL_STATE(6)] = 83,
  [SMALL_STATE(7)] = 109,
  [SMALL_STATE(8)] = 132,
  [SMALL_STATE(9)] = 159,
  [SMALL_STATE(10)] = 182,
  [SMALL_STATE(11)] = 205,
  [SMALL_STATE(12)] = 228,
  [SMALL_STATE(13)] = 251,
  [SMALL_STATE(14)] = 274,
  [SMALL_STATE(15)] = 288,
  [SMALL_STATE(16)] = 304,
  [SMALL_STATE(17)] = 322,
  [SMALL_STATE(18)] = 342,
  [SMALL_STATE(19)] = 364,
  [SMALL_STATE(20)] = 382,
  [SMALL_STATE(21)] = 400,
  [SMALL_STATE(22)] = 418,
  [SMALL_STATE(23)] = 426,
  [SMALL_STATE(24)] = 434,
  [SMALL_STATE(25)] = 442,
  [SMALL_STATE(26)] = 458,
  [SMALL_STATE(27)] = 466,
  [SMALL_STATE(28)] = 474,
  [SMALL_STATE(29)] = 482,
  [SMALL_STATE(30)] = 490,
  [SMALL_STATE(31)] = 497,
  [SMALL_STATE(32)] = 504,
  [SMALL_STATE(33)] = 513,
  [SMALL_STATE(34)] = 520,
  [SMALL_STATE(35)] = 527,
  [SMALL_STATE(36)] = 536,
  [SMALL_STATE(37)] = 546,
  [SMALL_STATE(38)] = 556,
  [SMALL_STATE(39)] = 566,
  [SMALL_STATE(40)] = 576,
  [SMALL_STATE(41)] = 583,
  [SMALL_STATE(42)] = 590,
  [SMALL_STATE(43)] = 597,
  [SMALL_STATE(44)] = 602,
  [SMALL_STATE(45)] = 609,
  [SMALL_STATE(46)] = 616,
  [SMALL_STATE(47)] = 621,
  [SMALL_STATE(48)] = 625,
  [SMALL_STATE(49)] = 629,
  [SMALL_STATE(50)] = 633,
  [SMALL_STATE(51)] = 637,
  [SMALL_STATE(52)] = 641,
  [SMALL_STATE(53)] = 645,
  [SMALL_STATE(54)] = 649,
  [SMALL_STATE(55)] = 653,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 1, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, 0, 2),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, 0, 2),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 5, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_loop, 3, 0, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 4, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 3, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 4, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_def, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_type, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_declaration, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_binding, 1, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_kon(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
