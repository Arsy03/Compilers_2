
#ifndef COMPILER_SELECTORLEXEME_H
#define COMPILER_SELECTORLEXEME_H

#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <iosfwd>
#include "../Lexeme.h"
#include "../TypeLexeme.h"
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
        }

        int getColumnBy(int indexSourceProgram) {
            int lastJump = positionJumps[getRowsBy(indexSourceProgram) - 1];
            return indexSourceProgram - lastJump;
        }
    };

    template<typename TLexeme>
    class SelectorLexeme : public FormableTable<TLexeme> {
        CounterPosition counterPosition; //TODO передавть конструктором из лекс анализера

        vector<Lexeme> streamSelectedLexeme;
    protected:
        virtual regex getRegex() = 0;

        virtual LexType getLexType() = 0;

    public:
        typedef std::regex_iterator<const char *> Myiter;
        virtual string select(string source){
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
        };

        virtual Table<TLexeme> getTable() {
            return Table<TLexeme>();
        };

        auto begin() {
            return streamSelectedLexeme.begin();
        }

        auto end() {
            return streamSelectedLexeme.end();
        }
    };


}

#endif //COMPILER_SELECTORLEXEME_H