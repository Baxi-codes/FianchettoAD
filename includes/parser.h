#ifndef PARSER_H
#define PARSER_H 

#include <string>
#include "lexer.h"
#include "ast.h"

class Parser {
private:
  Lexer lexer;
  Token current_token;
  void error() {
    std::cout << "Unexpected: " << current_token.value << "\n";
    has_error = true;
  }
  void advance() {
    current_token = lexer.nextToken();
  }
  bool expect(TokenType type) {
    if (current_token.type != type) {
      error();
      return true;
    }
    return false;
  }
  bool consume(TokenType type) {
    if (expect(type))
      return true;
    advance();
    return false;
  }
  std::shared_ptr<FunctionDefinitionAST> parse_function_definition();
  std::shared_ptr<FunctionDefinitionAST> parse_function_definition();
public:
  bool has_error;
  Parser(std::string &source) : lexer(source), has_error(false) {
    advance();
  }
  std::shared_ptr<ProgramAST> parse_program();
};


#endif // PARSER_H