#include "Lexer.hpp"
#include "Parser.hpp"
#include "table.hpp"
#include <iostream>


namespace Parser {

    using namespace Lexer;

// PLUS | MINUS
    Token *expr(bool get) {
        Token *left = new Token;
        left->right = term(get);
        for (;;) {
            switch (current_token) {
                case PLUS:
                    left->operand = current_token;
                    left->left = term(true);
                    break;
                case MINUS:
                    left->operand = current_token;
                    left->left = term(true);
                    break;
                default:
                    return left;
            } // end_switch
        }   // end_for

        return 0;
    }

    Token *term(bool get) {
        Token *left = new Token;
        left->right = prim(get);

        for (;;) {
            switch (current_token) {
                case MUL:
                    left->operand = current_token;
                    left->left = prim(true);
                    break;
                case DIV:
                    if (Token *d = prim(true)) {
                        left->operand = current_token;
                        left->left = d;
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

    Token *prim(bool get) {
        Token *right = new Token;
        if (get)
            getToken();
        switch (current_token) {
            case NUMBER: {
                //double val = number_value;
                right->operand = current_token;
                right->value = number_value;
                getToken();
                return right;
            }
            case NAME: {
                //double &v = table[string_value];
                right->operand = current_token;
                right->value = table[string_value];
                if (getToken() == ASSIGN) {
                    right->right = expr(true);
                }
                return right;
            }
            case MINUS: {
                //return -prim(true);
                right->operand = current_token;
                right->right = prim(true);
                return right;


            }
            case LP: {
                Token* expression = expr(true);
                if (current_token != RP) {
                    throw std::invalid_argument(" ')' expected");
                }
                getToken();
                return expression;
            }
            default: {
                throw std::runtime_error("primary expected");
            }
        } // end_switch
    }

    // end_prim

    void printToken(const Token * node){
        std::cout << "Token: " << node->operand << ' ';
        std::cout <<"Value:" << node->value << std::endl;
        if(node->right != nullptr){
            printToken(node->right);
        }
        if(node->left != nullptr){
            std::cout << '\t';
            printToken(node->left);
        }
    }
} // end_namespace
