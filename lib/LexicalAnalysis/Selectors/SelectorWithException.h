
#ifndef COMPILER_SELECTORWITHEXCEPTION_H
#define COMPILER_SELECTORWITHEXCEPTION_H


#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors {

    class SelectorWithException : public SelectorLexeme {

    public:
        virtual stringstream select(stringstream& soourceProgram){
            return SelectorLexeme::select(soourceProgram);
        };

    protected:
        virtual std::regex getExceptionRegex() = 0;

    private:
        void checkOnException(stringstream soourceProgram);
    };
}
#endif //COMPILER_SELECTORWITHEXCEPTION_H
