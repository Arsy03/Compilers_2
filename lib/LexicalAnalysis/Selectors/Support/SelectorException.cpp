
#include "SelectorException.h"

string LexicalAnalysis::Selectors::SelectorException::what() {
    stringstream ssresult;
    ssresult << "detected incorrect tokens of type: " << lexTypeToString(typeLexeme) << endl;

    ssresult << "entries: " << endl;
    for (auto entry: entries) {
        ssresult << "\t" << "entry: " << entry.getContent() << endl;
        ssresult << "\t" << "position: " <<
                 "row - " << counterPosition.getRowsBy(entry.getStartPosition()) << " : "
                 "column - " << counterPosition.getColumnBy(entry.getStartPosition()) << endl;
    }

    return  ssresult.str();
}
