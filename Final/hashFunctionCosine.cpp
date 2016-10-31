#include "hashFunctionCosine.h"
#include "psedoRandomNumbers.h"

using namespace std;
#include <iostream>
HashFunctionCosine::HashFunctionCosine(int dim):dimensions(dim)
{
    rVariable = new double[dimensions];

    for(int i =0; i<dimensions; i++)
    {
        rVariable[i]=Marsaglia();
        cout<<rVariable[i]<<" ";
    }
    cout<<endl;
}

HashFunctionCosine::~HashFunctionCosine()
{
    delete[] rVariable;
}

bool HashFunctionCosine::value(Vector* key)
{
    double result=0;

    for(int i =0; i<dimensions;i++) //isws elenxos an idia dimensions cosine kai rVariable
    {
        result += rVariable[i]*key->get_coordinance(i);
    }

    return (result >= 0);
}

void HashFunctionCosine::stats()
{
    int counter = 0;
    for(int i =0; i < dimensions; i++)
    {
        if(rVariable[i]> 0 )
        {
            counter++;
        }
    }
    cout<<counter<<endl;
}
