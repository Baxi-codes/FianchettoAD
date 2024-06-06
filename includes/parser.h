#ifndef PARSER_H
#define PARSER_H 

#include <string>
#include <pair>
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
  }s
  std::shared_ptr<FunctionDefinitionAST> parse_function_definition();
  std::shared_ptr<VariableDeclarationAST> parse_global_declaration();
  std::shared_ptr<StatementAST> parse_statement();
  std::shared_ptr<StatementAST> parse_expression_statement();
  std::shared_ptr<StatementAST> parse_declaration_statement();
  std::shared_ptr<VariableDeclarationAST> parse_declaration();  
  std::shared_ptr<StatementAST> parse_compound_statement();
  std::shared_ptr<StatementAST> parse_selection_statement();
  std::shared_ptr<StatementAST> parse_iteration_statement();
  std::shared_ptr<StatementAST> parse_jump_statement();
  std::shared_ptr<ExpressionAST> parse_expression();
  std::shared_ptr<ExpressionAST> parse_assignment_expression();

public:
  bool has_error;
  Parser(std::string &source) : lexer(source), has_error(false) {
    advance();
  }
  std::shared_ptr<ProgramAST> parse_program();
};


#endif // PARSER_H