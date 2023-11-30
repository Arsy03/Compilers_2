#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors{
    stringstream SelectorLexeme::select(stringstream sourceProgram) {
        string stringSource = sourceProgram.str();
        regex regexSelector = getRegex();


        return std::stringstream();
    }

}

