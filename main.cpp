#include <regex>
#include <iostream>
#include <fstream>

#include "set"
#include "lib/LexicalAnalysis/LexicalAnalyzer.h"

using namespace std;

using namespace LexicalAnalysis;

int main() {
    LexicalAnalyzer lexAnalizer("C:\\Users\\glebl\\CLionProjects\\Compilers_22\\TEST.txt");

    lexAnalizer.analize();
    lexAnalizer.print();

    system("pause");


    /* ifstream in;
     in.open();
     std::cout << "\033[31mКрасные буквы\033[0m" << std::endl;
     stringstream stream;
     stream << in.rdbuf();
     int f;
     cin >> f;
     LexicalAnalysis::Selectors::IdentificatorSelector keywSelector;

     CounterPosition counterPosition;
     counterPosition.countRows(stream.str());

     keywSelector.setCounterPosition(counterPosition);

     string programAfter;
     try {
         programAfter = keywSelector.select(stream.str());
     }
     catch (SelectorException e){
         cout << e.what();
     }
     for(auto l : keywSelector){
         cout << l << endl;
     }

     auto table = keywSelector.getTable();
     cout << table;


     cout << programAfter;

     return  0 ;*/
    std::string text = "+++++ \" jkgrn ik\"erjbng er"s;
    text = "+++++ \" jkgrn ik\"erjbng er"s;
    //std::regex er(R"((\")([^"]+)(\"))");
    smatch m;


}