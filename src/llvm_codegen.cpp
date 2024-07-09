#include "llvm_codegen.h"

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/Casting.h>
#include <llvm/Transforms/Utils.h>

llvm::Value *LLVMCodegenVisitor::getLLVMValue(ExpressionASTPtr expr) {
  current_value = nullptr;
  expr->accept(this);
  return current_value;
}

llvm::Type *LLVMCodegenVisitor::getLLVMType(const std::string &typeName) {
  if (typeName == "int") {
    return llvm::Type::getInt32Ty(*context);
  } else if (typeName == "float") {
    return llvm::Type::getFloatTy(*context);
  } else if (typeName == "string") {
    logError("Yet to support string type");
    return nullptr;
  } else {
    logError("Unknown type: " + typeName);
    return nullptr;
  }
}

void LLVMCodegenVisitor::visit(VariableDeclarationAST *node) {
  llvm::Type *type = getLLVMType(node->get_type());
  if (!type)
    return;
  llvm::Value *var;
  if (node->get_is_global_variable()) {
    if (!node->get_initial_value()) {
      logError("Initial value required in global variables");
      return;
    }
    if (!std::dynamic_pointer_cast<ConstantExpressionAST>(
            node->get_initial_value())) {
      logError("Initial value of global variables must be a constant");
    }
    llvm::GlobalVariable *GlobalVar = new llvm::GlobalVariable(
        *module, type,
        /* isConstant */ false, llvm::GlobalValue::PrivateLinkage,
        llvm::dyn_cast<llvm::Constant>(getLLVMValue(node->get_initial_value())),
        node->get_name());
    symbol_table.addSymbol(node->get_name(), node->get_type(), GlobalVar);
  } else {
    return;
  }
}

void LLVMCodegenVisitor::visit(FunctionDefinitionAST *node) {
  llvm::Type *returnType = getLLVMType(node->get_return_type());
  if (!returnType)
    return;

  std::vector<llvm::Type *> argTypes;
  for (const auto &argType : node->get_argument_types()) {
    llvm::Type *llvmArgType = getLLVMType(argType);
    if (!llvmArgType)
      return;
    argTypes.push_back(llvmArgType);
  }

  symbol_table.pushScope();

  llvm::FunctionType *funcType =
      llvm::FunctionType::get(returnType, argTypes, false);
  llvm::Function *function =
      llvm::Function::Create(funcType, llvm::Function::ExternalLinkage,
                             node->get_name(), module.get());

  llvm::BasicBlock *BB = llvm::BasicBlock::Create(*context, "entry", function);
  builder->SetInsertPoint(BB);

  unsigned idx = 0;
  for (auto &arg : function->args()) {
    symbol_table.addSymbol(node->get_argument_names()[idx],
                           node->get_argument_types()[idx], arg);
    idx++;
  }

  node->get_body()->accept(this);
  symbol_table.popScope();

  llvm::verifyFunction(*function);
}

void LLVMCodegenVisitor::visit(BinopExpressionAST *node) {}
void LLVMCodegenVisitor::visit(PrefixExpressionAST *node) {}
void LLVMCodegenVisitor::visit(PostfixExpressionAST *node) {}
void LLVMCodegenVisitor::visit(FunctionCallAST *node) {}
void LLVMCodegenVisitor::visit(SubscriptExpressionAST *node) {}
void LLVMCodegenVisitor::visit(TernaryExpressionAST *node) {}
void LLVMCodegenVisitor::visit(VariableExpressionAST *node) {}
void LLVMCodegenVisitor::visit(ConstantExpressionAST *node) {}
void LLVMCodegenVisitor::visit(ProgramAST *node) {}

void LLVMCodegenVisitor::visit(ExpressionStatementAST *node) {
  getLLVMValue(node->get_expression());
}

void LLVMCodegenVisitor::visit(DeclarationStatementAST *node) {
  node->get_declaration()->accept(this);
}

void LLVMCodegenVisitor::visit(CompoundStatementAST *node) {
  for (auto statement : node->get_statements()) {
    statement->accept(this);
  }
}

void LLVMCodegenVisitor::visit(SelectionStatementAST *node) {}
void LLVMCodegenVisitor::visit(WhileStatementAST *node) {}
void LLVMCodegenVisitor::visit(ForStatementAST *node) {}

void LLVMCodegenVisitor::visit(JumpStatementAST *node) {
  if (node->get_jump_stament_kind() == "return") {
    if (node->get_return_value()) {
      llvm::Value *retVal = getLLVMValue(node->get_return_value());
      if (retVal)
        builder->CreateRet(retVal);
    } else {
      builder->CreateRetVoid();
    }
  } else if (node->get_jump_stament_kind() == "break") {
    // Handle break logic
  } else if (node->get_jump_stament_kind() == "continue") {
    // Handle continue logic
  } else {
    logError("Unknown jump statement kind");
  }
}