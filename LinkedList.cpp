//
// Created by Andy on 08/06/2018.
//

#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    First = NULL;
}

template <class T>
LinkedList<T>::LinkedList(T first){
    First = new Node();
    (*First) = first;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    if(list.First != NULL){
        Node* f = list.First;
        First = new Node(*f);
    }
    else{
        First = NULL;
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    delete First;
}

template <class T>
void LinkedList<T>::operator=(T first) {
    if(First != NULL){
        (*First) = first;
    }
    else{
        First = new Node(first);
    }
}


