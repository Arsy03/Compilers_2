#include "SelectorWithException.h"
#include "ConstSelector.h"

using namespace std;

regex LexicalAnalysis::Selectors::ConstSelector::getRegex() {
    return std::regex(R"(((\")([^"]+)(\"))|(\d+)|(true|false))");
}

regex LexicalAnalysis::Selectors::ConstSelector::getExceptionRegex() {
    return std::regex(R"(\")");
}

LexType LexicalAnalysis::Selectors::ConstSelector::getLexType() {
    return LexType::Const;
}

TableElementLexeme LexicalAnalysis::Selectors::ConstSelector::getTableElement(string content) {
    return UniqueTableElementLexeme(content);
}
