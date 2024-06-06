#ifndef LEXER_H
#define LEXER_H

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
  KW_differentiable,
  KW_fn,
  KW_let,
  KW_int,
  KW_float,
  KW_double,
  KW_void,
  KW_if,
  KW_else,
  KW_while,
  KW_for,
  KW_return,
  KW_continue,
  KW_break,
  IDENTIFIER,
  L_SQUARE,
  R_SQUARE,
  L_PAREN,
  R_PAREN,
  L_BRACE,
  R_BRACE,
  PERIOD,
  ELLIPSIS,
  AMP,
  AMPAMP,
  AMPEQUAL,
  STAR,
  STAREQUAL,
  PLUS,
  PLUSPLUS,
  PLUSEQUAL,
  MINUS,
  ARROW,
  MINUSMINUS,
  MINUSEQUAL,
  TILDE,
  EXCLAIM,
  EXCLAIMEQUAL,
  SLASH,
  SLASHEQUAL,
  PERCENT,
  PERCENTEQUAL,
  LESS,
  LESSLESS,
  LESSEQUAL,
  LESSLESSEQUAL,
  GREATER,
  GREATERGREATER,
  GREATEREQUAL,
  GREATERGREATEREQUAL,
  CARET,
  CARETEQUAL,
  PIPE,
  PIPEPIPE,
  PIPEEQUAL,
  QUESTION,
  COLON,
  SEMI,
  EQUAL,
  EQUALEQUAL,
  COMMA,
  HASH,
  HASHHASH,
  HASHAT,
  INTEGER_LITERAL,
  FLOAT_LITERAL,
  STRING_LITERAL,
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
  std::string get_type();
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