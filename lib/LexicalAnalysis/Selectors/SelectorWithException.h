
#ifndef COMPILER_SELECTORWITHEXCEPTION_H
#define COMPILER_SELECTORWITHEXCEPTION_H


#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors {

    template<typename TLexeme>
    class SelectorWithException : public SelectorLexeme<TLexeme> {

    public:
        virtual string select(string sourceProgram){
            return SelectorLexeme<TLexeme>::select(sourceProgram);
        };

    protected:
        virtual std::regex getExceptionRegex() = 0;

    private:
        void checkOnException(string sourceProgram){};
    };
}
#endif //COMPILER_SELECTORWITHEXCEPTION_H
