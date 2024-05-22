#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "lexer.h"
extern "C" Token yylex();
extern "C" FILE *yyin;

Lexer::Lexer(const std::string &source) : source(source), position(0) {
  yyin = fopen(source.c_str(), "r");
}

std::vector<Token> Lexer::tokenize() {
  std::vector<Token> tokens;
  while (true) {
    Token token = nextToken();
    tokens.push_back(token);
    if (token.type == TokenType::END_OF_FILE)
      break;
  }
  return tokens;
}
