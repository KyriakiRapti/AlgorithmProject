#ifndef Included_HashFunctionCosine_H
#define Included_HashFunctionCosine_H

#include "dataTypes.h"

class HashFunctionCosine
{
    private:
        const int dimensions;
        double* rVariable; //r kanoniki katanomh

    public:
        HashFunctionCosine(int dim);
        ~HashFunctionCosine();

        bool value(Vector* key); //prepei na epistrefei 0,1 1bit
        void stats();
};
#endif

