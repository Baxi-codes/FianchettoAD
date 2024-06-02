#ifndef PROGRAM_H
#define PROGRAM_H

#include <memory>
#include <vector>

#include "ast/declaration.h"

class ProgramAST : public ASTNode {
  std::vector<std::shared_ptr<FunctionDefinitionAST>> function_definitions;
  std::vector<std::shared_ptr<VariableDeclarationAST>> global_declarations;

public:
  ProgramAST(
      std::vector<std::shared_ptr<FunctionDefinitionAST>> functions,
      std::vector<std::shared_ptr<VariableDeclarationAST>> global_declarations)
      : function_definitions(functions),
        global_declarations(global_declarations) {}

  std::vector<std::shared_ptr<FunctionDefinitionAST>> get_function_definitions() const { 
      return function_definitions; 
  }
  
  void set_function_definitions(const std::vector<std::shared_ptr<FunctionDefinitionAST>> &functions) { 
      function_definitions = functions; 
  }

  std::vector<std::shared_ptr<VariableDeclarationAST>> get_global_declarations() const { 
      return global_declarations; 
  }

  void set_global_declarations(const std::vector<std::shared_ptr<VariableDeclarationAST>> &declarations) { 
      global_declarations = declarations; 
  }

  void accept(ASTVisitor *v) override;
};

#endif // PROGRAM_H
