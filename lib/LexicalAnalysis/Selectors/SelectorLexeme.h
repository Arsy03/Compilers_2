
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

namespace LexicalAnalysis::Selectors {

    using namespace std;

    class CounterPosition {
        vector<int> positionJumps;
        bool worked = false;
    public:
        void countRows(string sourceProgram) {
            if (worked)
                return;

            positionJumps.push_back(0);

            for (int i = 0; i < sourceProgram.size(); i++)
                if (sourceProgram[i] == '\n')
                    positionJumps.push_back(i);

            positionJumps.push_back(sourceProgram.size());

            worked = true;
        }

        int getRowsBy(int indexSourceProgram) {
            for (int i = 0; i < positionJumps.size(); i++)
                if (positionJumps[i] > indexSourceProgram)
                    return i;
            return -1;
        }

        int getColumnBy(int indexSourceProgram) {
            int lastJump = positionJumps[getRowsBy(indexSourceProgram) - 1];
            return indexSourceProgram - lastJump + 1;
        }
    };

    class SelectorLexeme : public FormableTable<TableElementLexeme> {
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
        struct entry {
        private:
            int startPosition;
            string content;
        public:
            entry(int _startPosition, string _content) : startPosition(_startPosition), content(_content) {};

            int getStartPosition() { return startPosition; };

            int getEndPosition() { return startPosition + content.size(); };

            string getContent() { return content; };

        };

        vector<entry> findAllEntry(string source);

        void buildTableStreamLexeme(const vector<entry> &entries);

        string clearEntries(string source, const vector<entry> &entries);
    };


}

#endif //COMPILER_SELECTORLEXEME_H