#ifndef Included_HashTableEuclidean_H
#define Included_HashTableEuclidean_H

#include "List.h"
#include "Node.h"
#include "dataTypes.h"
#include "hashFunctionEuclidean.h"
#include "euclideanNode.h"
#define M 4294967291 //2^32-5

class HashTableEuclidean
{
    private:
        const int kHashFunctions;
        const unsigned int nBuckets; // mporei kai long long int
        long long int totalSize;
        List<EuclideanNode*>** buckets;
        HashFunctionEuclidean** gFunction;
        int* rVariables;

        //unsigned int hashFunction(Cosine* key); //auto tha mporouse na einai 4-6 bits anti gia int, 'h estw char
        //bool checkID(int id);
    public:
        HashTableEuclidean(unsigned int NBuckets, int k, int dimensions, int W);
        ~HashTableEuclidean();

        unsigned int hashFunction(Vector* key); //auto tha mporouse na einai 4-6 bits anti gia int, 'h estw char
        unsigned int hashFunctionID(Vector* key);


        long long int get_TotalSize();
        unsigned int get_nBuckets();
        Node<EuclideanNode*>* get_bucket(Vector* key);

        void insertNode(Vector* data);
        bool exists(Vector* data);
        //T searchNode(Cosine* searchData);
        //T deleteFirstNode();
        //T deleteNode(int key);

        void printSizeOfBuckets();
};


#endif
