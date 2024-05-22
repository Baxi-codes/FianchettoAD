
// Generated from Fianchetto.g4 by ANTLR 4.10.1

#pragma once

#include "FianchettoListener.h"
#include "antlr4-runtime.h"

/**
 * This class provides an empty implementation of FianchettoListener,
 * which can be extended to create a listener which only needs to handle a
 * subset of the available methods.
 */
class FianchettoBaseListener : public FianchettoListener {
public:
  virtual void
  enterProgram(FianchettoParser::ProgramContext * /*ctx*/) override {}
  virtual void
  exitProgram(FianchettoParser::ProgramContext * /*ctx*/) override {}

  virtual void enterFunctionDefinition(
      FianchettoParser::FunctionDefinitionContext * /*ctx*/) override {}
  virtual void exitFunctionDefinition(
      FianchettoParser::FunctionDefinitionContext * /*ctx*/) override {}

  virtual void enterGlobalDeclaration(
      FianchettoParser::GlobalDeclarationContext * /*ctx*/) override {}
  virtual void exitGlobalDeclaration(
      FianchettoParser::GlobalDeclarationContext * /*ctx*/) override {}

  virtual void enterParameterList(
      FianchettoParser::ParameterListContext * /*ctx*/) override {}
  virtual void
  exitParameterList(FianchettoParser::ParameterListContext * /*ctx*/) override {
  }

  virtual void
  enterParameter(FianchettoParser::ParameterContext * /*ctx*/) override {}
  virtual void
  exitParameter(FianchettoParser::ParameterContext * /*ctx*/) override {}

  virtual void enterTypeSpecifier(
      FianchettoParser::TypeSpecifierContext * /*ctx*/) override {}
  virtual void
  exitTypeSpecifier(FianchettoParser::TypeSpecifierContext * /*ctx*/) override {
  }

  virtual void
  enterStatement(FianchettoParser::StatementContext * /*ctx*/) override {}
  virtual void
  exitStatement(FianchettoParser::StatementContext * /*ctx*/) override {}

  virtual void enterExpressionStatement(
      FianchettoParser::ExpressionStatementContext * /*ctx*/) override {}
  virtual void exitExpressionStatement(
      FianchettoParser::ExpressionStatementContext * /*ctx*/) override {}

  virtual void enterCompoundStatement(
      FianchettoParser::CompoundStatementContext * /*ctx*/) override {}
  virtual void exitCompoundStatement(
      FianchettoParser::CompoundStatementContext * /*ctx*/) override {}

  virtual void enterSelectionStatement(
      FianchettoParser::SelectionStatementContext * /*ctx*/) override {}
  virtual void exitSelectionStatement(
      FianchettoParser::SelectionStatementContext * /*ctx*/) override {}

  virtual void enterIterationStatement(
      FianchettoParser::IterationStatementContext * /*ctx*/) override {}
  virtual void exitIterationStatement(
      FianchettoParser::IterationStatementContext * /*ctx*/) override {}

  virtual void enterJumpStatement(
      FianchettoParser::JumpStatementContext * /*ctx*/) override {}
  virtual void
  exitJumpStatement(FianchettoParser::JumpStatementContext * /*ctx*/) override {
  }

  virtual void
  enterDeclaration(FianchettoParser::DeclarationContext * /*ctx*/) override {}
  virtual void
  exitDeclaration(FianchettoParser::DeclarationContext * /*ctx*/) override {}

  virtual void
  enterExpression(FianchettoParser::ExpressionContext * /*ctx*/) override {}
  virtual void
  exitExpression(FianchettoParser::ExpressionContext * /*ctx*/) override {}

  virtual void enterAssignmentExpression(
      FianchettoParser::AssignmentExpressionContext * /*ctx*/) override {}
  virtual void exitAssignmentExpression(
      FianchettoParser::AssignmentExpressionContext * /*ctx*/) override {}

  virtual void enterConditionalExpression(
      FianchettoParser::ConditionalExpressionContext * /*ctx*/) override {}
  virtual void exitConditionalExpression(
      FianchettoParser::ConditionalExpressionContext * /*ctx*/) override {}

  virtual void enterLogicalOrExpression(
      FianchettoParser::LogicalOrExpressionContext * /*ctx*/) override {}
  virtual void exitLogicalOrExpression(
      FianchettoParser::LogicalOrExpressionContext * /*ctx*/) override {}

  virtual void enterLogicalAndExpression(
      FianchettoParser::LogicalAndExpressionContext * /*ctx*/) override {}
  virtual void exitLogicalAndExpression(
      FianchettoParser::LogicalAndExpressionContext * /*ctx*/) override {}

  virtual void enterEqualityExpression(
      FianchettoParser::EqualityExpressionContext * /*ctx*/) override {}
  virtual void exitEqualityExpression(
      FianchettoParser::EqualityExpressionContext * /*ctx*/) override {}

  virtual void enterRelationalExpression(
      FianchettoParser::RelationalExpressionContext * /*ctx*/) override {}
  virtual void exitRelationalExpression(
      FianchettoParser::RelationalExpressionContext * /*ctx*/) override {}

  virtual void enterAdditiveExpression(
      FianchettoParser::AdditiveExpressionContext * /*ctx*/) override {}
  virtual void exitAdditiveExpression(
      FianchettoParser::AdditiveExpressionContext * /*ctx*/) override {}

  virtual void enterMultiplicativeExpression(
      FianchettoParser::MultiplicativeExpressionContext * /*ctx*/) override {}
  virtual void exitMultiplicativeExpression(
      FianchettoParser::MultiplicativeExpressionContext * /*ctx*/) override {}

  virtual void enterUnaryExpression(
      FianchettoParser::UnaryExpressionContext * /*ctx*/) override {}
  virtual void exitUnaryExpression(
      FianchettoParser::UnaryExpressionContext * /*ctx*/) override {}

  virtual void enterPostfixExpression(
      FianchettoParser::PostfixExpressionContext * /*ctx*/) override {}
  virtual void exitPostfixExpression(
      FianchettoParser::PostfixExpressionContext * /*ctx*/) override {}

  virtual void enterPrimaryExpression(
      FianchettoParser::PrimaryExpressionContext * /*ctx*/) override {}
  virtual void exitPrimaryExpression(
      FianchettoParser::PrimaryExpressionContext * /*ctx*/) override {}

  virtual void
  enterArgumentList(FianchettoParser::ArgumentListContext * /*ctx*/) override {}
  virtual void
  exitArgumentList(FianchettoParser::ArgumentListContext * /*ctx*/) override {}

  virtual void
  enterConstant(FianchettoParser::ConstantContext * /*ctx*/) override {}
  virtual void
  exitConstant(FianchettoParser::ConstantContext * /*ctx*/) override {}

  virtual void enterAssignmentOperator(
      FianchettoParser::AssignmentOperatorContext * /*ctx*/) override {}
  virtual void exitAssignmentOperator(
      FianchettoParser::AssignmentOperatorContext * /*ctx*/) override {}

  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override {}
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override {}
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override {}
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override {}
};
