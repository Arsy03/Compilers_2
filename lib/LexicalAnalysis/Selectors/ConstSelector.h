
#ifndef BABUSHKA_2_CONSTSELECTOR_H
#define BABUSHKA_2_CONSTSELECTOR_H

#include "SelectorWithException.h"
#include "FormableTable.h"

namespace  LexicalAnalysis::Selectors {

    class ConstSelector : public SelectorWithException{
    private:

        regex getRegex() override;

        regex getExceptionRegex() override ;

        LexType getLexType() override;

        bool isUnickLexeme() override;
    };
}

#endif //BABUSHKA_2_CONSTSELECTOR_H
