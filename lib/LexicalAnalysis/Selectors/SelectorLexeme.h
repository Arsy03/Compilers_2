
#ifndef COMPILER_SELECTORLEXEME_H
#define COMPILER_SELECTORLEXEME_H

#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <iosfwd>
#include "../Lexeme.h"
#include "../TypeLexeme.h"

namespace LexicalAnalysis::Selectors {

    using namespace std;

    class SelectorLexeme {
        vector<Lexeme> streamSelectedLexeme;
    protected:
        virtual regex getRegex() = 0;
        virtual LexType getLexType() = 0;
    public:
        virtual stringstream select(stringstream sourceProgram);

        auto begin() {
            return streamSelectedLexeme.begin();
        }

        auto end() {
            return streamSelectedLexeme.end();
        }
    };
}


#endif //COMPILER_SELECTORLEXEME_H