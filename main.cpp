#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {
    LinkedList<int> *list = new LinkedList<int>(5);
    cout << list->First->Value << endl;
    return 0;
}