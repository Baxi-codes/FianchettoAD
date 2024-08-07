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

class FunctionCallAST : public ExpressionAST {
  ExpressionASTPtr functionName; // The name of the function being called
  std::vector<ExpressionASTPtr> arguments; // The arguments to the function

public:
  // Constructor
  FunctionCallAST(ExpressionASTPtr functionName, std::vector<ExpressionASTPtr> arguments)
      : functionName(functionName), arguments(arguments) {}

  // Getters and Setters
  ExpressionASTPtr get_functionName() const { return functionName; }
  void set_functionName(const ExpressionASTPtr &name) { functionName = name; }

  std::vector<ExpressionASTPtr> get_arguments() const { return arguments; }
  void set_arguments(const std::vector<ExpressionASTPtr> &args) { arguments = args; }

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
  std::string type;

public:
  ConstantExpressionAST(const std::string &value, const std::string &type)
      : value(value), type(type) {}

  std::string get_value() const { return value; }
  void set_value(const std::string &val) { value = val; }

  std::string get_type() const { return type; }
  void set_type(const std::string &typ) { type = typ; }

  void accept(ASTVisitor *v) override;
};

#endif // EXPRESSION_H
