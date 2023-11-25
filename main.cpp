#include <regex>
#include <iostream>
#include <fstream>
#include "lib/LexicalAnalysis/Selectors/CommentSelector.h"

using namespace std;

int main()
{
    ifstream in;
    in.open("C:\\Users\\glebl\\CLionProjects\\Babushka_2 (1)\\Babushka_2\\TEST.txt");

    stringstream stream;
    stream << in.rdbuf();

    LexicalAnalysis::Selectors::CommentSelector commentator;

    string programAfter = commentator.select(stream.str());

    for(auto l : commentator){
        cout << l << endl;
    }

    cout << programAfter;

    return  0 ;
    std::string text =  "+++++ \" jkgrn ik\"erjbng er"s;
    text =  "+++++ \" jkgrn ik\"erjbng er"s;
    //std::regex er(R"((\")([^"]+)(\"))");
    smatch m;


}