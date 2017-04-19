//
// Created by hui on 18.04.2017.
//

#ifndef CALC_AST_TREE_H
#define CALC_AST_TREE_H

#include "Lexer.hpp"
#include "Parser.hpp"

namespace Parser {
    class AST_tree {

    public:

        static void printAST(const Token* node);
    };

}
#endif //CALC_AST_TREE_H
