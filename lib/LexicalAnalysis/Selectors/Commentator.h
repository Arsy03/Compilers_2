
#ifndef COMPILER_COMMENTATOR_H
#define COMPILER_COMMENTATOR_H

#include "SelectorWithException.h"

namespace  LexicalAnalysis::Selectors {
    class Commentator : public SelectorWithException {
    private:

        regex getRegex() override;

        regex getExceptionRegex() override ;

        LexType getLexType() override;
    };
}
#endif //COMPILER_COMMENTATOR_H
