//#include "Lexer.h"
#include "Parser.h"
#include "table.h"
#include <stdexcept>
//#include <exception>

namespace Parser {

using namespace Lexer;

// PLUS | MINUS
Enode &expr(bool get) {

  Enode *left = prim(get);
  for (;;) {
    switch (current_token) {
    case PLUS:
    case MINUS:
    case MUL:
    case DIV:
      Enode *node = new Enode;
      node->operand = current_token;
      node->left = left;
      node->right = term(true);
      left = node;
      break;
    default:
      return left;
    } // end_switch
  }   // end_for

  return 0;
}

/*
Enode &term(bool get) {
  Enode *left = prim(get);

  for (;;) {
    switch (current_token) {
    case MUL:
      Enode *node = new Enode;
      node->operand = current_token;
      node->left = left;
      node->right = prim(true);
      left = node;
      break;
    case DIV:
      if (double d = prim(true)) {
        //left /= d;
        break;
      }
      // TODO error hendler
      // std::cout << "Divide by 0." << '\n';
      throw std::overflow_error("Divide by zero exception");
    // return 0;
    default:
      return left;
    }
  }

  return 0;
}
*/

Enode &prim(bool get) {

  if (get)
    getToken();

  Enode *val = new Enode;
  switch (current_token) {
  case NUMBER: {
    val->operand = current_token;
    val->value = number_value;
    getToken();
    return val;
  }
  case NAME: {
    // &v = table[string_value];
    // if (getToken() == ASSIGN) {
    //   v = expr(true);
    // return v;
    // }
    val->operand = current_token;
    val->left = table[string_value];
    if (getToken() == ASSIGN) {
      val->right = expr(true);
    }
    return val;
  }
  case MINUS: {
    return -prim(true);
  }
  case LP: {
    double e = expr(true);
    if (current_token != RP) {
      throw std::invalid_argument(" ')' expected");
    }
    getToken();
    return e;
  }
  default: { throw std::runtime_error("primary expected"); }
  } // end_switch
} // end_prim
} // end_namespace
