#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <cassert>
#include <memory>
#include <vector>

#include "astnode.h"

class ExpressionAST;
using ExpressionASTPtr = std::shared_ptr<ExpressionAST>;

class ExpressionAST : public ASTNode {
public:
  virtual ~ExpressionAST() = default;
};

class BinopExpressionAST : public ExpressionAST {
  std::string operation;
  ExpressionASTPtr LHS, RHS;

public:
  BinopExpressionAST(std::string operation, ExpressionASTPtr LHS,
                     ExpressionASTPtr RHS)
      : operation(operation), LHS(LHS), RHS(RHS) {}
  void accept(ASTVisitor *v) override;
};

class PrefixExpressionAST : public ExpressionAST {
  std::string operation;
  ExpressionASTPtr operand;

public:
  PrefixExpressionAST(std::string operation, ExpressionASTPtr operand)
      : operation(operation), operand(operand) {}
  void accept(ASTVisitor *v) override;
};

class PostfixExpressionAST : public ExpressionAST {
  std::string operation;
  ExpressionASTPtr operand;

public:
  PostfixExpressionAST(std::string operation, ExpressionASTPtr operand)
      : operation(operation), operand(operand) {}
  void accept(ASTVisitor *v) override;
};

class SubscriptExpressionAST : public ExpressionAST {
  ExpressionASTPtr baseExpression;
  ExpressionASTPtr indexExpression;

public:
  SubscriptExpressionAST(ExpressionASTPtr baseExpression, ExpressionASTPtr indexExpression)
      : baseExpression(baseExpression), indexExpression(indexExpression) {}
  void accept(ASTVisitor *v) override;
};

class TernaryExpressionAST : public ExpressionAST {
  ExpressionASTPtr condition; // The condition of the ternary expression
  ExpressionASTPtr trueExpr;  // The expression if the condition is true
  ExpressionASTPtr falseExpr; // The expression if the condition is false

public:
  TernaryExpressionAST(ExpressionASTPtr condition, ExpressionASTPtr trueExpr,
                       ExpressionASTPtr falseExpr)
      : condition(condition), trueExpr(trueExpr), falseExpr(falseExpr) {}

  void accept(ASTVisitor *v) override;

  // Getter methods for condition, true expression, and false expression
  ExpressionASTPtr getCondition() const { return condition; }
  ExpressionASTPtr getTrueExpr() const { return trueExpr; }
  ExpressionASTPtr getFalseExpr() const { return falseExpr; }
};

class VariableExpressionAST : public ExpressionAST {
  std::string name;
  VariableExpressionAST(std::string name) : name(name) {}
};

class ConstantExpressionAST : public ExpressionAST {
  std::string value;

public:
  ConstantExpressionAST(const std::string &value) : value(value) {}
  void accept(ASTVisitor *v) override;
};

#endif // EXPRESSION_H
