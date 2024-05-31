#ifndef LEXER_H
#define LEXER_H

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
  KEYWORD,
  IDENTIFIER,
  OPERATOR,
  INTEGER_LITERAL,
  FLOAT_LITERAL,
  STRING_LITERAL,
  PUNCTUATION,
  PRIME,
  END_OF_FILE
};

struct Location {
  std::string filename;
  int line;
  int column;
};

struct Token {
  TokenType type;
  std::string value;
  Location loc;
};

class Lexer {
  std::string source;
  size_t position;
  FILE* file_ptr;
  Token nextToken();
public:
  Lexer(const std::string &source);
  std::vector<Token> tokenize();
  ~Lexer();
};

#endif // LEXER_H