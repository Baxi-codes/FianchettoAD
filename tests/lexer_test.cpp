#include "lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
  std::string filename(argv[1]);
  Lexer lexer(filename);
  std::vector<Token> tokens = lexer.tokenize();
  for (auto token : tokens) {
    if (token.type == TokenType::KEYWORD)
      std::cout << "KEYWORD: ";
    if (token.type == TokenType::IDENTIFIER)
      std::cout << "IDENTIFIER: ";
    if (token.type == TokenType::OPERATOR)
      std::cout << "OPERATOR: ";
    if (token.type == TokenType::INTEGER_LITERAL)
      std::cout << "INTEGER_LITERAL: ";
    if (token.type == TokenType::FLOAT_LITERAL)
      std::cout << "FLOAT_LITERAL: ";
    if (token.type == TokenType::STRING_LITERAL)
      std::cout << "STRING_LITERAL: ";
    if (token.type == TokenType::PUNCTUATION)
      std::cout << "PUNCTUATION: ";
    if (token.type == TokenType::PRIME)
      std::cout << "PRIME: ";
    if (token.type == TokenType::END_OF_FILE)
      std::cout << "END_OF_FILE: ";
    std::cout << token.value << " at line " << token.line << " column " << token.column << std::endl;
	}
	return 0;
}