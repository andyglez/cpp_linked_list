#include <iostream>
#include "LinkedList.cpp"

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

int main() {
    LinkedList<int>* list = new LinkedList<int>();
    (*list) = 5;
    LinkedList<int>* copy = new LinkedList<int>(*list);
    cout << copy << " === " << list << endl;
    cout << copy->First->Value << " === " << list->First->Value << endl;

    function_parameters_examples();
    delete(list);
    //delete(copy);
    return 0;
}