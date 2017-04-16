#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include "Lexer.h"

namespace Parser {

struct Enode {
  Lexer::token_t operand;
  Enode *left;
  Enode *right;
  double *value;

  Enode &expr(bool get);
  Enode &term(bool get);
  bool prim(bool get);
};
}

#endif
