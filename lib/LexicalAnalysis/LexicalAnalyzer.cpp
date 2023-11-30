
#include <fstream>
#include <sstream>
#include "LexicalAnalyzer.h"

#include "Selectors/CommentSelector.h"
#include "Selectors/ConstSelector.h"
#include "Selectors/KeyWordSelector.h"
#include "Selectors/DividerSelector.h"
#include "Selectors/IdentificatorSelector.h"

#include "Selectors/Support/SelectorException.h"

namespace LexicalAnalysis {
    using namespace Selectors;

    LexicalAnalyzer::LexicalAnalyzer(std::string fileProgram) {
        //"C:\\Users\\glebl\\CLionProjects\\Compilers_22\\TEST.txt"
        currentProgram = getFullProgram(fileProgram);
        buildSelectors(currentProgram);

    }

    std::string LexicalAnalyzer::getFullProgram(std::string fileProgram) {
        ifstream in;
        in.open(fileProgram);

        stringstream stream;
        stream << in.rdbuf();
        return stream.str();
    }

    void LexicalAnalyzer::buildSelectors(string program) {
        auto commentSelector = new CommentSelector();
        auto constSelector = new ConstSelector();
        auto keyworldSelector = new KeyWorldSelector();
        auto dividerSelector = new DividerSelector();
        auto identificatorSelector = new IdentificatorSelector();

        allSelectors = {commentSelector, constSelector, keyworldSelector, dividerSelector, identificatorSelector};
        coolSelectors = {constSelector, identificatorSelector, keyworldSelector};

        CounterPosition counterPosition;
        counterPosition.countRows(program);
        for (auto selector: allSelectors)
            selector->setCounterPosition(counterPosition);
    }

    void LexicalAnalyzer::analize() {
        for (auto selector: allSelectors) {
            try {
                cout << "Current step lex analize: \n" << currentProgram << endl
                     << "_______________________" << endl;
                currentProgram = selector->select(currentProgram);
            }
            catch (SelectorException e) {
                cout << e.what() << endl;
                system("pause");
                throw exception();
            }
        }
        auto unknowLexemes = findAllEntry(currentProgram, regex(R"([^ \n]+)"));

        if (!unknowLexemes.empty()) {
            cout << "unknown tokens discovered: \n";
            for (auto unknowLexeme: unknowLexemes)
                cout << unknowLexeme.getContent() << endl;
            cout << endl;
            system("pause");
            throw exception();
        }
    }

    vector<Table<string>> LexicalAnalyzer::getTables() {
        vector<Table<string>> result;

        for (auto selector: coolSelectors)
            result.push_back(selector->getTable());
        return result;
    }

    vector<Lexeme> LexicalAnalyzer::getStreams() {

    }

    void LexicalAnalyzer::print() {
        for (auto selector: coolSelectors) {
            cout << "Stream lexeme of type " << lexTypeToString(selector->getLexType()) << endl;
            for (auto l: (*selector)) {
                cout << l << endl;
            }

            cout << "Table lexeme of type " << lexTypeToString(selector->getLexType()) << endl;
            auto table = selector->getTable();
            cout << table << endl;
        }
    }
}