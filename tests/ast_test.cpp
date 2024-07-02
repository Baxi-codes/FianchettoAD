#include "ast.h"
#include "utils/ast_printer.h"
#include <memory>

class ASTNode;
class StatementAST;
class ExpressionAST;
class DeclarationAST;

using ASTNodePtr = std::shared_ptr<ASTNode>;
using StatementASTPtr = std::shared_ptr<StatementAST>;
using ExpressionASTPtr = std::shared_ptr<ExpressionAST>;
using DeclarationASTPtr = std::shared_ptr<DeclarationAST>;

int main() {
    // Create some example AST nodes
    ExpressionASTPtr varExpr = std::make_shared<VariableExpressionAST>("x");
    ExpressionASTPtr constExpr = std::make_shared<ConstantExpressionAST>("42");
    ExpressionASTPtr binopExpr = std::make_shared<BinopExpressionAST>("+", varExpr, constExpr);
    StatementASTPtr exprStmt = std::make_shared<ExpressionStatementAST>(binopExpr);
    StatementASTPtr ret = std::make_shared<JumpStatementAST>("return", constExpr);
    
    std::vector<StatementASTPtr> statements;
    statements.push_back(exprStmt);
    statements.push_back(ret);
    auto compStmt = std::make_shared<CompoundStatementAST>(statements);

    auto funcDef = std::make_shared<FunctionDefinitionAST>("void", "main", compStmt);

    std::vector<std::shared_ptr<FunctionDefinitionAST>> functions;
    functions.push_back(funcDef);
    std::vector<std::shared_ptr<VariableDeclarationAST>> globals;
    
    auto program = std::make_shared<ProgramAST>(functions, globals);
    
    // Create an ASTPrinter and use it to print the AST
    ASTPrinter printer;
    program->accept(&printer);

    return 0;
}
