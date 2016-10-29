#ifndef Included_DataTypes_H
#define Included_DataTypes_H

#include <iostream>
#include "stdio.h"
#include "string.h"
#include <bitset>
/*void copyArray(double* from, double* to, int size)
{
    for(int i =0; i <)
}
*/
class Vector
{
    private:
        //int id;
        std::string id;
        const int dimensions;
        double* coordinance;
    public:
        Vector(int dim, double* coord): dimensions(dim)
        {
            coordinance = new double[dimensions];
            memcpy(coordinance, coord, dimensions*sizeof(double));
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
            if(pos > dimensions) return -9999;
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
#endif

