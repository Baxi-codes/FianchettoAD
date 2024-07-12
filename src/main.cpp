#include <argparse/argparse.hpp>
#include <iostream>

#include "parser.h"
#include "utils/ast_printer.h"
#include "llvm_codegen.h"

int main(int argc, char *argv[]) {
  argparse::ArgumentParser program("fianchetto");

  program.add_argument("--print-ast")
      .help("print AST to stdout")
      .default_value(false)
      .implicit_value(true);

  program.add_argument("--emit-llvm")
      .help("print LLVM IR source to stdout")
      .default_value(false)
      .implicit_value(true);

  program.add_argument("--target")
      .default_value(std::string{"native"})
      .choices("native", "wasm");

  program.add_argument("-o", "--output")
      .help("specify output file")
      .required()
      .default_value(std::string("a.out"))
      .action([](const std::string &value) { return value; });

  program.add_argument("input").help("input file").required();

  try {
    program.parse_args(argc, argv);
  } catch (const std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    std::exit(1);
  }

  std::string output_file = program.get<std::string>("-o");
  std::string input_file = program.get<std::string>("input");
  std::string target = program.get<std::string>("target");
  bool emit_llvm = program.get<bool>("--emit-llvm");
  bool print_ast = program.get<bool>("--print-ast");
  
  Parser parser(input_file);
  
  // Parse the source into an AST
  std::shared_ptr<ProgramAST> ast = parser.parse_program();

  // Check for parsing errors
  if (parser.has_error) {
    std::cerr << "Parsing failed due to errors.\n";
    return 1;
  }

  if (print_ast) {
    // Create an ASTPrinter to print the AST structure
    ASTPrinter printer;

    // Print the AST
    std::cout << "Parsed AST:\n";
    ast->accept(&printer);
    
    return 0;
  }

  std::string base_filename = input_file.substr(input_file.find_last_of("/\\") + 1);
  
  LLVMCodegenVisitor cgen_visitor(base_filename);
  ast->accept(&cgen_visitor);

  if (emit_llvm) {
    cgen_visitor.print_ir();
    return 0;
  }
  
  cgen_visitor.objgen(output_file, target);

  return 0;
}
