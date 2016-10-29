#include "euclideanNode.h"

EuclideanNode::EuclideanNode(Vector* Data, int id)
{
    data = Data;
    ID = id;
}
EuclideanNode::~EuclideanNode()
{
}

Vector* EuclideanNode::get_vector()
{
    return data;
}

int EuclideanNode::get_ID()
{
    return ID;
}
