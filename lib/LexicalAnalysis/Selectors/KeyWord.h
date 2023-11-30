
#ifndef BABUSHKA_2_KEYWORD_H
#define BABUSHKA_2_KEYWORD_H

#include "SelectorLexeme.h"

namespace  LexicalAnalysis::Selectors {
    class KeyWorld : public SelectorLexeme {
    private:

        regex getRegex() override;

        LexType getLexType() override;
    };
}

#endif //BABUSHKA_2_KEYWORD_H