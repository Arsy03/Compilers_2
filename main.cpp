#include <regex>
#include <iostream>
#include <fstream>
#include "lib/LexicalAnalysis/Selectors/Commentator.h"

using namespace std;

typedef std::regex_iterator<const char *> Myiter;
int main()
{
    ifstream in;
    in.open("E:\\Workspace\\Clion_Projects\\Babushka_2\\TEST.txt");

    stringstream stream;
    stream << in.rdbuf();

    LexicalAnalysis::Selectors::Commentator commentator;

    stream = commentator.select(stream);

    for(auto l : commentator){
        cout << l << endl;
    }

    cout << stream.rdbuf();

    return  0 ;
    std::string text =  "+++++ \" jkgrn ik\"erjbng er"s;
    text =  "+++++ \" jkgrn ik\"erjbng er"s;
    //std::regex er(R"((\")([^"]+)(\"))");
    smatch m;


    //cout << std::regex_search(text, m, er);
    cout << m.str();

    std::string pats = " dfg\" false 45 true ";
    const char *pat = pats.c_str();
    Myiter::regex_type rx(R"(\")");
    Myiter next(pat, pat + strlen(pat), rx);
    Myiter end;

    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;
}