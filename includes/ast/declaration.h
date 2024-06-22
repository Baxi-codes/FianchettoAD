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
  bool has_initial_value, is_global_variable;

public:
  VariableDeclarationAST(std::string type, std::string name,
                         bool has_initial_value, bool is_global_variable, ExpressionASTPtr initial_value)
      : type(type), name(name), initial_value(initial_value),
        has_initial_value(has_initial_value),
        is_global_variable(is_global_variable) {}

  std::string get_type() const { return type; }
  void set_type(const std::string &t) { type = t; }

  std::string get_name() const { return name; }
  void set_name(const std::string &n) { name = n; }

  ExpressionASTPtr get_initial_value() const { return initial_value; }
  void set_initial_value(ExpressionASTPtr value) { initial_value = value; }

  bool get_has_initial_value() const { return has_initial_value; }
  void set_has_initial_value(bool has_value) { has_initial_value = has_value; }

  bool get_is_global_variable() const { return is_global_variable; }
  void set_is_global_variable(bool is_global) {
    is_global_variable = is_global;
  }

  void accept(ASTVisitor *v) override;
};

class FunctionDefinitionAST : public ASTNode {
  std::string return_type, name;
  std::vector<std::string> argument_types, argument_names;
  StatementASTPtr body;
  bool differentiable;

public:
  FunctionDefinitionAST(std::string type, std::string name,
                        std::vector<std::string> argument_types,
                        std::vector<std::string> argument_names,
                        StatementASTPtr body, bool differentiable)
      : return_type(type), name(name), body(body),
        differentiable(differentiable), argument_types(argument_types),
        argument_names(argument_names) {}

  std::string get_return_type() const { return return_type; }
  void set_return_type(const std::string &type) { return_type = type; }

  std::string get_name() const { return name; }
  void set_name(const std::string &n) { name = n; }

  std::vector<std::string> get_argument_types() const { return argument_types; }
  void set_argument_types(std::vector<std::string> types) { argument_types = types; }

  std::vector<std::string> get_argument_names() const { return argument_names; }
  void set_argument_names(std::vector<std::string> names) { argument_names = names; }

  StatementASTPtr get_body() const { return body; }
  void set_body(StatementASTPtr b) { body = b; }

  void accept(ASTVisitor *v) override;
};

#endif // DECLARATION_H
