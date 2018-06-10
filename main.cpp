#include <iostream>
#include "LinkedList.cpp"

using namespace std;

template <class T>
T my_max(T x, T y){
    if(x < y)
        return y;
    return x;
}

int main() {
    LinkedList<int> *list = new LinkedList<int>(5);
    cout << list->First->Value << endl;
    cout << my_max(8, 9) << endl;
    return 0;
}