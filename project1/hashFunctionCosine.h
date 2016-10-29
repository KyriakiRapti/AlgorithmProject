#ifndef Included_HashFunctionCosine_H
#define Included_HashFunctionCosine_H

//#include <bitset>
#include "dataTypes.h"

class HashFunctionCosine
{
    private:
        //const int keySize = 6;
        const int dimensions;
        double* rVariable;//r kanoniki katanomh

    public:
        HashFunctionCosine(int dim);
        ~HashFunctionCosine();

        bool value(Cosine* key); //prepei na epistrefei 0,1 1bit
};
#endif

