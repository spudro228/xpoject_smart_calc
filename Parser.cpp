#include "Lexer.h"
#include "Parser.h"
#include "table.h"
#include <stdexcept>
//#include <exception>

namespace Parser {

using namespace Lexer;

// PLUS | MINUS
double expr(bool get) {

  double left = term(get);
  for (;;) {
    switch (current_token) {
    case PLUS:
      left += term(true);
      break;
    case MINUS:
      left -= term(true);
      break;
    default:
      return left;
    } // end_switch
  }   // end_for

  return 0;
}

double term(bool get) {
  double left = prim(get);

  for (;;) {
    switch (current_token) {
    case MUL:
      left *= prim(true);
      break;
    case DIV:
      if (double d = prim(true)) {
        left /= d;
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

double prim(bool get) {

  if (get)
    getToken();
  switch (current_token) {
  case NUMBER: {
    double val = number_value;
    getToken();
    return val;
  }
  case NAME: {
    double &v = table[string_value];
    if (getToken() == ASSIGN) {
      v = expr(true);
    }
    return v;
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
