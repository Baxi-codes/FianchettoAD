#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ast.h"
#include <memory>

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
      : operation(operation), LHS(LHS), RHS(RHS) {}
  void accept(ASTVisitor *v) override;
};

class PostfixExpressionAST : public ExpressionAST {
  std::string operation;
  ExpressionASTPtr operand;

public:
  PostfixExpressionAST(std::string operation, ExpressionASTPtr operand)
      : operation(operation), LHS(LHS), RHS(RHS) {}
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



#endif // EXPRESSION_H
