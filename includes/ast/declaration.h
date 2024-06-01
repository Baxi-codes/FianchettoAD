#ifndef DECLARATION_H
#define DECLARATION_H

#include <cassert>
#include <memory>
#include <vector>

#include "ast/astnode.h"
#include "ast/expression.h"

class ASTNode;
class StatementAST;
class ExpressionAST;

using ASTNodePtr = std::shared_ptr<ASTNode>;
using StatementASTPtr = std::shared_ptr<StatementAST>;
using ExpressionASTPtr = std::shared_ptr<ExpressionAST>;

class VariableDeclarationAST : public ASTNode {
  std::string type, name;
  ExpressionASTPtr initial_value;
  bool has_initial_value;

public:
  VariableDeclarationAST(std::string type, std::string name)
      : type(type), name(name), initial_value(nullptr), has_initial_value(0) {}
  VariableDeclarationAST(std::string type, std::string name,
                         ExpressionASTPtr initial_value)
      : type(type), name(name), initial_value(initial_value),
        has_initial_value(1) {}
};

class FunctionDefinitionAST : public ASTNode {
  std::string return_type, name;
  StatementASTPtr body;

public:
  FunctionDefinitionAST(std::string type, std::string name,
                        StatementASTPtr body)
      : return_type(type), name(name), body(body) {}
};

#endif // DECLARATION_H
