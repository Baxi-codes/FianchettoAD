#include "parser.h"
#include "ast.h"
#include "lexer.h"

using ASTNodePtr = std::shared_ptr<ASTNode>;
using StatementASTPtr = std::shared_ptr<StatementAST>;
using ExpressionASTPtr = std::shared_ptr<ExpressionAST>;

std::shared_ptr<ProgramAST> Parser::parse_program() {
  std::vector<std::shared_ptr<FunctionDefinitionAST>> function_definitions;
  std::vector<std::shared_ptr<VariableDeclarationAST>> global_declarations;
  while (current_token.type != TokenType::END_OF_FILE) {
    switch (current_token.type) {
    case TokenType::KW_fn:
    case TokenType::KW_differentiable:
      function_definitions.push_back(std::move(parse_function_definition()));
      break;
    case TokenType::KW_let:
      global_declarations.push_back(std::move(parse_variable_declaration(true)));
      break;
    case TokenType::SEMI:
      advance();
      break;
    default:
      error();
    }
  }
}

std::shared_ptr<FunctionDefinitionAST> Parser::parse_function_definition() {
  bool differentiable = false;
  std::vector<std::string> argument_types, argument_names;
  if (current_token.type == TokenType::KW_differentiable) {
    differentiable = true;
    consume(TokenType::KW_differentiable);
  }
  consume(TokenType::KW_fn);
  std::string return_type(current_token.value);
  advance();
  expect(TokenType::IDENTIFIER);
  std::string name(current_token.value);
  advance();
  consume(TokenType::L_PAREN);
  vector<std::string> argument_types, argument_names;
  if (current_token.type != TokenType::R_PAREN) {
    argument_types.push_back(current_token.value);
    advance();
    expect(TokenType::IDENTIFIER);
    argument_names.push_back(current_token.value);
    advance();
    while (current_token.type != TokenType::R_PAREN) {
      consume(TokenType::COMMA);
      argument_types.push_back(current_token.value);
      advance();
      expect(TokenType::IDENTIFIER);
      argument_names.push_back(current_token.value);
      advance();
    }
  }
  consume(TokenType::R_PAREN);
  return std::make_shared<FunctionDefinitionAST>(
      return_type, name, argument_types, argument_names,
      std::move(parse_statement()), differentiable);
}

std::shared_ptr<VariableDeclarationAST> Parser::parse_variable_declaration(bool is_global_variable = false) {
  std::string type, name;
  ExpressionASTPtr initial_value = nullptr;
  bool has_initial_value;
  consume(TokenType::KW_let);
  type = current_token.value;
  advance();
  expect(TokenType::IDENTIFIER);
  type = current_token.value;
  advance();
  if (current_token == TokenType::EQUAL) {
    has_initial_value = 1;
    consume(TokenType::EQUAL);
    initial_value = std::move(parse_expression());
    consume(TokenType::SEMI);
  }
}

StatementASTPtr Parser::parse_statement() {
  switch(current_token.type) {
    case TokenType::L_BRACE:
      return std::move(parse_compound_statement());
      break;
    case TokenType::KW_if:
      return std::move(parse_selection_statement());
      break;
    case TokenType::KW_for:
      return std::move(parse_iteration_statement());
      break;
    case TokenType::KW_return:
    case TokenType::KW_continue:
    case TokenType::KW_break:
      return std::move(parse_jump_statement());
      break;
    case TokenType::KW_let:
      return std::move(parse_declaration_statement());
      break;
    case SEMI:
      return nullptr;
    default:
      return parse_expression_statement();
  }
}

StatementASTPtr Parser::parse_compound_statement() {
  std::vector<StatementASTPtr> statements;
  consume(TokenType::L_BRACE);
  while(current_token.type != TokenType::R_BRACE) {
    statements.push_back(parse_statement());
  }
  consume(TokenType::R_BRACE);
  return std::make_shared<CompoundStatementAST>(statements);
}

StatementASTPtr Parser::parse_selection_statement() {
  ExpressionASTPtr condition;
  StatementASTPtr body, else_body = nullptr;
  consume(TokenType::KW_if);
  consume(TokenType::L_PAREN);
  condition = std::move(parse_expression());
  consume(TokenType::R_PAREN);
  body = std::move(parse_statement());
  if (current_token.type == TokenType::KW_else) {
    consume(TokenType::KW_else);
    else_body = std::move(parse_statement());
  }
}

StatementASTPtr Parser::parse_iteration_statement() {
  if (current_token.type == TokenType::KW_for) {
    // parse for loop
    StatementASTPtr start;
    ExpressionASTPtr end, step;
    StatementASTPtr body;
    consume(TokenType::KW_for);
    consume(TokenType::L_PAREN);
    start = std::move(parse_statement());
    step = std::move(parse_expression());
    consume(TokenType::SEMI);
    end = std::move(parse_expression());
    consume(TokenType::R_PAREN);
    body = std::move(parse_statement());
    return std::make_shared<ForStatementAST>(start, end, step, body);
  } else {
    ExpressionASTPtr condition;
    StatementASTPtr body;
    consume(TokenType::KW_while);
    consume(TokenType::L_PAREN);
    condition = std::move(parse_expression());
    consume(TokenType::R_PAREN);
    body = std::move(parse_statement());
    return std::make_shared<WhileStatementAST>(condition, body);
  }
}

StatementASTPtr Parser::parse_jump_statement() {
  std::string jump_stament_kind = current_token.value;
  ExpressionASTPtr return_value = nullptr;
  switch(current_token.type) {
    case TokenType::KW_return:
      consume(TokenType::KW_return);
      return_value = std::move(parse_expression());
      break;
    case TokenType::KW_break:
      consume(TokenType::KW_break);
      break;
    case TokenType::KW_continue:
      consume(TokenType::KW_continue);
      break;
  }
  consume(TokenType::SEMI);
  return std::make_shared<JumpStatementAST>(jump_stament_kind, return_value);
}

StatementASTPtr Parser::parse_declaration_statement() {
  return std::make_shared<VariableDeclarationAST>(std::move(parse_variable_declaration()));
}

ExpressionASTPtr Parser::parse_expression_statement() {
  return std::make_shared<ExpressionStatementAST>(std::move(parse_expression()));  
}

ExpressionASTPtr Parser::parse_expression() {
  return std::move(parse_assignment_expression());
}

ExpressionASTPtr Parser::parse_assignment_expression() {
  std::string operation;
  ExpressionASTPtr LHS, RHS = nullptr;
  LHS = std::move(parse_logical_or_expression());
  switch(current_token.type) {
    case TokenType::EQUAL:
    case TokenType::PLUSEQUAL:
    case TokenType::MINUSEQUAL:
    case TokenType::STAREQUAL:
    case TokenType::AMPEQUAL:
    case TokenType::PIPEEQUAL:
    case TokenType::SLASHEQUAL:
      operation = current_token.value;
      RHS = std::move(parse_assignment_expression());

  }
}

