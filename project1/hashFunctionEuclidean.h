#ifndef Included_HashFunctionEuclidean_H
#define Included_HashFunctionEuclidean_H

//#include <bitset>
#include "dataTypes.h"

class HashFunctionEuclidean
{
    private:
        //const int keySize = 6;
        const int w;
        const int dimensions;
        double tVar;
        double* vVariable;//r kanoniki katanomh


    public:
        HashFunctionEuclidean(int dim, int W);
        ~HashFunctionEuclidean();

        int value(Vector* key); //prepei na epistrefei 0,1 1bit
};
#endif

