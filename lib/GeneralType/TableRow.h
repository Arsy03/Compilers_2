
#ifndef COMPILER_TABLEROW_H
#define COMPILER_TABLEROW_H

template<typename T1 = short, typename T2 = short>
class TableRow{
    T1 t1;
    T2 t2;
public:


    auto operator[](int index){

    }

private:
    T1 get1(){
        return t1;
    }

    T2 get2(){
        return t2;
    }
};

#endif //COMPILER_TABLEROW_H
