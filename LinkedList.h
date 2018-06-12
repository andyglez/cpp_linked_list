//
// Created by Andy on 6/11/2018.
//

#include <c++/vector>
#include "Node.cpp"

using namespace std;

template <class T>
class LinkedList{
public:
    typedef Node<T> Node;
    Node* First;
    LinkedList();
    LinkedList(T first);
    LinkedList(vector<T> v);
    LinkedList(const LinkedList<T>& list);
    virtual ~LinkedList();

    virtual void operator=(T first);
    int Size();
    vector<T> Enumerate();
};
