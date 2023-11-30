
#ifndef COMPILER_COMMENTATOR_H
#define COMPILER_COMMENTATOR_H

#include "SelectorWithException.h"

namespace LexicalAnalysis::Selectors {

    class CommentSelector : public SelectorWithException {
    private:

        regex getRegex() override;

        regex getExceptionRegex() override;

        LexType getLexType() override;

        bool isUnickLexeme() override;
    };
}
#endif //COMPILER_COMMENTATOR_H
