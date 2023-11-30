
#ifndef BABUSHKA_2_IDENTIFICATORSELECTOR_H
#define BABUSHKA_2_IDENTIFICATORSELECTOR_H

#include "SelectorLexeme.h"

namespace  LexicalAnalysis::Selectors {
    class IdentificatorSelector : public SelectorLexeme {
    private:

        regex getRegex() override;

        LexType getLexType() override;

        bool isUnickLexeme() override;
    };
}

#endif //BABUSHKA_2_IDENTIFICATORSELECTOR_H