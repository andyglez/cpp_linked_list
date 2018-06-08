#include <iostream>
#include "Node.cpp"

using namespace std;

int main() {
    Node<int> *n = new Node<int>(5);
    cout << n->value << endl;
    return 0;
}