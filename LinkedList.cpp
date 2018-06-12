//
// Created by Andy on 08/06/2018.
//

#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    Node* f = list.First;
    this->First = new Node(*f);
}
template <class T>
LinkedList<T>::LinkedList(T first){
    this->First = new Node(first);
}

template <class T>
LinkedList<T>::~LinkedList() {
    delete First;
}


