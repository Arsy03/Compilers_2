
#ifndef COMPILER_SELECTORWITHEXCEPTION_H
#define COMPILER_SELECTORWITHEXCEPTION_H

#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors {

    class SelectorWithException : public SelectorLexeme {

    public:
        virtual string select(string sourceProgram) {
            string result = SelectorLexeme::select(sourceProgram);
            checkOnException(result);
            return result;
        };

    protected:
        virtual std::regex getExceptionRegex() = 0;

    private:
        void checkOnException(string sourceProgram);
    };

}
#endif //COMPILER_SELECTORWITHEXCEPTION_H
