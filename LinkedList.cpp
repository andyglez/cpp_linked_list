//
// Created by Andy on 08/06/2018.
//

#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList(T first){
    this->First = new Node(first);
}