#include "SelectorLexeme.h"
#include "IdentificatorSelector.h"

using namespace std;

regex LexicalAnalysis::Selectors::IdentificatorSelector::getRegex() {
    return std::regex(R"(\s(\w\S*))");
}

LexType LexicalAnalysis::Selectors::IdentificatorSelector::getLexType() {
    return Identificator;
}

bool LexicalAnalysis::Selectors::IdentificatorSelector::isUnickLexeme() {
    return false;
}
