#include <iostream>
#include <vector>
#include "src/LinkedList.cpp"

using namespace std;

template <class T>
T my_max(T x, T y){
    if(x < y)
        return y;
    return x;
}

void by_value(int x){
    x = 2;
}
void by_pointer(int* x){
    *x = 2;
}
void by_reference(int& x){
    x = 2;
}

void function_parameters_examples(){
    int arg = 1;
    by_value(arg);
    cout << "By Value the argument has " << arg << endl;

    arg = 1;
    by_pointer(&arg);
    cout << "By pointer the argument has " << arg << endl;

    arg = 1;
    by_reference(arg);
    cout << "By reference the argument has " << arg << endl;
}

void vector_constructions_examples(){
    vector<int> a(5,0);
    for (int i = 0; i < a.size(); ++i) {
        a[i] = i;
    }
    LinkedList<int>* v = new LinkedList<int>(a);
    vector<int> r = v->Enumerate();
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << endl;
    }
    delete(v);
}

template <class T>
void Print(LinkedList<T>* list){
    Node<T>* iter = list->First;
    while (iter != NULL){
        cout << iter->Value << endl;
        iter = iter->Next;
    }
}


int main() {
    LinkedList<int>* list = new LinkedList<int>();
    //(*list) = 5;
    LinkedList<int>* copy = new LinkedList<int>(*list);
    //cout << copy << " === " << list << endl;
    //cout << copy->First->Value << " === " << list->First->Value << endl;

    for (int i = 0; i < 100; i++) {
        list->AddLast(i);
    }
    /*for (int j = 0; j < 99; ++j) {
        list->RemoveLast();
    }*/
    cout << list->At(78) << endl;
    cout << list->RemoveAt(78) << endl;
    //Print(list);
    cout << "Size = " << list->Size() << endl;
    //vector_constructions_examples();
    //function_parameters_examples();
    delete(list);
    delete(copy);
    return 0;
}