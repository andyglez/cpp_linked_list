//
// Created by Andy on 6/8/2018.
//
#include <c++/cstdio>
#include "Node.h"

template <class T>
Node<T>::Node(const Node<T>& n){
    this->Value = n.Value;
    if(n.Next != NULL){
        Node<T>* aux1 = n.Next;
        this->Next  = new Node(*aux1);
    }
    if(n.Prev != NULL) {
        Node<T>* aux2 = n.Prev;
        this->Prev = new Node<T>(*aux2);
    }
}

template  <class T>
Node<T>::Node(T val){
    this->Value = val;
    this->Next  = 0;
    this->Prev  = 0;
}
