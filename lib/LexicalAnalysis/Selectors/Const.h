
#ifndef BABUSHKA_2_CONST_H
#define BABUSHKA_2_CONST_H

#include "SelectorWithException.h"
#include "FormableTable.h"

namespace  LexicalAnalysis::Selectors {
    class ConstSelector : public SelectorWithException, FormableTable <string> {
    private:

        regex getRegex() override;

        regex getExceptionRegex() override ;

        LexType getLexType() override;


    };
}

#endif //BABUSHKA_2_CONST_H
