// std__regex__regex_iterator.cpp
// compile with: /EHsc
#include <regex>
#include <iostream>

typedef std::regex_iterator<const char *> Myiter;
int main()
{
    std::string pat = "123 djmrol 456";
    const char* pat0 = pat.c_str();
    Myiter::regex_type rx("\\d+");
    Myiter next(pat0, pat0 + pat.size(), rx);
    Myiter end;

    for (; next != end; ++next)
        std::cout << "match == " << next->str() << std::endl;
}