//
// Created by Andy on 6/11/2018.
//

template  <class T>
class Node{
public:
    T Value;
    Node<T>* Next;
    Node<T>* Prev;
    Node(T val);
};


