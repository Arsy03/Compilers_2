
#ifndef BABUSHKA_2_OUTPUTTABLE_H
#define BABUSHKA_2_OUTPUTTABLE_H

#include <string>

using namespace std;

namespace OutputTable {
    const string separatorColumn = "\t";
    const string separatorRow = "\n";

    string replaceSpaces(const string &input);
}

#endif //BABUSHKA_2_OUTPUTTABLE_H
