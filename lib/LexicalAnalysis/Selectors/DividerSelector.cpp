#include "SelectorLexeme.h"
#include "DividerSelector.h"

using namespace std;

regex LexicalAnalysis::Selectors::DividerSelector::getRegex() {
    return std::regex(R"((\+)|(\-)|(\=\=)|(\=)|(\>)|(\;)|(\()|(\))|(\{)|(\}))");
}

LexType LexicalAnalysis::Selectors::DividerSelector::getLexType() {
    return Divider;
}

bool LexicalAnalysis::Selectors::DividerSelector::isUnickLexeme() {
    return false;
}
