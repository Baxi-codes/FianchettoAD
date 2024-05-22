grammar Fianchetto;

program: (functionDefinition | globalDeclaration)* EOF;

functionDefinition
    : typeSpecifier IDENTIFIER '(' parameterList? ')' compoundStatement
    ;

globalDeclaration
    : typeSpecifier IDENTIFIER ('=' expression)? ';'
    ;

parameterList
    : parameter (',' parameter)*
    ;

parameter
    : typeSpecifier IDENTIFIER
    ;

typeSpecifier
    : 'int'
    | 'float'
    | 'double'
    | 'void'
    | 'differentiable' typeSpecifier
    ;

statement
    : expressionStatement
    | compoundStatement
    | selectionStatement
    | iterationStatement
    | jumpStatement
    ;

expressionStatement
    : expression? ';'
    ;

compoundStatement
    : '{' (declaration | statement)* '}'
    ;

selectionStatement
    : 'if' '(' expression ')' statement ('else' statement)?
    ;

iterationStatement
    : 'while' '(' expression ')' statement
    | 'for' '(' expression? ';' expression? ';' expression? ')' statement
    ;

jumpStatement
    : 'return' expression? ';'
    ;

declaration
    : typeSpecifier IDENTIFIER ('=' expression)? ';'
    ;

expression
    : assignmentExpression
    ;

assignmentExpression
    : conditionalExpression
    | unaryExpression assignmentOperator assignmentExpression
    ;

conditionalExpression
    : logicalOrExpression
    | logicalOrExpression '?' expression ':' conditionalExpression
    ;

logicalOrExpression
    : logicalAndExpression
    | logicalOrExpression '||' logicalAndExpression
    ;

logicalAndExpression
    : equalityExpression
    | logicalAndExpression '&&' equalityExpression
    ;

equalityExpression
    : relationalExpression
    | equalityExpression '==' relationalExpression
    | equalityExpression '!=' relationalExpression
    ;

relationalExpression
    : additiveExpression
    | relationalExpression '<' additiveExpression
    | relationalExpression '>' additiveExpression
    | relationalExpression '<=' additiveExpression
    | relationalExpression '>=' additiveExpression
    ;

additiveExpression
    : multiplicativeExpression
    | additiveExpression '+' multiplicativeExpression
    | additiveExpression '-' multiplicativeExpression
    ;

multiplicativeExpression
    : unaryExpression
    | multiplicativeExpression '*' unaryExpression
    | multiplicativeExpression '/' unaryExpression
    | multiplicativeExpression '%' unaryExpression
    ;

unaryExpression
    : postfixExpression
    | '!' unaryExpression
    | '-' unaryExpression
    | '++' unaryExpression
    | '--' unaryExpression
    ;

postfixExpression
    : primaryExpression
    | postfixExpression '[' expression ']'
    | postfixExpression '(' argumentList? ')'
    | IDENTIFIER '\'' '(' expression ')' // Derivative call
    ;

primaryExpression
    : IDENTIFIER
    | constant
    | '(' expression ')'
    ;

argumentList
    : expression (',' expression)*
    ;

constant
    : INTEGER_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    ;

assignmentOperator
    : '='
    | '+='
    | '-='
    | '*='
    | '/='
    | '%='
    ;

INTEGER_LITERAL
    : [0-9]+
    ;

FLOAT_LITERAL
    : [0-9]*'.'[0-9]+([eE][+-]?[0-9]+)?
    ;

STRING_LITERAL
    : '"' (~["\\] | '\\' .)* '"'
    ;

IDENTIFIER
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

COMMENT
    : '//' ~[\r\n]* -> skip
    ;

MULTI_LINE_COMMENT
    : '/*' .*? '*/' -> skip
    ;

WHITESPACE
    : [ \t\r\n]+ -> skip
    ;
