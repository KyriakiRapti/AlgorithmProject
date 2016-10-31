#ifndef Included_HashTableCosine_H
#define Included_HashTableCosine_H

#include "List.h"
#include "Node.h"
#include "dataTypes.h"
#include "hashFunctionCosine.h"

class HashTableCosine
{
    private:
        const int kHashFunctions;
        const unsigned int nBuckets; // mporei kai long long int
        long long int totalSize;
        List<Vector*>** buckets;
        HashFunctionCosine** gFunction;

        //unsigned int hashFunction(Cosine* key); //auto tha mporouse na einai 4-6 bits anti gia int, 'h estw char
        //bool checkID(int id);
    public:
        HashTableCosine(unsigned int NBuckets, int k, int dimensions);
        ~HashTableCosine();

        unsigned int hashFunction(Vector* key); //auto tha mporouse na einai 4-6 bits anti gia int, 'h estw char


        long long int get_TotalSize();
        unsigned int get_nBuckets();
        Node<Vector*>* get_bucket(Vector* key);

        void insertNode(Vector* data);
        bool exists(Vector* data);
        //T searchNode(Cosine* searchData);
        //T deleteFirstNode();
        //T deleteNode(int key);

        void printSizeOfBuckets();
};


#endif
