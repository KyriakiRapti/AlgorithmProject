#include <cmath>

#include "hashFunctionEuclidean.h"
#include "psedoRandomNumbers.h"

HashFunctionEuclidean::HashFunctionEuclidean(int dim, int W):dimensions(dim), w(W)
{
    vVariable = new double[dimensions];

    for(int i =0; i<dimensions; i++)
    {
        vVariable[i]=Marsaglia();
    }

    tVar = randomNumber(0, w);
}
HashFunctionEuclidean::~HashFunctionEuclidean()
{
    delete[] vVariable;
}

int HashFunctionEuclidean::value(Vector* key)
{
    double result=0;

    for(int i =0; i<dimensions;i++) //isws elenxos an idia dimensions cosine kai rVariable
    {
        result += vVariable[i]*key->get_coordinance(i);
    }

    return (int)(floor((result+ tVar)/w));
}
