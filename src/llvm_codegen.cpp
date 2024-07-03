#include "llvm_codegen.h"

llvm::Value* LLVMCodegenVisitor::getLLVMValue(ExpressionASTPtr expr) {
  current_value = nullptr;
  expr->accept(this);
  return current_value;
}

void LLVMCodegenVisitor::visit(FunctionDefinitionAST *node) {
  std::string return_type = node->get_return_type(), name = node->get_name();
  std::vector<std::string> argument_types = node->get_argument_types(), argument_names = node->get_argument_names();
  StatementASTPtr body = node->get_body();
  // later...
}

void LLVMCodegenVisitor::visit(VariableExpressionAST *node) {
  llvm::Value *v = symbol_table.lookupSymbol(node->get_name());
  if (!v) {
    logError("Variable not declared in current scope");
    currentValue = nullptr;
    return;
  }
  currentValue = builder.CreateLoad(v, node->get_name().c_str());
}

void LLVMCodegenVisitor::visit(ConstantExpressionAST *node) {
	if (node->get_type() != "int") {
		logError("Only int type supported for now");
    current_value = nullptr;
    return;
	}
  llvm::Type *type = llvm::Type::getInt32Ty(context);
  currentValue = llvm::ConstantInt::get(type, std::stoi(node->get_value()));
}

void LLVMCodegenVisitor::visit(BinopExpressionAST *node) {
  std::string op = node->get_operation();

  if (op == "=") {
    std::shared_ptr<VariableExpressionAST> LHS = node->get_LHS();
    llvm::Value* value = getLLVMValue(node->get_RHS);
    symbol_table.addSymbol(LHS->get_name(), symbol_table.getType(LHS->get_name()), value);
    return;
  }

  llvm::Value *L = getLLVMValue(node->get_LHS());
  llvm::Value *R = getLLVMValue(node->get_RHS());

  if (!L || !R) {
    currentValue = nullptr;
    return;
  }
  if (op == "+") {
    currentValue = builder.CreateAdd(L, R, "addtmp");
  } else if (op == "-") {
    currentValue = builder.CreateSub(L, R, "subtmp");
  } else if (op == "*") {
    currentValue = builder.CreateMul(L, R, "multmp");
  } else if (op == "/") {
    currentValue = builder.CreateSDiv(L, R, "divtmp");
  } else {
    logError("Unknown binary operator");
    currentValue = nullptr;
  }
}