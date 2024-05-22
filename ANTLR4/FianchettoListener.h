
// Generated from Fianchetto.g4 by ANTLR 4.10.1

#pragma once

#include "FianchettoParser.h"
#include "antlr4-runtime.h"

/**
 * This interface defines an abstract listener for a parse tree produced by
 * FianchettoParser.
 */
class FianchettoListener : public antlr4::tree::ParseTreeListener {
public:
  virtual void enterProgram(FianchettoParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(FianchettoParser::ProgramContext *ctx) = 0;

  virtual void
  enterFunctionDefinition(FianchettoParser::FunctionDefinitionContext *ctx) = 0;
  virtual void
  exitFunctionDefinition(FianchettoParser::FunctionDefinitionContext *ctx) = 0;

  virtual void
  enterGlobalDeclaration(FianchettoParser::GlobalDeclarationContext *ctx) = 0;
  virtual void
  exitGlobalDeclaration(FianchettoParser::GlobalDeclarationContext *ctx) = 0;

  virtual void
  enterParameterList(FianchettoParser::ParameterListContext *ctx) = 0;
  virtual void
  exitParameterList(FianchettoParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(FianchettoParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(FianchettoParser::ParameterContext *ctx) = 0;

  virtual void
  enterTypeSpecifier(FianchettoParser::TypeSpecifierContext *ctx) = 0;
  virtual void
  exitTypeSpecifier(FianchettoParser::TypeSpecifierContext *ctx) = 0;

  virtual void enterStatement(FianchettoParser::StatementContext *ctx) = 0;
  virtual void exitStatement(FianchettoParser::StatementContext *ctx) = 0;

  virtual void enterExpressionStatement(
      FianchettoParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(
      FianchettoParser::ExpressionStatementContext *ctx) = 0;

  virtual void
  enterCompoundStatement(FianchettoParser::CompoundStatementContext *ctx) = 0;
  virtual void
  exitCompoundStatement(FianchettoParser::CompoundStatementContext *ctx) = 0;

  virtual void
  enterSelectionStatement(FianchettoParser::SelectionStatementContext *ctx) = 0;
  virtual void
  exitSelectionStatement(FianchettoParser::SelectionStatementContext *ctx) = 0;

  virtual void
  enterIterationStatement(FianchettoParser::IterationStatementContext *ctx) = 0;
  virtual void
  exitIterationStatement(FianchettoParser::IterationStatementContext *ctx) = 0;

  virtual void
  enterJumpStatement(FianchettoParser::JumpStatementContext *ctx) = 0;
  virtual void
  exitJumpStatement(FianchettoParser::JumpStatementContext *ctx) = 0;

  virtual void enterDeclaration(FianchettoParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(FianchettoParser::DeclarationContext *ctx) = 0;

  virtual void enterExpression(FianchettoParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(FianchettoParser::ExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(
      FianchettoParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(
      FianchettoParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterConditionalExpression(
      FianchettoParser::ConditionalExpressionContext *ctx) = 0;
  virtual void exitConditionalExpression(
      FianchettoParser::ConditionalExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(
      FianchettoParser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(
      FianchettoParser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(
      FianchettoParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(
      FianchettoParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void
  enterEqualityExpression(FianchettoParser::EqualityExpressionContext *ctx) = 0;
  virtual void
  exitEqualityExpression(FianchettoParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(
      FianchettoParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(
      FianchettoParser::RelationalExpressionContext *ctx) = 0;

  virtual void
  enterAdditiveExpression(FianchettoParser::AdditiveExpressionContext *ctx) = 0;
  virtual void
  exitAdditiveExpression(FianchettoParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(
      FianchettoParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(
      FianchettoParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void
  enterUnaryExpression(FianchettoParser::UnaryExpressionContext *ctx) = 0;
  virtual void
  exitUnaryExpression(FianchettoParser::UnaryExpressionContext *ctx) = 0;

  virtual void
  enterPostfixExpression(FianchettoParser::PostfixExpressionContext *ctx) = 0;
  virtual void
  exitPostfixExpression(FianchettoParser::PostfixExpressionContext *ctx) = 0;

  virtual void
  enterPrimaryExpression(FianchettoParser::PrimaryExpressionContext *ctx) = 0;
  virtual void
  exitPrimaryExpression(FianchettoParser::PrimaryExpressionContext *ctx) = 0;

  virtual void
  enterArgumentList(FianchettoParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(FianchettoParser::ArgumentListContext *ctx) = 0;

  virtual void enterConstant(FianchettoParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(FianchettoParser::ConstantContext *ctx) = 0;

  virtual void
  enterAssignmentOperator(FianchettoParser::AssignmentOperatorContext *ctx) = 0;
  virtual void
  exitAssignmentOperator(FianchettoParser::AssignmentOperatorContext *ctx) = 0;
};
