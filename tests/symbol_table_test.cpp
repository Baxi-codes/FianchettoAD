#include "symbol_table.h"
#include <iostream>
#include <llvm/IR/Constants.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>

int main() {
  // Initialize the LLVM context
  llvm::LLVMContext context;

  // Create a SymbolTable instance
  SymbolTable symTable;

  // Push a new scope
  symTable.pushScope();

  // Add some values to the symbol table
  llvm::Value *value1 =
      llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 42);
  symTable.addSymbol("x", value1);

  llvm::Value *value2 =
      llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 100);
  symTable.addSymbol("y", value2);

  // Print current scopes
  std::cout << "Current Scopes after adding x and y:" << std::endl;
  symTable.printScopes();

  // Lookup symbols
  llvm::Value *lookupX = symTable.lookupSymbol("x");
  std::cout << "Lookup x: " << lookupX << " (expected: " << value1 << ")"
            << std::endl;

  llvm::Value *lookupY = symTable.lookupSymbol("y");
  std::cout << "Lookup y: " << lookupY << " (expected: " << value2 << ")"
            << std::endl;

  // Push another scope and add a symbol
  symTable.pushScope();
  llvm::Value *value3 =
      llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 200);
  symTable.addSymbol("z", value3);

  std::cout << "\nCurrent Scopes after adding z in a new scope:" << std::endl;
  symTable.printScopes();

  // Lookup symbols in the new scope
  llvm::Value *lookupZ = symTable.lookupSymbol("z");
  std::cout << "Lookup z: " << lookupZ << " (expected: " << value3 << ")"
            << std::endl;

  // Lookup existing symbols in the outer scope
  lookupX = symTable.lookupSymbol("x");
  std::cout << "Lookup x: " << lookupX << " (expected: " << value1 << ")"
            << std::endl;

  // Pop the innermost scope
  symTable.popScope();
  std::cout << "\nCurrent Scopes after popping the last scope:" << std::endl;
  symTable.printScopes();

  // Lookup symbols after popping scope
  lookupZ = symTable.lookupSymbol("z");
  std::cout << "Lookup z after popping scope: " << lookupZ
            << " (expected: nullptr)" << std::endl;

  lookupX = symTable.lookupSymbol("x");
  std::cout << "Lookup x: " << lookupX << " (expected: " << value1 << ")"
            << std::endl;

  return 0;
}
