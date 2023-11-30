
#ifndef BABUSHKA_2_TYPELEXEME_H
#define BABUSHKA_2_TYPELEXEME_H

#include <string>

enum LexType{
    Comment = -1,
    Const = 1,
    KeyWord = 2,
    Divider = 3,
    Identificator = 4,
};

std::string lexTypeToString(LexType type);

#endif //BABUSHKA_2_TYPELEXEME_H
