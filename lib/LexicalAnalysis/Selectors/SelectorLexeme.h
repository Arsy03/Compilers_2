
#ifndef COMPILER_SELECTORLEXEME_H
#define COMPILER_SELECTORLEXEME_H

#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <iosfwd>
#include "../Lexeme.h"
#include "../TypeLexeme.h"
#include "../TableElementLexeme.h"
#include "FormableTable.h"
#include "Support/RegexProvider.h"
#include "Support/CounterPositionInProgram.h"

namespace LexicalAnalysis::Selectors {

    using namespace std;

    class SelectorLexeme : public FormableTable<TableElementLexeme> {
    protected:
        CounterPosition counterPosition; //TODO передавть конструктором из лекс анализера

        Table<TableElementLexeme> tableLexeme;
        vector<Lexeme> streamSelectedLexeme;
    protected:
        virtual regex getRegex() = 0;

        virtual LexType getLexType() = 0;

        virtual TableElementLexeme getTableElement(string content) = 0;

    public:
        virtual string select(string source);

        virtual Table<TableElementLexeme> getTable() {
            return tableLexeme;
        };

        auto begin() {
            return streamSelectedLexeme.begin();
        }

        auto end() {
            return streamSelectedLexeme.end();
        }

    private:
        void buildTableStreamLexeme(const vector<entry> &entries);

        string clearEntries(string source, const vector<entry> &entries);
    };


}

#endif //COMPILER_SELECTORLEXEME_H