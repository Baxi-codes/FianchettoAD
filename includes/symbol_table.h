#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <iostream>
#include <llvm/IR/Value.h>
#include <optional>
#include <stack>
#include <string>
#include <unordered_map>

class SymbolTable {
public:
  using Scope = std::unordered_map<std::string, llvm::Value *>;
  void pushScope();
  void popScope();
  void addSymbol(const std::string &name, const std::string &type, llvm::Value *value);
  llvm::Value *lookupSymbol(const std::string &name);
  std::string getType(const std::string &name);
  void printScopes();

private:
  std::unordered_map<std::sting, std::string> types;
  std::stack<Scope> scopes;
};

#endif // SYMBOL_TABLE_H
