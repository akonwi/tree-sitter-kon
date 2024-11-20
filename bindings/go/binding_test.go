package tree_sitter_kon_test

import (
	"testing"

	tree_sitter_kon "github.com/akonwi/tree-sitter-kon/bindings/go"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_kon.Language())
	if language == nil {
		t.Errorf("Error loading Kon grammar")
	}
}
