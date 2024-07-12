#include "utils/ast_printer.h"

void ASTPrinter::printIndent() {
  for (int i = 0; i < indentLevel; ++i) {
    std::cout << "  ";  // Print two spaces per indentation level
  }
}

void ASTPrinter::visit(VariableDeclarationAST *node) {
  printIndent();
  std::cout << "VariableDeclaration: " << node->get_name() << " ( type "
            << node->get_type() << " )\n";
  if (node->get_has_initial_value()) {
    printIndent();
    std::cout << " initial_value: \n";
    ++indentLevel;
    node->get_initial_value()->accept(this);
    --indentLevel;
  }
  printIndent();
  std::cout << " (is_global: " << (node->get_is_global_variable() ? "true" : "false") << ")\n";
}

void ASTPrinter::visit(FunctionDefinitionAST *node) {
  printIndent();
  std::cout << "FunctionDefinition: " << node->get_return_type() << " " << node->get_name() << "(";
  for (size_t i = 0; i < node->get_argument_names().size(); ++i) {
    std::cout << node->get_argument_types()[i] << " " << node->get_argument_names()[i];
    if (i < node->get_argument_names().size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << ")";
  if (node->get_body()) {
    std::cout << " {\n";
    ++indentLevel;
    node->get_body()->accept(this);
    --indentLevel;
    printIndent();
    std::cout << "}\n";
  }
}

void ASTPrinter::visit(BinopExpressionAST *node) {
  printIndent();
  std::cout << "BinopExpression: (" << node->get_operation() << ")\n";
  ++indentLevel;
  node->get_LHS()->accept(this);
  node->get_RHS()->accept(this);
  --indentLevel;
}

void ASTPrinter::visit(PrefixExpressionAST *node) {
  printIndent();
  std::cout << "PrefixExpression: (" << node->get_operation() << ")\n";
  ++indentLevel;
  node->get_operand()->accept(this);
  --indentLevel;
}

void ASTPrinter::visit(PostfixExpressionAST *node) {
  printIndent();
  std::cout << "PostfixExpression: (" << node->get_operation() << ")\n";
  ++indentLevel;
  node->get_operand()->accept(this);
  --indentLevel;
}

void ASTPrinter::visit(FunctionCallAST *node) {
  printIndent();
  std::cout << "FunctionCall:\n";
  ++indentLevel;
  node->get_functionName()->accept(this);
  printIndent();
  std::cout << "(\n";
  ++indentLevel;
  for (size_t i = 0; i < node->get_arguments().size(); ++i) {
    node->get_arguments()[i]->accept(this);
    if (i < node->get_arguments().size() - 1) {
      std::cout << ", \n";
    }
  }
  --indentLevel;
  printIndent();
  std::cout << ")\n";
  --indentLevel;
}

void ASTPrinter::visit(SubscriptExpressionAST *node) {
  printIndent();
  std::cout << "SubscriptExpression: \n";
  ++indentLevel;
  node->get_baseExpression()->accept(this);
  node->get_indexExpression()->accept(this);
  --indentLevel;
}

void ASTPrinter::visit(TernaryExpressionAST *node) {
  printIndent();
  std::cout << "TernaryExpression: \n";
  ++indentLevel;
  std::cout << "Condition: \n";
  node->get_condition()->accept(this);
  std::cout << "TrueExpr: \n";
  node->get_trueExpr()->accept(this);
  std::cout << "FalseExpr: \n";
  node->get_falseExpr()->accept(this);
  --indentLevel;
}

void ASTPrinter::visit(VariableExpressionAST *node) {
  printIndent();
  std::cout << "VariableExpression: " << node->get_name() << "\n";
}

void ASTPrinter::visit(ConstantExpressionAST *node) {
  printIndent();
  std::cout << "ConstantExpression: " << node->get_value() << " ( type "
            << node->get_type() << " )" << "\n";
}

void ASTPrinter::visit(DeclarationStatementAST *node) {
  printIndent();
  std::cout << "DeclarationStatement:\n";
  ++indentLevel;
  node->get_declaration()->accept(this);
  --indentLevel;
}

void ASTPrinter::visit(ExpressionStatementAST *node) {
  printIndent();
  std::cout << "ExpressionStatement:\n";
  ++indentLevel;
  node->get_expression()->accept(this);
  --indentLevel;
}

void ASTPrinter::visit(CompoundStatementAST *node) {
  printIndent();
  std::cout << "CompoundStatement: {\n";
  ++indentLevel;
  for (const auto &stmt : node->get_statements()) {
    stmt->accept(this);
  }
  --indentLevel;
  printIndent();
  std::cout << "}\n";
}

void ASTPrinter::visit(SelectionStatementAST *node) {
  printIndent();
  std::cout << "SelectionStatement (if):\n";
  ++indentLevel;
  printIndent();
  std::cout << "Condition:\n";
  node->get_condition()->accept(this);
  printIndent();
  std::cout << "Body:\n";
  node->get_body()->accept(this);
  if (node->get_else_body()) {
    printIndent();
    std::cout << "Else Body:\n";
    node->get_else_body()->accept(this);
  }
  --indentLevel;
}

void ASTPrinter::visit(WhileStatementAST *node) {
  printIndent();
  std::cout << "WhileStatement:\n";
  ++indentLevel;
  printIndent();
  std::cout << "Condition:\n";
  ++indentLevel;
  printIndent();
  node->get_condition()->accept(this);
  --indentLevel;
  printIndent();
  std::cout << "Body:\n";
  ++indentLevel;
  node->get_body()->accept(this);
  --indentLevel;
  --indentLevel;
}

void ASTPrinter::visit(ForStatementAST *node) {
  printIndent();
  std::cout << "ForStatement:\n";
  ++indentLevel;
  printIndent();
  std::cout << "Start:\n";
  node->get_start()->accept(this);
  printIndent();
  std::cout << "End:\n";
  ++indentLevel;
  node->get_end()->accept(this);
  --indentLevel;
  printIndent();
  std::cout << "Step:\n";
  ++indentLevel;
  node->get_step()->accept(this);
  --indentLevel;
  printIndent();
  std::cout << "Body:\n";
  ++indentLevel;
  node->get_body()->accept(this);
  --indentLevel;
  --indentLevel;
}

void ASTPrinter::visit(JumpStatementAST *node) {
  printIndent();
  std::cout << "JumpStatement (" << node->get_jump_stament_kind() << ")";
  if (node->get_jump_stament_kind() == "return" && node->get_return_value()) {
    std::cout << " with value:\n";
    ++indentLevel;
    node->get_return_value()->accept(this);
    --indentLevel;
  } else {
    std::cout << "\n";
  }
}

void ASTPrinter::visit(ProgramAST *node) {
  printIndent();
  std::cout << "Program:\n";
  ++indentLevel;
  printIndent();
  std::cout << "Global Declarations:\n";
  ++indentLevel;
  for (auto decl : node->get_global_declarations()) {
    decl->accept(this);
  }
  --indentLevel;
  printIndent();
  std::cout << "Function Definitions:\n";
  ++indentLevel;
  for (auto func : node->get_function_definitions()) {
    func->accept(this);
  }
  --indentLevel;
  --indentLevel;
}
