#ifndef Included_Lsh_H
#define Included_Lsh_H

#include <fstream>
#include "dataTypes.h"
#include "List.h"
#include "hashTableCosine.h"
#include "hashtable.h"

template<class T>
class LSH
{
    private:
        std::string type;
        const int L;
        const int K;
        HashTable<T>** hashtables; //edw tha mpei template an ginete
        //double radius;
        List<T>* input; //kai edw
        //List<T>* searchList;

    public:
        LSH(std::string Type, List<T>* Input, int L1, int K1);
        ~LSH();

        void runLSH(std::ofstream& outFile, List<T>* Search, double radius);
        void writeFile(std::ofstream& outFile, T queryPoint, List<T>* rangeNeigtbours, T aproxVector, double aproxDistance,  double trueDistance, double LSHTime, double bruteTime);
        void rangeSearch(T key, List<T>* result, double radius);
        double AproxNN(T key, T& aproxNear);
        double TrueNN(T key, T& aproxNear);
        //Vector* NNCosine(HashTableCosine** hashtables, Vector* key, int L, double& distance, int maxChecks);
        double distance(Vector* point1, Vector* point2);
        int distance(Hamming* point1, Hamming* point2);
        bool elementExists(List<T>* tmpList, T key);

};
/*
void lshCosine(List<Vector*>* input, List<Vector*>* searchList, int L, int K, double radius);
void writeFileCosine(std::ofstream& outFile, Vector* queryPoint, List<Vector*>* rangeNeigtbours, Vector* aproxVector, double aproxDistance,  double nearDistance);
void rangeSearchCosine(HashTableCosine** hashtables, Vector* key, int L, double radius, List<Vector*>* result);
Vector* NNCosine(HashTableCosine** hashtables, Vector* key, int L, double& distance, int maxChecks);
*/

#endif
