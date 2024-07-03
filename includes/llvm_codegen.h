#ifndef LLVM_CODEGEN_H
#define LLVM_CODEGEN_H

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>

#include "visitor.h"
#include "ast.h"
#include "symbol_table.h"

class LLVMCodegenVisitor : public ASTVisitor {
  llvm::LLVMContext context;
  std::unique_ptr<llvm::Module> module;
  llvm::IRBuilder<> builder;
  SymbolTable symbol_table;
  llvm::Value* current_value;

public:
  LLVMCodegenVisitor(const std::string &moduleName)
      : module(std::make_unique<llvm::Module>(moduleName, context)), builder(context) {}

  std::unique_ptr<llvm::Module> getModule() { return std::move(module); }

  // Override visit methods for different AST node types
  void visit(VariableDeclarationAST *node) override;
  void visit(FunctionDefinitionAST *node) override;
  void visit(BinopExpressionAST *node) override;
  void visit(PrefixExpressionAST *node) override;
  void visit(PostfixExpressionAST *node) override;
  void visit(FunctionCallAST *node) override;
  void visit(SubscriptExpressionAST *node) override;
  void visit(TernaryExpressionAST *node) override;
  void visit(VariableExpressionAST *node) override;
  void visit(ConstantExpressionAST *node) override;
  void visit(ProgramAST *node) override;
  void visit(ExpressionStatementAST *node) override;
  void visit(DeclarationStatementAST *node) override;
  void visit(CompoundStatementAST *node) override;
  void visit(SelectionStatementAST *node) override;
  void visit(WhileStatementAST *node) override;
  void visit(ForStatementAST *node) override;
  void visit(JumpStatementAST *node) override;

private:
  llvm::Value* logError(const std::string &msg) {
    std::cerr << "Error: " << msg << std::endl;
    return nullptr;
  }
  
  llvm::Value* getLLVMValue(ExpressionASTPtr expr);
};

#endif // LLVM_CODEGEN_H
