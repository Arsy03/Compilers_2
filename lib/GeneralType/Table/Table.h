
#ifndef COMPILER_TABLE_H
#define COMPILER_TABLE_H

#include "OutputTable.h"
#include <set>

using namespace std;
using namespace OutputTable;

template<typename T>
class Table {
    vector<string> header;
    vector<T> rows;

public:
    Table(){
        setHeader({"N", "content"});
    }

    void setHeader(const std::vector<std::string> &_header) {
        header = vector<string>(_header);
    }

    int width() const {
        return header.size();
    }

    int height() const {
        return rows.size();
    }

    void append(const T& obj){
        rows.push_back(obj);
    }

    int getNumRows(const T& obj) const{
        auto it = std::find(rows.begin(), rows.end(), obj);
        if (it != rows.end()) {
            size_t position = std::distance(rows.begin(), it);
            return position + 1;
        }

        return -1;
    }

    bool contains(const T& obj){
        return getNumRows(obj) != -1;
    }

    /*T &operator[](int row) const {
        return rows[row - 1];
    }*/

    auto begin() const{
        return rows.begin();
    }

    auto end() const{
        return rows.end();
    }

    friend ostream &operator<<(ostream &os, const Table<T> &table) {
        for (const auto &col: table.header) {
            os << col << separatorColumn; // Используем табуляцию в качестве разделителя
        }
        os << separatorRow;

        int i = 1;
        auto begin = table.rows.begin();
        auto end = table.rows.end();

        for (auto row : table.rows) {
            stringstream ss;
            ss << i++ << separatorColumn << row;
            string rowStr = ss.str();
            os << replaceSpaces(rowStr) << separatorRow;
        }
        return os;
    };
};





#endif //COMPILER_TABLE_H
