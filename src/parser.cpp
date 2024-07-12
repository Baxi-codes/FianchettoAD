#include "parser.h"
#include "ast.h"
#include "lexer.h"

#include <cassert>
#include <cstddef>
#include <memory>
#include <vector>

void print_stacktrace(void) {
  std::size_t size;
  enum Constexpr { MAX_SIZE = 1024 };
  void *array[MAX_SIZE];
  size = backtrace(array, MAX_SIZE);
  backtrace_symbols_fd(array, size, STDOUT_FILENO);
}

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
  return std::move(std::make_shared<ProgramAST>(function_definitions, global_declarations));
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
  bool has_initial_value = 0;
  consume(TokenType::KW_let);
  type = current_token.value;
  advance();
  expect(TokenType::IDENTIFIER);
  name = current_token.value;
  advance();
  if (current_token.type == TokenType::EQUAL) {
    has_initial_value = 1;
    consume(TokenType::EQUAL);
    initial_value = std::move(parse_expression());
    consume(TokenType::SEMI);
  }
  return std::make_shared<VariableDeclarationAST>(type, name, has_initial_value, is_global_variable, initial_value);
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
    case TokenType::KW_while:
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
  return std::move(std::make_shared<SelectionStatementAST>(condition, body, else_body));
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
  auto decl = parse_variable_declaration();
  return std::make_shared<DeclarationStatementAST>(std::move(decl));
}

StatementASTPtr Parser::parse_expression_statement() {
  auto expr = parse_expression();
  consume(TokenType::SEMI);
  return std::make_shared<ExpressionStatementAST>(std::move(expr));
}

ExpressionASTPtr Parser::parse_expression() {
  return std::move(parse_assignment_expression());
}

ExpressionASTPtr Parser::parse_assignment_expression() {
  std::string operation;
  ExpressionASTPtr lhs, rhs = nullptr;
  lhs = parse_logical_or_expression();
  switch(current_token.type) {
    case TokenType::EQUAL:
    case TokenType::PLUSEQUAL:
    case TokenType::MINUSEQUAL:
    case TokenType::STAREQUAL:
    case TokenType::AMPEQUAL:
    case TokenType::PIPEEQUAL:
    case TokenType::SLASHEQUAL:
      operation = current_token.value;
      advance();
      rhs = std::move(parse_assignment_expression());
  }
  if (rhs) return std::make_shared<BinopExpressionAST>(operation, lhs, rhs);
  return std::move(lhs);
}

bool Parser::ensure_lvalue(const ExpressionASTPtr &expr) {
    if (std::dynamic_pointer_cast<VariableExpressionAST>(expr) != nullptr ||
      std::dynamic_pointer_cast<SubscriptExpressionAST>(expr) != nullptr) {
      return true;
    }
    return false;
}


ExpressionASTPtr Parser::parse_logical_or_expression() {
  ExpressionASTPtr lhs = parse_logical_and_expression();
  while (current_token.type == TokenType::PIPEPIPE) {
    consume(TokenType::PIPEPIPE);
    lhs = std::make_shared<BinopExpressionAST>(current_token.value, std::move(lhs), parse_logical_and_expression());
  }
  return std::move(lhs);
}

ExpressionASTPtr Parser::parse_logical_and_expression() {
  ExpressionASTPtr lhs = parse_equality_expression();
  while (current_token.type == TokenType::AMPAMP) {
    std::string op = current_token.value;
    advance();
    lhs = std::make_shared<BinopExpressionAST>(op, std::move(lhs), parse_equality_expression());
    consume(TokenType::AMPAMP);
  }
  return std::move(lhs);
}

ExpressionASTPtr Parser::parse_equality_expression() {
  ExpressionASTPtr lhs = parse_relational_expression();
  while (current_token.type == TokenType::EQUALEQUAL || current_token.type == TokenType::EXCLAIMEQUAL) {
    std::string op = current_token.value;
    advance();
    lhs = std::make_shared<BinopExpressionAST>(op, std::move(lhs), parse_relational_expression());
  }
  return std::move(lhs);
}

std::shared_ptr<ExpressionAST> Parser::parse_relational_expression() {
    auto lhs = parse_additive_expression();
    while (current_token.type == TokenType::LESS || current_token.type == TokenType::LESSEQUAL ||
           current_token.type == TokenType::GREATER || current_token.type == TokenType::GREATEREQUAL) {
        std::string op = current_token.value;
        advance();
        auto rhs = parse_additive_expression();
        lhs = std::make_shared<BinopExpressionAST>(op, std::move(lhs), std::move(rhs));
    }
    return lhs;
}

std::shared_ptr<ExpressionAST> Parser::parse_additive_expression() {
    auto lhs = parse_multiplicative_expression();
    while (current_token.type == TokenType::PLUS || current_token.type == TokenType::MINUS) {
        std::string op = current_token.value;
        advance();
        auto rhs = parse_additive_expression();
        lhs = std::make_shared<BinopExpressionAST>(op, std::move(lhs), std::move(rhs));
    }
    return lhs;
}

std::shared_ptr<ExpressionAST> Parser::parse_multiplicative_expression() {
    auto lhs = parse_unary_expression();
    while (current_token.type == TokenType::STAR || current_token.type == TokenType::SLASH || current_token.type == TokenType::PERCENT) {
        std::string op = current_token.value;
        advance();
        auto rhs = parse_additive_expression();
        lhs = std::make_shared<BinopExpressionAST>(op, std::move(lhs), std::move(rhs));
    }
    return lhs;
}

std::shared_ptr<ExpressionAST> Parser::parse_unary_expression() {
    if (current_token.type == TokenType::EXCLAIM || current_token.type == TokenType::MINUS ||
        current_token.type == TokenType::PLUSPLUS || current_token.type == TokenType::MINUSMINUS) {
        std::string op = current_token.value;
        advance();
        auto operand = parse_unary_expression();
        return std::make_shared<PrefixExpressionAST>(op, std::move(operand));
    }
    return parse_postfix_expression();
}

std::shared_ptr<ExpressionAST> Parser::parse_postfix_expression() {
    auto lhs = parse_primary_expression();
    while (current_token.type == TokenType::PLUSPLUS || current_token.type == TokenType::MINUSMINUS ||
           current_token.type == TokenType::L_SQUARE || current_token.type == TokenType::L_PAREN) {
        if (current_token.type == TokenType::PLUSPLUS || current_token.type == TokenType::MINUSMINUS) {
            std::string op = current_token.value;
            advance();
            lhs = std::make_shared<PostfixExpressionAST>(op, std::move(lhs));
        } else if (current_token.type == TokenType::L_SQUARE) {
            advance();
            auto index = parse_expression();
            consume(TokenType::R_PAREN);
            lhs = std::make_shared<SubscriptExpressionAST>(std::move(lhs), std::move(index));
        } else if (current_token.type == TokenType::L_PAREN) {
            advance();
            std::vector<std::shared_ptr<ExpressionAST>> args;
            if (current_token.type != TokenType::R_PAREN) {
              args.push_back(parse_expression());
              while (current_token.type == TokenType::COMMA) {
                advance();
                args.push_back(std::move(parse_expression()));
              }
            }
            expect(TokenType::R_PAREN);
            advance();
            assert(std::dynamic_pointer_cast<VariableExpressionAST>(lhs) != nullptr && "LHS of a function call should be an identifier only!");
            lhs = std::make_shared<FunctionCallAST>(std::move(lhs), std::move(args));
        }
    }
    return lhs;
}

std::shared_ptr<ExpressionAST> Parser::parse_primary_expression() {
    if (current_token.type == TokenType::IDENTIFIER) {
        auto id = current_token.value;
        advance();
        return std::make_shared<VariableExpressionAST>(std::move(id));
    } else if (current_token.type == TokenType::INTEGER_LITERAL || current_token.type == TokenType::FLOAT_LITERAL ||
               current_token.type == TokenType::STRING_LITERAL) {
        auto constant = current_token.value;
        std::string type;
        switch (current_token.type) {
        case TokenType::INTEGER_LITERAL:
          type = "int";
          break;
        case TokenType::FLOAT_LITERAL:
          type = "float";
          break;
        case TokenType::STRING_LITERAL:
          type = "string";
          break;
        }
        advance();
        return std::make_shared<ConstantExpressionAST>(constant, type);
    } else if (current_token.type == TokenType::L_PAREN) {
        advance();
        auto expr = parse_expression();
        consume(TokenType::R_PAREN);
        return expr;
    }
    error(); // Unexpected primary expression
    return nullptr; // Unreachable
}
