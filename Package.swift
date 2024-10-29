// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterKon",
    products: [
        .library(name: "TreeSitterKon", targets: ["TreeSitterKon"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterKon",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterKonTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterKon",
            ],
            path: "bindings/swift/TreeSitterKonTests"
        )
    ],
    cLanguageStandard: .c11
)
