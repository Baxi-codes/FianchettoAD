#include "lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
  std::string filename(argv[1]);
  Lexer lexer(filename);
  std::vector<Token> tokens = lexer.tokenize();
  for (auto token : tokens) {
    std::cout << token.get_type() << ": " << token.value << " at line " << token.loc.line << " column "
              << token.loc.column << std::endl;
  }
  return 0;
}