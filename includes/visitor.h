#ifndef VISITOR_H
#define VISITOR_H

#include "ast.h"

class ASTVisitor {
public:
  virtual ~ASTVisitor() = default;
};

#endif // VISITOR_H