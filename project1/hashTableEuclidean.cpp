#include "hashTableEuclidean.h"
#include <cstdlib>
#include <iostream>

#include "hashFunctionEuclidean.h"
#include "psedoRandomNumbers.h"
#include <bitset>

using namespace std;
//kapou elenxos gia k > 64 den douleuei

HashTableEuclidean::HashTableEuclidean(unsigned int NBuckets, int k, int dimensions, int W):nBuckets(NBuckets), kHashFunctions(k)
{
    if(NBuckets <= 0) return;

    totalSize = 0;

    buckets = new List<EuclideanNode*> *[nBuckets]; //kayaskeuazoume ena pinaka apo listes
    for(int i = 0; i < nBuckets; i++)
    {
        buckets[i] = new List<EuclideanNode*>();
    }

    gFunction = new HashFunctionEuclidean*[kHashFunctions]();
    for(int i=0; i< kHashFunctions; i++)
    {
        gFunction[i] = new HashFunctionEuclidean(dimensions, W);
    }

    rVariables = new int[kHashFunctions];
    for(int i=0; i< kHashFunctions;i++)
    {
        rVariables[i] = randomNumberInteger(); // mexri ton megalitero akeraio
    }
}

HashTableEuclidean::~HashTableEuclidean()
{
    EuclideanNode* tmp;
    for(int i = 0; i < nBuckets; i++)
    {
        tmp = buckets[i]->deleteFirstNode();
        while(tmp != NULL)
        {
            delete tmp;
            tmp = buckets[i]->deleteFirstNode();//diagrafoume ta stoixeia tis listas dn diagrafetai to T an einai dynamika desmeumeno tha exw leak
        }
        delete buckets[i]; //kai meta thn idia thn lista
        //buckets[i] = NULL;
    }
    delete []buckets;
    //buckets = NULL;


    for(int i =0; i < kHashFunctions; i++)
    {
        delete gFunction[i];
    }
    delete []gFunction;

    delete[] rVariables;


}


unsigned int HashTableEuclidean::hashFunction(Vector* key) //allagh, elenxos an douleuei
{
    return this->hashFunctionID(key)%nBuckets;
}

unsigned int HashTableEuclidean::hashFunctionID(Vector* key)
{
    int result =0;

    for(int i=0; i < kHashFunctions; i++)
    {
        result += (rVariables[i]*gFunction[i]->value(key))%M;
    }

    return result;
}

long long int HashTableEuclidean::get_TotalSize()
{
    return totalSize;
}

unsigned int HashTableEuclidean::get_nBuckets()
{
    return nBuckets;
}

Node<EuclideanNode* >* HashTableEuclidean::get_bucket(Vector* key)
{ //epistregei thn lista pou antistixei se auto to bucket
    return buckets[hashFunction(key)]->get_begin(); //mhpws douleuei xwris to ulong???
}

void HashTableEuclidean::insertNode(Vector* data)
{
    //if(searchNode(bAccount->getId()) != NULL) return false; //yparxei idi
    totalSize++;
    int id = this->hashFunctionID(data);
    EuclideanNode* tmp = new EuclideanNode(data, id);
    buckets[id%nBuckets]->insertEnd(tmp); //mesa sthn insert mporw na valw thn hashFunction anti gia thn praksh

}

void HashTableEuclidean::printSizeOfBuckets()
{
    for(int i =0; i < nBuckets; i++)
    {
        cout<<i<<"     "<<buckets[i]->getSize()<<endl;
    }
}
