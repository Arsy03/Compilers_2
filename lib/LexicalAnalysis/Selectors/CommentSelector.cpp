#include "SelectorWithException.h"
#include "CommentSelector.h"

using namespace std;

regex LexicalAnalysis::Selectors::CommentSelector::getRegex() {
    return std::regex(R"(((\/\*)([^]*?)(\*\/))|((\/\/)(.*)))");
}

regex LexicalAnalysis::Selectors::CommentSelector::getExceptionRegex() {
    return std::regex(R"((\/\*)|(\*\/))");
}

LexType LexicalAnalysis::Selectors::CommentSelector::getLexType() {
    return LexType::Comment;
}

TableElementLexeme LexicalAnalysis::Selectors::CommentSelector::getTableElement(string content) {
    return UniqueTableElementLexeme(content);
}
