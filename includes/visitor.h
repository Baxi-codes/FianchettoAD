#ifndef VISITOR_H
#define VISITOR_H

#include "ast.h"

class ASTVisitor {
public:
  virtual ~ASTVisitor() = default;

  // Declaration visitor methods
  virtual void visit(VariableDeclarationAST *node) = 0;
  virtual void visit(FunctionDefinitionAST *node) = 0;

  // Expression visitor methods
  virtual void visit(BinopExpressionAST *node) = 0;
  virtual void visit(PrefixExpressionAST *node) = 0;
  virtual void visit(PostfixExpressionAST *node) = 0;
  virtual void visit(SubscriptExpressionAST *node) = 0;
  virtual void visit(TernaryExpressionAST *node) = 0;
  virtual void visit(VariableExpressionAST *node) = 0;
  virtual void visit(ConstantExpressionAST *node) = 0;

  // Statement visitor methods
  virtual void visit(DeclarationStatementAST *node) = 0;
  virtual void visit(ExpressionStatementAST *node) = 0;
  virtual void visit(CompoundStatementAST *node) = 0;
  virtual void visit(SelectionStatementAST *node) = 0;
  virtual void visit(WhileStatementAST *node) = 0;
  virtual void visit(ForStatementAST *node) = 0;
  virtual void visit(JumpStatementAST *node) = 0;

  // Program visitor methods
  virtual void visit(ProgramAST *node) = 0;
};

#endif // VISITOR_H
