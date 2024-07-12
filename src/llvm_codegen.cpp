#include "llvm_codegen.h"

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/Casting.h>
#include <llvm/Support/raw_ostream.h>
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
    llvm::AllocaInst *alloca =
        builder->CreateAlloca(type, nullptr, node->get_name());
    if (node->get_initial_value()) {
      llvm::Value *initialValue = getLLVMValue(node->get_initial_value());
      builder->CreateStore(initialValue, alloca);
    }
    symbol_table.addSymbol(node->get_name(), node->get_type(), alloca);
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
                           node->get_argument_types()[idx], &arg);
    idx++;
  }

  node->get_body()->accept(this);
  symbol_table.popScope();

  llvm::verifyFunction(*function);
}

void LLVMCodegenVisitor::visit(BinopExpressionAST *node) {
  llvm::Value *left = getLLVMValue(node->get_LHS());
  llvm::Value *right = getLLVMValue(node->get_RHS());

  if (!left || !right)
    return;

  current_value = nullptr;
  std::string op = node->get_operation();

  std::string type = "int";

  bool has_float_type =
      (left->getType()->isFloatTy() || right->getType()->isFloatTy());

  if (has_float_type) {
    type = "float";
    if (left->getType()->isIntegerTy()) {
      left = builder->CreateSIToFP(left, llvm::Type::getFloatTy(*context),
                                   "int_to_float_lhs");
    }
    if (right->getType()->isIntegerTy()) {
      right = builder->CreateSIToFP(right, llvm::Type::getFloatTy(*context),
                                    "int_to_float_lhs");
    }
  }

  if (type == "int") {
    if (op == "+") {
      current_value = builder->CreateAdd(left, right, "addtmp");
    } else if (op == "-") {
      current_value = builder->CreateSub(left, right, "subtmp");
    } else if (op == "*") {
      current_value = builder->CreateMul(left, right, "multmp");
    } else if (op == "/") {
      current_value = builder->CreateSDiv(left, right, "divtmp");
    } else if (op == "%") {
      current_value = builder->CreateSRem(left, right, "remtmp");
    } else if (op == "&") {
      current_value = builder->CreateAnd(left, right, "andtmp");
    } else if (op == "|") {
      current_value = builder->CreateOr(left, right, "ortmp");
    } else if (op == "==") {
      llvm::Value *cmp = builder->CreateICmpEQ(left, right, "eqtmp");
      current_value = builder->CreateZExt(cmp, left->getType(), "exttmp");
    } else if (op == "!=") {
      llvm::Value *cmp = builder->CreateICmpNE(left, right, "netmp");
      current_value = builder->CreateZExt(cmp, left->getType(), "exttmp");
    } else if (op == "<") {
      llvm::Value *cmp = builder->CreateICmpSLT(left, right, "lttmp");
      current_value = builder->CreateZExt(cmp, left->getType(), "exttmp");
    } else if (op == "<=") {
      llvm::Value *cmp = builder->CreateICmpSLE(left, right, "letmp");
      current_value = builder->CreateZExt(cmp, left->getType(), "exttmp");
    } else if (op == ">") {
      llvm::Value *cmp = builder->CreateICmpSGT(left, right, "gttmp");
      current_value = builder->CreateZExt(cmp, left->getType(), "exttmp");
    } else if (op == ">=") {
      llvm::Value *cmp = builder->CreateICmpSGE(left, right, "getmp");
      current_value = builder->CreateZExt(cmp, left->getType(), "exttmp");
    } else {
      logError("Unsupported binary operation '" + op + "'");
      return;
    }
  } else if (type == "float") {
    if (op == "+") {
      current_value = builder->CreateFAdd(left, right, "addtmp");
    } else if (op == "-") {
      current_value = builder->CreateFSub(left, right, "subtmp");
    } else if (op == "*") {
      current_value = builder->CreateFMul(left, right, "multmp");
    } else if (op == "/") {
      current_value = builder->CreateFDiv(left, right, "divtmp");
    } else if (op == "==") {
      llvm::Value *cmp = builder->CreateFCmpOEQ(left, right, "eqtmp");
      current_value = builder->CreateZExt(
          cmp, llvm::Type::getInt32Ty(left->getContext()), "exttmp");
    } else if (op == "!=") {
      llvm::Value *cmp = builder->CreateFCmpONE(left, right, "netmp");
      current_value = builder->CreateZExt(
          cmp, llvm::Type::getInt32Ty(left->getContext()), "exttmp");
    } else if (op == "<") {
      llvm::Value *cmp = builder->CreateFCmpOLT(left, right, "lttmp");
      current_value = builder->CreateZExt(
          cmp, llvm::Type::getInt32Ty(left->getContext()), "exttmp");
    } else if (op == "<=") {
      llvm::Value *cmp = builder->CreateFCmpOLE(left, right, "letmp");
      current_value = builder->CreateZExt(
          cmp, llvm::Type::getInt32Ty(left->getContext()), "exttmp");
    } else if (op == ">") {
      llvm::Value *cmp = builder->CreateFCmpOGT(left, right, "gttmp");
      current_value = builder->CreateZExt(
          cmp, llvm::Type::getInt32Ty(left->getContext()), "exttmp");
    } else if (op == ">=") {
      llvm::Value *cmp = builder->CreateFCmpOGE(left, right, "getmp");
      current_value = builder->CreateZExt(
          cmp, llvm::Type::getInt32Ty(left->getContext()), "exttmp");
    } else {
      logError("Unsupported binary operation '" + op + "'");
      return;
    }
  }
}

void LLVMCodegenVisitor::visit(PrefixExpressionAST *node) {
  llvm::Value *operand = getLLVMValue(node->get_operand());
  std::string op = node->get_operation();

  current_value = nullptr;
  if (op == "!") {
    // Logical NOT
    if (operand->getType()->isIntegerTy()) {
      current_value = builder->CreateICmpEQ(
          operand, llvm::ConstantInt::get(operand->getType(), 0), "nottmp");
    } else if (operand->getType()->isFloatingPointTy()) {
      current_value = builder->CreateFCmpUEQ(
          operand, llvm::ConstantFP::get(operand->getType(), 0.0), "nottmp");
    }
    current_value = builder->CreateZExt(
        current_value, llvm::Type::getInt32Ty(*context), "not_ext");
  } else if (op == "-") {
    // Negation
    if (operand->getType()->isIntegerTy()) {
      current_value = builder->CreateNeg(operand, "negtmp");
    } else if (operand->getType()->isFloatingPointTy()) {
      current_value = builder->CreateFNeg(operand, "negtmp");
    }
  } else {
    logError("Unsupported prefix operation '" + node->get_operation() + "'");
    return;
  }
}

void LLVMCodegenVisitor::visit(PostfixExpressionAST *node) {
  logError("Unsupported postfix operator '" + node->get_operation() + "'");
}

void LLVMCodegenVisitor::visit(FunctionCallAST *node) {
  std::string function_name =
      std::dynamic_pointer_cast<VariableExpressionAST>(node->get_functionName())
          ->get_name();
  llvm::Function *callee = module->getFunction(function_name);
  if (!callee) {
    logError("Function not found: " + function_name);
  }
  std::vector<llvm::Value *> args_values;
  for (auto arg : node->get_arguments()) {
    args_values.push_back(getLLVMValue(arg));
    if (!args_values.back())
      logError("Some error computing arguments of function " + function_name);
  }
  current_value = builder->CreateCall(callee, args_values, "calltmp");
}

void LLVMCodegenVisitor::visit(SubscriptExpressionAST *node) {
  logError("Didn't implement subscript codegen");
}

void LLVMCodegenVisitor::visit(TernaryExpressionAST *node) {
  logError("Didn't implement ternary codegen");
}

void LLVMCodegenVisitor::visit(VariableExpressionAST *node) {
  std::string name = node->get_name();
  current_value =
      builder->CreateLoad(getLLVMType(symbol_table.getType(name)),
                          symbol_table.lookupSymbol(name), "loadtmp");
}

void LLVMCodegenVisitor::visit(ConstantExpressionAST *node) {
  llvm::Value *value = nullptr;
  std::string valStr = node->get_value();

  if (node->get_type() == "int") {
    int intValue = std::stoi(valStr); // Convert the string to an integer
    value = llvm::ConstantInt::get(*context, llvm::APInt(32, intValue, true));
  } else if (node->get_type() == "float") {
    float floatValue = std::stof(valStr); // Convert the string to a float
    value = llvm::ConstantFP::get(*context, llvm::APFloat(floatValue));
  } else {
    logError("Unsupported constant type");
    return;
  }
  if (value) {
    current_value = value;
  }
}

void LLVMCodegenVisitor::visit(ProgramAST *node) {
  symbol_table.pushScope();
  for (auto declaration : node->get_global_declarations()) {
    declaration->accept(this);
  }
  for (auto function : node->get_function_definitions()) {
    function->accept(this);
  }
  symbol_table.popScope();
}

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

void LLVMCodegenVisitor::visit(SelectionStatementAST *node) {
  llvm::Value *condValue = getLLVMValue(node->get_condition());
  if (!condValue) {
    logError("Failed to generate code for condition");
    return;
  }
  llvm::Function *function = builder->GetInsertBlock()->getParent();
  // Create basic blocks for the then and else cases
  llvm::BasicBlock *thenBB =
      llvm::BasicBlock::Create(*context, "then", function);
  llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(*context, "else");
  llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(*context, "ifcont");

  // Convert the condition to a boolean value (i1)
  llvm::Value *condBool = builder->CreateICmpNE(
      condValue, llvm::ConstantInt::get(condValue->getType(), 0), "ifcond");

  // Create the conditional branch
  builder->CreateCondBr(condBool, thenBB, elseBB);

  // Emit then block
  builder->SetInsertPoint(thenBB);
  node->get_body()->accept(this);
  builder->CreateBr(mergeBB);

  // Emit else block
  function->insert(function->end(), elseBB);
  builder->SetInsertPoint(elseBB);
  if (node->get_else_body()) {
    node->get_else_body()->accept(this);
  }
  builder->CreateBr(mergeBB);
  elseBB = builder->GetInsertBlock();

  // Emit merge block
  function->insert(function->end(), mergeBB);
  builder->SetInsertPoint(mergeBB);
  // printf("Ok\n");
}

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

void LLVMCodegenVisitor::print_ir() { module->print(llvm::errs(), nullptr); }