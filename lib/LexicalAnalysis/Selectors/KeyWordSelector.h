
#ifndef BABUSHKA_2_KEYWORDSELECTOR_H
#define BABUSHKA_2_KEYWORDSELECTOR_H

#include "SelectorLexeme.h"

namespace  LexicalAnalysis::Selectors {
    class KeyWorldSelector : public SelectorLexeme {
    private:

        regex getRegex() override;

        LexType getLexType() override;

        bool isUnickLexeme() override;
    };
}

#endif //BABUSHKA_2_KEYWORDSELECTOR_H