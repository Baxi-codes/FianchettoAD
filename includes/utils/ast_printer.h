#ifndef AST_PRINTER_H
#define AST_PRINTER_H

#include "visitor.h"
#include <iostream>
#include <string>

class ASTPrinter : public ASTVisitor {
public:
  void visit(VariableDeclarationAST *node) override;
  void visit(FunctionDefinitionAST *node) override;

  void visit(BinopExpressionAST *node) override;
  void visit(PrefixExpressionAST *node) override;
  void visit(PostfixExpressionAST *node) override;
  void visit(SubscriptExpressionAST *node) override;
  void visit(TernaryExpressionAST *node) override;
  void visit(VariableExpressionAST *node) override;
  void visit(ConstantExpressionAST *node) override;

  void visit(ExpressionStatementAST *node) override;
  void visit(DeclarationStatementAST *node) override;
  void visit(CompoundStatementAST *node) override;
  void visit(SelectionStatementAST *node) override;
  void visit(WhileStatementAST *node) override;
  void visit(ForStatementAST *node) override;
  void visit(JumpStatementAST *node) override;

  void visit(ProgramAST *node) override;

private:
  void printIndent();
  void incrementIndent();
  void decrementIndent();

  int indentLevel = 0;
};

#endif // AST_PRINTER_H
