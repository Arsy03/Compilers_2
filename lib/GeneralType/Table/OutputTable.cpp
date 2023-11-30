#include "OutputTable.h"

namespace OutputTable {
    string replaceSpaces(const string &input) {
        char space = '@';
        std::string result = input;
        size_t found = result.find(space);

        while (found != std::string::npos) {
            result.replace(found, 1, separatorColumn); // Заменяем пробел на табуляцию
            found = result.find(space, found + 1); // Ищем следующий пробел
        }

        return result;
    }
}