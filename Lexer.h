
#ifndef CALC_LEXER_H
#define CALC_LEXER_H
#include <string>
namespace Lexer {
typedef enum Token {
  NAME,
  NUMBER,
  END,
  PLUS = '+',
  MINUS = '-',
  MUL = '*',
  DIV = '/',
  PRINT = ';',
  ASSIGN = '=',
  LP = '(',
  RP = ')'
} token_t;

extern token_t current_token;
extern double number_value;
extern std::string string_value;
token_t getToken();
}
#endif
