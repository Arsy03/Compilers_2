#include "SelectorLexeme.h"
#include "Divider.h"

using namespace std;

regex LexicalAnalysis::Selectors::Dividerr::getRegex() {
    return std::regex(R"((\+)|(\-)|(\;)|(\()|(\))|(\{)|(\}))");
}

LexType LexicalAnalysis::Selectors::Dividerr::getLexType() {
    return Divider;
}
