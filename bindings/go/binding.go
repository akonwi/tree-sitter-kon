package tree_sitter_kon

// #cgo CFLAGS: -std=c11 -fPIC
// #include "../../src/parser.c"
// // NOTE: if your language has an external scanner, add it here.
import "C"

import "unsafe"

// Get the tree-sitter Language for this grammar.
func Language() unsafe.Pointer {
	// bump
	// bump
	// bump
	return unsafe.Pointer(C.tree_sitter_kon())
}
