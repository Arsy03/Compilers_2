#include "SelectorLexeme.h"
#include "KeyWord.h"

using namespace std;

regex LexicalAnalysis::Selectors::KeyWorld::getRegex() {
    return std::regex(R"((main)|(integer)|(bool)|(string))");
}

LexType LexicalAnalysis::Selectors::KeyWorld::getLexType() {
    return KeyWord;
}
