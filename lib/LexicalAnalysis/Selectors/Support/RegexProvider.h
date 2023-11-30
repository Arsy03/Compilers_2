
#ifndef BABUSHKA_2_REGEXPROVIDER_H
#define BABUSHKA_2_REGEXPROVIDER_H

#include <string>
#include <vector>
#include <regex>

using namespace std;

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

vector<entry> findAllEntry(const string &source, const regex &regexSelector);

#endif //BABUSHKA_2_REGEXPROVIDER_H
