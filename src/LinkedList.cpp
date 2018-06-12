//
// Created by Andy on 08/06/2018.
//

#include <c++/stdexcept>
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

template <class T>
void LinkedList<T>::AddLast(T value) {
    if(First != NULL) {
        Node *iter = First;
        while (iter->Next != NULL) {
            iter = iter->Next;
        }
        iter->Next = new Node(value);
        iter->Next->Prev = iter;
    }
    else{
        First = new Node(value);
    }
}

template <class T>
T LinkedList<T>::RemoveLast() {
    Node *iter = First;
    if(First != NULL){
        while (iter->Next != NULL){
            iter = iter->Next;
        }
    }
    T result = iter->Value;
    if(iter->Prev != NULL){
        iter->Prev->Next = NULL;
    }
    delete iter;
    return result;
}

template <class T>
T LinkedList<T>::At(int index) {
    Node *iter = First;
    while (iter != NULL && --index > 0){
        iter = iter->Next;
    }
    if(index != 0){
        throw new out_of_range("Index exceeds the list's size");
    }
    return iter->Value;
}

template <class T>
T LinkedList<T>::RemoveAt(int index) {
    Node *iter = First;
    while (iter != NULL && --index > 0){
        iter = iter->Next;
    }
    if(index != 0){
        throw new out_of_range("Index exceeds the list's size");
    }
    Node *aux = iter->Prev;
    aux->Next = iter->Next;
    iter->Next->Prev = iter->Prev;
    iter->Next = NULL;
    int value = iter->Value;
    delete iter;
    return value;
}










