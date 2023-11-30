#include "TypeLexeme.h"

#include <string>

using namespace std;

string lexTypeToString(LexType type) {
    switch (type) {
        case LexType::Comment:
            return "Comment";
        case LexType::Const:
            return "Const";
        case LexType::KeyWord:
            return "KeyWord";
        case LexType::Divider:
            return "Divider";
        case LexType::Identificator:
            return "Identificator";
        default:
            return "Unknown";
    }
}