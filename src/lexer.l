%{
#include <cctype>
#include <iostream>
#include <string>
#include "lexer.h"

#define YY_DECL Token Lexer::nextToken()

int column = 1;

#define YY_USER_ACTION column += yyleng; // Update column number for each matched token

%}

%x COMMENT
%option noyywrap
%option yylineno


%%
"//".*                                          { /* Ignore single-line comment */ }
"/*"                                            { BEGIN(COMMENT); } // Begin of a multiline comment
<COMMENT>{
    "*/"    { BEGIN(INITIAL); } // End of a multiline comment
    \n      { column = 1; } // Reset column number at the end of each line
    .       {  } // Ignore other characters
}
"let"                                           { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"differentiable"                                { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"if"                                            { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"else"                                          { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"while"                                         { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"for"                                           { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"return"                                        { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"int"                                           { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"float"                                         { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"double"                                        { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
"void"                                          { return Token{TokenType::KEYWORD, yytext, {source, yylineno, column - yyleng}}; }
[a-zA-Z_][a-zA-Z0-9_]*                          { return Token{TokenType::IDENTIFIER, yytext, {source, yylineno, column - yyleng}}; }
[0-9]*"."[0-9]+([eE][-+]?[0-9]+)?               { return Token{TokenType::FLOAT_LITERAL, yytext, {source, yylineno, column - yyleng}}; }
[0-9]+                                          { return Token{TokenType::INTEGER_LITERAL, yytext, {source, yylineno, column - yyleng}}; }
\"(\\.|[^"\\])*\"                               { return Token{TokenType::STRING_LITERAL, yytext, {source, yylineno, column - yyleng}}; }
"+"                                             { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"-"                                             { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"*"                                             { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"/"                                             { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"="                                             { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"=="                                            { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"!="                                            { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"<"                                             { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
">"                                             { return Token{TokenType::OPERATOR, yytext, {source, yylineno, column - yyleng}}; }
"("                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
")"                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
"{"                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
"}"                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
";"                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
","                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
"."                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
"'"                                             { return Token{TokenType::PUNCTUATION, yytext, {source, yylineno, column - yyleng}}; }
[ \t\r]+                                        { /* Ignore whitespace */ }
\n                                              { column = 1; }
.                                               { std::cerr << "Unknown character: " << yytext << std::endl; exit(1); }
<<EOF>>                                         { return Token{TokenType::END_OF_FILE, ""}; }
%%