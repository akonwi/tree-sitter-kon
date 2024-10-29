#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 42
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 36
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_fn = 1,
  anon_sym_LPAREN = 2,
  anon_sym_COMMA = 3,
  anon_sym_RPAREN = 4,
  anon_sym_LBRACE = 5,
  anon_sym_RBRACE = 6,
  anon_sym_let = 7,
  anon_sym_mut = 8,
  anon_sym_Str = 9,
  anon_sym_Num = 10,
  anon_sym_Bool = 11,
  sym_identifier = 12,
  anon_sym_DQUOTE = 13,
  aux_sym_string_token1 = 14,
  sym_number = 15,
  anon_sym_true = 16,
  anon_sym_false = 17,
  anon_sym_COLON = 18,
  sym_assign = 19,
  sym_source_file = 20,
  sym_variable_definition = 21,
  sym_function_definition = 22,
  sym_parameters = 23,
  sym_param_def = 24,
  sym_return_type = 25,
  sym_block = 26,
  sym__type_declaration = 27,
  sym_variable_binding = 28,
  sym_primitive_type = 29,
  sym_primitive_value = 30,
  sym_string = 31,
  sym_boolean = 32,
  sym__colon = 33,
  aux_sym_source_file_repeat1 = 34,
  aux_sym_parameters_repeat1 = 35,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_fn] = "fn",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_let] = "let",
  [anon_sym_mut] = "mut",
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
  [sym_assign] = "assign",
  [sym_source_file] = "source_file",
  [sym_variable_definition] = "variable_definition",
  [sym_function_definition] = "function_definition",
  [sym_parameters] = "parameters",
  [sym_param_def] = "param_def",
  [sym_return_type] = "return_type",
  [sym_block] = "block",
  [sym__type_declaration] = "_type_declaration",
  [sym_variable_binding] = "variable_binding",
  [sym_primitive_type] = "primitive_type",
  [sym_primitive_value] = "primitive_value",
  [sym_string] = "string",
  [sym_boolean] = "boolean",
  [sym__colon] = "_colon",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_mut] = anon_sym_mut,
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
  [sym_assign] = sym_assign,
  [sym_source_file] = sym_source_file,
  [sym_variable_definition] = sym_variable_definition,
  [sym_function_definition] = sym_function_definition,
  [sym_parameters] = sym_parameters,
  [sym_param_def] = sym_param_def,
  [sym_return_type] = sym_return_type,
  [sym_block] = sym_block,
  [sym__type_declaration] = sym__type_declaration,
  [sym_variable_binding] = sym_variable_binding,
  [sym_primitive_type] = sym_primitive_type,
  [sym_primitive_value] = sym_primitive_value,
  [sym_string] = sym_string,
  [sym_boolean] = sym_boolean,
  [sym__colon] = sym__colon,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mut] = {
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
  [sym_assign] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_definition] = {
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
  [sym__type_declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_variable_binding] = {
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
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(21);
      ADVANCE_MAP(
        '"', 34,
        '(', 23,
        ')', 25,
        ',', 24,
        ':', 41,
        '=', 42,
        'B', 9,
        'N', 17,
        'S', 16,
        'f', 2,
        'l', 5,
        'm', 19,
        't', 12,
        '{', 26,
        '}', 27,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 1:
      if (lookahead == ')') ADVANCE(25);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(6);
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(40);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 6:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 7:
      if (lookahead == 'l') ADVANCE(32);
      END_STATE();
    case 8:
      if (lookahead == 'm') ADVANCE(31);
      END_STATE();
    case 9:
      if (lookahead == 'o') ADVANCE(10);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(7);
      END_STATE();
    case 11:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 12:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 13:
      if (lookahead == 's') ADVANCE(4);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(28);
      END_STATE();
    case 15:
      if (lookahead == 't') ADVANCE(29);
      END_STATE();
    case 16:
      if (lookahead == 't') ADVANCE(11);
      END_STATE();
    case 17:
      if (lookahead == 'u') ADVANCE(8);
      END_STATE();
    case 18:
      if (lookahead == 'u') ADVANCE(3);
      END_STATE();
    case 19:
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_Str);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_Num);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_Bool);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_assign);
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
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 35},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_mut] = ACTIONS(1),
    [anon_sym_Str] = ACTIONS(1),
    [anon_sym_Num] = ACTIONS(1),
    [anon_sym_Bool] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_assign] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(41),
    [sym_variable_definition] = STATE(2),
    [sym_function_definition] = STATE(2),
    [sym_variable_binding] = STATE(33),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(5),
    [anon_sym_let] = ACTIONS(7),
    [anon_sym_mut] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(5), 1,
      anon_sym_fn,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    STATE(33), 1,
      sym_variable_binding,
    ACTIONS(7), 2,
      anon_sym_let,
      anon_sym_mut,
    STATE(3), 3,
      sym_variable_definition,
      sym_function_definition,
      aux_sym_source_file_repeat1,
  [19] = 5,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      anon_sym_fn,
    STATE(33), 1,
      sym_variable_binding,
    ACTIONS(16), 2,
      anon_sym_let,
      anon_sym_mut,
    STATE(3), 3,
      sym_variable_definition,
      sym_function_definition,
      aux_sym_source_file_repeat1,
  [38] = 5,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      sym_number,
    STATE(14), 1,
      sym_primitive_value,
    ACTIONS(23), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_string,
      sym_boolean,
  [56] = 5,
    ACTIONS(25), 1,
      anon_sym_LBRACE,
    STATE(11), 1,
      sym_block,
    STATE(26), 1,
      sym_return_type,
    STATE(35), 1,
      sym_primitive_type,
    ACTIONS(27), 3,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [74] = 5,
    ACTIONS(19), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      sym_number,
    STATE(20), 1,
      sym_primitive_value,
    ACTIONS(23), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym_string,
      sym_boolean,
  [92] = 4,
    ACTIONS(29), 1,
      anon_sym_COLON,
    ACTIONS(31), 1,
      sym_assign,
    STATE(8), 1,
      sym__colon,
    STATE(34), 1,
      sym__type_declaration,
  [105] = 2,
    STATE(38), 1,
      sym_primitive_type,
    ACTIONS(27), 3,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [114] = 1,
    ACTIONS(33), 4,
      anon_sym_LBRACE,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [121] = 1,
    ACTIONS(35), 4,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      sym_assign,
  [128] = 1,
    ACTIONS(37), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [135] = 1,
    ACTIONS(39), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [142] = 1,
    ACTIONS(41), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [149] = 1,
    ACTIONS(43), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [156] = 2,
    STATE(28), 1,
      sym_primitive_type,
    ACTIONS(27), 3,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [165] = 1,
    ACTIONS(45), 4,
      anon_sym_LBRACE,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [172] = 1,
    ACTIONS(47), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [179] = 1,
    ACTIONS(49), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [186] = 1,
    ACTIONS(51), 4,
      anon_sym_LBRACE,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [193] = 1,
    ACTIONS(53), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [200] = 1,
    ACTIONS(55), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_let,
      anon_sym_mut,
  [207] = 3,
    ACTIONS(57), 1,
      anon_sym_COMMA,
    ACTIONS(59), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_parameters_repeat1,
  [217] = 3,
    ACTIONS(61), 1,
      anon_sym_RPAREN,
    ACTIONS(63), 1,
      sym_identifier,
    STATE(22), 1,
      sym_param_def,
  [227] = 3,
    ACTIONS(57), 1,
      anon_sym_COMMA,
    ACTIONS(65), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      aux_sym_parameters_repeat1,
  [237] = 3,
    ACTIONS(67), 1,
      anon_sym_COMMA,
    ACTIONS(70), 1,
      anon_sym_RPAREN,
    STATE(25), 1,
      aux_sym_parameters_repeat1,
  [247] = 2,
    ACTIONS(25), 1,
      anon_sym_LBRACE,
    STATE(17), 1,
      sym_block,
  [254] = 1,
    ACTIONS(70), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [259] = 1,
    ACTIONS(72), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [264] = 2,
    ACTIONS(63), 1,
      sym_identifier,
    STATE(27), 1,
      sym_param_def,
  [271] = 2,
    ACTIONS(74), 1,
      anon_sym_LPAREN,
    STATE(5), 1,
      sym_parameters,
  [278] = 2,
    ACTIONS(76), 1,
      anon_sym_COLON,
    STATE(15), 1,
      sym__colon,
  [285] = 1,
    ACTIONS(78), 1,
      anon_sym_RBRACE,
  [289] = 1,
    ACTIONS(80), 1,
      sym_identifier,
  [293] = 1,
    ACTIONS(82), 1,
      sym_assign,
  [297] = 1,
    ACTIONS(84), 1,
      anon_sym_LBRACE,
  [301] = 1,
    ACTIONS(86), 1,
      anon_sym_DQUOTE,
  [305] = 1,
    ACTIONS(88), 1,
      aux_sym_string_token1,
  [309] = 1,
    ACTIONS(90), 1,
      sym_assign,
  [313] = 1,
    ACTIONS(92), 1,
      sym_identifier,
  [317] = 1,
    ACTIONS(94), 1,
      sym_identifier,
  [321] = 1,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 19,
  [SMALL_STATE(4)] = 38,
  [SMALL_STATE(5)] = 56,
  [SMALL_STATE(6)] = 74,
  [SMALL_STATE(7)] = 92,
  [SMALL_STATE(8)] = 105,
  [SMALL_STATE(9)] = 114,
  [SMALL_STATE(10)] = 121,
  [SMALL_STATE(11)] = 128,
  [SMALL_STATE(12)] = 135,
  [SMALL_STATE(13)] = 142,
  [SMALL_STATE(14)] = 149,
  [SMALL_STATE(15)] = 156,
  [SMALL_STATE(16)] = 165,
  [SMALL_STATE(17)] = 172,
  [SMALL_STATE(18)] = 179,
  [SMALL_STATE(19)] = 186,
  [SMALL_STATE(20)] = 193,
  [SMALL_STATE(21)] = 200,
  [SMALL_STATE(22)] = 207,
  [SMALL_STATE(23)] = 217,
  [SMALL_STATE(24)] = 227,
  [SMALL_STATE(25)] = 237,
  [SMALL_STATE(26)] = 247,
  [SMALL_STATE(27)] = 254,
  [SMALL_STATE(28)] = 259,
  [SMALL_STATE(29)] = 264,
  [SMALL_STATE(30)] = 271,
  [SMALL_STATE(31)] = 278,
  [SMALL_STATE(32)] = 285,
  [SMALL_STATE(33)] = 289,
  [SMALL_STATE(34)] = 293,
  [SMALL_STATE(35)] = 297,
  [SMALL_STATE(36)] = 301,
  [SMALL_STATE(37)] = 305,
  [SMALL_STATE(38)] = 309,
  [SMALL_STATE(39)] = 313,
  [SMALL_STATE(40)] = 317,
  [SMALL_STATE(41)] = 321,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 4, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 3, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 4, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 5, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_def, 3, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_type, 1, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_declaration, 2, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_binding, 1, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
