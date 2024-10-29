import XCTest
import SwiftTreeSitter
import TreeSitterKon

final class TreeSitterKonTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_kon())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Kon grammar")
    }
}
