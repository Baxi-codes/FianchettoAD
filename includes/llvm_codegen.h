#ifndef LLVM_CODEGEN_H
#define LLVM_CODEGEN_H

#include <iostream>
#include <optional>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/TargetParser/Triple.h>
#include <llvm/TargetParser/Host.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>

#include "ast.h"
#include "symbol_table.h"
#include "visitor.h"

class LLVMCodegenVisitor : public ASTVisitor {
  std::shared_ptr<llvm::LLVMContext> context;
  std::shared_ptr<llvm::Module> module;
  std::shared_ptr<llvm::IRBuilder<>> builder;
  SymbolTable symbol_table;
  llvm::Value *current_value;

public:
  LLVMCodegenVisitor(const std::string &moduleName) {
    context = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>(moduleName, *context);
    builder = std::make_unique<llvm::IRBuilder<>>(*context);
  }

  std::shared_ptr<llvm::Module> get_module() { return module; }

  void print_ir();
  void objgen(const std::string &filename, const std::string &target) {
    // Initialize the target registry etc.
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string targetTriple;
    if (target == "native") {
        targetTriple = llvm::sys::getDefaultTargetTriple();
    } else if (target == "wasm") {
        targetTriple = "wasm32-unknown-unknown-wasm";
    } else {
        llvm::errs() << "Unsupported target: " << target << "\n";
        return;
    }
    
    module->setTargetTriple(targetTriple);

    std::string error;
    auto Target = llvm::TargetRegistry::lookupTarget(targetTriple, error);

    if (!Target) {
        llvm::errs() << error;
        return;
    }

    auto CPU = "generic";
    auto features = "";

    llvm::TargetOptions opt;
    auto RM = std::optional<llvm::Reloc::Model>();
    auto theTargetMachine = Target->createTargetMachine(targetTriple, CPU, features, opt, RM);

    module->setDataLayout(theTargetMachine->createDataLayout());
    module->setTargetTriple(targetTriple);

    std::error_code EC;
    llvm::raw_fd_ostream dest(filename.c_str(), EC, llvm::sys::fs::OF_None);

    llvm::legacy::PassManager pass;
    auto fileType = llvm::CodeGenFileType::ObjectFile;

    if (theTargetMachine->addPassesToEmitFile(pass, dest, nullptr, fileType)) {
        llvm::errs() << "theTargetMachine can't emit a file of this type";
        return;
    }

    pass.run(*module.get());
    dest.flush();

    llvm::outs() << "Object code written to " << filename.c_str() << "\n";
  }

  std::shared_ptr<llvm::Module> getModule() { return std::move(module); }

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
  llvm::Value *logError(const std::string &msg) {
    std::cerr << "Error: " << msg << std::endl;
    return nullptr;
  }

  llvm::Type *getLLVMType(const std::string &typeName);
  llvm::Value *getLLVMValue(ExpressionASTPtr expr);
};

#endif // LLVM_CODEGEN_H
