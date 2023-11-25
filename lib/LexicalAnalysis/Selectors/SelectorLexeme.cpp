#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors{

    typedef std::regex_iterator<const char *> Myiter;
    stringstream SelectorLexeme::select(stringstream& sourceProgram) {
        string stringSource = sourceProgram.str();
        counterPosition.countRows(stringSource);

        regex regexSelector = getRegex();

        const char *pat = stringSource.c_str();
        Myiter::regex_type rx(regexSelector);
        Myiter next(pat, pat + strlen(pat), rx);
        Myiter end;

        for (; next != end; ++next) {
            int startIndex = next->position() + 1;
             // TODO Сохранить значение в таблицу
            streamSelectedLexeme.push_back(
                    Lexeme(getLexType(),
                    counterPosition.getRowsBy(startIndex),
                    counterPosition.getColumnBy(startIndex)));

            startIndex = next->position();
            int endIndex = next->position() + next->str().size();
            for(int i = startIndex; i < endIndex; ++i)
                stringSource[i] = ' ';
        }

        return std::stringstream(stringSource);
    }
}

