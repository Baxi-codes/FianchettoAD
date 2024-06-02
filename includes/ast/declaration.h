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

  std::string get_type() const { return type; }
  void set_type(const std::string &t) { type = t; }

  std::string get_name() const { return name; }
  void set_name(const std::string &n) { name = n; }

  ExpressionASTPtr get_initial_value() const { return initial_value; }
  void set_initial_value(ExpressionASTPtr value) { initial_value = value; }

  bool get_has_initial_value() const { return has_initial_value; }
  void set_has_initial_value(bool has_value) { has_initial_value = has_value; }

  void accept(ASTVisitor *v) override;
};

class FunctionDefinitionAST : public ASTNode {
  std::string return_type, name;
  StatementASTPtr body;

public:
  FunctionDefinitionAST(std::string type, std::string name,
                        StatementASTPtr body)
      : return_type(type), name(name), body(body) {}

  std::string get_return_type() const { return return_type; }
  void set_return_type(const std::string &type) { return_type = type; }

  std::string get_name() const { return name; }
  void set_name(const std::string &n) { name = n; }

  StatementASTPtr get_body() const { return body; }
  void set_body(StatementASTPtr b) { body = b; }

  void accept(ASTVisitor *v) override;
};

#endif // DECLARATION_H
