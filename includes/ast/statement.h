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

using ASTNodePtr = std::shared_ptr<ASTNode>;
using StatementASTPtr = std::shared_ptr<StatementAST>;
using ExpressionASTPtr = std::shared_ptr<ExpressionAST>;

class StatementAST : public ASTNode {
public:
  virtual ~StatementAST() = default;
};

class ExpressionStatementAST : public StatementAST {
  ExpressionASTPtr expression;

public:
  ExpressionStatementAST(ExpressionASTPtr expression)
      : expression(expression) {}
  void accept(ASTVisitor *v) override;
};

class CompoundStatementAST : public StatementAST {
  std::vector<StatementASTPtr> statements;

public:
  CompoundStatementAST(std::vector<StatementASTPtr> statements)
      : statements(statements) {}
  void accept(ASTVisitor *v) override;
};

class SelectionStatementAST : public StatementAST {
  ExpressionASTPtr condition;
  StatementASTPtr body, else_body;

public:
  SelectionStatementAST(ExpressionASTPtr condition, StatementASTPtr body)
      : condition(condition), body(body) {}
  SelectionStatementAST(ExpressionASTPtr condition, StatementASTPtr body,
                        StatementASTPtr else_body)
      : condition(condition), body(body), else_body(else_body) {}
  void accept(ASTVisitor *v) override;
};

class WhileStatementAST : public StatementAST {
  ExpressionASTPtr condition;
  StatementASTPtr body;

public:
  WhileStatementAST(ExpressionASTPtr condition, StatementASTPtr body)
      : condition(condition), body(body) {}
  void accept(ASTVisitor *v) override;
};

class ForStatementAST : public StatementAST {
  ASTNodePtr start;
  ExpressionASTPtr end, step;
  StatementASTPtr body;

public:
  ForStatementAST(ASTNodePtr start, ExpressionASTPtr end,
                  ExpressionASTPtr step, StatementASTPtr body)
      : start(start), end(end), step(step), body(body) {}
  void accept(ASTVisitor *v) override;
};

class JumpStatementAST : public StatementAST {
  std::string jumpStamentKind;
  ExpressionASTPtr return_value;

public:
  JumpStatementAST(std::string jumpStamentKind)
      : jumpStamentKind(jumpStamentKind), return_value(nullptr) {}
  JumpStatementAST(std::string jumpStamentKind, ExpressionASTPtr return_value)
      : jumpStamentKind(jumpStamentKind), return_value(return_value) {
    assert(jumpStamentKind == "return" &&
           "Only return kind of jump statements take the second argument");
  }
  void accept(ASTVisitor *v) override;
};

#endif // STATEMENT_H
