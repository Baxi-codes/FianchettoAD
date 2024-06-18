#ifndef STATEMENT_H
#define STATEMENT_H

#include <cassert>
#include <memory>
#include <vector>

#include "ast/astnode.h"
#include "ast/expression.h"

class ASTNode;
class StatementAST;
class ExpressionAST;
class VariableDeclarationAST;

using ASTNodePtr = std::shared_ptr<ASTNode>;
using StatementASTPtr = std::shared_ptr<StatementAST>;
using ExpressionASTPtr = std::shared_ptr<ExpressionAST>;
using VariableDeclarationASTPtr = std::shared_ptr<VariableDeclarationAST>;

class StatementAST : public ASTNode {
public:
  virtual ~StatementAST() = default;
};

class ExpressionStatementAST : public StatementAST {
  ExpressionASTPtr expression;

public:
  ExpressionStatementAST(ExpressionASTPtr expression)
      : expression(expression) {}
  
  ExpressionASTPtr get_expression() const { return expression; }
  void set_expression(ExpressionASTPtr expr) { expression = expr; }

  void accept(ASTVisitor *v) override;
};

class DeclarationStatementAST : public StatementAST {
  VariableDeclarationASTPtr declaration;

public:
  DeclarationStatementAST(VariableDeclarationASTPtr declaration)
      : declaration(declaration) {}
  
  VariableDeclarationASTPtr get_declaration() const { return declaration; }
  void set_declaration(VariableDeclarationASTPtr expr) { declaration = expr; }

  void accept(ASTVisitor *v) override;
};

class CompoundStatementAST : public StatementAST {
  std::vector<StatementASTPtr> statements;

public:
  CompoundStatementAST(std::vector<StatementASTPtr> statements)
      : statements(statements) {}

  std::vector<StatementASTPtr> get_statements() const { return statements; }
  void set_statements(const std::vector<StatementASTPtr> &stmts) { statements = stmts; }

  void accept(ASTVisitor *v) override;
};

class SelectionStatementAST : public StatementAST {
  ExpressionASTPtr condition;
  StatementASTPtr body, else_body;

public:
  SelectionStatementAST(ExpressionASTPtr condition, StatementASTPtr body,
                        StatementASTPtr else_body)
      : condition(condition), body(body), else_body(else_body) {}
  
  ExpressionASTPtr get_condition() const { return condition; }
  void set_condition(ExpressionASTPtr cond) { condition = cond; }

  StatementASTPtr get_body() const { return body; }
  void set_body(StatementASTPtr b) { body = b; }

  StatementASTPtr get_else_body() const { return else_body; }
  void set_else_body(StatementASTPtr elseB) { else_body = elseB; }

  void accept(ASTVisitor *v) override;
};

class WhileStatementAST : public StatementAST {
  ExpressionASTPtr condition;
  StatementASTPtr body;

public:
  WhileStatementAST(ExpressionASTPtr condition, StatementASTPtr body)
      : condition(condition), body(body) {}

  ExpressionASTPtr get_condition() const { return condition; }
  void set_condition(ExpressionASTPtr cond) { condition = cond; }

  StatementASTPtr get_body() const { return body; }
  void set_body(StatementASTPtr b) { body = b; }

  void accept(ASTVisitor *v) override;
};

class ForStatementAST : public StatementAST {
  StatementASTPtr start;
  ExpressionASTPtr end, step;
  StatementASTPtr body;

public:
  ForStatementAST(StatementASTPtr start, ExpressionASTPtr end, ExpressionASTPtr step,
                  StatementASTPtr body)
      : start(start), end(end), step(step), body(body) {}

  StatementASTPtr get_start() const { return start; }
  void set_start(StatementASTPtr s) { start = s; }

  ExpressionASTPtr get_end() const { return end; }
  void set_end(ExpressionASTPtr e) { end = e; }

  ExpressionASTPtr get_step() const { return step; }
  void set_step(ExpressionASTPtr s) { step = s; }

  StatementASTPtr get_body() const { return body; }
  void set_body(StatementASTPtr b) { body = b; }

  void accept(ASTVisitor *v) override;
};

class JumpStatementAST : public StatementAST {
  std::string jump_stament_kind;
  ExpressionASTPtr return_value;

public:
  JumpStatementAST(std::string jump_stament_kind)
      : jump_stament_kind(jump_stament_kind), return_value(nullptr) {}
  JumpStatementAST(std::string jump_stament_kind, ExpressionASTPtr return_value)
      : jump_stament_kind(jump_stament_kind), return_value(return_value) {
    assert(jump_stament_kind == "return" &&
           "Only return kind of jump statements take the second argument");
  }

  std::string get_jump_stament_kind() const { return jump_stament_kind; }
  void set_jump_stament_kind(const std::string &kind) { jump_stament_kind = kind; }

  ExpressionASTPtr get_return_value() const { return return_value; }
  void set_return_value(ExpressionASTPtr value) { return_value = value; }

  void accept(ASTVisitor *v) override;
};

#endif // STATEMENT_H
