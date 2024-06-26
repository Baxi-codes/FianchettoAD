#ifndef PARSER_H
#define PARSER_H 

#include <string>
#include <utility>
#include <execinfo.h> /* backtrace, backtrace_symbols_fd */
#include <unistd.h> /* STDOUT_FILENO */

#include "lexer.h"
#include "ast.h"

void print_stacktrace(void);

// TODO: improve error diagnostics

class Parser {
private:
  Lexer lexer;
  Token current_token;
  void error() {
    std::cerr << "Unexpected: " << current_token.get_type() << ": " << current_token.value << " at line " << current_token.loc.line << " column "
              << current_token.loc.column << std::endl;
    has_error = true;
    print_stacktrace();
    exit(1);
  }
  void advance() {
    current_token = lexer.nextToken();
  }
  bool expect(TokenType type) {
    if (current_token.type != type) {
      std::cerr << "Expected token type" << tt_to_str(type) << "\n";
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
  std::shared_ptr<VariableDeclarationAST> parse_variable_declaration(bool is_global_variable);
  std::shared_ptr<StatementAST> parse_statement();
  std::shared_ptr<StatementAST> parse_expression_statement();
  std::shared_ptr<StatementAST> parse_declaration_statement();
  std::shared_ptr<VariableDeclarationAST> parse_declaration();  
  std::shared_ptr<StatementAST> parse_compound_statement();
  std::shared_ptr<StatementAST> parse_selection_statement();
  std::shared_ptr<StatementAST> parse_iteration_statement();
  std::shared_ptr<StatementAST> parse_jump_statement();
  std::shared_ptr<ExpressionAST> parse_expression();
  bool ensure_lvalue(const ExpressionASTPtr &expr);
  std::shared_ptr<ExpressionAST> parse_assignment_expression();
  std::shared_ptr<ExpressionAST> parse_logical_or_expression();
  std::shared_ptr<ExpressionAST> parse_logical_and_expression();
  std::shared_ptr<ExpressionAST> parse_equality_expression();
  std::shared_ptr<ExpressionAST> parse_relational_expression();
  std::shared_ptr<ExpressionAST> parse_additive_expression();
  std::shared_ptr<ExpressionAST> parse_multiplicative_expression();
  std::shared_ptr<ExpressionAST> parse_unary_expression();
  std::shared_ptr<ExpressionAST> parse_postfix_expression();
  std::shared_ptr<ExpressionAST> parse_primary_expression();

public:
  bool has_error;
  Parser(std::string &source) : lexer(source), has_error(false) {
    advance();
  }
  std::shared_ptr<ProgramAST> parse_program();
};


#endif // PARSER_H