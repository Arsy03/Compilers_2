
#ifndef COMPILER_FORMABLETABLE_H
#define COMPILER_FORMABLETABLE_H

#include "../../GeneralType/Table.h"

template<typename T>
class FormableTable{
public:
    virtual Table<T> getTable() = 0;
};

#endif //COMPILER_FORMABLETABLE_H
