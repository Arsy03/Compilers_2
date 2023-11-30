
#ifndef COMPILER_LEXICALANALYZER_H
#define COMPILER_LEXICALANALYZER_H

#include <string>
#include "Selectors/SelectorLexeme.h"

namespace LexicalAnalysis {
    using namespace Selectors;
    using namespace std;

    class LexicalAnalyzer {
    private:
        string currentProgram;

        vector<SelectorLexeme*> allSelectors;
        vector<SelectorLexeme*> coolSelectors;
    public:
        LexicalAnalyzer(string fileProgram);

        void analize();

        void print();

        vector<Table<string>> getTables();

        vector<Lexeme> getStreams();
    private:
        string getFullProgram(string fileProgram);

        void buildSelectors(string program);
    };
}

#endif //COMPILER_LEXICALANALYZER_H
