
#ifndef BABUSHKA_2_DIVIDER_H
#define BABUSHKA_2_DIVIDER_H

#include "SelectorLexeme.h"

namespace  LexicalAnalysis::Selectors {
    class Dividerr : public SelectorLexeme {
    private:

        regex getRegex() override;

        LexType getLexType() override;
    };
}

#endif //BABUSHKA_2_DIVIDER_H