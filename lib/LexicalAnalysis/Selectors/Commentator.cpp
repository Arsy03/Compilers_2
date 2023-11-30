#include "SelectorWithException.h"
#include "Commentator.h"

using namespace std;

regex LexicalAnalysis::Selectors::Commentator::getRegex() {
    return std::regex(R"(((\/\*)(.*)(\*\/))|((\/\/)(.*)))");
}

regex LexicalAnalysis::Selectors::Commentator::getExceptionRegex() {
    return std::regex(R"((\/\*)|(\*\/))");
}

LexType LexicalAnalysis::Selectors::Commentator::getLexType() {
    return Comment;
}