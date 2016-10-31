#include "hashFunction.h"
#include <stdlib.h>


template <class T>
HashFunction<T>::HashFunction()
{

}

template <class T>
unsigned int HashFunction<T>::HashFunctionHash(T key) //allagh, elenxos an douleuei
{
    return (int) key;
}

//---------------------------------------------------------

HashFunction<Vector*>::HashFunction(int K, int Dimensions):kHashFunctions(K), dimensions(Dimensions)
{
    gFunction = new HashFunctionCosine*[kHashFunctions]();
    for(int i=0; i< kHashFunctions; i++)
    {
        gFunction[i] = new HashFunctionCosine(dimensions);
    }
}

HashFunction<Vector*>::~HashFunction()
{
    for(int i =0; i < kHashFunctions; i++)
    {
        delete gFunction[i];
    }
    delete []gFunction;
}


unsigned int HashFunction<Vector*>::HashFunctionHash(Vector* key) //allagh, elenxos an douleuei
{
    std::bitset<sizeof(unsigned int)> fBit; //h 32, 64

    for(int i=0; i < kHashFunctions; i++)
    {
        if(gFunction[i]->value(key)) //true
        {
            fBit[kHashFunctions-i-1] = 1;
        }
        else
        {
            fBit[kHashFunctions-i-1] = 0;
        }
    }
    return fBit.to_ulong();
}

//---------------------------------------------

HashFunction<Hamming*>::HashFunction(int K, int noBts):kHashFunctions(K), noBits(noBts)
{
    gFunction = new int[kHashFunctions];
    for(int i =0; i < kHashFunctions; i++)
    {
        gFunction[i] = randomNumberInt(0,noBts-1); //times apo 0 mexri number of bits-1
        //std::cout<<gFunction[i]<<" ";
    }
    //std::cout<<std::endl;
}

HashFunction<Hamming*>::~HashFunction()
{
    delete []gFunction;
}

//template<>
unsigned int HashFunction<Hamming*>::HashFunctionHash(Hamming* key) //allagh, elenxos an douleuei
{
    std::bitset<64> fBit; //h 32, 64
    std::bitset<64> inputBitset;

    key->get_bitString(inputBitset);

    for(int i=0;i<kHashFunctions;i++)
    {
        fBit[kHashFunctions-i-1]=inputBitset[noBits-gFunction[i]-1];
        //std::cout<<"/"<<noBits-gFunction[i]-1<<"/"<<inputBitset[noBits-gFunction[i]-1]<<std::endl;
    }

    return fBit.to_ulong();
}

//------------------------------------------------
HashFunction<EuclideanNode*>::HashFunction(int K, int Dimensions, int W, int noBuckets):kHashFunctions(K), dimensions(Dimensions), nBuckets(noBuckets)
{
    gFunction = new HashFunctionEuclidean*[kHashFunctions]();
    for(int i=0; i< kHashFunctions; i++)
    {
        gFunction[i] = new HashFunctionEuclidean(dimensions, W);
    }

    rVariables = new int[kHashFunctions];
    for(int i=0; i< kHashFunctions;i++)
    {
        rVariables[i] = rand();//randomNumberInteger(); // mexri ton megalitero akeraio
    }
}

HashFunction<EuclideanNode*>::~HashFunction()
{
    for(int i =0; i < kHashFunctions; i++)
    {
        delete gFunction[i];
    }
    delete []gFunction;

    delete []rVariables;
}

unsigned int HashFunction<EuclideanNode*>::HashFunctionHash(EuclideanNode* key)
{
    return (this->hashFunctionID(key)%nBuckets+nBuckets)%nBuckets;
}

int HashFunction<EuclideanNode*>::hashFunctionID(EuclideanNode* key)
{
    long long int result =0;

    for(int i=0; i < kHashFunctions; i++)
    {
        result += (rVariables[i]*gFunction[i]->value(key->get_vector()))%M;
    }

    return (int) result%M; //mod M
}

template class HashFunction<int>;
template class HashFunction<Vector*>;
template class HashFunction<Hamming*>;
template class HashFunction<EuclideanNode*>;

