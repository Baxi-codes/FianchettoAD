#ifndef ASTNODE_H
#define ASTNODE_H

#include <cassert>
#include <memory>
#include <vector>

#include "lexer.h"

class ASTNode;
using ASTNodePtr = std::shared_ptr<ASTNode>;

class ASTVisitor;

class ASTNode {
public:
  virtual ~ASTNode() = default;
  Location loc;
  virtual void accept(ASTVisitor *v) = 0;
};

#endif // ASTNODE_H