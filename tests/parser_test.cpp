#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"
#include "utils/ast_printer.h"

int main(int argc, char *argv[]) {
  // Check for input source either via command line or standard input
  std::string source;

  if (argc > 1) {
    source = std::string(argv[1]);
  } else {
  	printf("Filename required\n");
  }

  // Create a parser with the source code
  Parser parser(source);

  // Parse the source into an AST
  std::shared_ptr<ProgramAST> ast = parser.parse_program();

  // Check for parsing errors
  if (parser.has_error) {
    std::cerr << "Parsing failed due to errors.\n";
    return 1;
  }

  // Create an ASTPrinter to print the AST structure
  ASTPrinter printer;

  // Print the AST
  std::cout << "Parsed AST:\n";
  ast->accept(&printer);

  return 0;
}
