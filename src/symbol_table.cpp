#include "symbol_table.h"

// Push a new scope onto the stack
void SymbolTable::pushScope() { scopes.emplace(); }

// Pop the current scope from the stack
void SymbolTable::popScope() {
  if (!scopes.empty()) {
    scopes.pop();
  } else {
    std::cerr << "Error: No scope to pop!" << std::endl;
  }
}

// Add a symbol to the current scope
void SymbolTable::addSymbol(const std::string &name, const std::string &type,
                            llvm::Value *value) {
  if (scopes.empty()) {
    std::cerr << "Error: No active scope to add a symbol!" << std::endl;
    return;
  }
  scopes.top()[name] = value;
  types[name] = type;
}

// Lookup a symbol, starting from the innermost scope to the outermost
llvm::Value *SymbolTable::lookupSymbol(const std::string &name) {
  std::stack<Scope> temp = scopes;
  while (!temp.empty()) {
    auto &currentScope = temp.top();
    auto it = currentScope.find(name);
    if (it != currentScope.end()) {
      return it->second; // Found the symbol
    }
    temp.pop();
  }
  return nullptr; // Symbol not found
}

std::string SymbolTable::getType(const std::string &name) {
  return types[name];
}

// Optional: Helper function to print the current scopes for debugging
void SymbolTable::printScopes() {
  std::stack<Scope> temp = scopes;
  int scopeLevel = 0;
  while (!temp.empty()) {
    std::cout << "Scope Level " << scopeLevel << ":\n";
    for (const auto &pair : temp.top()) {
      std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }
    temp.pop();
    scopeLevel++;
  }
}
