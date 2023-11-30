#include "SelectorLexeme.h"
#include "Identificator.h"

using namespace std;

regex LexicalAnalysis::Selectors::Ident::getRegex() {
    return std::regex(R"(\s[a-zA-Z]\s)");
}

LexType LexicalAnalysis::Selectors::Ident::getLexType() {
    return Identificator;
}