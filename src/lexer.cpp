#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Lexer.h"

Lexer::Lexer(const std::string &source) : source(source), position(0) {}

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

Token Lexer::nextToken() {
  while (position < source.size() && std::isspace(source[position])) {
    position++;
  }

  if (position >= source.size()) {
    return {TokenType::END_OF_FILE, ""};
  }

  char currentChar = source[position];

  if (std::isalpha(currentChar) || currentChar == '_') {
    return identifier();
  }

  if (std::isdigit(currentChar)) {
    return number();
  }

  if (currentChar == '\'') {
    return prime();
  }

  if (currentChar == '"') {
    return stringLiteral();
  }

  if (isOperator(currentChar)) {
    return op();
  }

  if (isPunctuation(currentChar)) {
    return punctuation();
  }

  throw std::runtime_error("Unexpected character: " +
                           std::string(1, currentChar));
}

Token Lexer::identifier() {
  size_t start = position;
  while (position < source.size() &&
         (std::isalnum(source[position]) || source[position] == '_')) {
    position++;
  }
  std::string value = source.substr(start, position - start);

  static std::unordered_map<std::string, TokenType> keywords = {
      {"differentiable", TokenType::KEYWORD},
      {"if", TokenType::KEYWORD},
      {"else", TokenType::KEYWORD},
      {"while", TokenType::KEYWORD},
      {"for", TokenType::KEYWORD},
      {"return", TokenType::KEYWORD},
      {"int", TokenType::KEYWORD},
      {"float", TokenType::KEYWORD},
      {"double", TokenType::KEYWORD},
      {"void", TokenType::KEYWORD}};

  if (keywords.find(value) != keywords.end()) {
    return {keywords[value], value};
  }
  return {TokenType::IDENTIFIER, value};
}

Token Lexer::number() {
  size_t start = position;
  while (position < source.size() && std::isdigit(source[position])) {
    position++;
  }
  if (position < source.size() && source[position] == '.') {
    position++;
    while (position < source.size() && std::isdigit(source[position])) {
      position++;
    }
    return {TokenType::FLOAT_LITERAL, source.substr(start, position - start)};
  }
  return {TokenType::INTEGER_LITERAL, source.substr(start, position - start)};
}

Token Lexer::stringLiteral() {
  size_t start = ++position; // Skip the opening quote
  while (position < source.size() && source[position] != '"') {
    position++;
  }
  if (position >= source.size()) {
    throw std::runtime_error("Unterminated string literal");
  }
  position++; // Skip the closing quote
  return {TokenType::STRING_LITERAL,
          source.substr(start, position - start - 1)};
}

Token Lexer::op() {
  char currentChar = source[position];
  position++;
  return {TokenType::OPERATOR, std::string(1, currentChar)};
}

Token Lexer::punctuation() {
  char currentChar = source[position];
  position++;
  return {TokenType::PUNCTUATION, std::string(1, currentChar)};
}

Token Lexer::prime() {
  char currentChar = source[position];
  position++;
  return {TokenType::PRIME, std::string(1, currentChar)};
}

bool Lexer::isOperator(char c) {
  static std::string operators = "+-*/%=<>!&|";
  return operators.find(c) != std::string::npos;
}

bool Lexer::isPunctuation(char c) {
  static std::string punctuations = ",;(){}[]";
  return punctuations.find(c) != std::string::npos;
}
