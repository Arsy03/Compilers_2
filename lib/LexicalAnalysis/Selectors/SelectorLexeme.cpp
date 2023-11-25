/*#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors{

    typedef std::regex_iterator<const char *> Myiter;
    template<typename TLexeme>
    string SelectorLexeme<TLexeme>::select(string source) {
        counterPosition.countRows(source);//TODO пперенести его в лекс анализер

        regex regexSelector = getRegex();

        const char *pat = source.c_str();
        Myiter::regex_type rx(regexSelector);
        Myiter next(pat, pat + source.size(), rx);
        Myiter end;

        for (; next != end; ++next) {
            int startIndex = next->position() + 1;
             // TODO Сохранить значение в таблицу
            streamSelectedLexeme.push_back( //TODO +индекс в таблице с типом LexType
                    Lexeme(getLexType(),
                    counterPosition.getRowsBy(startIndex),
                    counterPosition.getColumnBy(startIndex)));

            startIndex = next->position();
            int endIndex = next->position() + next->str().size();
            for(int i = startIndex; i < endIndex; ++i)
                source[i] = ' ';
        }

        return source;
    }
}

*/