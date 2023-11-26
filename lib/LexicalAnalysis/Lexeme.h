
#ifndef COMPILER_LEXEME_H
#define COMPILER_LEXEME_H

#include "TypeLexeme.h"
#include <iostream>

struct Lexeme {
    LexType lexType;
    int numRowTable;
    int numRow;
    int numColumn;

public:
    Lexeme(LexType _lexType, int _numRowTable, int _numRow, int _numColumn) : lexType(_lexType),
                                                                              numRowTable(_numRowTable),
                                                                              numRow(_numRow), numColumn(_numColumn) {};

    friend std::ostream &operator<<(std::ostream &os, const Lexeme &lxm) {
        os << lxm.lexType << ' ' << lxm.numRowTable << " " << lxm.numRow << ' ' << lxm.numColumn;
        return os;
    }
};


#endif //COMPILER_LEXEME_H
