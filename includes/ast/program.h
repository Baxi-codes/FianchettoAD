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
  void accept(ASTVisitor *v) override;
};

#endif // PROGRAM_H