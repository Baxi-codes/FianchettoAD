
// Generated from Fianchetto.g4 by ANTLR 4.10.1

#pragma once

#include "antlr4-runtime.h"

class FianchettoParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1,
    T__1 = 2,
    T__2 = 3,
    T__3 = 4,
    T__4 = 5,
    T__5 = 6,
    T__6 = 7,
    T__7 = 8,
    T__8 = 9,
    T__9 = 10,
    T__10 = 11,
    T__11 = 12,
    T__12 = 13,
    T__13 = 14,
    T__14 = 15,
    T__15 = 16,
    T__16 = 17,
    T__17 = 18,
    T__18 = 19,
    T__19 = 20,
    T__20 = 21,
    T__21 = 22,
    T__22 = 23,
    T__23 = 24,
    T__24 = 25,
    T__25 = 26,
    T__26 = 27,
    T__27 = 28,
    T__28 = 29,
    T__29 = 30,
    T__30 = 31,
    T__31 = 32,
    T__32 = 33,
    T__33 = 34,
    T__34 = 35,
    T__35 = 36,
    T__36 = 37,
    T__37 = 38,
    T__38 = 39,
    T__39 = 40,
    T__40 = 41,
    T__41 = 42,
    T__42 = 43,
    INTEGER_LITERAL = 44,
    FLOAT_LITERAL = 45,
    STRING_LITERAL = 46,
    IDENTIFIER = 47,
    COMMENT = 48,
    MULTI_LINE_COMMENT = 49,
    WHITESPACE = 50
  };

  enum {
    RuleProgram = 0,
    RuleFunctionDefinition = 1,
    RuleGlobalDeclaration = 2,
    RuleParameterList = 3,
    RuleParameter = 4,
    RuleTypeSpecifier = 5,
    RuleStatement = 6,
    RuleExpressionStatement = 7,
    RuleCompoundStatement = 8,
    RuleSelectionStatement = 9,
    RuleIterationStatement = 10,
    RuleJumpStatement = 11,
    RuleDeclaration = 12,
    RuleExpression = 13,
    RuleAssignmentExpression = 14,
    RuleConditionalExpression = 15,
    RuleLogicalOrExpression = 16,
    RuleLogicalAndExpression = 17,
    RuleEqualityExpression = 18,
    RuleRelationalExpression = 19,
    RuleAdditiveExpression = 20,
    RuleMultiplicativeExpression = 21,
    RuleUnaryExpression = 22,
    RulePostfixExpression = 23,
    RulePrimaryExpression = 24,
    RuleArgumentList = 25,
    RuleConstant = 26,
    RuleAssignmentOperator = 27
  };

  explicit FianchettoParser(antlr4::TokenStream *input);

  FianchettoParser(antlr4::TokenStream *input,
                   const antlr4::atn::ParserATNSimulatorOptions &options);

  ~FianchettoParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN &getATN() const override;

  const std::vector<std::string> &getRuleNames() const override;

  const antlr4::dfa::Vocabulary &getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  class ProgramContext;
  class FunctionDefinitionContext;
  class GlobalDeclarationContext;
  class ParameterListContext;
  class ParameterContext;
  class TypeSpecifierContext;
  class StatementContext;
  class ExpressionStatementContext;
  class CompoundStatementContext;
  class SelectionStatementContext;
  class IterationStatementContext;
  class JumpStatementContext;
  class DeclarationContext;
  class ExpressionContext;
  class AssignmentExpressionContext;
  class ConditionalExpressionContext;
  class LogicalOrExpressionContext;
  class LogicalAndExpressionContext;
  class EqualityExpressionContext;
  class RelationalExpressionContext;
  class AdditiveExpressionContext;
  class MultiplicativeExpressionContext;
  class UnaryExpressionContext;
  class PostfixExpressionContext;
  class PrimaryExpressionContext;
  class ArgumentListContext;
  class ConstantContext;
  class AssignmentOperatorContext;

  class ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<FunctionDefinitionContext *> functionDefinition();
    FunctionDefinitionContext *functionDefinition(size_t i);
    std::vector<GlobalDeclarationContext *> globalDeclaration();
    GlobalDeclarationContext *globalDeclaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ProgramContext *program();

  class FunctionDefinitionContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefinitionContext(antlr4::ParserRuleContext *parent,
                              size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSpecifierContext *typeSpecifier();
    antlr4::tree::TerminalNode *IDENTIFIER();
    CompoundStatementContext *compoundStatement();
    ParameterListContext *parameterList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  FunctionDefinitionContext *functionDefinition();

  class GlobalDeclarationContext : public antlr4::ParserRuleContext {
  public:
    GlobalDeclarationContext(antlr4::ParserRuleContext *parent,
                             size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSpecifierContext *typeSpecifier();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  GlobalDeclarationContext *globalDeclaration();

  class ParameterListContext : public antlr4::ParserRuleContext {
  public:
    ParameterListContext(antlr4::ParserRuleContext *parent,
                         size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext *parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ParameterListContext *parameterList();

  class ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSpecifierContext *typeSpecifier();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ParameterContext *parameter();

  class TypeSpecifierContext : public antlr4::ParserRuleContext {
  public:
    TypeSpecifierContext(antlr4::ParserRuleContext *parent,
                         size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSpecifierContext *typeSpecifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  TypeSpecifierContext *typeSpecifier();

  class StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionStatementContext *expressionStatement();
    CompoundStatementContext *compoundStatement();
    SelectionStatementContext *selectionStatement();
    IterationStatementContext *iterationStatement();
    JumpStatementContext *jumpStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  StatementContext *statement();

  class ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStatementContext(antlr4::ParserRuleContext *parent,
                               size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExpressionStatementContext *expressionStatement();

  class CompoundStatementContext : public antlr4::ParserRuleContext {
  public:
    CompoundStatementContext(antlr4::ParserRuleContext *parent,
                             size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext *declaration(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext *statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  CompoundStatementContext *compoundStatement();

  class SelectionStatementContext : public antlr4::ParserRuleContext {
  public:
    SelectionStatementContext(antlr4::ParserRuleContext *parent,
                              size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext *statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  SelectionStatementContext *selectionStatement();

  class IterationStatementContext : public antlr4::ParserRuleContext {
  public:
    IterationStatementContext(antlr4::ParserRuleContext *parent,
                              size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  IterationStatementContext *iterationStatement();

  class JumpStatementContext : public antlr4::ParserRuleContext {
  public:
    JumpStatementContext(antlr4::ParserRuleContext *parent,
                         size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  JumpStatementContext *jumpStatement();

  class DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSpecifierContext *typeSpecifier();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  DeclarationContext *declaration();

  class ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentExpressionContext *assignmentExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExpressionContext *expression();

  class AssignmentExpressionContext : public antlr4::ParserRuleContext {
  public:
    AssignmentExpressionContext(antlr4::ParserRuleContext *parent,
                                size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConditionalExpressionContext *conditionalExpression();
    UnaryExpressionContext *unaryExpression();
    AssignmentOperatorContext *assignmentOperator();
    AssignmentExpressionContext *assignmentExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  AssignmentExpressionContext *assignmentExpression();

  class ConditionalExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConditionalExpressionContext(antlr4::ParserRuleContext *parent,
                                 size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalOrExpressionContext *logicalOrExpression();
    ExpressionContext *expression();
    ConditionalExpressionContext *conditionalExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ConditionalExpressionContext *conditionalExpression();

  class LogicalOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicalOrExpressionContext(antlr4::ParserRuleContext *parent,
                               size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalAndExpressionContext *logicalAndExpression();
    LogicalOrExpressionContext *logicalOrExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LogicalOrExpressionContext *logicalOrExpression();
  LogicalOrExpressionContext *logicalOrExpression(int precedence);
  class LogicalAndExpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicalAndExpressionContext(antlr4::ParserRuleContext *parent,
                                size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqualityExpressionContext *equalityExpression();
    LogicalAndExpressionContext *logicalAndExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LogicalAndExpressionContext *logicalAndExpression();
  LogicalAndExpressionContext *logicalAndExpression(int precedence);
  class EqualityExpressionContext : public antlr4::ParserRuleContext {
  public:
    EqualityExpressionContext(antlr4::ParserRuleContext *parent,
                              size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationalExpressionContext *relationalExpression();
    EqualityExpressionContext *equalityExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  EqualityExpressionContext *equalityExpression();
  EqualityExpressionContext *equalityExpression(int precedence);
  class RelationalExpressionContext : public antlr4::ParserRuleContext {
  public:
    RelationalExpressionContext(antlr4::ParserRuleContext *parent,
                                size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AdditiveExpressionContext *additiveExpression();
    RelationalExpressionContext *relationalExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  RelationalExpressionContext *relationalExpression();
  RelationalExpressionContext *relationalExpression(int precedence);
  class AdditiveExpressionContext : public antlr4::ParserRuleContext {
  public:
    AdditiveExpressionContext(antlr4::ParserRuleContext *parent,
                              size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MultiplicativeExpressionContext *multiplicativeExpression();
    AdditiveExpressionContext *additiveExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  AdditiveExpressionContext *additiveExpression();
  AdditiveExpressionContext *additiveExpression(int precedence);
  class MultiplicativeExpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeExpressionContext(antlr4::ParserRuleContext *parent,
                                    size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryExpressionContext *unaryExpression();
    MultiplicativeExpressionContext *multiplicativeExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  MultiplicativeExpressionContext *multiplicativeExpression();
  MultiplicativeExpressionContext *multiplicativeExpression(int precedence);
  class UnaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryExpressionContext(antlr4::ParserRuleContext *parent,
                           size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PostfixExpressionContext *postfixExpression();
    UnaryExpressionContext *unaryExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  UnaryExpressionContext *unaryExpression();

  class PostfixExpressionContext : public antlr4::ParserRuleContext {
  public:
    PostfixExpressionContext(antlr4::ParserRuleContext *parent,
                             size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryExpressionContext *primaryExpression();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();
    PostfixExpressionContext *postfixExpression();
    ArgumentListContext *argumentList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PostfixExpressionContext *postfixExpression();
  PostfixExpressionContext *postfixExpression(int precedence);
  class PrimaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExpressionContext(antlr4::ParserRuleContext *parent,
                             size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ConstantContext *constant();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PrimaryExpressionContext *primaryExpression();

  class ArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentListContext(antlr4::ParserRuleContext *parent,
                        size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext *expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ArgumentListContext *argumentList();

  class ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ConstantContext *constant();

  class AssignmentOperatorContext : public antlr4::ParserRuleContext {
  public:
    AssignmentOperatorContext(antlr4::ParserRuleContext *parent,
                              size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  AssignmentOperatorContext *assignmentOperator();

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex,
               size_t predicateIndex) override;

  bool logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx,
                                  size_t predicateIndex);
  bool logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx,
                                   size_t predicateIndex);
  bool equalityExpressionSempred(EqualityExpressionContext *_localctx,
                                 size_t predicateIndex);
  bool relationalExpressionSempred(RelationalExpressionContext *_localctx,
                                   size_t predicateIndex);
  bool additiveExpressionSempred(AdditiveExpressionContext *_localctx,
                                 size_t predicateIndex);
  bool
  multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx,
                                  size_t predicateIndex);
  bool postfixExpressionSempred(PostfixExpressionContext *_localctx,
                                size_t predicateIndex);

  // By default the static state used to implement the parser is lazily
  // initialized during the first call to the constructor. You can call this
  // function if you wish to initialize the static state ahead of time.
  static void initialize();

private:
};
