
#ifndef BABUSHKA_2_COUNTERPOSITIONINPROGRAM_H
#define BABUSHKA_2_COUNTERPOSITIONINPROGRAM_H

#include <vector>
#include <string>

using namespace std;

class CounterPosition {
    vector<int> positionJumps;
    bool worked = false;
public:
    void countRows(string sourceProgram) {
        if (worked)
            return;

        positionJumps.push_back(0);

        for (int i = 0; i < sourceProgram.size(); i++)
            if (sourceProgram[i] == '\n')
                positionJumps.push_back(i);

        positionJumps.push_back(sourceProgram.size());

        worked = true;
    }

    int getRowsBy(int indexSourceProgram) {
        for (int i = 0; i < positionJumps.size(); i++)
            if (positionJumps[i] > indexSourceProgram)
                return i;
        return -1;
    }

    int getColumnBy(int indexSourceProgram) {
        int lastJump = positionJumps[getRowsBy(indexSourceProgram) - 1];
        return indexSourceProgram - lastJump + 1;
    }
};

#endif //BABUSHKA_2_COUNTERPOSITIONINPROGRAM_H
