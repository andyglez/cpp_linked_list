//
// Created by Andy on 08/06/2018.
//

#include "../hdr/LinkedList.h"

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
LinkedList<T>::LinkedList(vector<T> v) {
    First = new Node(v[0]);
    Node* iter = First;
    for(int i = 1; i < v.size(); i++){
        iter->Next = new Node(v[i]);
        iter->Next->Prev = iter;
        iter = iter->Next;
    }
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

template <class T>
int LinkedList<T>::Size() {
    if(First == NULL)
        return 0;
    int count = 0;
    Node* iter = First;
    while (iter != NULL){
        iter = iter->Next;
        count++;
    }
    return count;
}

template <class T>
vector<T> LinkedList<T>::Enumerate() {
    vector<T> v(Size(), 0);
    Node* iter = First;
    for (int i = 0; i < v.size(); i++) {
        v[i] = iter->Value;
        iter = iter->Next;
    }
    return v;
}











