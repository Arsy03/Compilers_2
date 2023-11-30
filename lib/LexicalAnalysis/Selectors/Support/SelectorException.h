
#ifndef BABUSHKA_2_SELECTOREXCEPTION_H
#define BABUSHKA_2_SELECTOREXCEPTION_H

#include "RegexProvider.h"
#include "../../TypeLexeme.h"
#include "CounterPositionInProgram.h"

namespace LexicalAnalysis::Selectors {

    class SelectorException : exception {
        LexType typeLexeme;
        vector<entry> entries;
        CounterPosition counterPosition;
    public:
        SelectorException(const LexType _typeLexeme, const vector<entry> &_entries,
                          const CounterPosition _counterPosition) {
            typeLexeme = _typeLexeme;
            entries = vector<entry>(_entries);
            counterPosition = _counterPosition;
        };

        string what();
    };
}

#endif //BABUSHKA_2_SELECTOREXCEPTION_H
