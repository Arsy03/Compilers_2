#include "SelectorLexeme.h"
#include "KeyWordSelector.h"

using namespace std;

regex LexicalAnalysis::Selectors::KeyWorldSelector::getRegex() {
    return std::regex(R"((main)|(integer)|(bool)|(string)|(if)|(then)|(else)|(endif)|(while)|(endwhile)|(return)|(proc))");
}

LexType LexicalAnalysis::Selectors::KeyWorldSelector::getLexType() {
    return KeyWord;
}

bool LexicalAnalysis::Selectors::KeyWorldSelector::isUnickLexeme() {
    return false;
}
