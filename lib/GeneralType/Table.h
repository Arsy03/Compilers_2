
#ifndef COMPILER_TABLE_H
#define COMPILER_TABLE_H


#include <vector>
#include <string>

using namespace std;

template<typename T>
class Table {
    vector<string> header;
    vector<T> rows;

public:
    void setHeader(const std::vector<std::string> &_header) {
        header = vector<string>(_header);
    }

    int width() const {
        return header.size();
    }

    int height() const {
        return rows.size();
    }

    T &operator[](int row) {
        return rows[row];
    }

    friend ostream &operator<<(ostream &os, const Table &obj);
};


#endif //COMPILER_TABLE_H
