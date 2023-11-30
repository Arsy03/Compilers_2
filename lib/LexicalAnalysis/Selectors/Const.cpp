#include "SelectorWithException.h"
#include "Const.h"

using namespace std;

regex LexicalAnalysis::Selectors::ConstSelector::getRegex() {
    return std::regex(R"(((\")(\W+)(\"))|(\d+)|(true|false))");
}

regex LexicalAnalysis::Selectors::ConstSelector::getExceptionRegex() {
    return std::regex(R"((\")(\W+))");
}

LexType LexicalAnalysis::Selectors::ConstSelector::getLexType() {
    return Const;
}
