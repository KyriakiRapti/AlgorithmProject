#ifndef Included_HashNode_H
#define Included_HashNode_H

template <class T>
class HashNode
{
    private:
        int key; //mporw kai unsigned, string
        T data;
    public:
        HashNode(int key1, T Data);
        ~HashNode();

        int get_key();
        T get_data();
};
#endif
