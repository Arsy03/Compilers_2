#include <regex>
#include <iostream>
#include <fstream>
#include "lib/LexicalAnalysis/Selectors/CommentSelector.h"
#include "set"
#include "lib/LexicalAnalysis/Selectors/Support/SelectorException.h"

using namespace std;

using namespace LexicalAnalysis::Selectors;

int main()
{
    ifstream in;
    in.open("C:\\Users\\glebl\\CLionProjects\\Babushka_2 (1)\\Babushka_2\\TEST.txt");

    stringstream stream;
    stream << in.rdbuf();

    LexicalAnalysis::Selectors::CommentSelector commentator;

    string programAfter;
    try {
        programAfter = commentator.select(stream.str());
    }
    catch (SelectorException e){
        cout << e.what();
    }
    for(auto l : commentator){
        cout << l << endl;
    }

    auto table = commentator.getTable();
    cout << table;


    cout << programAfter;

    return  0 ;
    std::string text =  "+++++ \" jkgrn ik\"erjbng er"s;
    text =  "+++++ \" jkgrn ik\"erjbng er"s;
    //std::regex er(R"((\")([^"]+)(\"))");
    smatch m;


}