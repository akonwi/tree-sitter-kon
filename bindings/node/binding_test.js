/// <reference types="node" />

const assert = require("node:assert");
const { test } = require("node:test");

test("can load grammar", () => {
  const parser = new (require("tree-sitter"))();
  assert.doesNotThrow(() => parser.setLanguage(require(".")));
  assert.equal(parser.parse("let x = 5").rootNode.type, "program");
});
