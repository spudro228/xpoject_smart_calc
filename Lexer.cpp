#include "Lexer.hpp"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

namespace Lexer {
    token_t current_token;
    double number_value;
    std::string string_value;
    std::map<Lexer::Token, std::string> tokenTable = {
            {Token::NAME,   "NAME"},
            {Token::NUMBER, "NUMBER"},
            {Token::ASSIGN, "="},
            {Token::DIV,    "/"},
            {Token::MUL,    "*"},
            {Token::PLUS,   "+"},
            {Token::MINUS,  "-"},
            {Token::LP,     "("},
            {Token::RP,     ")"},
            {Token::PRINT,  ";"},
            {Token::END,    "END"}
    };

/**
 * Get Next token!
 */
    token_t getToken() {
        char ch;
        do {
            if (!std::cin.get(ch))
                return current_token = END;
        } while (ch != '\n' && isspace(ch));

        switch (ch) {
            case 0:
                return current_token = END;
            case ';':
            case '\n':
                return current_token = PRINT;
            case '*':
            case '/':
            case '+':
            case '-':
            case '(':
            case ')':
            case '=':
                return current_token = Token(ch);
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                std::cin.putback(ch);
                std::cin >> number_value;
                return current_token = NUMBER;
                // if is an alphabetic letter  - NAME, NAME=, else Error
            default: {
                if (isalpha(ch)) {
                    string_value = ch;
                    while (std::cin.get(ch) && isalnum(ch)) {
                        string_value.push_back(ch);
                    }
                    std::cin.putback(ch);
                    // std::cin >> string_value;
                    return current_token = NAME;
                }

                // TODO: cange error hendler
                throw std::runtime_error("primary expected");
                return current_token = PRINT;
            }
        }
    }

}
