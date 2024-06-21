#include "ast.h"
#include "visitor.h"

// Implementations of accept methods for each AST node type

// Declarations
void VariableDeclarationAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void FunctionDefinitionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

// Expressions
void BinopExpressionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void PrefixExpressionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void PostfixExpressionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void SubscriptExpressionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void FunctionCallAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void TernaryExpressionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void VariableExpressionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void ConstantExpressionAST::accept(ASTVisitor *v) {
    v->visit(this);
}

// Statements
void ExpressionStatementAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void DeclarationStatementAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void CompoundStatementAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void SelectionStatementAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void WhileStatementAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void ForStatementAST::accept(ASTVisitor *v) {
    v->visit(this);
}

void JumpStatementAST::accept(ASTVisitor *v) {
    v->visit(this);
}

// Program
void ProgramAST::accept(ASTVisitor *v) {
    v->visit(this);
}
