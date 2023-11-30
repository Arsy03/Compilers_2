
#ifndef BABUSHKA_2_TABLEELEMENTLEXEME_H
#define BABUSHKA_2_TABLEELEMENTLEXEME_H

#include <string>

using namespace std;

class TableElementLexeme{
protected:
    string content;
    int hash;
public:
    int getHash() const { return hash; };

    string getContent() const { return content; }

    bool operator<(const TableElementLexeme& other) const{
        return this->hash < other.hash;
    };

    bool operator==(const TableElementLexeme& other) const{
        return this->hash == other.hash;
    };

    friend ostream &operator<<(ostream &os, const TableElementLexeme &obj){
        os << obj.content;
        return os;
    }
};

class RepeatTableElementLexeme : public TableElementLexeme{
private:
    std::hash<string> hasher;
public:
    RepeatTableElementLexeme(string _content){
        content = _content;
        hash = hasher(_content);
    }
};

class UniqueTableElementLexeme : public TableElementLexeme{
private:
    static int countInstance;

public:
    UniqueTableElementLexeme(string _content){
        content = _content;
        hash = countInstance;
        countInstance++;
    }
};


#endif //BABUSHKA_2_TABLEELEMENTLEXEME_H
