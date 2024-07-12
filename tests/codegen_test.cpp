#include <fstream>
#include <iostream>
#include <sstream>

#include "llvm_codegen.h"
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
  ASTPrinter printer;
  ast->accept(&printer);
  LLVMCodegenVisitor codegen_visitor("test");
  ast->accept(&codegen_visitor);
  std::cout << "\nPrinting the LLVM IR... \n\n";
  codegen_visitor.print_ir();
  return 0;
}
