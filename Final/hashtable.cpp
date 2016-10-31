#include "hashtable.h"
#include <cstdlib>
#include <iostream>
//#include "bankAccount.h"
#include "hashFunction.h"
#include "euclideanNode.h"

using namespace std;

template <class T>
HashTable<T>::HashTable(int NBuckets, HashFunction<T>* hashMethod)
{
    if(NBuckets <= 0) return;

    nBuckets = NBuckets;
    totalSize = 0;

    buckets = new List<T> *[nBuckets]; //kayaskeuazoume ena pinaka apo listes
    for(int i = 0; i < nBuckets; i++)
    {
        buckets[i] = new List<T>();
    }

    gFunction = hashMethod;
}

template <class T>
HashTable<T>::~HashTable()
{
    for(int i = 0; i < nBuckets; i++)
    {
        delete buckets[i]; //kai meta thn idia thn lista
        //buckets[i] = NULL;
    }
    delete []buckets;
    //buckets = NULL;
}

template <class T>
unsigned int HashTable<T>::hashFunction(T key) //allagh, elenxos an douleuei
{
    return gFunction->HashFunctionHash(key);
}

template <class T>
int HashTable<T>::get_TotalSize()
{
    return totalSize;
}

template <class T>
int HashTable<T>::get_nBuckets()
{
    return nBuckets;
}

template <class T>
HashFunction<T>* HashTable<T>::getHashFunction()
{
    return gFunction;
}

template <class T>
Node<T>* HashTable<T>::get_bucket(T key)
{ //epistregei thn lista pou antistixei se auto to bucket
    return buckets[hashFunction(key)]->get_begin(); //mhpws douleuei xwris to ulong???
}

/*template <class T>
T HashTable<T>::searchNode(int key)
{
    Node<HashNode<T>*>* tmp = buckets[hashFunction(key)]->get_begin();

    while(tmp != NULL)
    {
        if(tmp->get_data()->get_key() == key)
        {
            return tmp->get_data()->get_data();
        }
        tmp = tmp->get_next();
    }
    return NULL;
}*/

template <class T>
void HashTable<T>::insertNode(T data)
{
    //if(searchNode(bAccount->getId()) != NULL) return false; //yparxei idi
    totalSize++;
    buckets[hashFunction(data)]->insertEnd(data);

}


//template <class T>
template<>
void HashTable<EuclideanNode*>::insertNode(EuclideanNode* data)
{
    totalSize++;
    //cout<<"TEST"<<endl;
    data->set_ID(gFunction->hashFunctionID(data));
    cout<<hashFunction(data)<<" "<<nBuckets<<endl;
    buckets[hashFunction(data)]->insertEnd(data);

}


/*template<> //template<>
void HashTable<EuclideanNode*>::insertNode(Vector* data)
{
    totalSize++;
    int id = gFunction->hashFunctionID();

    EuclideanNode* tmp = new EuclideanNode(data, id);
    buckets[hashFunction(data)]->insertEnd(tmp); //me thn praksh tha glutwsw ypologismous
}*/

/*
template <class T>
T HashTable<T>::deleteNode(int key)
{
    Node<HashNode<T>*>* tmp = buckets[hashFunction(key)]->get_begin();
    HashNode<T>* delNode;
    T returnValue;

    while(tmp != NULL)
    {
        if(tmp->get_data()->get_key() == key)
        {
            totalSize--;
            delNode = buckets[hashFunction(key)]->deleteNode(tmp);
            returnValue = delNode->get_data();
            delete delNode;

            return returnValue;
        }
        tmp = tmp->get_next();
    }

    return NULL;
}

template <class T>
T HashTable<T>::deleteFirstNode()
{
    Node<HashNode<T>*>* tmp;
    HashNode<T>* delNode;
    T returnValue;

    for(int i =0; i < nBuckets; i++)
    {
        delNode = buckets[i]->deleteFirstNode();
        if(delNode != NULL)
        {
            returnValue = delNode->get_data();
            delete delNode;

            return returnValue;
        }
    }

    return NULL;
}

*/

template <class T>
void HashTable<T>::printSizeOfBuckets()
{
    for(int i =0; i < nBuckets; i++)
    {
        cout<<i<<"     "<<buckets[i]->getSize()<<endl;
    }
}

template class HashTable<int>;
template class HashTable<Vector*>;
template class HashTable<Hamming*>;
template class HashTable<EuclideanNode*>;

