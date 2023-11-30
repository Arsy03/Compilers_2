
#ifndef BABUSHKA_2_IDENTIFICATOR_H
#define BABUSHKA_2_IDENTIFICATOR_H

#include "SelectorLexeme.h"

namespace  LexicalAnalysis::Selectors {
    class Ident : public SelectorLexeme {
    private:

        regex getRegex() override;

        LexType getLexType() override;
    };
}

#endif //BABUSHKA_2_IDENTIFICATOR_H