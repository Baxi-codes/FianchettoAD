#ifndef AST_PRINTER_H
#define AST_PRINTER_H

#include <iostream>
#include "ast.h"  // Include the header file with all AST node definitions
#include "visitor.h"

class ASTPrinter : public ASTVisitor {
public:
  ASTPrinter() = default;

  // Declaration visitor methods
  void visit(VariableDeclarationAST *node) override;
  void visit(FunctionDefinitionAST *node) override;

  // Expression visitor methods
  void visit(BinopExpressionAST *node) override;
  void visit(PrefixExpressionAST *node) override;
  void visit(PostfixExpressionAST *node) override;
  void visit(FunctionCallAST *node) override;
  void visit(SubscriptExpressionAST *node) override;
  void visit(TernaryExpressionAST *node) override;
  void visit(VariableExpressionAST *node) override;
  void visit(ConstantExpressionAST *node) override;

  // Statement visitor methods
  void visit(DeclarationStatementAST *node) override;
  void visit(ExpressionStatementAST *node) override;
  void visit(CompoundStatementAST *node) override;
  void visit(SelectionStatementAST *node) override;
  void visit(WhileStatementAST *node) override;
  void visit(ForStatementAST *node) override;
  void visit(JumpStatementAST *node) override;

  // Program visitor methods
  void visit(ProgramAST *node) override;

private:
  int indentLevel = 0;
  void printIndent();
};

#endif // AST_PRINTER_H
