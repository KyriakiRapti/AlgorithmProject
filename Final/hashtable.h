#ifndef Included_HashTable_H
#define Included_HashTable_H

#include "List.h"
#include "Node.h"
#include "hashFunction.h"

template <class T>
class HashTable
{
    private:
        //const int keySize;
        int nBuckets;
        int totalSize;
        List<T>** buckets;
        HashFunction<T>* gFunction;

        unsigned int hashFunction(T key); //auto tha mporouse na einai 4-6 bits anti gia int, 'h estw char
        //bool checkID(int id);
    public:
        HashTable(int NBuckets, HashFunction<T>* hashMethod);
        ~HashTable();

        int get_TotalSize();
        int get_nBuckets();
        HashFunction<T>* getHashFunction();

        Node<T>* get_bucket(T key);

        void insertNode(T data);
        //template <> void insertNode<EuclideanNode*>(Vector* data);

        void printSizeOfBuckets();
};

/*template<>
void HashTable<EuclideanNode*>::insertNode(EuclideanNode* data)
{
    totalSize++;

    data->set_ID(gFunction->hashFunctionID(data));
    buckets[hashFunction(data)]->insertEnd(data);
}*/

#endif

