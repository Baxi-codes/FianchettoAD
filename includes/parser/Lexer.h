#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    INTEGER_LITERAL,
    FLOAT_LITERAL,
    STRING_LITERAL,
    PUNCTUATION,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
    std::string input;
    size_t currentPos;

    Token nextToken();
    Token identifier();
    Token number();
    Token stringLiteral();
    Token op();
    Token punctuation();
    bool isOperator(char c);
    bool isPunctuation(char c);
    
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();
};

#endif // LEXER_H