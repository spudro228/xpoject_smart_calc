//
// Created by hui on 18.04.2017.
//

#include "AST_tree.h"
#include "Lexer.hpp"
#include <iostream>

namespace Parser {
    using namespace Lexer;

    void AST_tree::printAST(const Token *node) {
        switch (node->operand) {
            case NAME: {
                std::cout << "NAME ";
                break;
            }
            case NUMBER:
                std::cout << "NUMBER ";
                break;
            case END:
                std::cout << "END ";
                break;
            case PLUS:
                std::cout << "PLUS ";
                break;
            case MINUS:
                std::cout << "MINUS ";
                break;
            case MUL:
                std::cout << "MUL ";
                break;
            case DIV:
                std::cout << "DIV ";
                break;
            case PRINT:
                std::cout << "PRINT ";
                break;
            case ASSIGN:
                std::cout << "ASSIGN ";
                break;
            case LP:
                std::cout << "LP ";
                break;
            case RP:
                std::cout << "RP ";
                break;
        }
        if (node->left != nullptr) {
            printAST(node->left);

        }
        if (node->right != nullptr){
            printAST(node->right);

        }
        //std::cout << Lexer::tokenTable[Lexer::Token::ASSIGN] << std::endl;
    }
}
