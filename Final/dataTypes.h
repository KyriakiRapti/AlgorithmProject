#ifndef Included_DataTypes_H
#define Included_DataTypes_H

#include <iostream>
#include "stdio.h"
#include "string.h"
#include <bitset>

class Vector
{
    private:
        std::string id;
        const int dimensions;
        double* coordinance;
    public:
        Vector(std::string ID, int dim, double* coord): dimensions(dim)
        {
            id = ID;
            coordinance = new double[dimensions];
            memcpy(coordinance, coord, dimensions*sizeof(double)); //antigrafei ta dedomena apo ton ena pinaka ston allo
        }
        ~Vector()
        {
            delete[] coordinance;
        }

        std::string get_string()
        {
            return id;
        }

        int get_dimensions()
        {
            return dimensions;
        }

        double get_coordinance(int pos)
        {
            if(pos >= dimensions) return -9999;
            return coordinance[pos];
        }
};

class Hamming
{
    private:
        std::string id;
        std::bitset<64> bitString;
    public:
        Hamming(std::string ID, std::bitset<64> bitSet)
        {
            id = ID;
            bitString = bitSet;
        }

        std::string get_string()
        {
            return id;
        }

        void get_bitString(std::bitset<64>& data)
        {
            data = bitString;
        }
};

class MatrixPoint
{
    private:
        std::string id;
        const int N;
        int* distances;

    public:
        MatrixPoint(std::string ID, int* dist,  int n): N(n)
        {
            id = ID;
            distances = new int[N];
            memcpy(distances, dist, N*sizeof(int));
        }

        ~MatrixPoint()
        {
            delete [] distances;
        }

        std::string get_string()
        {
            return id;
        }

        int get_noItems()
        {
            return N;
        }

        int get_distance(int pos)
        {
            if(pos >= N) return -9999;
            return distances[pos];
        }
};
#endif

