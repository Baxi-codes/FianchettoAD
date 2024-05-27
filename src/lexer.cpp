#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "lexer.h"
extern "C" Token yylex();
extern void yyrestart( FILE *new_file );

Lexer::Lexer(const std::string &source) : source(source), position(0) {
  file_ptr = fopen(source.c_str(), "r");
  yyrestart(file_ptr);
}

Lexer::~Lexer() {
  fclose(file_ptr);
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
