#include "Lexer.hpp"
#include "Parser.hpp"
#include "table.hpp"
#include "AST_tree.h"
#include <iostream>

namespace Cal {
    struct Token {
        std::string string;
        Token *next;

    };

    Token *make(std::string string);

    Token *call();
}
namespace Cal {
    Token *make(std::string string) {
        Token *node = new Token;
        node->string = string;
        node->next = 0;
        return node;
    }

    Token *call() {
        Token *node = new Token;
        node->next = make("hollo!!!");
        return node;
    }

    void printToken(const Token *node) {
        std::cout << node->string << std::endl;
        if (node->next != NULL) {
            std::cout << '\t';
            printToken(node->next);
        }
    }
}

int main() {
    table["pi"] = 3.14;
    table["e"] = 2.71;
    std::cout << "Lexer..." << '\n';
    Parser::Token *token = Parser::expr(true);
    Parser::AST_tree::printAST(token);


/*  table["pi"] = 3.14;
  table["e"] = 2.71;
  while (std::cin) {

    try {

      std::cout << "Enter lexems: ";
      Lexer::getToken();
      if (Lexer::current_token == Lexer::END)
        break;
      if (Lexer::current_token == Lexer::PRINT)
        continue;
      std::cout << "Token NUMBER = " << Lexer::current_token << '\t';
      std::cout << "Token VALUE = " << Lexer::number_value << '\t';
      std::cout << "String VALUE = " << Lexer::string_value << '\n';
      std::cout << Parser::expr(false) << '\n';

    } catch (std::overflow_error e) {
      std::cout << e.what() << " -> " << Lexer::number_value << std::endl;
    } catch (std::invalid_argument e) {
      std::cout << e.what() << std::endl;
    } catch (std::runtime_error e) {
      std::cout << e.what() << std::endl;
    }
  }*/

    return 0;
}
