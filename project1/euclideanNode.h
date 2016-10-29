#ifndef Included_euclideanNode_H
#define Included_euclideanNode_H

#include "dataTypes.h"
class EuclideanNode
{
    private:
        Vector* data; //mporw kai unsigned, string
        int ID;
    public:
        EuclideanNode(Vector* Data, int id);
        ~EuclideanNode();

        Vector* get_vector();
        int get_ID();
};
#endif
