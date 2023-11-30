
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

    class SelectorLexeme : public FormableTable<string> {
    protected:
        CounterPosition counterPosition; //TODO передавть конструктором из лекс анализера

        Table<string> tableLexeme;
        vector<Lexeme> streamSelectedLexeme;
    protected:
        virtual regex getRegex() = 0;

        virtual bool isUnickLexeme() = 0;

    public:
        virtual LexType getLexType() = 0;

        virtual string select(string source);

        virtual Table<string> getTable() {
            return tableLexeme;
        };

        void setCounterPosition(CounterPosition _counterPosition) {
            counterPosition = _counterPosition;
        }

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