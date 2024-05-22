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

struct Token {
  TokenType type;
  std::string value;
};

class Lexer {
  std::string source;
  size_t position;

  Token nextToken();
  Token identifier();
  Token number();
  Token stringLiteral();
  Token op();
  Token punctuation();
  Token prime();
  bool isOperator(char c);
  bool isPunctuation(char c);

public:
  Lexer(const std::string &source);
  std::vector<Token> tokenize();
};

#endif // LEXER_H