#ifndef CALC_PARSER_H
#define CALC_PARSER_H

namespace Parser {

    struct Token {
        Lexer::token_t operand;
        Token *left = nullptr;
        Token *right = nullptr;
        double value = 0;
    };

    Token *expr(bool get);

    Token *term(bool get);

    Token *prim(bool get);

    void printToken(const Token * node);

}

#endif
