#include "Node.h"
//#include "bankAccount.h"
//#include "edge.h"
#include <cstdlib>
#include "hashNode.h"
#include "dataTypes.h"

template <class T>
Node<T>::Node(T Data)
{
    data = Data;
    next = NULL;
}

template <class T>
Node<T>::~Node()
{

}

template <class T>
Node<T>* Node<T>::get_next()
{
    return next;
}

template <class T>
T Node<T>::get_data()
{
    return data;
}

template <class T>
void Node<T>::set_next(Node* next1)
{
    next = next1;
}

template <class T>
void Node<T>::set_data(T Data)
{
    data = Data;
}

template class Node<int>;
template class Node<double>;
template class Node<Cosine* >;
//template class Node<bankAccount>;
//template class Node<Edge>;
