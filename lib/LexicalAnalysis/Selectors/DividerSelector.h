
#ifndef BABUSHKA_2_DIVIDER_H
#define BABUSHKA_2_DIVIDER_H

#include "SelectorLexeme.h"

namespace  LexicalAnalysis::Selectors {
    class DividerSelector : public SelectorLexeme {
    private:

        regex getRegex() override;

        LexType getLexType() override;

        bool isUnickLexeme() override;
    };
}

#endif //BABUSHKA_2_DIVIDER_H