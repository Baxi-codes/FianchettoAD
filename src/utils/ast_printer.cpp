#include "utils/ast_printer.h"
#include "ast.h"

void ASTPrinter::printIndent() {
  for (int i = 0; i < indentLevel; ++i) {
    std::cout << "  ";
  }
}

void ASTPrinter::incrementIndent() {
  ++indentLevel;
}

void ASTPrinter::decrementIndent() {
  --indentLevel;
}

void ASTPrinter::visit(VariableDeclarationAST *node) {
  printIndent();
  std::cout << "VariableDeclarationAST: " << node->get_type() << " " << node->get_name();
  if (node->get_has_initial_value()) {
    std::cout << " = ";
    node->get_initial_value()->accept(this);
  }
  std::cout << std::endl;
}

void ASTPrinter::visit(FunctionDefinitionAST *node) {
  printIndent();
  std::cout << "FunctionDefinitionAST: " << node->get_return_type() << " " << node->get_name() << std::endl;
  incrementIndent();
  node->get_body()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(BinopExpressionAST *node) {
  printIndent();
  std::cout << "BinopExpressionAST: " << node->get_operation() << std::endl;
  incrementIndent();
  node->get_LHS()->accept(this);
  node->get_RHS()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(PrefixExpressionAST *node) {
  printIndent();
  std::cout << "PrefixExpressionAST: " << node->get_operation() << std::endl;
  incrementIndent();
  node->get_operand()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(PostfixExpressionAST *node) {
  printIndent();
  std::cout << "PostfixExpressionAST: " << node->get_operation() << std::endl;
  incrementIndent();
  node->get_operand()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(SubscriptExpressionAST *node) {
  printIndent();
  std::cout << "SubscriptExpressionAST" << std::endl;
  incrementIndent();
  node->get_baseExpression()->accept(this);
  node->get_indexExpression()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(TernaryExpressionAST *node) {
  printIndent();
  std::cout << "TernaryExpressionAST" << std::endl;
  incrementIndent();
  node->get_condition()->accept(this);
  node->get_trueExpr()->accept(this);
  node->get_falseExpr()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(VariableExpressionAST *node) {
  printIndent();
  std::cout << "VariableExpressionAST: " << node->get_name() << std::endl;
}

void ASTPrinter::visit(ConstantExpressionAST *node) {
  printIndent();
  std::cout << "ConstantExpressionAST: " << node->get_value() << std::endl;
}

void ASTPrinter::visit(ExpressionStatementAST *node) {
  printIndent();
  std::cout << "ExpressionStatementAST" << std::endl;
  incrementIndent();
  node->get_expression()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(DeclarationStatementAST *node) {
  printIndent();
  std::cout << "DeclartionStatementAST" << std::endl;
  incrementIndent();
  node->get_declaration()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(CompoundStatementAST *node) {
  printIndent();
  std::cout << "CompoundStatementAST" << std::endl;
  incrementIndent();
  for (const auto &stmt : node->get_statements()) {
    stmt->accept(this);
  }
  decrementIndent();
}

void ASTPrinter::visit(SelectionStatementAST *node) {
  printIndent();
  std::cout << "SelectionStatementAST" << std::endl;
  incrementIndent();
  node->get_condition()->accept(this);
  node->get_body()->accept(this);
  if (node->get_else_body()) {
    node->get_else_body()->accept(this);
  }
  decrementIndent();
}

void ASTPrinter::visit(WhileStatementAST *node) {
  printIndent();
  std::cout << "WhileStatementAST" << std::endl;
  incrementIndent();
  node->get_condition()->accept(this);
  node->get_body()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(ForStatementAST *node) {
  printIndent();
  std::cout << "ForStatementAST" << std::endl;
  incrementIndent();
  node->get_start()->accept(this);
  node->get_end()->accept(this);
  node->get_step()->accept(this);
  node->get_body()->accept(this);
  decrementIndent();
}

void ASTPrinter::visit(JumpStatementAST *node) {
  printIndent();
  std::cout << "JumpStatementAST: " << node->get_jumpStamentKind() << std::endl;
  if (node->get_return_value()) {
    incrementIndent();
    node->get_return_value()->accept(this);
    decrementIndent();
  }
}

void ASTPrinter::visit(ProgramAST *node) {
  printIndent();
  std::cout << "ProgramAST" << std::endl;
  incrementIndent();
  for (const auto &func : node->get_function_definitions()) {
    func->accept(this);
  }
  for (const auto &global : node->get_global_declarations()) {
    global->accept(this);
  }
  decrementIndent();
}
