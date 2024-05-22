%{
#include <cctype>
#include <iostream>
#include <string>
#include "lexer.h"

#define YY_DECL Token Lexer::nextToken()
static void comment(void);

%}

%option noyywrap

%%
"//".*                                          { /* Ignore single-line comment */ }
"/*"                                            { comment(); }
"differentiable"                                { return Token{TokenType::KEYWORD, yytext}; }
"if"                                            { return Token{TokenType::KEYWORD, yytext}; }
"else"                                          { return Token{TokenType::KEYWORD, yytext}; }
"while"                                         { return Token{TokenType::KEYWORD, yytext}; }
"for"                                           { return Token{TokenType::KEYWORD, yytext}; }
"return"                                        { return Token{TokenType::KEYWORD, yytext}; }
"int"                                           { return Token{TokenType::KEYWORD, yytext}; }
"float"                                         { return Token{TokenType::KEYWORD, yytext}; }
"double"                                        { return Token{TokenType::KEYWORD, yytext}; }
"void"                                          { return Token{TokenType::KEYWORD, yytext}; }
[a-zA-Z_][a-zA-Z0-9_]*                          { return Token{TokenType::IDENTIFIER, yytext}; }
[0-9]*"."[0-9]+([eE][-+]?[0-9]+)?               { return Token{TokenType::FLOAT_LITERAL, yytext}; }
[0-9]+                                          { return Token{TokenType::INTEGER_LITERAL, yytext}; }
\"(\\.|[^"\\])*\"                               { return Token{TokenType::STRING_LITERAL, yytext}; }
"+"                                             { return Token{TokenType::OPERATOR, yytext}; }
"-"                                             { return Token{TokenType::OPERATOR, yytext}; }
"*"                                             { return Token{TokenType::OPERATOR, yytext}; }
"/"                                             { return Token{TokenType::OPERATOR, yytext}; }
"="                                             { return Token{TokenType::OPERATOR, yytext}; }
"=="                                            { return Token{TokenType::OPERATOR, yytext}; }
"!="                                            { return Token{TokenType::OPERATOR, yytext}; }
"<"                                             { return Token{TokenType::OPERATOR, yytext}; }
">"                                             { return Token{TokenType::OPERATOR, yytext}; }
"("                                             { return Token{TokenType::PUNCTUATION, yytext}; }
")"                                             { return Token{TokenType::PUNCTUATION, yytext}; }
"{"                                             { return Token{TokenType::PUNCTUATION, yytext}; }
"}"                                             { return Token{TokenType::PUNCTUATION, yytext}; }
";"                                             { return Token{TokenType::PUNCTUATION, yytext}; }
","                                             { return Token{TokenType::PUNCTUATION, yytext}; }
"."                                             { return Token{TokenType::PUNCTUATION, yytext}; }
"'"                                             { return Token{TokenType::PUNCTUATION, yytext}; }
[ \t\n\r]+                                      { /* Ignore whitespace */ }
.                                               { std::cerr << "Unknown character: " << yytext << std::endl; exit(1); }
<<EOF>>                                         { return Token{TokenType::END_OF_FILE, ""}; }
%%

static void comment(void)
{
  int c;

  while ((c = yyinput()) != 0)
    if (c == '*')
    {
      while ((c = yyinput()) == '*')
        ;

      if (c == '/')
        return;

      if (c == 0)
        break;
    }
  printf("unterminated comment");
}
