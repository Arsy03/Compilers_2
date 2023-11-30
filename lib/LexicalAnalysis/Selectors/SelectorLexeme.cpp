#include "SelectorLexeme.h"

namespace LexicalAnalysis::Selectors {

    string SelectorLexeme::select(string source) {
        counterPosition.countRows(source);//TODO пперенести его в лекс анализер

        vector<entry> entries = findAllEntry(source, getRegex());
        buildTableStreamLexeme(entries);

        source = clearEntries(source, entries);

        return source;
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

