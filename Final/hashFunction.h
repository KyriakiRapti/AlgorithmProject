#ifndef Included_HashFunction_H
#define Included_HashFunction_H

#include "dataTypes.h"
#include "euclideanNode.h"
#include <bitset>

#include "hashFunctionCosine.h"
#include "psedoRandomNumbers.h"
#include "hashFunctionEuclidean.h"

#define M 4294967291 //2^32-5

template<class T>
class HashFunction
{
    private:

    public:
        HashFunction();
        unsigned int HashFunctionHash(T key);

};

template<>
class HashFunction<Vector*>
{
    private:
        const int dimensions;
        const int kHashFunctions;
        HashFunctionCosine** gFunction;


    public:
        HashFunction(int K, int Dimensions);
        ~HashFunction();

        unsigned int HashFunctionHash(Vector* key);
};

template<>
class HashFunction<Hamming*>
{
    private:
        const int kHashFunctions;
        const int noBits;
        int* gFunction;


    public:
        HashFunction(int K, int noBts);
        ~HashFunction();

        unsigned int HashFunctionHash(Hamming* key);
};

template<>
class HashFunction<EuclideanNode*>
{
    private:
        const int dimensions;
        const int kHashFunctions;
        const int nBuckets;
        HashFunctionEuclidean** gFunction;
        int* rVariables;


    public:
        HashFunction(int K, int Dimensions, int W, int noBuckets);
        ~HashFunction();

        unsigned int HashFunctionHash(EuclideanNode* key);

        int hashFunctionID(EuclideanNode* key);
};
#endif // Included_HashFunction_H

