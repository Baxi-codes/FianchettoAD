#ifndef AST_H
#define AST_H

#include <vector>

class ASTNode;
class ExpressionAST;

using ASTNodePtr = std::shared_ptr<ASTNode>;
using ExpressionASTPtr = std::shared_ptr<ExpressionAST>;

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
      : functions(functions), global_declarations(global_declarations) {}
  void accept(ASTVisitor *v) override;
}

class ExpressionStatementAST : public ASTNode {
  ExpressionASTPtr expression;
  public:
  WhileStatementAST(ExpressionASTPtr expression)
      : expression(expression) {}
  void accept(ASTVisitor *v) override;
}

class CompoundStatementAST : public ASTNode {
  std::vector<ASTNodePtr> statements;

public:
  CompoundStatementAST(std::vector<ASTNodePtr> statements)
      : statements(statements) {}
  void accept(ASTVisitor *v) override;
}

class SelectionStatementAST : public ASTNode {
  ExpressionASTPtr condition;
  ASTNodePtr body, else_body;

public:
  SelectionStatementAST(ExpressionASTPtr condition, ASTNodePtr body)
      : condition(condition), body(body) {}
  SelectionStatementAST(ExpressionASTPtr condition, ASTNodePtr body,
                        ASTNodePtr else_body)
      : condition(condition), body(body), else_body(else_body) {}
  void accept(ASTVisitor *v) override;
}

class WhileStatementAST : public ASTNode {
  ExpressionASTPtr condition;
  ASTNodePtr body;

public:
  WhileStatementAST(ExpressionASTPtr condition, ASTNodePtr body)
      : condition(condition), body(body) {}
  void accept(ASTVisitor *v) override;
}

class WhileStatementAST : public ASTNode {
  ExpressionASTPtr condition;
  ASTNodePtr body;

public:
  WhileStatementAST(ExpressionASTPtr condition, ASTNodePtr body)
      : condition(condition), body(body) {}
  void accept(ASTVisitor *v) override;
}

#endif // AST_H