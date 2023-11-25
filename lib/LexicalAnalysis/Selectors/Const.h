
#ifndef BABUSHKA_2_CONST_H
#define BABUSHKA_2_CONST_H

#include "SelectorWithException.h"
#include "FormableTable.h"

namespace  LexicalAnalysis::Selectors {

    class Const{
    private:
        static int countInstance;
        string content;
        int hash;
    public:
        Const(string _content) : content(_content), hash(countInstance) { countInstance++; };

        int getHash() { return hash; };
    };

    class ConstSelector : public SelectorWithException<Const>{
    private:

        regex getRegex() override;

        regex getExceptionRegex() override ;

        LexType getLexType() override;
    };
}

#endif //BABUSHKA_2_CONST_H
