
#ifndef COMPILER_LEXEME_H
#define COMPILER_LEXEME_H

#include "TypeLexeme.h"
#include <iostream>

struct Lexeme{
    LexType lexType;
    int numRow;
    int numColumn;

public:
    Lexeme(LexType _lexType, int _numRow, int _numColumn): lexType(_lexType), numRow (_numRow), numColumn(_numColumn) {};

    friend std::ostream &operator<<(std::ostream &os, const Lexeme &lxm) {
        os << lxm.lexType << ' ' << lxm.numRow << ' ' << lxm.numColumn;
        return os;
    }
};


#endif //COMPILER_LEXEME_H
