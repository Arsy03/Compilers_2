
#include <sstream>
#include "Table.h"

namespace OutPutTable {

    const string separatorColumn = "\t";
    const string separatorRow = "\n";
    

    string replaceSpaces(const string &input) {
        std::string result = input;
        size_t found = result.find(' ');

        while (found != std::string::npos) {
            result.replace(found, 1, separatorColumn); // Заменяем пробел на табуляцию
            found = result.find(' ', found + 1); // Ищем следующий пробел
        }

        return result;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const Table<T> &obj) {
        for (const auto &col: obj.header) {
            os << col << separatorColumn; // Используем табуляцию в качестве разделителя
        }
        os << separatorRow;

        for (int i = 0; i < obj.height(); i++) {
            stringstream ss;
            ss << obj.rows[i];
            string rowStr = ss.str();
            os << replaceSpaces(rowStr) << separatorRow;
        }

        return os;
    }
}