#include "hashTableCosine.h"
#include <cstdlib>
#include <iostream>

#include "hashFunctionCosine.h"
#include <bitset>

using namespace std;
//kapou elenxos gia k > 64 den douleuei

HashTableCosine::HashTableCosine(unsigned int NBuckets, int k, int dimensions):nBuckets(NBuckets), kHashFunctions(k)
{
    if(NBuckets <= 0) return;

    totalSize = 0;

    buckets = new List<Vector*> *[nBuckets]; //kayaskeuazoume ena pinaka apo listes
    for(int i = 0; i < nBuckets; i++)
    {
        buckets[i] = new List<Vector*>();
    }

    gFunction = new HashFunctionCosine*[kHashFunctions]();
    for(int i=0; i< kHashFunctions; i++)
    {
        gFunction[i] = new HashFunctionCosine(dimensions);
    }
}

HashTableCosine::~HashTableCosine()
{
    for(int i = 0; i < nBuckets; i++)
    {
        /*tmp = buckets[i]->deleteFirstNode();
        while(tmp != NULL)
        {
            delete tmp;
            tmp = buckets[i]->deleteFirstNode();//diagrafoume ta stoixeia tis listas dn diagrafetai to T an einai dynamika desmeumeno tha exw leak
        }*/
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


}


unsigned int HashTableCosine::hashFunction(Vector* key) //allagh, elenxos an douleuei
{//
    bitset<sizeof(unsigned int)> fBit; //h 32, 64

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
    /*string tmp;
    string fBitset;
    //unsigned int result;

    for(int i=0; i< KEYSIZE; i++)
    {
        tmp = gFunction[i]->value(key).to_string();
        fBitset += tmp;
    }
    cout<<"fbit"<<fBitset<<" "<< bitset<KEYSIZE>(fBitset)<<endl;


    return atoll(fBitset.c_str());*/
}

long long int HashTableCosine::get_TotalSize()
{
    return totalSize;
}

unsigned int HashTableCosine::get_nBuckets()
{
    return nBuckets;
}

Node<Vector* >* HashTableCosine::get_bucket(Vector* key)
{ //epistregei thn lista pou antistixei se auto to bucket
    return buckets[hashFunction(key)]->get_begin(); //mhpws douleuei xwris to ulong???
}

void HashTableCosine::insertNode(Vector* data)
{
    //if(searchNode(bAccount->getId()) != NULL) return false; //yparxei idi
    totalSize++;
    buckets[hashFunction(data)]->insertEnd(data);

}

void HashTableCosine::printSizeOfBuckets()
{
    for(int i =0; i < nBuckets; i++)
    {
        cout<<i<<"     "<<buckets[i]->getSize()<<endl;
    }
}
