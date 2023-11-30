#include "RegexProvider.h"

typedef std::regex_iterator<const char *> Myiter;
vector<entry> findAllEntry(const string &source, const regex &regexSelector) {
    vector<entry> result;

    const char *pat = source.c_str();
    Myiter::regex_type rx(regexSelector);
    Myiter next(pat, pat + source.size(), rx);
    Myiter end;

    for (; next != end; ++next)
        result.push_back(entry(next->position(), next->str()));

    return result;
}
