//
// Created by Andy on 6/11/2018.
//

#include <c++/vector>
#include "../src/Node.cpp"

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
    virtual const T operator[](const int index);

    int Size();
    void AddLast(T value);
    T RemoveLast();
    T At(int index);
    T RemoveAt(int index);
    vector<T> Enumerate();
};
