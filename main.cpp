#include "Lexer.h"
#include "Parser.h"
#include "table.h"
#include <iostream>

int main() {
  // Lexer::token_t tok = Lexer::getToken();
  // if (Lexer::current_token == Lexer::END) {
  //   std::cout << "TOKEN - END" << '\n';
  // }
  // std::cout << Lexer::current_token << '\n';
  // std::cout << "Current token: " << Lexer::NAME << '\n';
  // std::cout << Lexer::getToken() << '\n';
  // std::cout << Lexer::current_token << '\n';
  std::cout << "Lexer..." << '\n';
  // try {
  //         i = intDivEx (10, 0);
  //     } catch (std::overflow_error e) {
  //         std::cout << e.what() << " -> ";
  //     }
  table["pi"] = 3.14;
  table["e"] = 2.71;
  // while (std::cin) {
  //
  //   try {
  //
  //     std::cout << "Enter lexems: ";
  //     Lexer::getToken();
  //     if (Lexer::current_token == Lexer::END)
  //       break;
  //     if (Lexer::current_token == Lexer::PRINT)
  //       continue;
  //     std::cout << "Token NUMBER = " << Lexer::current_token << '\t';
  //     std::cout << "Token VALUE = " << Lexer::number_value << '\t';
  //     std::cout << "String VALUE = " << Lexer::string_value << '\n';
  //     std::cout << Parser::expr(false) << '\n';
  //
  //   } catch (std::overflow_error e) {
  //     std::cout << e.what() << " -> " << Lexer::number_value << std::endl;
  //   } catch (std::invalid_argument e) {
  //     std::cout << e.what() << std::endl;
  //   } catch (std::runtime_error e) {
  //     std::cout << e.what() << std::endl;
  //   }
  // }

  return 0;
}
