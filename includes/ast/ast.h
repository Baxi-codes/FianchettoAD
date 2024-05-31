#ifndef AST_H
#define AST_H

#include <cassert>
#include <memory>
#include <vector>

#include "lexer.h"

class ASTNode;

class ASTVisitor {
public:
  virtual ~ASTVisitor() = default;
};

class ASTNode {
public:
  virtual ~ASTNode() = default;
  Location loc;
  virtual void accept(ASTVisitor *v) = 0;
};

class ProgramAST : public ASTNode {
  std::vector<ASTNodePtr> function_definitions;
  std::vector<ASTNodePtr> global_declarations;

public:
  ProgramAST(std::vector<ASTNodePtr> functions,
             std::vector<ASTNodePtr> global_declarations)
      : function_definitions(functions),
        global_declarations(global_declarations) {}
  void accept(ASTVisitor *v) override;
};

#endif // AST_H