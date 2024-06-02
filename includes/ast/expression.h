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
  
  std::string get_operation() const { return operation; }
  void set_operation(const std::string &op) { operation = op; }
  
  ExpressionASTPtr get_LHS() const { return LHS; }
  void set_LHS(ExpressionASTPtr lhs) { LHS = lhs; }

  ExpressionASTPtr get_RHS() const { return RHS; }
  void set_RHS(ExpressionASTPtr rhs) { RHS = rhs; }

  void accept(ASTVisitor *v) override;
};

class PrefixExpressionAST : public ExpressionAST {
  std::string operation;
  ExpressionASTPtr operand;

public:
  PrefixExpressionAST(std::string operation, ExpressionASTPtr operand)
      : operation(operation), operand(operand) {}
  
  std::string get_operation() const { return operation; }
  void set_operation(const std::string &op) { operation = op; }

  ExpressionASTPtr get_operand() const { return operand; }
  void set_operand(ExpressionASTPtr op) { operand = op; }

  void accept(ASTVisitor *v) override;
};

class PostfixExpressionAST : public ExpressionAST {
  std::string operation;
  ExpressionASTPtr operand;

public:
  PostfixExpressionAST(std::string operation, ExpressionASTPtr operand)
      : operation(operation), operand(operand) {}
  
  std::string get_operation() const { return operation; }
  void set_operation(const std::string &op) { operation = op; }

  ExpressionASTPtr get_operand() const { return operand; }
  void set_operand(ExpressionASTPtr op) { operand = op; }

  void accept(ASTVisitor *v) override;
};

class SubscriptExpressionAST : public ExpressionAST {
  ExpressionASTPtr baseExpression;
  ExpressionASTPtr indexExpression;

public:
  SubscriptExpressionAST(ExpressionASTPtr baseExpression, ExpressionASTPtr indexExpression)
      : baseExpression(baseExpression), indexExpression(indexExpression) {}
  
  ExpressionASTPtr get_baseExpression() const { return baseExpression; }
  void set_baseExpression(ExpressionASTPtr baseExpr) { baseExpression = baseExpr; }

  ExpressionASTPtr get_indexExpression() const { return indexExpression; }
  void set_indexExpression(ExpressionASTPtr indexExpr) { indexExpression = indexExpr; }

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

  ExpressionASTPtr get_condition() const { return condition; }
  void set_condition(ExpressionASTPtr cond) { condition = cond; }

  ExpressionASTPtr get_trueExpr() const { return trueExpr; }
  void set_trueExpr(ExpressionASTPtr trueExpression) { trueExpr = trueExpression; }

  ExpressionASTPtr get_falseExpr() const { return falseExpr; }
  void set_falseExpr(ExpressionASTPtr falseExpression) { falseExpr = falseExpression; }

  void accept(ASTVisitor *v) override;
};

class VariableExpressionAST : public ExpressionAST {
  std::string name;

public:
  VariableExpressionAST(std::string name) : name(name) {}

  std::string get_name() const { return name; }
  void set_name(const std::string &n) { name = n; }

  void accept(ASTVisitor *v) override;
};

class ConstantExpressionAST : public ExpressionAST {
  std::string value;

public:
  ConstantExpressionAST(const std::string &value) : value(value) {}

  std::string get_value() const { return value; }
  void set_value(const std::string &val) { value = val; }

  void accept(ASTVisitor *v) override;
};

#endif // EXPRESSION_H
