#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors {

    string SelectorLexeme::select(string source) {
        counterPosition.countRows(source);//TODO пперенести его в лекс анализер

        vector<entry> entries = findAllEntry(source);
        buildTableStreamLexeme(entries);

        source = clearEntries(source, entries);

        return source;
    }

    typedef std::regex_iterator<const char *> Myiter;
    vector<SelectorLexeme::entry> SelectorLexeme::findAllEntry(string source) {
        vector<entry> result;
        regex regexSelector = getRegex();

        const char *pat = source.c_str();
        Myiter::regex_type rx(regexSelector);
        Myiter next(pat, pat + source.size(), rx);
        Myiter end;

        for (; next != end; ++next)
            result.push_back(entry(next->position(), next->str()));

        return result;
    }

    void SelectorLexeme::buildTableStreamLexeme(const vector<entry> &entries) {
        for (auto entry: entries){
            auto tableElement = getTableElement(entry.getContent());

            tableLexeme.append(tableElement);

            LexType typeLexeme = getLexType();
            int numRowTable = tableLexeme.getNumRows(tableElement);
            int numRows = counterPosition.getRowsBy(entry.getStartPosition());
            int numColumn = counterPosition.getColumnBy(entry.getStartPosition());

            streamSelectedLexeme.push_back(Lexeme(typeLexeme, numRowTable, numRows, numColumn));
        }
    }

    string SelectorLexeme::clearEntries(string source, const vector<entry> &entries){
        for (auto entry: entries){
            for(int i = entry.getStartPosition(); i < entry.getEndPosition(); ++i)
                source[i] = ' ';
        }
        return source;
    }
}

