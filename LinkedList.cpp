//
// Created by Andy on 08/06/2018.
//

#include "Node.cpp"

template <class T>
class LinkedList{
public:
    Node<T>* First;
    LinkedList(T first){
        First = new Node<T>(first);
    }
};