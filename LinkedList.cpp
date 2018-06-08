//
// Created by Andy on 08/06/2018.
//

#include "Node.cpp"

template <class T>
class LinkedList{
    typedef Node<T> Node;
public:
    Node* First;
    LinkedList(T first){
        First = new Node(first);
    }
};