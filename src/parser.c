#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 23
#define ALIAS_COUNT 0
#define TOKEN_COUNT 14
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_let = 1,
  anon_sym_mut = 2,
  anon_sym_Str = 3,
  anon_sym_Num = 4,
  anon_sym_Bool = 5,
  sym_identifier = 6,
  anon_sym_DQUOTE = 7,
  aux_sym_string_token1 = 8,
  sym_number = 9,
  anon_sym_true = 10,
  anon_sym_false = 11,
  sym_colon = 12,
  sym_assign = 13,
  sym_source_file = 14,
  sym_variable_definition = 15,
  sym__type_declaration = 16,
  sym_variable_binding = 17,
  sym_primitive_type = 18,
  sym_primitive_value = 19,
  sym_string = 20,
  sym_boolean = 21,
  aux_sym_source_file_repeat1 = 22,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [sym_colon] = "colon",
  [sym_assign] = "assign",
  [sym_source_file] = "source_file",
  [sym_variable_definition] = "variable_definition",
  [sym__type_declaration] = "_type_declaration",
  [sym_variable_binding] = "variable_binding",
  [sym_primitive_type] = "primitive_type",
  [sym_primitive_value] = "primitive_value",
  [sym_string] = "string",
  [sym_boolean] = "boolean",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  [sym_colon] = sym_colon,
  [sym_assign] = sym_assign,
  [sym_source_file] = sym_source_file,
  [sym_variable_definition] = sym_variable_definition,
  [sym__type_declaration] = sym__type_declaration,
  [sym_variable_binding] = sym_variable_binding,
  [sym_primitive_type] = sym_primitive_type,
  [sym_primitive_value] = sym_primitive_value,
  [sym_string] = sym_string,
  [sym_boolean] = sym_boolean,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
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
  [sym_colon] = {
    .visible = true,
    .named = true,
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
  [aux_sym_source_file_repeat1] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(21);
      ADVANCE_MAP(
        '"', 28,
        ':', 35,
        '=', 36,
        'B', 8,
        'N', 16,
        'S', 15,
        'f', 1,
        'l', 4,
        'm', 18,
        't', 11,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == 'e') ADVANCE(33);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 5:
      if (lookahead == 'l') ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 7:
      if (lookahead == 'm') ADVANCE(25);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == 'o') ADVANCE(6);
      END_STATE();
    case 10:
      if (lookahead == 'r') ADVANCE(24);
      END_STATE();
    case 11:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 12:
      if (lookahead == 's') ADVANCE(3);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 15:
      if (lookahead == 't') ADVANCE(10);
      END_STATE();
    case 16:
      if (lookahead == 'u') ADVANCE(7);
      END_STATE();
    case 17:
      if (lookahead == 'u') ADVANCE(2);
      END_STATE();
    case 18:
      if (lookahead == 'u') ADVANCE(14);
      END_STATE();
    case 19:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_Str);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_Num);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_Bool);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(30);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_colon);
      END_STATE();
    case 36:
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
  [14] = {.lex_state = 19},
  [15] = {.lex_state = 19},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 29},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_mut] = ACTIONS(1),
    [anon_sym_Str] = ACTIONS(1),
    [anon_sym_Num] = ACTIONS(1),
    [anon_sym_Bool] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_colon] = ACTIONS(1),
    [sym_assign] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(13),
    [sym_variable_definition] = STATE(4),
    [sym_variable_binding] = STATE(15),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_let] = ACTIONS(5),
    [anon_sym_mut] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(7), 1,
      anon_sym_DQUOTE,
    ACTIONS(9), 1,
      sym_number,
    STATE(10), 1,
      sym_primitive_value,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(9), 2,
      sym_string,
      sym_boolean,
  [18] = 5,
    ACTIONS(7), 1,
      anon_sym_DQUOTE,
    ACTIONS(9), 1,
      sym_number,
    STATE(11), 1,
      sym_primitive_value,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(9), 2,
      sym_string,
      sym_boolean,
  [36] = 4,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    STATE(15), 1,
      sym_variable_binding,
    ACTIONS(5), 2,
      anon_sym_let,
      anon_sym_mut,
    STATE(5), 2,
      sym_variable_definition,
      aux_sym_source_file_repeat1,
  [51] = 4,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    STATE(15), 1,
      sym_variable_binding,
    ACTIONS(17), 2,
      anon_sym_let,
      anon_sym_mut,
    STATE(5), 2,
      sym_variable_definition,
      aux_sym_source_file_repeat1,
  [66] = 2,
    STATE(18), 1,
      sym_primitive_type,
    ACTIONS(20), 3,
      anon_sym_Str,
      anon_sym_Num,
      anon_sym_Bool,
  [75] = 3,
    ACTIONS(22), 1,
      sym_colon,
    ACTIONS(24), 1,
      sym_assign,
    STATE(16), 1,
      sym__type_declaration,
  [85] = 1,
    ACTIONS(26), 3,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
  [91] = 1,
    ACTIONS(28), 3,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
  [97] = 1,
    ACTIONS(30), 3,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
  [103] = 1,
    ACTIONS(32), 3,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
  [109] = 1,
    ACTIONS(34), 3,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_mut,
  [115] = 1,
    ACTIONS(36), 1,
      ts_builtin_sym_end,
  [119] = 1,
    ACTIONS(38), 1,
      sym_identifier,
  [123] = 1,
    ACTIONS(40), 1,
      sym_identifier,
  [127] = 1,
    ACTIONS(42), 1,
      sym_assign,
  [131] = 1,
    ACTIONS(44), 1,
      aux_sym_string_token1,
  [135] = 1,
    ACTIONS(46), 1,
      sym_assign,
  [139] = 1,
    ACTIONS(48), 1,
      sym_assign,
  [143] = 1,
    ACTIONS(50), 1,
      anon_sym_DQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 18,
  [SMALL_STATE(4)] = 36,
  [SMALL_STATE(5)] = 51,
  [SMALL_STATE(6)] = 66,
  [SMALL_STATE(7)] = 75,
  [SMALL_STATE(8)] = 85,
  [SMALL_STATE(9)] = 91,
  [SMALL_STATE(10)] = 97,
  [SMALL_STATE(11)] = 103,
  [SMALL_STATE(12)] = 109,
  [SMALL_STATE(13)] = 115,
  [SMALL_STATE(14)] = 119,
  [SMALL_STATE(15)] = 123,
  [SMALL_STATE(16)] = 127,
  [SMALL_STATE(17)] = 131,
  [SMALL_STATE(18)] = 135,
  [SMALL_STATE(19)] = 139,
  [SMALL_STATE(20)] = 143,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_value, 1, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 4, 0, 0),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_definition, 5, 0, 0),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_binding, 1, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_declaration, 2, 0, 0),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
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
