
#ifndef COMPILER_SELECTORLEXEME_H
#define COMPILER_SELECTORLEXEME_H

#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <iosfwd>
#include "../Lexeme.h"
#include "../TypeLexeme.h"

namespace LexicalAnalysis::Selectors {

    using namespace std;

    class CounterPosition{
        vector<int> positionJumps;
        bool worked = false;
    public:
        void countRows(string sourceProgram){
            if(worked)
                return;

            positionJumps.push_back(0);

            for(int i = 0; i < sourceProgram.size(); i++)
                if(sourceProgram[i] == '\n')
                    positionJumps.push_back(i);

            worked = true;
        }

        int getRowsBy(int indexSourceProgram){
            for(int i = 0; i < positionJumps.size(); i++)
                if(positionJumps[i] > indexSourceProgram)
                    return i;
        }

        int getColumnBy(int indexSourceProgram){
            int lastJump = positionJumps[getRowsBy(indexSourceProgram) - 1];
            return indexSourceProgram - lastJump;
        }
    };

    class SelectorLexeme {
        CounterPosition counterPosition;
        vector<Lexeme> streamSelectedLexeme;
    protected:
        virtual regex getRegex() = 0;
        virtual LexType getLexType() = 0;
    public:
        virtual stringstream select(stringstream& sourceProgram);

        auto begin() {
            return streamSelectedLexeme.begin();
        }

        auto end() {
            return streamSelectedLexeme.end();
        }
    };


}


#endif //COMPILER_SELECTORLEXEME_H