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
"let"                                           { return Token{TokenType::KW_let, yytext, {source, yylineno, column - yyleng}}; }
"fn"                                            { return Token{TokenType::KW_fn, yytext, {source, yylineno, column - yyleng}}; }
"differentiable"                                { return Token{TokenType::KW_differentiable, yytext, {source, yylineno, column - yyleng}}; }
"if"                                            { return Token{TokenType::KW_if, yytext, {source, yylineno, column - yyleng}}; }
"else"                                          { return Token{TokenType::KW_else, yytext, {source, yylineno, column - yyleng}}; }
"while"                                         { return Token{TokenType::KW_while, yytext, {source, yylineno, column - yyleng}}; }
"for"                                           { return Token{TokenType::KW_for, yytext, {source, yylineno, column - yyleng}}; }
"return"                                        { return Token{TokenType::KW_return, yytext, {source, yylineno, column - yyleng}}; }
"int"                                           { return Token{TokenType::KW_int, yytext, {source, yylineno, column - yyleng}}; }
"float"                                         { return Token{TokenType::KW_float, yytext, {source, yylineno, column - yyleng}}; }
"double"                                        { return Token{TokenType::KW_double, yytext, {source, yylineno, column - yyleng}}; }
"void"                                          { return Token{TokenType::KW_void, yytext, {source, yylineno, column - yyleng}}; }
[a-zA-Z_][a-zA-Z0-9_]*                          { return Token{TokenType::IDENTIFIER, yytext, {source, yylineno, column - yyleng}}; }
[0-9]*"."[0-9]+([eE][-+]?[0-9]+)?               { return Token{TokenType::FLOAT_LITERAL, yytext, {source, yylineno, column - yyleng}}; }
[0-9]+                                          { return Token{TokenType::INTEGER_LITERAL, yytext, {source, yylineno, column - yyleng}}; }
\"(\\.|[^"\\])*\"                               { return Token{TokenType::STRING_LITERAL, yytext, {source, yylineno, column - yyleng}}; }
"["                                             { return Token{TokenType::L_SQUARE, yytext, {source, yylineno, column - yyleng}}; }
"]"                                             { return Token{TokenType::R_SQUARE, yytext, {source, yylineno, column - yyleng}}; }
"("                                             { return Token{TokenType::L_PAREN, yytext, {source, yylineno, column - yyleng}}; }
")"                                             { return Token{TokenType::R_PAREN, yytext, {source, yylineno, column - yyleng}}; }
"{"                                             { return Token{TokenType::L_BRACE, yytext, {source, yylineno, column - yyleng}}; }
"}"                                             { return Token{TokenType::R_BRACE, yytext, {source, yylineno, column - yyleng}}; }
"..."                                           { return Token{TokenType::ELLIPSIS, yytext, {source, yylineno, column - yyleng}}; }
"."                                             { return Token{TokenType::PERIOD, yytext, {source, yylineno, column - yyleng}}; }
"&&"                                            { return Token{TokenType::AMPAMP, yytext, {source, yylineno, column - yyleng}}; }
"&="                                            { return Token{TokenType::AMPEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"&"                                             { return Token{TokenType::AMP, yytext, {source, yylineno, column - yyleng}}; }
"*="                                            { return Token{TokenType::STAREQUAL, yytext, {source, yylineno, column - yyleng}}; }
"*"                                             { return Token{TokenType::STAR, yytext, {source, yylineno, column - yyleng}}; }
"+="                                            { return Token{TokenType::PLUSEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"++"                                            { return Token{TokenType::PLUSPLUS, yytext, {source, yylineno, column - yyleng}}; }
"+"                                             { return Token{TokenType::PLUS, yytext, {source, yylineno, column - yyleng}}; }
"-="                                            { return Token{TokenType::MINUSEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"--"                                            { return Token{TokenType::MINUSMINUS, yytext, {source, yylineno, column - yyleng}}; }
"->"                                            { return Token{TokenType::ARROW, yytext, {source, yylineno, column - yyleng}}; }
"-"                                             { return Token{TokenType::MINUS, yytext, {source, yylineno, column - yyleng}}; }
"~"                                             { return Token{TokenType::TILDE, yytext, {source, yylineno, column - yyleng}}; }
"!="                                            { return Token{TokenType::EXCLAIMEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"!"                                             { return Token{TokenType::EXCLAIM, yytext, {source, yylineno, column - yyleng}}; }
"/="                                            { return Token{TokenType::SLASHEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"/"                                             { return Token{TokenType::SLASH, yytext, {source, yylineno, column - yyleng}}; }
"%="                                            { return Token{TokenType::PERCENTEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"%"                                             { return Token{TokenType::PERCENT, yytext, {source, yylineno, column - yyleng}}; }
"<<="                                           { return Token{TokenType::LESSLESSEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"<="                                            { return Token{TokenType::LESSEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"<<"                                            { return Token{TokenType::LESSLESS, yytext, {source, yylineno, column - yyleng}}; }
"<"                                             { return Token{TokenType::LESS, yytext, {source, yylineno, column - yyleng}}; }
">>="                                           { return Token{TokenType::GREATERGREATEREQUAL, yytext, {source, yylineno, column - yyleng}}; }
">="                                            { return Token{TokenType::GREATEREQUAL, yytext, {source, yylineno, column - yyleng}}; }
">>"                                            { return Token{TokenType::GREATERGREATER, yytext, {source, yylineno, column - yyleng}}; }
">"                                             { return Token{TokenType::GREATER, yytext, {source, yylineno, column - yyleng}}; }
"^="                                            { return Token{TokenType::CARETEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"^"                                             { return Token{TokenType::CARET, yytext, {source, yylineno, column - yyleng}}; }
"|="                                            { return Token{TokenType::PIPEEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"||"                                            { return Token{TokenType::PIPEPIPE, yytext, {source, yylineno, column - yyleng}}; }
"|"                                             { return Token{TokenType::PIPE, yytext, {source, yylineno, column - yyleng}}; }
"?"                                             { return Token{TokenType::QUESTION, yytext, {source, yylineno, column - yyleng}}; }
":"                                             { return Token{TokenType::COLON, yytext, {source, yylineno, column - yyleng}}; }
";"                                             { return Token{TokenType::SEMI, yytext, {source, yylineno, column - yyleng}}; }
"=="                                            { return Token{TokenType::EQUALEQUAL, yytext, {source, yylineno, column - yyleng}}; }
"="                                             { return Token{TokenType::EQUAL, yytext, {source, yylineno, column - yyleng}}; }
","                                             { return Token{TokenType::COMMA, yytext, {source, yylineno, column - yyleng}}; }
"##"                                            { return Token{TokenType::HASHHASH, yytext, {source, yylineno, column - yyleng}}; }
"#@"                                            { return Token{TokenType::HASHAT, yytext, {source, yylineno, column - yyleng}}; }
"#"                                             { return Token{TokenType::HASH, yytext, {source, yylineno, column - yyleng}}; }
"'"                                             { return Token{TokenType::PRIME, yytext, {source, yylineno, column - yyleng}}; }
[ \t\r]+                                        { /* Ignore whitespace */ }
\n                                              { column = 1; }
.                                               { std::cerr << "Unknown character: " << yytext << std::endl; exit(1); }
<<EOF>>                                         { return Token{TokenType::END_OF_FILE, ""}; }
%%