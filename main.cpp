#include <iostream>
#include <vector>
#include "src/LinkedList.cpp"
#include "src/Function.cpp"

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

template <class R, class T>
LinkedList<R>* Map(LinkedList<T>* orig, Function<R,T> f){
    LinkedList<R>* list = new LinkedList<R>();
    int size = orig->Size();
    for (int i = 1; i <= size; i++) {
        T aux  = (*orig)[i];
        R item = f(aux);
        list->AddLast(item);
    }
    return list;
};


int main() {

    ///DEFAULT CONSTRUCTOR EXAMPLE
    LinkedList<int>* list = new LinkedList<int>();

    /// BASIC ASSIGNATION EXAMPLE
    (*list) = 5;

    ///COPY CONSTRUCTOR SAMPLE
    LinkedList<int>* copy = new LinkedList<int>(*list);


    for (int i = 0; i < 100; i++) {
        list->AddLast(i);
    }
    /// FUNCTION EXAMPLE
    Function<int,int> f = Function<int, int>();
    LinkedList<int>* aux = Map<int,int>(list, f);

    /// INDEXING EXAMPLE WITH OPERATOR [] AND LOCAL FUNCTION
    int a = (*list)[78];
    cout << list->At(78) << " -- " << a << endl;

    /// REMOVING LINKED NODES EXAMPLE
    for (int j = 0; j < 99; ++j) {
        list->RemoveLast();
    }


    /// EXTENDED PRINTS
    //Print(list);
    //Print(aux);
    //cout << "Size = " << list->Size() << endl;

    /// OTHER EXAMPLES
    //vector_constructions_examples();
    //function_parameters_examples();

    /// CLEANING UP ;)
    delete(list);
    delete(copy);
    return 0;
}