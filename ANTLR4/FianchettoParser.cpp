
// Generated from Fianchetto.g4 by ANTLR 4.10.1

#include "FianchettoListener.h"

#include "FianchettoParser.h"

using namespace antlrcpp;

using namespace antlr4;

namespace {

struct FianchettoParserStaticData final {
  FianchettoParserStaticData(std::vector<std::string> ruleNames,
                             std::vector<std::string> literalNames,
                             std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FianchettoParserStaticData(const FianchettoParserStaticData &) = delete;
  FianchettoParserStaticData(FianchettoParserStaticData &&) = delete;
  FianchettoParserStaticData &
  operator=(const FianchettoParserStaticData &) = delete;
  FianchettoParserStaticData &operator=(FianchettoParserStaticData &&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag fianchettoParserOnceFlag;
FianchettoParserStaticData *fianchettoParserStaticData = nullptr;

void fianchettoParserInitialize() {
  assert(fianchettoParserStaticData == nullptr);
  auto staticData = std::make_unique<FianchettoParserStaticData>(
      std::vector<std::string>{"program",
                               "functionDefinition",
                               "globalDeclaration",
                               "parameterList",
                               "parameter",
                               "typeSpecifier",
                               "statement",
                               "expressionStatement",
                               "compoundStatement",
                               "selectionStatement",
                               "iterationStatement",
                               "jumpStatement",
                               "declaration",
                               "expression",
                               "assignmentExpression",
                               "conditionalExpression",
                               "logicalOrExpression",
                               "logicalAndExpression",
                               "equalityExpression",
                               "relationalExpression",
                               "additiveExpression",
                               "multiplicativeExpression",
                               "unaryExpression",
                               "postfixExpression",
                               "primaryExpression",
                               "argumentList",
                               "constant",
                               "assignmentOperator"},
      std::vector<std::string>{"",
                               "'('",
                               "')'",
                               "'='",
                               "';'",
                               "','",
                               "'int'",
                               "'float'",
                               "'double'",
                               "'void'",
                               "'differentiable'",
                               "'{'",
                               "'}'",
                               "'if'",
                               "'else'",
                               "'while'",
                               "'for'",
                               "'return'",
                               "'\\u003F'",
                               "':'",
                               "'||'",
                               "'&&'",
                               "'=='",
                               "'!='",
                               "'<'",
                               "'>'",
                               "'<='",
                               "'>='",
                               "'+'",
                               "'-'",
                               "'*'",
                               "'/'",
                               "'%'",
                               "'!'",
                               "'++'",
                               "'--'",
                               "'['",
                               "']'",
                               "'''",
                               "'+='",
                               "'-='",
                               "'*='",
                               "'/='",
                               "'%='"},
      std::vector<std::string>{"",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "INTEGER_LITERAL",
                               "FLOAT_LITERAL",
                               "STRING_LITERAL",
                               "IDENTIFIER",
                               "COMMENT",
                               "MULTI_LINE_COMMENT",
                               "WHITESPACE"});
  static const int32_t serializedATNSegment[] = {
      4,   1,   50,  332, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,
      2,   2,   3,   7,   3,   2,   4,   7,   4,   2,   5,   7,   5,   2,   6,
      7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,   9,   2,
      10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,
      2,   14,  7,   14,  2,   15,  7,   15,  2,   16,  7,   16,  2,   17,  7,
      17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,  7,   20,  2,   21,
      7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,   24,  2,
      25,  7,   25,  2,   26,  7,   26,  2,   27,  7,   27,  1,   0,   1,   0,
      5,   0,   59,  8,   0,   10,  0,   12,  0,   62,  9,   0,   1,   0,   1,
      0,   1,   1,   1,   1,   1,   1,   1,   1,   3,   1,   70,  8,   1,   1,
      1,   1,   1,   1,   1,   1,   2,   1,   2,   1,   2,   1,   2,   3,   2,
      79,  8,   2,   1,   2,   1,   2,   1,   3,   1,   3,   1,   3,   5,   3,
      86,  8,   3,   10,  3,   12,  3,   89,  9,   3,   1,   4,   1,   4,   1,
      4,   1,   5,   1,   5,   1,   5,   1,   5,   1,   5,   1,   5,   3,   5,
      100, 8,   5,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   3,   6,
      107, 8,   6,   1,   7,   3,   7,   110, 8,   7,   1,   7,   1,   7,   1,
      8,   1,   8,   1,   8,   5,   8,   117, 8,   8,   10,  8,   12,  8,   120,
      9,   8,   1,   8,   1,   8,   1,   9,   1,   9,   1,   9,   1,   9,   1,
      9,   1,   9,   1,   9,   3,   9,   131, 8,   9,   1,   10,  1,   10,  1,
      10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  1,   10,  3,   10,
      142, 8,   10,  1,   10,  1,   10,  3,   10,  146, 8,   10,  1,   10,  1,
      10,  3,   10,  150, 8,   10,  1,   10,  1,   10,  3,   10,  154, 8,   10,
      1,   11,  1,   11,  3,   11,  158, 8,   11,  1,   11,  1,   11,  1,   12,
      1,   12,  1,   12,  1,   12,  3,   12,  166, 8,   12,  1,   12,  1,   12,
      1,   13,  1,   13,  1,   14,  1,   14,  1,   14,  1,   14,  1,   14,  3,
      14,  177, 8,   14,  1,   15,  1,   15,  1,   15,  1,   15,  1,   15,  1,
      15,  1,   15,  3,   15,  186, 8,   15,  1,   16,  1,   16,  1,   16,  1,
      16,  1,   16,  1,   16,  5,   16,  194, 8,   16,  10,  16,  12,  16,  197,
      9,   16,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  5,
      17,  205, 8,   17,  10,  17,  12,  17,  208, 9,   17,  1,   18,  1,   18,
      1,   18,  1,   18,  1,   18,  1,   18,  1,   18,  1,   18,  1,   18,  5,
      18,  219, 8,   18,  10,  18,  12,  18,  222, 9,   18,  1,   19,  1,   19,
      1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,
      19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  5,   19,  239, 8,
      19,  10,  19,  12,  19,  242, 9,   19,  1,   20,  1,   20,  1,   20,  1,
      20,  1,   20,  1,   20,  1,   20,  1,   20,  1,   20,  5,   20,  253, 8,
      20,  10,  20,  12,  20,  256, 9,   20,  1,   21,  1,   21,  1,   21,  1,
      21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,
      1,   21,  5,   21,  270, 8,   21,  10,  21,  12,  21,  273, 9,   21,  1,
      22,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,
      1,   22,  3,   22,  284, 8,   22,  1,   23,  1,   23,  1,   23,  1,   23,
      1,   23,  1,   23,  1,   23,  1,   23,  3,   23,  294, 8,   23,  1,   23,
      1,   23,  1,   23,  1,   23,  1,   23,  1,   23,  1,   23,  1,   23,  3,
      23,  304, 8,   23,  1,   23,  5,   23,  307, 8,   23,  10,  23,  12,  23,
      310, 9,   23,  1,   24,  1,   24,  1,   24,  1,   24,  1,   24,  1,   24,
      3,   24,  318, 8,   24,  1,   25,  1,   25,  1,   25,  5,   25,  323, 8,
      25,  10,  25,  12,  25,  326, 9,   25,  1,   26,  1,   26,  1,   27,  1,
      27,  1,   27,  0,   7,   32,  34,  36,  38,  40,  42,  46,  28,  0,   2,
      4,   6,   8,   10,  12,  14,  16,  18,  20,  22,  24,  26,  28,  30,  32,
      34,  36,  38,  40,  42,  44,  46,  48,  50,  52,  54,  0,   2,   1,   0,
      44,  46,  2,   0,   3,   3,   39,  43,  352, 0,   60,  1,   0,   0,   0,
      2,   65,  1,   0,   0,   0,   4,   74,  1,   0,   0,   0,   6,   82,  1,
      0,   0,   0,   8,   90,  1,   0,   0,   0,   10,  99,  1,   0,   0,   0,
      12,  106, 1,   0,   0,   0,   14,  109, 1,   0,   0,   0,   16,  113, 1,
      0,   0,   0,   18,  123, 1,   0,   0,   0,   20,  153, 1,   0,   0,   0,
      22,  155, 1,   0,   0,   0,   24,  161, 1,   0,   0,   0,   26,  169, 1,
      0,   0,   0,   28,  176, 1,   0,   0,   0,   30,  185, 1,   0,   0,   0,
      32,  187, 1,   0,   0,   0,   34,  198, 1,   0,   0,   0,   36,  209, 1,
      0,   0,   0,   38,  223, 1,   0,   0,   0,   40,  243, 1,   0,   0,   0,
      42,  257, 1,   0,   0,   0,   44,  283, 1,   0,   0,   0,   46,  293, 1,
      0,   0,   0,   48,  317, 1,   0,   0,   0,   50,  319, 1,   0,   0,   0,
      52,  327, 1,   0,   0,   0,   54,  329, 1,   0,   0,   0,   56,  59,  3,
      2,   1,   0,   57,  59,  3,   4,   2,   0,   58,  56,  1,   0,   0,   0,
      58,  57,  1,   0,   0,   0,   59,  62,  1,   0,   0,   0,   60,  58,  1,
      0,   0,   0,   60,  61,  1,   0,   0,   0,   61,  63,  1,   0,   0,   0,
      62,  60,  1,   0,   0,   0,   63,  64,  5,   0,   0,   1,   64,  1,   1,
      0,   0,   0,   65,  66,  3,   10,  5,   0,   66,  67,  5,   47,  0,   0,
      67,  69,  5,   1,   0,   0,   68,  70,  3,   6,   3,   0,   69,  68,  1,
      0,   0,   0,   69,  70,  1,   0,   0,   0,   70,  71,  1,   0,   0,   0,
      71,  72,  5,   2,   0,   0,   72,  73,  3,   16,  8,   0,   73,  3,   1,
      0,   0,   0,   74,  75,  3,   10,  5,   0,   75,  78,  5,   47,  0,   0,
      76,  77,  5,   3,   0,   0,   77,  79,  3,   26,  13,  0,   78,  76,  1,
      0,   0,   0,   78,  79,  1,   0,   0,   0,   79,  80,  1,   0,   0,   0,
      80,  81,  5,   4,   0,   0,   81,  5,   1,   0,   0,   0,   82,  87,  3,
      8,   4,   0,   83,  84,  5,   5,   0,   0,   84,  86,  3,   8,   4,   0,
      85,  83,  1,   0,   0,   0,   86,  89,  1,   0,   0,   0,   87,  85,  1,
      0,   0,   0,   87,  88,  1,   0,   0,   0,   88,  7,   1,   0,   0,   0,
      89,  87,  1,   0,   0,   0,   90,  91,  3,   10,  5,   0,   91,  92,  5,
      47,  0,   0,   92,  9,   1,   0,   0,   0,   93,  100, 5,   6,   0,   0,
      94,  100, 5,   7,   0,   0,   95,  100, 5,   8,   0,   0,   96,  100, 5,
      9,   0,   0,   97,  98,  5,   10,  0,   0,   98,  100, 3,   10,  5,   0,
      99,  93,  1,   0,   0,   0,   99,  94,  1,   0,   0,   0,   99,  95,  1,
      0,   0,   0,   99,  96,  1,   0,   0,   0,   99,  97,  1,   0,   0,   0,
      100, 11,  1,   0,   0,   0,   101, 107, 3,   14,  7,   0,   102, 107, 3,
      16,  8,   0,   103, 107, 3,   18,  9,   0,   104, 107, 3,   20,  10,  0,
      105, 107, 3,   22,  11,  0,   106, 101, 1,   0,   0,   0,   106, 102, 1,
      0,   0,   0,   106, 103, 1,   0,   0,   0,   106, 104, 1,   0,   0,   0,
      106, 105, 1,   0,   0,   0,   107, 13,  1,   0,   0,   0,   108, 110, 3,
      26,  13,  0,   109, 108, 1,   0,   0,   0,   109, 110, 1,   0,   0,   0,
      110, 111, 1,   0,   0,   0,   111, 112, 5,   4,   0,   0,   112, 15,  1,
      0,   0,   0,   113, 118, 5,   11,  0,   0,   114, 117, 3,   24,  12,  0,
      115, 117, 3,   12,  6,   0,   116, 114, 1,   0,   0,   0,   116, 115, 1,
      0,   0,   0,   117, 120, 1,   0,   0,   0,   118, 116, 1,   0,   0,   0,
      118, 119, 1,   0,   0,   0,   119, 121, 1,   0,   0,   0,   120, 118, 1,
      0,   0,   0,   121, 122, 5,   12,  0,   0,   122, 17,  1,   0,   0,   0,
      123, 124, 5,   13,  0,   0,   124, 125, 5,   1,   0,   0,   125, 126, 3,
      26,  13,  0,   126, 127, 5,   2,   0,   0,   127, 130, 3,   12,  6,   0,
      128, 129, 5,   14,  0,   0,   129, 131, 3,   12,  6,   0,   130, 128, 1,
      0,   0,   0,   130, 131, 1,   0,   0,   0,   131, 19,  1,   0,   0,   0,
      132, 133, 5,   15,  0,   0,   133, 134, 5,   1,   0,   0,   134, 135, 3,
      26,  13,  0,   135, 136, 5,   2,   0,   0,   136, 137, 3,   12,  6,   0,
      137, 154, 1,   0,   0,   0,   138, 139, 5,   16,  0,   0,   139, 141, 5,
      1,   0,   0,   140, 142, 3,   26,  13,  0,   141, 140, 1,   0,   0,   0,
      141, 142, 1,   0,   0,   0,   142, 143, 1,   0,   0,   0,   143, 145, 5,
      4,   0,   0,   144, 146, 3,   26,  13,  0,   145, 144, 1,   0,   0,   0,
      145, 146, 1,   0,   0,   0,   146, 147, 1,   0,   0,   0,   147, 149, 5,
      4,   0,   0,   148, 150, 3,   26,  13,  0,   149, 148, 1,   0,   0,   0,
      149, 150, 1,   0,   0,   0,   150, 151, 1,   0,   0,   0,   151, 152, 5,
      2,   0,   0,   152, 154, 3,   12,  6,   0,   153, 132, 1,   0,   0,   0,
      153, 138, 1,   0,   0,   0,   154, 21,  1,   0,   0,   0,   155, 157, 5,
      17,  0,   0,   156, 158, 3,   26,  13,  0,   157, 156, 1,   0,   0,   0,
      157, 158, 1,   0,   0,   0,   158, 159, 1,   0,   0,   0,   159, 160, 5,
      4,   0,   0,   160, 23,  1,   0,   0,   0,   161, 162, 3,   10,  5,   0,
      162, 165, 5,   47,  0,   0,   163, 164, 5,   3,   0,   0,   164, 166, 3,
      26,  13,  0,   165, 163, 1,   0,   0,   0,   165, 166, 1,   0,   0,   0,
      166, 167, 1,   0,   0,   0,   167, 168, 5,   4,   0,   0,   168, 25,  1,
      0,   0,   0,   169, 170, 3,   28,  14,  0,   170, 27,  1,   0,   0,   0,
      171, 177, 3,   30,  15,  0,   172, 173, 3,   44,  22,  0,   173, 174, 3,
      54,  27,  0,   174, 175, 3,   28,  14,  0,   175, 177, 1,   0,   0,   0,
      176, 171, 1,   0,   0,   0,   176, 172, 1,   0,   0,   0,   177, 29,  1,
      0,   0,   0,   178, 186, 3,   32,  16,  0,   179, 180, 3,   32,  16,  0,
      180, 181, 5,   18,  0,   0,   181, 182, 3,   26,  13,  0,   182, 183, 5,
      19,  0,   0,   183, 184, 3,   30,  15,  0,   184, 186, 1,   0,   0,   0,
      185, 178, 1,   0,   0,   0,   185, 179, 1,   0,   0,   0,   186, 31,  1,
      0,   0,   0,   187, 188, 6,   16,  -1,  0,   188, 189, 3,   34,  17,  0,
      189, 195, 1,   0,   0,   0,   190, 191, 10,  1,   0,   0,   191, 192, 5,
      20,  0,   0,   192, 194, 3,   34,  17,  0,   193, 190, 1,   0,   0,   0,
      194, 197, 1,   0,   0,   0,   195, 193, 1,   0,   0,   0,   195, 196, 1,
      0,   0,   0,   196, 33,  1,   0,   0,   0,   197, 195, 1,   0,   0,   0,
      198, 199, 6,   17,  -1,  0,   199, 200, 3,   36,  18,  0,   200, 206, 1,
      0,   0,   0,   201, 202, 10,  1,   0,   0,   202, 203, 5,   21,  0,   0,
      203, 205, 3,   36,  18,  0,   204, 201, 1,   0,   0,   0,   205, 208, 1,
      0,   0,   0,   206, 204, 1,   0,   0,   0,   206, 207, 1,   0,   0,   0,
      207, 35,  1,   0,   0,   0,   208, 206, 1,   0,   0,   0,   209, 210, 6,
      18,  -1,  0,   210, 211, 3,   38,  19,  0,   211, 220, 1,   0,   0,   0,
      212, 213, 10,  2,   0,   0,   213, 214, 5,   22,  0,   0,   214, 219, 3,
      38,  19,  0,   215, 216, 10,  1,   0,   0,   216, 217, 5,   23,  0,   0,
      217, 219, 3,   38,  19,  0,   218, 212, 1,   0,   0,   0,   218, 215, 1,
      0,   0,   0,   219, 222, 1,   0,   0,   0,   220, 218, 1,   0,   0,   0,
      220, 221, 1,   0,   0,   0,   221, 37,  1,   0,   0,   0,   222, 220, 1,
      0,   0,   0,   223, 224, 6,   19,  -1,  0,   224, 225, 3,   40,  20,  0,
      225, 240, 1,   0,   0,   0,   226, 227, 10,  4,   0,   0,   227, 228, 5,
      24,  0,   0,   228, 239, 3,   40,  20,  0,   229, 230, 10,  3,   0,   0,
      230, 231, 5,   25,  0,   0,   231, 239, 3,   40,  20,  0,   232, 233, 10,
      2,   0,   0,   233, 234, 5,   26,  0,   0,   234, 239, 3,   40,  20,  0,
      235, 236, 10,  1,   0,   0,   236, 237, 5,   27,  0,   0,   237, 239, 3,
      40,  20,  0,   238, 226, 1,   0,   0,   0,   238, 229, 1,   0,   0,   0,
      238, 232, 1,   0,   0,   0,   238, 235, 1,   0,   0,   0,   239, 242, 1,
      0,   0,   0,   240, 238, 1,   0,   0,   0,   240, 241, 1,   0,   0,   0,
      241, 39,  1,   0,   0,   0,   242, 240, 1,   0,   0,   0,   243, 244, 6,
      20,  -1,  0,   244, 245, 3,   42,  21,  0,   245, 254, 1,   0,   0,   0,
      246, 247, 10,  2,   0,   0,   247, 248, 5,   28,  0,   0,   248, 253, 3,
      42,  21,  0,   249, 250, 10,  1,   0,   0,   250, 251, 5,   29,  0,   0,
      251, 253, 3,   42,  21,  0,   252, 246, 1,   0,   0,   0,   252, 249, 1,
      0,   0,   0,   253, 256, 1,   0,   0,   0,   254, 252, 1,   0,   0,   0,
      254, 255, 1,   0,   0,   0,   255, 41,  1,   0,   0,   0,   256, 254, 1,
      0,   0,   0,   257, 258, 6,   21,  -1,  0,   258, 259, 3,   44,  22,  0,
      259, 271, 1,   0,   0,   0,   260, 261, 10,  3,   0,   0,   261, 262, 5,
      30,  0,   0,   262, 270, 3,   44,  22,  0,   263, 264, 10,  2,   0,   0,
      264, 265, 5,   31,  0,   0,   265, 270, 3,   44,  22,  0,   266, 267, 10,
      1,   0,   0,   267, 268, 5,   32,  0,   0,   268, 270, 3,   44,  22,  0,
      269, 260, 1,   0,   0,   0,   269, 263, 1,   0,   0,   0,   269, 266, 1,
      0,   0,   0,   270, 273, 1,   0,   0,   0,   271, 269, 1,   0,   0,   0,
      271, 272, 1,   0,   0,   0,   272, 43,  1,   0,   0,   0,   273, 271, 1,
      0,   0,   0,   274, 284, 3,   46,  23,  0,   275, 276, 5,   33,  0,   0,
      276, 284, 3,   44,  22,  0,   277, 278, 5,   29,  0,   0,   278, 284, 3,
      44,  22,  0,   279, 280, 5,   34,  0,   0,   280, 284, 3,   44,  22,  0,
      281, 282, 5,   35,  0,   0,   282, 284, 3,   44,  22,  0,   283, 274, 1,
      0,   0,   0,   283, 275, 1,   0,   0,   0,   283, 277, 1,   0,   0,   0,
      283, 279, 1,   0,   0,   0,   283, 281, 1,   0,   0,   0,   284, 45,  1,
      0,   0,   0,   285, 286, 6,   23,  -1,  0,   286, 294, 3,   48,  24,  0,
      287, 288, 5,   47,  0,   0,   288, 289, 5,   38,  0,   0,   289, 290, 5,
      1,   0,   0,   290, 291, 3,   26,  13,  0,   291, 292, 5,   2,   0,   0,
      292, 294, 1,   0,   0,   0,   293, 285, 1,   0,   0,   0,   293, 287, 1,
      0,   0,   0,   294, 308, 1,   0,   0,   0,   295, 296, 10,  3,   0,   0,
      296, 297, 5,   36,  0,   0,   297, 298, 3,   26,  13,  0,   298, 299, 5,
      37,  0,   0,   299, 307, 1,   0,   0,   0,   300, 301, 10,  2,   0,   0,
      301, 303, 5,   1,   0,   0,   302, 304, 3,   50,  25,  0,   303, 302, 1,
      0,   0,   0,   303, 304, 1,   0,   0,   0,   304, 305, 1,   0,   0,   0,
      305, 307, 5,   2,   0,   0,   306, 295, 1,   0,   0,   0,   306, 300, 1,
      0,   0,   0,   307, 310, 1,   0,   0,   0,   308, 306, 1,   0,   0,   0,
      308, 309, 1,   0,   0,   0,   309, 47,  1,   0,   0,   0,   310, 308, 1,
      0,   0,   0,   311, 318, 5,   47,  0,   0,   312, 318, 3,   52,  26,  0,
      313, 314, 5,   1,   0,   0,   314, 315, 3,   26,  13,  0,   315, 316, 5,
      2,   0,   0,   316, 318, 1,   0,   0,   0,   317, 311, 1,   0,   0,   0,
      317, 312, 1,   0,   0,   0,   317, 313, 1,   0,   0,   0,   318, 49,  1,
      0,   0,   0,   319, 324, 3,   26,  13,  0,   320, 321, 5,   5,   0,   0,
      321, 323, 3,   26,  13,  0,   322, 320, 1,   0,   0,   0,   323, 326, 1,
      0,   0,   0,   324, 322, 1,   0,   0,   0,   324, 325, 1,   0,   0,   0,
      325, 51,  1,   0,   0,   0,   326, 324, 1,   0,   0,   0,   327, 328, 7,
      0,   0,   0,   328, 53,  1,   0,   0,   0,   329, 330, 7,   1,   0,   0,
      330, 55,  1,   0,   0,   0,   36,  58,  60,  69,  78,  87,  99,  106, 109,
      116, 118, 130, 141, 145, 149, 153, 157, 165, 176, 185, 195, 206, 218, 220,
      238, 240, 252, 254, 269, 271, 283, 293, 303, 306, 308, 317, 324};
  staticData->serializedATN = antlr4::atn::SerializedATNView(
      serializedATNSegment,
      sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i),
                                           i);
  }
  fianchettoParserStaticData = staticData.release();
}

} // namespace

FianchettoParser::FianchettoParser(TokenStream *input)
    : FianchettoParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FianchettoParser::FianchettoParser(
    TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options)
    : Parser(input) {
  FianchettoParser::initialize();
  _interpreter = new atn::ParserATNSimulator(
      this, *fianchettoParserStaticData->atn,
      fianchettoParserStaticData->decisionToDFA,
      fianchettoParserStaticData->sharedContextCache, options);
}

FianchettoParser::~FianchettoParser() { delete _interpreter; }

const atn::ATN &FianchettoParser::getATN() const {
  return *fianchettoParserStaticData->atn;
}

std::string FianchettoParser::getGrammarFileName() const {
  return "Fianchetto.g4";
}

const std::vector<std::string> &FianchettoParser::getRuleNames() const {
  return fianchettoParserStaticData->ruleNames;
}

const dfa::Vocabulary &FianchettoParser::getVocabulary() const {
  return fianchettoParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FianchettoParser::getSerializedATN() const {
  return fianchettoParserStaticData->serializedATN;
}

//----------------- ProgramContext
//------------------------------------------------------------------

FianchettoParser::ProgramContext::ProgramContext(ParserRuleContext *parent,
                                                 size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *FianchettoParser::ProgramContext::EOF() {
  return getToken(FianchettoParser::EOF, 0);
}

std::vector<FianchettoParser::FunctionDefinitionContext *>
FianchettoParser::ProgramContext::functionDefinition() {
  return getRuleContexts<FianchettoParser::FunctionDefinitionContext>();
}

FianchettoParser::FunctionDefinitionContext *
FianchettoParser::ProgramContext::functionDefinition(size_t i) {
  return getRuleContext<FianchettoParser::FunctionDefinitionContext>(i);
}

std::vector<FianchettoParser::GlobalDeclarationContext *>
FianchettoParser::ProgramContext::globalDeclaration() {
  return getRuleContexts<FianchettoParser::GlobalDeclarationContext>();
}

FianchettoParser::GlobalDeclarationContext *
FianchettoParser::ProgramContext::globalDeclaration(size_t i) {
  return getRuleContext<FianchettoParser::GlobalDeclarationContext>(i);
}

size_t FianchettoParser::ProgramContext::getRuleIndex() const {
  return FianchettoParser::RuleProgram;
}

void FianchettoParser::ProgramContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void FianchettoParser::ProgramContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

FianchettoParser::ProgramContext *FianchettoParser::program() {
  ProgramContext *_localctx =
      _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, FianchettoParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (
        (((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) &
          ((1ULL << FianchettoParser::T__5) | (1ULL << FianchettoParser::T__6) |
           (1ULL << FianchettoParser::T__7) | (1ULL << FianchettoParser::T__8) |
           (1ULL << FianchettoParser::T__9))) != 0)) {
      setState(58);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 0, _ctx)) {
      case 1: {
        setState(56);
        functionDefinition();
        break;
      }

      case 2: {
        setState(57);
        globalDeclaration();
        break;
      }

      default:
        break;
      }
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    match(FianchettoParser::EOF);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext
//------------------------------------------------------------------

FianchettoParser::FunctionDefinitionContext::FunctionDefinitionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::TypeSpecifierContext *
FianchettoParser::FunctionDefinitionContext::typeSpecifier() {
  return getRuleContext<FianchettoParser::TypeSpecifierContext>(0);
}

tree::TerminalNode *FianchettoParser::FunctionDefinitionContext::IDENTIFIER() {
  return getToken(FianchettoParser::IDENTIFIER, 0);
}

FianchettoParser::CompoundStatementContext *
FianchettoParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<FianchettoParser::CompoundStatementContext>(0);
}

FianchettoParser::ParameterListContext *
FianchettoParser::FunctionDefinitionContext::parameterList() {
  return getRuleContext<FianchettoParser::ParameterListContext>(0);
}

size_t FianchettoParser::FunctionDefinitionContext::getRuleIndex() const {
  return FianchettoParser::RuleFunctionDefinition;
}

void FianchettoParser::FunctionDefinitionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void FianchettoParser::FunctionDefinitionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}

FianchettoParser::FunctionDefinitionContext *
FianchettoParser::functionDefinition() {
  FunctionDefinitionContext *_localctx =
      _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 2, FianchettoParser::RuleFunctionDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    typeSpecifier();
    setState(66);
    match(FianchettoParser::IDENTIFIER);
    setState(67);
    match(FianchettoParser::T__0);
    setState(69);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) &
          ((1ULL << FianchettoParser::T__5) | (1ULL << FianchettoParser::T__6) |
           (1ULL << FianchettoParser::T__7) | (1ULL << FianchettoParser::T__8) |
           (1ULL << FianchettoParser::T__9))) != 0)) {
      setState(68);
      parameterList();
    }
    setState(71);
    match(FianchettoParser::T__1);
    setState(72);
    compoundStatement();

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalDeclarationContext
//------------------------------------------------------------------

FianchettoParser::GlobalDeclarationContext::GlobalDeclarationContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::TypeSpecifierContext *
FianchettoParser::GlobalDeclarationContext::typeSpecifier() {
  return getRuleContext<FianchettoParser::TypeSpecifierContext>(0);
}

tree::TerminalNode *FianchettoParser::GlobalDeclarationContext::IDENTIFIER() {
  return getToken(FianchettoParser::IDENTIFIER, 0);
}

FianchettoParser::ExpressionContext *
FianchettoParser::GlobalDeclarationContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

size_t FianchettoParser::GlobalDeclarationContext::getRuleIndex() const {
  return FianchettoParser::RuleGlobalDeclaration;
}

void FianchettoParser::GlobalDeclarationContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalDeclaration(this);
}

void FianchettoParser::GlobalDeclarationContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalDeclaration(this);
}

FianchettoParser::GlobalDeclarationContext *
FianchettoParser::globalDeclaration() {
  GlobalDeclarationContext *_localctx =
      _tracker.createInstance<GlobalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, FianchettoParser::RuleGlobalDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    typeSpecifier();
    setState(75);
    match(FianchettoParser::IDENTIFIER);
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FianchettoParser::T__2) {
      setState(76);
      match(FianchettoParser::T__2);
      setState(77);
      expression();
    }
    setState(80);
    match(FianchettoParser::T__3);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext
//------------------------------------------------------------------

FianchettoParser::ParameterListContext::ParameterListContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<FianchettoParser::ParameterContext *>
FianchettoParser::ParameterListContext::parameter() {
  return getRuleContexts<FianchettoParser::ParameterContext>();
}

FianchettoParser::ParameterContext *
FianchettoParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<FianchettoParser::ParameterContext>(i);
}

size_t FianchettoParser::ParameterListContext::getRuleIndex() const {
  return FianchettoParser::RuleParameterList;
}

void FianchettoParser::ParameterListContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void FianchettoParser::ParameterListContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}

FianchettoParser::ParameterListContext *FianchettoParser::parameterList() {
  ParameterListContext *_localctx =
      _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 6, FianchettoParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    parameter();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FianchettoParser::T__4) {
      setState(83);
      match(FianchettoParser::T__4);
      setState(84);
      parameter();
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext
//------------------------------------------------------------------

FianchettoParser::ParameterContext::ParameterContext(ParserRuleContext *parent,
                                                     size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::TypeSpecifierContext *
FianchettoParser::ParameterContext::typeSpecifier() {
  return getRuleContext<FianchettoParser::TypeSpecifierContext>(0);
}

tree::TerminalNode *FianchettoParser::ParameterContext::IDENTIFIER() {
  return getToken(FianchettoParser::IDENTIFIER, 0);
}

size_t FianchettoParser::ParameterContext::getRuleIndex() const {
  return FianchettoParser::RuleParameter;
}

void FianchettoParser::ParameterContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void FianchettoParser::ParameterContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

FianchettoParser::ParameterContext *FianchettoParser::parameter() {
  ParameterContext *_localctx =
      _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 8, FianchettoParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    typeSpecifier();
    setState(91);
    match(FianchettoParser::IDENTIFIER);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext
//------------------------------------------------------------------

FianchettoParser::TypeSpecifierContext::TypeSpecifierContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::TypeSpecifierContext *
FianchettoParser::TypeSpecifierContext::typeSpecifier() {
  return getRuleContext<FianchettoParser::TypeSpecifierContext>(0);
}

size_t FianchettoParser::TypeSpecifierContext::getRuleIndex() const {
  return FianchettoParser::RuleTypeSpecifier;
}

void FianchettoParser::TypeSpecifierContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void FianchettoParser::TypeSpecifierContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}

FianchettoParser::TypeSpecifierContext *FianchettoParser::typeSpecifier() {
  TypeSpecifierContext *_localctx =
      _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 10, FianchettoParser::RuleTypeSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
    case FianchettoParser::T__5: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      match(FianchettoParser::T__5);
      break;
    }

    case FianchettoParser::T__6: {
      enterOuterAlt(_localctx, 2);
      setState(94);
      match(FianchettoParser::T__6);
      break;
    }

    case FianchettoParser::T__7: {
      enterOuterAlt(_localctx, 3);
      setState(95);
      match(FianchettoParser::T__7);
      break;
    }

    case FianchettoParser::T__8: {
      enterOuterAlt(_localctx, 4);
      setState(96);
      match(FianchettoParser::T__8);
      break;
    }

    case FianchettoParser::T__9: {
      enterOuterAlt(_localctx, 5);
      setState(97);
      match(FianchettoParser::T__9);
      setState(98);
      typeSpecifier();
      break;
    }

    default:
      throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext
//------------------------------------------------------------------

FianchettoParser::StatementContext::StatementContext(ParserRuleContext *parent,
                                                     size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::ExpressionStatementContext *
FianchettoParser::StatementContext::expressionStatement() {
  return getRuleContext<FianchettoParser::ExpressionStatementContext>(0);
}

FianchettoParser::CompoundStatementContext *
FianchettoParser::StatementContext::compoundStatement() {
  return getRuleContext<FianchettoParser::CompoundStatementContext>(0);
}

FianchettoParser::SelectionStatementContext *
FianchettoParser::StatementContext::selectionStatement() {
  return getRuleContext<FianchettoParser::SelectionStatementContext>(0);
}

FianchettoParser::IterationStatementContext *
FianchettoParser::StatementContext::iterationStatement() {
  return getRuleContext<FianchettoParser::IterationStatementContext>(0);
}

FianchettoParser::JumpStatementContext *
FianchettoParser::StatementContext::jumpStatement() {
  return getRuleContext<FianchettoParser::JumpStatementContext>(0);
}

size_t FianchettoParser::StatementContext::getRuleIndex() const {
  return FianchettoParser::RuleStatement;
}

void FianchettoParser::StatementContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void FianchettoParser::StatementContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

FianchettoParser::StatementContext *FianchettoParser::statement() {
  StatementContext *_localctx =
      _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, FianchettoParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
    case FianchettoParser::T__0:
    case FianchettoParser::T__3:
    case FianchettoParser::T__28:
    case FianchettoParser::T__32:
    case FianchettoParser::T__33:
    case FianchettoParser::T__34:
    case FianchettoParser::INTEGER_LITERAL:
    case FianchettoParser::FLOAT_LITERAL:
    case FianchettoParser::STRING_LITERAL:
    case FianchettoParser::IDENTIFIER: {
      enterOuterAlt(_localctx, 1);
      setState(101);
      expressionStatement();
      break;
    }

    case FianchettoParser::T__10: {
      enterOuterAlt(_localctx, 2);
      setState(102);
      compoundStatement();
      break;
    }

    case FianchettoParser::T__12: {
      enterOuterAlt(_localctx, 3);
      setState(103);
      selectionStatement();
      break;
    }

    case FianchettoParser::T__14:
    case FianchettoParser::T__15: {
      enterOuterAlt(_localctx, 4);
      setState(104);
      iterationStatement();
      break;
    }

    case FianchettoParser::T__16: {
      enterOuterAlt(_localctx, 5);
      setState(105);
      jumpStatement();
      break;
    }

    default:
      throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext
//------------------------------------------------------------------

FianchettoParser::ExpressionStatementContext::ExpressionStatementContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::ExpressionContext *
FianchettoParser::ExpressionStatementContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

size_t FianchettoParser::ExpressionStatementContext::getRuleIndex() const {
  return FianchettoParser::RuleExpressionStatement;
}

void FianchettoParser::ExpressionStatementContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void FianchettoParser::ExpressionStatementContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}

FianchettoParser::ExpressionStatementContext *
FianchettoParser::expressionStatement() {
  ExpressionStatementContext *_localctx =
      _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, FianchettoParser::RuleExpressionStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) & ((1ULL << FianchettoParser::T__0) |
                           (1ULL << FianchettoParser::T__28) |
                           (1ULL << FianchettoParser::T__32) |
                           (1ULL << FianchettoParser::T__33) |
                           (1ULL << FianchettoParser::T__34) |
                           (1ULL << FianchettoParser::INTEGER_LITERAL) |
                           (1ULL << FianchettoParser::FLOAT_LITERAL) |
                           (1ULL << FianchettoParser::STRING_LITERAL) |
                           (1ULL << FianchettoParser::IDENTIFIER))) != 0)) {
      setState(108);
      expression();
    }
    setState(111);
    match(FianchettoParser::T__3);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext
//------------------------------------------------------------------

FianchettoParser::CompoundStatementContext::CompoundStatementContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<FianchettoParser::DeclarationContext *>
FianchettoParser::CompoundStatementContext::declaration() {
  return getRuleContexts<FianchettoParser::DeclarationContext>();
}

FianchettoParser::DeclarationContext *
FianchettoParser::CompoundStatementContext::declaration(size_t i) {
  return getRuleContext<FianchettoParser::DeclarationContext>(i);
}

std::vector<FianchettoParser::StatementContext *>
FianchettoParser::CompoundStatementContext::statement() {
  return getRuleContexts<FianchettoParser::StatementContext>();
}

FianchettoParser::StatementContext *
FianchettoParser::CompoundStatementContext::statement(size_t i) {
  return getRuleContext<FianchettoParser::StatementContext>(i);
}

size_t FianchettoParser::CompoundStatementContext::getRuleIndex() const {
  return FianchettoParser::RuleCompoundStatement;
}

void FianchettoParser::CompoundStatementContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void FianchettoParser::CompoundStatementContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}

FianchettoParser::CompoundStatementContext *
FianchettoParser::compoundStatement() {
  CompoundStatementContext *_localctx =
      _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, FianchettoParser::RuleCompoundStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(FianchettoParser::T__10);
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((
        ((_la & ~0x3fULL) == 0) &&
        ((1ULL << _la) &
         ((1ULL << FianchettoParser::T__0) | (1ULL << FianchettoParser::T__3) |
          (1ULL << FianchettoParser::T__5) | (1ULL << FianchettoParser::T__6) |
          (1ULL << FianchettoParser::T__7) | (1ULL << FianchettoParser::T__8) |
          (1ULL << FianchettoParser::T__9) | (1ULL << FianchettoParser::T__10) |
          (1ULL << FianchettoParser::T__12) |
          (1ULL << FianchettoParser::T__14) |
          (1ULL << FianchettoParser::T__15) |
          (1ULL << FianchettoParser::T__16) |
          (1ULL << FianchettoParser::T__28) |
          (1ULL << FianchettoParser::T__32) |
          (1ULL << FianchettoParser::T__33) |
          (1ULL << FianchettoParser::T__34) |
          (1ULL << FianchettoParser::INTEGER_LITERAL) |
          (1ULL << FianchettoParser::FLOAT_LITERAL) |
          (1ULL << FianchettoParser::STRING_LITERAL) |
          (1ULL << FianchettoParser::IDENTIFIER))) != 0)) {
      setState(116);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
      case FianchettoParser::T__5:
      case FianchettoParser::T__6:
      case FianchettoParser::T__7:
      case FianchettoParser::T__8:
      case FianchettoParser::T__9: {
        setState(114);
        declaration();
        break;
      }

      case FianchettoParser::T__0:
      case FianchettoParser::T__3:
      case FianchettoParser::T__10:
      case FianchettoParser::T__12:
      case FianchettoParser::T__14:
      case FianchettoParser::T__15:
      case FianchettoParser::T__16:
      case FianchettoParser::T__28:
      case FianchettoParser::T__32:
      case FianchettoParser::T__33:
      case FianchettoParser::T__34:
      case FianchettoParser::INTEGER_LITERAL:
      case FianchettoParser::FLOAT_LITERAL:
      case FianchettoParser::STRING_LITERAL:
      case FianchettoParser::IDENTIFIER: {
        setState(115);
        statement();
        break;
      }

      default:
        throw NoViableAltException(this);
      }
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(121);
    match(FianchettoParser::T__11);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext
//------------------------------------------------------------------

FianchettoParser::SelectionStatementContext::SelectionStatementContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::ExpressionContext *
FianchettoParser::SelectionStatementContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

std::vector<FianchettoParser::StatementContext *>
FianchettoParser::SelectionStatementContext::statement() {
  return getRuleContexts<FianchettoParser::StatementContext>();
}

FianchettoParser::StatementContext *
FianchettoParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<FianchettoParser::StatementContext>(i);
}

size_t FianchettoParser::SelectionStatementContext::getRuleIndex() const {
  return FianchettoParser::RuleSelectionStatement;
}

void FianchettoParser::SelectionStatementContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void FianchettoParser::SelectionStatementContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}

FianchettoParser::SelectionStatementContext *
FianchettoParser::selectionStatement() {
  SelectionStatementContext *_localctx =
      _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, FianchettoParser::RuleSelectionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(FianchettoParser::T__12);
    setState(124);
    match(FianchettoParser::T__0);
    setState(125);
    expression();
    setState(126);
    match(FianchettoParser::T__1);
    setState(127);
    statement();
    setState(130);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
        _input, 10, _ctx)) {
    case 1: {
      setState(128);
      match(FianchettoParser::T__13);
      setState(129);
      statement();
      break;
    }

    default:
      break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext
//------------------------------------------------------------------

FianchettoParser::IterationStatementContext::IterationStatementContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<FianchettoParser::ExpressionContext *>
FianchettoParser::IterationStatementContext::expression() {
  return getRuleContexts<FianchettoParser::ExpressionContext>();
}

FianchettoParser::ExpressionContext *
FianchettoParser::IterationStatementContext::expression(size_t i) {
  return getRuleContext<FianchettoParser::ExpressionContext>(i);
}

FianchettoParser::StatementContext *
FianchettoParser::IterationStatementContext::statement() {
  return getRuleContext<FianchettoParser::StatementContext>(0);
}

size_t FianchettoParser::IterationStatementContext::getRuleIndex() const {
  return FianchettoParser::RuleIterationStatement;
}

void FianchettoParser::IterationStatementContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void FianchettoParser::IterationStatementContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}

FianchettoParser::IterationStatementContext *
FianchettoParser::iterationStatement() {
  IterationStatementContext *_localctx =
      _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, FianchettoParser::RuleIterationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
    case FianchettoParser::T__14: {
      enterOuterAlt(_localctx, 1);
      setState(132);
      match(FianchettoParser::T__14);
      setState(133);
      match(FianchettoParser::T__0);
      setState(134);
      expression();
      setState(135);
      match(FianchettoParser::T__1);
      setState(136);
      statement();
      break;
    }

    case FianchettoParser::T__15: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      match(FianchettoParser::T__15);
      setState(139);
      match(FianchettoParser::T__0);
      setState(141);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << FianchettoParser::T__0) |
                             (1ULL << FianchettoParser::T__28) |
                             (1ULL << FianchettoParser::T__32) |
                             (1ULL << FianchettoParser::T__33) |
                             (1ULL << FianchettoParser::T__34) |
                             (1ULL << FianchettoParser::INTEGER_LITERAL) |
                             (1ULL << FianchettoParser::FLOAT_LITERAL) |
                             (1ULL << FianchettoParser::STRING_LITERAL) |
                             (1ULL << FianchettoParser::IDENTIFIER))) != 0)) {
        setState(140);
        expression();
      }
      setState(143);
      match(FianchettoParser::T__3);
      setState(145);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << FianchettoParser::T__0) |
                             (1ULL << FianchettoParser::T__28) |
                             (1ULL << FianchettoParser::T__32) |
                             (1ULL << FianchettoParser::T__33) |
                             (1ULL << FianchettoParser::T__34) |
                             (1ULL << FianchettoParser::INTEGER_LITERAL) |
                             (1ULL << FianchettoParser::FLOAT_LITERAL) |
                             (1ULL << FianchettoParser::STRING_LITERAL) |
                             (1ULL << FianchettoParser::IDENTIFIER))) != 0)) {
        setState(144);
        expression();
      }
      setState(147);
      match(FianchettoParser::T__3);
      setState(149);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << FianchettoParser::T__0) |
                             (1ULL << FianchettoParser::T__28) |
                             (1ULL << FianchettoParser::T__32) |
                             (1ULL << FianchettoParser::T__33) |
                             (1ULL << FianchettoParser::T__34) |
                             (1ULL << FianchettoParser::INTEGER_LITERAL) |
                             (1ULL << FianchettoParser::FLOAT_LITERAL) |
                             (1ULL << FianchettoParser::STRING_LITERAL) |
                             (1ULL << FianchettoParser::IDENTIFIER))) != 0)) {
        setState(148);
        expression();
      }
      setState(151);
      match(FianchettoParser::T__1);
      setState(152);
      statement();
      break;
    }

    default:
      throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpStatementContext
//------------------------------------------------------------------

FianchettoParser::JumpStatementContext::JumpStatementContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::ExpressionContext *
FianchettoParser::JumpStatementContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

size_t FianchettoParser::JumpStatementContext::getRuleIndex() const {
  return FianchettoParser::RuleJumpStatement;
}

void FianchettoParser::JumpStatementContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void FianchettoParser::JumpStatementContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}

FianchettoParser::JumpStatementContext *FianchettoParser::jumpStatement() {
  JumpStatementContext *_localctx =
      _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, FianchettoParser::RuleJumpStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(FianchettoParser::T__16);
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) & ((1ULL << FianchettoParser::T__0) |
                           (1ULL << FianchettoParser::T__28) |
                           (1ULL << FianchettoParser::T__32) |
                           (1ULL << FianchettoParser::T__33) |
                           (1ULL << FianchettoParser::T__34) |
                           (1ULL << FianchettoParser::INTEGER_LITERAL) |
                           (1ULL << FianchettoParser::FLOAT_LITERAL) |
                           (1ULL << FianchettoParser::STRING_LITERAL) |
                           (1ULL << FianchettoParser::IDENTIFIER))) != 0)) {
      setState(156);
      expression();
    }
    setState(159);
    match(FianchettoParser::T__3);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext
//------------------------------------------------------------------

FianchettoParser::DeclarationContext::DeclarationContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::TypeSpecifierContext *
FianchettoParser::DeclarationContext::typeSpecifier() {
  return getRuleContext<FianchettoParser::TypeSpecifierContext>(0);
}

tree::TerminalNode *FianchettoParser::DeclarationContext::IDENTIFIER() {
  return getToken(FianchettoParser::IDENTIFIER, 0);
}

FianchettoParser::ExpressionContext *
FianchettoParser::DeclarationContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

size_t FianchettoParser::DeclarationContext::getRuleIndex() const {
  return FianchettoParser::RuleDeclaration;
}

void FianchettoParser::DeclarationContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void FianchettoParser::DeclarationContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

FianchettoParser::DeclarationContext *FianchettoParser::declaration() {
  DeclarationContext *_localctx =
      _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 24, FianchettoParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    typeSpecifier();
    setState(162);
    match(FianchettoParser::IDENTIFIER);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FianchettoParser::T__2) {
      setState(163);
      match(FianchettoParser::T__2);
      setState(164);
      expression();
    }
    setState(167);
    match(FianchettoParser::T__3);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext
//------------------------------------------------------------------

FianchettoParser::ExpressionContext::ExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::AssignmentExpressionContext *
FianchettoParser::ExpressionContext::assignmentExpression() {
  return getRuleContext<FianchettoParser::AssignmentExpressionContext>(0);
}

size_t FianchettoParser::ExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleExpression;
}

void FianchettoParser::ExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void FianchettoParser::ExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

FianchettoParser::ExpressionContext *FianchettoParser::expression() {
  ExpressionContext *_localctx =
      _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 26, FianchettoParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    assignmentExpression();

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentExpressionContext
//------------------------------------------------------------------

FianchettoParser::AssignmentExpressionContext::AssignmentExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::ConditionalExpressionContext *
FianchettoParser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<FianchettoParser::ConditionalExpressionContext>(0);
}

FianchettoParser::UnaryExpressionContext *
FianchettoParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<FianchettoParser::UnaryExpressionContext>(0);
}

FianchettoParser::AssignmentOperatorContext *
FianchettoParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<FianchettoParser::AssignmentOperatorContext>(0);
}

FianchettoParser::AssignmentExpressionContext *
FianchettoParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<FianchettoParser::AssignmentExpressionContext>(0);
}

size_t FianchettoParser::AssignmentExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleAssignmentExpression;
}

void FianchettoParser::AssignmentExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void FianchettoParser::AssignmentExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}

FianchettoParser::AssignmentExpressionContext *
FianchettoParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx =
      _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, FianchettoParser::RuleAssignmentExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(176);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
        _input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(172);
      unaryExpression();
      setState(173);
      assignmentOperator();
      setState(174);
      assignmentExpression();
      break;
    }

    default:
      break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalExpressionContext
//------------------------------------------------------------------

FianchettoParser::ConditionalExpressionContext::ConditionalExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::LogicalOrExpressionContext *
FianchettoParser::ConditionalExpressionContext::logicalOrExpression() {
  return getRuleContext<FianchettoParser::LogicalOrExpressionContext>(0);
}

FianchettoParser::ExpressionContext *
FianchettoParser::ConditionalExpressionContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

FianchettoParser::ConditionalExpressionContext *
FianchettoParser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<FianchettoParser::ConditionalExpressionContext>(0);
}

size_t FianchettoParser::ConditionalExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleConditionalExpression;
}

void FianchettoParser::ConditionalExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalExpression(this);
}

void FianchettoParser::ConditionalExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalExpression(this);
}

FianchettoParser::ConditionalExpressionContext *
FianchettoParser::conditionalExpression() {
  ConditionalExpressionContext *_localctx =
      _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, FianchettoParser::RuleConditionalExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
        _input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(178);
      logicalOrExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(179);
      logicalOrExpression(0);
      setState(180);
      match(FianchettoParser::T__17);
      setState(181);
      expression();
      setState(182);
      match(FianchettoParser::T__18);
      setState(183);
      conditionalExpression();
      break;
    }

    default:
      break;
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOrExpressionContext
//------------------------------------------------------------------

FianchettoParser::LogicalOrExpressionContext::LogicalOrExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::LogicalAndExpressionContext *
FianchettoParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContext<FianchettoParser::LogicalAndExpressionContext>(0);
}

FianchettoParser::LogicalOrExpressionContext *
FianchettoParser::LogicalOrExpressionContext::logicalOrExpression() {
  return getRuleContext<FianchettoParser::LogicalOrExpressionContext>(0);
}

size_t FianchettoParser::LogicalOrExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleLogicalOrExpression;
}

void FianchettoParser::LogicalOrExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}

void FianchettoParser::LogicalOrExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}

FianchettoParser::LogicalOrExpressionContext *
FianchettoParser::logicalOrExpression() {
  return logicalOrExpression(0);
}

FianchettoParser::LogicalOrExpressionContext *
FianchettoParser::logicalOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FianchettoParser::LogicalOrExpressionContext *_localctx =
      _tracker.createInstance<LogicalOrExpressionContext>(_ctx, parentState);
  FianchettoParser::LogicalOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by
                         // generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, FianchettoParser::RuleLogicalOrExpression,
                     precedence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(188);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(195);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(
            parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(190);

        if (!(precpred(_ctx, 1)))
          throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(191);
        match(FianchettoParser::T__19);
        setState(192);
        logicalAndExpression(0);
      }
      setState(197);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 19, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext
//------------------------------------------------------------------

FianchettoParser::LogicalAndExpressionContext::LogicalAndExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::EqualityExpressionContext *
FianchettoParser::LogicalAndExpressionContext::equalityExpression() {
  return getRuleContext<FianchettoParser::EqualityExpressionContext>(0);
}

FianchettoParser::LogicalAndExpressionContext *
FianchettoParser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<FianchettoParser::LogicalAndExpressionContext>(0);
}

size_t FianchettoParser::LogicalAndExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleLogicalAndExpression;
}

void FianchettoParser::LogicalAndExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void FianchettoParser::LogicalAndExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}

FianchettoParser::LogicalAndExpressionContext *
FianchettoParser::logicalAndExpression() {
  return logicalAndExpression(0);
}

FianchettoParser::LogicalAndExpressionContext *
FianchettoParser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FianchettoParser::LogicalAndExpressionContext *_localctx =
      _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  FianchettoParser::LogicalAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by
                         // generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, FianchettoParser::RuleLogicalAndExpression,
                     precedence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(199);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(206);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(
            parentContext, parentState);
        pushNewRecursionContext(_localctx, startState,
                                RuleLogicalAndExpression);
        setState(201);

        if (!(precpred(_ctx, 1)))
          throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(202);
        match(FianchettoParser::T__20);
        setState(203);
        equalityExpression(0);
      }
      setState(208);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 20, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext
//------------------------------------------------------------------

FianchettoParser::EqualityExpressionContext::EqualityExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::RelationalExpressionContext *
FianchettoParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<FianchettoParser::RelationalExpressionContext>(0);
}

FianchettoParser::EqualityExpressionContext *
FianchettoParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<FianchettoParser::EqualityExpressionContext>(0);
}

size_t FianchettoParser::EqualityExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleEqualityExpression;
}

void FianchettoParser::EqualityExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void FianchettoParser::EqualityExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}

FianchettoParser::EqualityExpressionContext *
FianchettoParser::equalityExpression() {
  return equalityExpression(0);
}

FianchettoParser::EqualityExpressionContext *
FianchettoParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FianchettoParser::EqualityExpressionContext *_localctx =
      _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  FianchettoParser::EqualityExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by
                         // generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, FianchettoParser::RuleEqualityExpression,
                     precedence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(210);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(220);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(218);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleEqualityExpression);
          setState(212);

          if (!(precpred(_ctx, 2)))
            throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(213);
          match(FianchettoParser::T__21);
          setState(214);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleEqualityExpression);
          setState(215);

          if (!(precpred(_ctx, 1)))
            throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(216);
          match(FianchettoParser::T__22);
          setState(217);
          relationalExpression(0);
          break;
        }

        default:
          break;
        }
      }
      setState(222);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 22, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationalExpressionContext
//------------------------------------------------------------------

FianchettoParser::RelationalExpressionContext::RelationalExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::AdditiveExpressionContext *
FianchettoParser::RelationalExpressionContext::additiveExpression() {
  return getRuleContext<FianchettoParser::AdditiveExpressionContext>(0);
}

FianchettoParser::RelationalExpressionContext *
FianchettoParser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<FianchettoParser::RelationalExpressionContext>(0);
}

size_t FianchettoParser::RelationalExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleRelationalExpression;
}

void FianchettoParser::RelationalExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void FianchettoParser::RelationalExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}

FianchettoParser::RelationalExpressionContext *
FianchettoParser::relationalExpression() {
  return relationalExpression(0);
}

FianchettoParser::RelationalExpressionContext *
FianchettoParser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FianchettoParser::RelationalExpressionContext *_localctx =
      _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  FianchettoParser::RelationalExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by
                         // generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, FianchettoParser::RuleRelationalExpression,
                     precedence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(224);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(238);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 23, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleRelationalExpression);
          setState(226);

          if (!(precpred(_ctx, 4)))
            throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(227);
          match(FianchettoParser::T__23);
          setState(228);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleRelationalExpression);
          setState(229);

          if (!(precpred(_ctx, 3)))
            throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(230);
          match(FianchettoParser::T__24);
          setState(231);
          additiveExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleRelationalExpression);
          setState(232);

          if (!(precpred(_ctx, 2)))
            throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(233);
          match(FianchettoParser::T__25);
          setState(234);
          additiveExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleRelationalExpression);
          setState(235);

          if (!(precpred(_ctx, 1)))
            throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(236);
          match(FianchettoParser::T__26);
          setState(237);
          additiveExpression(0);
          break;
        }

        default:
          break;
        }
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 24, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext
//------------------------------------------------------------------

FianchettoParser::AdditiveExpressionContext::AdditiveExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::MultiplicativeExpressionContext *
FianchettoParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<FianchettoParser::MultiplicativeExpressionContext>(0);
}

FianchettoParser::AdditiveExpressionContext *
FianchettoParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<FianchettoParser::AdditiveExpressionContext>(0);
}

size_t FianchettoParser::AdditiveExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleAdditiveExpression;
}

void FianchettoParser::AdditiveExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void FianchettoParser::AdditiveExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}

FianchettoParser::AdditiveExpressionContext *
FianchettoParser::additiveExpression() {
  return additiveExpression(0);
}

FianchettoParser::AdditiveExpressionContext *
FianchettoParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FianchettoParser::AdditiveExpressionContext *_localctx =
      _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  FianchettoParser::AdditiveExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by
                         // generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, FianchettoParser::RuleAdditiveExpression,
                     precedence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(244);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(254);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(252);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 25, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleAdditiveExpression);
          setState(246);

          if (!(precpred(_ctx, 2)))
            throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(247);
          match(FianchettoParser::T__27);
          setState(248);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleAdditiveExpression);
          setState(249);

          if (!(precpred(_ctx, 1)))
            throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(250);
          match(FianchettoParser::T__28);
          setState(251);
          multiplicativeExpression(0);
          break;
        }

        default:
          break;
        }
      }
      setState(256);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 26, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MultiplicativeExpressionContext
//------------------------------------------------------------------

FianchettoParser::MultiplicativeExpressionContext::
    MultiplicativeExpressionContext(ParserRuleContext *parent,
                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::UnaryExpressionContext *
FianchettoParser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContext<FianchettoParser::UnaryExpressionContext>(0);
}

FianchettoParser::MultiplicativeExpressionContext *
FianchettoParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<FianchettoParser::MultiplicativeExpressionContext>(0);
}

size_t FianchettoParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleMultiplicativeExpression;
}

void FianchettoParser::MultiplicativeExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void FianchettoParser::MultiplicativeExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}

FianchettoParser::MultiplicativeExpressionContext *
FianchettoParser::multiplicativeExpression() {
  return multiplicativeExpression(0);
}

FianchettoParser::MultiplicativeExpressionContext *
FianchettoParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FianchettoParser::MultiplicativeExpressionContext *_localctx =
      _tracker.createInstance<MultiplicativeExpressionContext>(_ctx,
                                                               parentState);
  FianchettoParser::MultiplicativeExpressionContext *previousContext =
      _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by
                         // generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42,
                     FianchettoParser::RuleMultiplicativeExpression,
                     precedence);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(258);
    unaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(271);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(269);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 27, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleMultiplicativeExpression);
          setState(260);

          if (!(precpred(_ctx, 3)))
            throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(261);
          match(FianchettoParser::T__29);
          setState(262);
          unaryExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleMultiplicativeExpression);
          setState(263);

          if (!(precpred(_ctx, 2)))
            throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(264);
          match(FianchettoParser::T__30);
          setState(265);
          unaryExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState,
                                  RuleMultiplicativeExpression);
          setState(266);

          if (!(precpred(_ctx, 1)))
            throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(267);
          match(FianchettoParser::T__31);
          setState(268);
          unaryExpression();
          break;
        }

        default:
          break;
        }
      }
      setState(273);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 28, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext
//------------------------------------------------------------------

FianchettoParser::UnaryExpressionContext::UnaryExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::PostfixExpressionContext *
FianchettoParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<FianchettoParser::PostfixExpressionContext>(0);
}

FianchettoParser::UnaryExpressionContext *
FianchettoParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<FianchettoParser::UnaryExpressionContext>(0);
}

size_t FianchettoParser::UnaryExpressionContext::getRuleIndex() const {
  return FianchettoParser::RuleUnaryExpression;
}

void FianchettoParser::UnaryExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void FianchettoParser::UnaryExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}

FianchettoParser::UnaryExpressionContext *FianchettoParser::unaryExpression() {
  UnaryExpressionContext *_localctx =
      _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 44, FianchettoParser::RuleUnaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
    case FianchettoParser::T__0:
    case FianchettoParser::INTEGER_LITERAL:
    case FianchettoParser::FLOAT_LITERAL:
    case FianchettoParser::STRING_LITERAL:
    case FianchettoParser::IDENTIFIER: {
      enterOuterAlt(_localctx, 1);
      setState(274);
      postfixExpression(0);
      break;
    }

    case FianchettoParser::T__32: {
      enterOuterAlt(_localctx, 2);
      setState(275);
      match(FianchettoParser::T__32);
      setState(276);
      unaryExpression();
      break;
    }

    case FianchettoParser::T__28: {
      enterOuterAlt(_localctx, 3);
      setState(277);
      match(FianchettoParser::T__28);
      setState(278);
      unaryExpression();
      break;
    }

    case FianchettoParser::T__33: {
      enterOuterAlt(_localctx, 4);
      setState(279);
      match(FianchettoParser::T__33);
      setState(280);
      unaryExpression();
      break;
    }

    case FianchettoParser::T__34: {
      enterOuterAlt(_localctx, 5);
      setState(281);
      match(FianchettoParser::T__34);
      setState(282);
      unaryExpression();
      break;
    }

    default:
      throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext
//------------------------------------------------------------------

FianchettoParser::PostfixExpressionContext::PostfixExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

FianchettoParser::PrimaryExpressionContext *
FianchettoParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<FianchettoParser::PrimaryExpressionContext>(0);
}

tree::TerminalNode *FianchettoParser::PostfixExpressionContext::IDENTIFIER() {
  return getToken(FianchettoParser::IDENTIFIER, 0);
}

FianchettoParser::ExpressionContext *
FianchettoParser::PostfixExpressionContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

FianchettoParser::PostfixExpressionContext *
FianchettoParser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<FianchettoParser::PostfixExpressionContext>(0);
}

FianchettoParser::ArgumentListContext *
FianchettoParser::PostfixExpressionContext::argumentList() {
  return getRuleContext<FianchettoParser::ArgumentListContext>(0);
}

size_t FianchettoParser::PostfixExpressionContext::getRuleIndex() const {
  return FianchettoParser::RulePostfixExpression;
}

void FianchettoParser::PostfixExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void FianchettoParser::PostfixExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}

FianchettoParser::PostfixExpressionContext *
FianchettoParser::postfixExpression() {
  return postfixExpression(0);
}

FianchettoParser::PostfixExpressionContext *
FianchettoParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FianchettoParser::PostfixExpressionContext *_localctx =
      _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  FianchettoParser::PostfixExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by
                         // generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, FianchettoParser::RulePostfixExpression,
                     precedence);

  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(293);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
        _input, 30, _ctx)) {
    case 1: {
      setState(286);
      primaryExpression();
      break;
    }

    case 2: {
      setState(287);
      match(FianchettoParser::IDENTIFIER);
      setState(288);
      match(FianchettoParser::T__37);
      setState(289);
      match(FianchettoParser::T__0);
      setState(290);
      expression();
      setState(291);
      match(FianchettoParser::T__1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(308);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(306);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 32, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(295);

          if (!(precpred(_ctx, 3)))
            throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(296);
          match(FianchettoParser::T__35);
          setState(297);
          expression();
          setState(298);
          match(FianchettoParser::T__36);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(
              parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(300);

          if (!(precpred(_ctx, 2)))
            throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(301);
          match(FianchettoParser::T__0);
          setState(303);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~0x3fULL) == 0) &&
               ((1ULL << _la) & ((1ULL << FianchettoParser::T__0) |
                                 (1ULL << FianchettoParser::T__28) |
                                 (1ULL << FianchettoParser::T__32) |
                                 (1ULL << FianchettoParser::T__33) |
                                 (1ULL << FianchettoParser::T__34) |
                                 (1ULL << FianchettoParser::INTEGER_LITERAL) |
                                 (1ULL << FianchettoParser::FLOAT_LITERAL) |
                                 (1ULL << FianchettoParser::STRING_LITERAL) |
                                 (1ULL << FianchettoParser::IDENTIFIER))) !=
                   0)) {
            setState(302);
            argumentList();
          }
          setState(305);
          match(FianchettoParser::T__1);
          break;
        }

        default:
          break;
        }
      }
      setState(310);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 33, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExpressionContext
//------------------------------------------------------------------

FianchettoParser::PrimaryExpressionContext::PrimaryExpressionContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *FianchettoParser::PrimaryExpressionContext::IDENTIFIER() {
  return getToken(FianchettoParser::IDENTIFIER, 0);
}

FianchettoParser::ConstantContext *
FianchettoParser::PrimaryExpressionContext::constant() {
  return getRuleContext<FianchettoParser::ConstantContext>(0);
}

FianchettoParser::ExpressionContext *
FianchettoParser::PrimaryExpressionContext::expression() {
  return getRuleContext<FianchettoParser::ExpressionContext>(0);
}

size_t FianchettoParser::PrimaryExpressionContext::getRuleIndex() const {
  return FianchettoParser::RulePrimaryExpression;
}

void FianchettoParser::PrimaryExpressionContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void FianchettoParser::PrimaryExpressionContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}

FianchettoParser::PrimaryExpressionContext *
FianchettoParser::primaryExpression() {
  PrimaryExpressionContext *_localctx =
      _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 48, FianchettoParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
    case FianchettoParser::IDENTIFIER: {
      enterOuterAlt(_localctx, 1);
      setState(311);
      match(FianchettoParser::IDENTIFIER);
      break;
    }

    case FianchettoParser::INTEGER_LITERAL:
    case FianchettoParser::FLOAT_LITERAL:
    case FianchettoParser::STRING_LITERAL: {
      enterOuterAlt(_localctx, 2);
      setState(312);
      constant();
      break;
    }

    case FianchettoParser::T__0: {
      enterOuterAlt(_localctx, 3);
      setState(313);
      match(FianchettoParser::T__0);
      setState(314);
      expression();
      setState(315);
      match(FianchettoParser::T__1);
      break;
    }

    default:
      throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext
//------------------------------------------------------------------

FianchettoParser::ArgumentListContext::ArgumentListContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<FianchettoParser::ExpressionContext *>
FianchettoParser::ArgumentListContext::expression() {
  return getRuleContexts<FianchettoParser::ExpressionContext>();
}

FianchettoParser::ExpressionContext *
FianchettoParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<FianchettoParser::ExpressionContext>(i);
}

size_t FianchettoParser::ArgumentListContext::getRuleIndex() const {
  return FianchettoParser::RuleArgumentList;
}

void FianchettoParser::ArgumentListContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void FianchettoParser::ArgumentListContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}

FianchettoParser::ArgumentListContext *FianchettoParser::argumentList() {
  ArgumentListContext *_localctx =
      _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 50, FianchettoParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    expression();
    setState(324);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FianchettoParser::T__4) {
      setState(320);
      match(FianchettoParser::T__4);
      setState(321);
      expression();
      setState(326);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext
//------------------------------------------------------------------

FianchettoParser::ConstantContext::ConstantContext(ParserRuleContext *parent,
                                                   size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *FianchettoParser::ConstantContext::INTEGER_LITERAL() {
  return getToken(FianchettoParser::INTEGER_LITERAL, 0);
}

tree::TerminalNode *FianchettoParser::ConstantContext::FLOAT_LITERAL() {
  return getToken(FianchettoParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode *FianchettoParser::ConstantContext::STRING_LITERAL() {
  return getToken(FianchettoParser::STRING_LITERAL, 0);
}

size_t FianchettoParser::ConstantContext::getRuleIndex() const {
  return FianchettoParser::RuleConstant;
}

void FianchettoParser::ConstantContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void FianchettoParser::ConstantContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

FianchettoParser::ConstantContext *FianchettoParser::constant() {
  ConstantContext *_localctx =
      _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 52, FianchettoParser::RuleConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    _la = _input->LA(1);
    if (!((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << FianchettoParser::INTEGER_LITERAL) |
                             (1ULL << FianchettoParser::FLOAT_LITERAL) |
                             (1ULL << FianchettoParser::STRING_LITERAL))) !=
               0))) {
      _errHandler->recoverInline(this);
    } else {
      _errHandler->reportMatch(this);
      consume();
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext
//------------------------------------------------------------------

FianchettoParser::AssignmentOperatorContext::AssignmentOperatorContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t FianchettoParser::AssignmentOperatorContext::getRuleIndex() const {
  return FianchettoParser::RuleAssignmentOperator;
}

void FianchettoParser::AssignmentOperatorContext::enterRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void FianchettoParser::AssignmentOperatorContext::exitRule(
    tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FianchettoListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}

FianchettoParser::AssignmentOperatorContext *
FianchettoParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx =
      _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 54, FianchettoParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    _la = _input->LA(1);
    if (!((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) & ((1ULL << FianchettoParser::T__2) |
                             (1ULL << FianchettoParser::T__38) |
                             (1ULL << FianchettoParser::T__39) |
                             (1ULL << FianchettoParser::T__40) |
                             (1ULL << FianchettoParser::T__41) |
                             (1ULL << FianchettoParser::T__42))) != 0))) {
      _errHandler->recoverInline(this);
    } else {
      _errHandler->reportMatch(this);
      consume();
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool FianchettoParser::sempred(RuleContext *context, size_t ruleIndex,
                               size_t predicateIndex) {
  switch (ruleIndex) {
  case 16:
    return logicalOrExpressionSempred(
        antlrcpp::downCast<LogicalOrExpressionContext *>(context),
        predicateIndex);
  case 17:
    return logicalAndExpressionSempred(
        antlrcpp::downCast<LogicalAndExpressionContext *>(context),
        predicateIndex);
  case 18:
    return equalityExpressionSempred(
        antlrcpp::downCast<EqualityExpressionContext *>(context),
        predicateIndex);
  case 19:
    return relationalExpressionSempred(
        antlrcpp::downCast<RelationalExpressionContext *>(context),
        predicateIndex);
  case 20:
    return additiveExpressionSempred(
        antlrcpp::downCast<AdditiveExpressionContext *>(context),
        predicateIndex);
  case 21:
    return multiplicativeExpressionSempred(
        antlrcpp::downCast<MultiplicativeExpressionContext *>(context),
        predicateIndex);
  case 23:
    return postfixExpressionSempred(
        antlrcpp::downCast<PostfixExpressionContext *>(context),
        predicateIndex);

  default:
    break;
  }
  return true;
}

bool FianchettoParser::logicalOrExpressionSempred(
    LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
  case 0:
    return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool FianchettoParser::logicalAndExpressionSempred(
    LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
  case 1:
    return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool FianchettoParser::equalityExpressionSempred(
    EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
  case 2:
    return precpred(_ctx, 2);
  case 3:
    return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool FianchettoParser::relationalExpressionSempred(
    RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
  case 4:
    return precpred(_ctx, 4);
  case 5:
    return precpred(_ctx, 3);
  case 6:
    return precpred(_ctx, 2);
  case 7:
    return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool FianchettoParser::additiveExpressionSempred(
    AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
  case 8:
    return precpred(_ctx, 2);
  case 9:
    return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool FianchettoParser::multiplicativeExpressionSempred(
    MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
  case 10:
    return precpred(_ctx, 3);
  case 11:
    return precpred(_ctx, 2);
  case 12:
    return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool FianchettoParser::postfixExpressionSempred(
    PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
  case 13:
    return precpred(_ctx, 3);
  case 14:
    return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void FianchettoParser::initialize() {
  std::call_once(fianchettoParserOnceFlag, fianchettoParserInitialize);
}
