//
// Created by Andy on 6/11/2018.
//

#include "Node.cpp"

template <class T>
class LinkedList{
public:
    typedef Node<T> Node;
    Node* First;
    LinkedList(T first);
    LinkedList(LinkedList<T>& list);
};
