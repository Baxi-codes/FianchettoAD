#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "lexer.h"
extern "C" Token yylex();
extern void yyrestart( FILE *new_file );

std::string Token::get_type() {
    switch (type) {
        case TokenType::KW_differentiable: return "KW_differentiable";
        case TokenType::KW_fn: return "KW_fn";
        case TokenType::KW_let: return "KW_let";
        case TokenType::KW_int: return "KW_int";
        case TokenType::KW_float: return "KW_float";
        case TokenType::KW_double: return "KW_double";
        case TokenType::KW_void: return "KW_void";
        case TokenType::KW_if: return "KW_if";
        case TokenType::KW_else: return "KW_else";
        case TokenType::KW_while: return "KW_while";
        case TokenType::KW_for: return "KW_for";
        case TokenType::KW_return: return "KW_return";
        case TokenType::KW_continue: return "KW_continue";
        case TokenType::KW_break: return "KW_break";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::L_SQUARE: return "L_SQUARE";
        case TokenType::R_SQUARE: return "R_SQUARE";
        case TokenType::L_PAREN: return "L_PAREN";
        case TokenType::R_PAREN: return "R_PAREN";
        case TokenType::L_BRACE: return "L_BRACE";
        case TokenType::R_BRACE: return "R_BRACE";
        case TokenType::PERIOD: return "PERIOD";
        case TokenType::ELLIPSIS: return "ELLIPSIS";
        case TokenType::AMP: return "AMP";
        case TokenType::AMPAMP: return "AMPAMP";
        case TokenType::AMPEQUAL: return "AMPEQUAL";
        case TokenType::STAR: return "STAR";
        case TokenType::STAREQUAL: return "STAREQUAL";
        case TokenType::PLUS: return "PLUS";
        case TokenType::PLUSPLUS: return "PLUSPLUS";
        case TokenType::PLUSEQUAL: return "PLUSEQUAL";
        case TokenType::MINUS: return "MINUS";
        case TokenType::ARROW: return "ARROW";
        case TokenType::MINUSMINUS: return "MINUSMINUS";
        case TokenType::MINUSEQUAL: return "MINUSEQUAL";
        case TokenType::TILDE: return "TILDE";
        case TokenType::EXCLAIM: return "EXCLAIM";
        case TokenType::EXCLAIMEQUAL: return "EXCLAIMEQUAL";
        case TokenType::SLASH: return "SLASH";
        case TokenType::SLASHEQUAL: return "SLASHEQUAL";
        case TokenType::PERCENT: return "PERCENT";
        case TokenType::PERCENTEQUAL: return "PERCENTEQUAL";
        case TokenType::LESS: return "LESS";
        case TokenType::LESSLESS: return "LESSLESS";
        case TokenType::LESSEQUAL: return "LESSEQUAL";
        case TokenType::LESSLESSEQUAL: return "LESSLESSEQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATERGREATER: return "GREATERGREATER";
        case TokenType::GREATEREQUAL: return "GREATEREQUAL";
        case TokenType::GREATERGREATEREQUAL: return "GREATERGREATEREQUAL";
        case TokenType::CARET: return "CARET";
        case TokenType::CARETEQUAL: return "CARETEQUAL";
        case TokenType::PIPE: return "PIPE";
        case TokenType::PIPEPIPE: return "PIPEPIPE";
        case TokenType::PIPEEQUAL: return "PIPEEQUAL";
        case TokenType::QUESTION: return "QUESTION";
        case TokenType::COLON: return "COLON";
        case TokenType::SEMI: return "SEMI";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUALEQUAL: return "EQUALEQUAL";
        case TokenType::COMMA: return "COMMA";
        case TokenType::HASH: return "HASH";
        case TokenType::HASHHASH: return "HASHHASH";
        case TokenType::HASHAT: return "HASHAT";
        case TokenType::INTEGER_LITERAL: return "INTEGER_LITERAL";
        case TokenType::FLOAT_LITERAL: return "FLOAT_LITERAL";
        case TokenType::STRING_LITERAL: return "STRING_LITERAL";
        case TokenType::END_OF_FILE: return "END_OF_FILE";
        default: return "UNKNOWN_TOKEN";
    }
}


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
