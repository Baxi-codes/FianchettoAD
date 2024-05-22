%{
#include <cctype>
#include <iostream>
#include <string>
#include "Lexer.h"

#define YY_DECL Token Lexer::nextToken()
%}

%%
"if"|"else"|"while"|"return"              { return Token{TokenType::KEYWORD, yytext}; }
[a-zA-Z_][a-zA-Z0-9_]*                     { return Token{TokenType::IDENTIFIER, yytext}; }
[0-9]+\.[0-9]+                            { return Token{TokenType::FLOAT_LITERAL, yytext}; }
[0-9]+                                    { return Token{TokenType::INTEGER_LITERAL, yytext}; }
\"(\\.|[^"\\])*\"                         { return Token{TokenType::STRING_LITERAL, yytext}; }
"+"|"-"|"*"|"/"|"="|"=="|"!="|"<"|">"     { return Token{TokenType::OPERATOR, yytext}; }
"(" | ")" | "{" | "}" | ";" | "," | "."   { return Token{TokenType::PUNCTUATION, yytext}; }
"'"[^']+"'"                               { return Token{TokenType::PRIME, yytext}; }
[ \t\n\r]+                                { /* Ignore whitespace */ }
.                                         { std::cerr << "Unknown character: " << yytext << std::endl; exit(1); }
<<EOF>>                                   { return Token{TokenType::END_OF_FILE, ""}; }
%%

Token Lexer::nextToken() {
    return yylex();
}
