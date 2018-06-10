# C++ Generic Linked List implementation #

This project represents an introduction to C++, along with some of it's specifications
such as:
  * Generic Programming
  * Memory Management
  * Object Oriented Programming
  * Instantiation Philosophy
  * Operator Overrides
  * Functional Programming

## Generic Programming ##

C++ proposes the concept of templates as it's solution to generic programming.

**Function Templates**
~~~cpp
template <class T>
T my_max(T x, T y){
    if(x < y)
        return y;
    return x;
}
~~~

> A function template is a pattern for creating functions, according to the parameters types.

Please, note the syntax:
template (**keyword**) + angle-brackets (delimit a comma-separated list of parameter types) + function

> Template occurs at compile time.

The compiler examines the type of the function argument and from the function argument's type determines the template argument.
Then substitutes that template argument for T and generates a new instance of the function, customized for the template argument.

According to the previous example, you can note the simple impositions made for the users of my_max function:
  * T must be copyable, meaning that copy constructor must be public, so it can get parameters and return a value.
  * T must be comparable since there is a comparison operation (<) between the two parameters.

Types of parameters are taken from context of use, so if they are different you'll get the compiler complains but still
there is a way to specify which type will be used. For example:

~~~cpp
int  a = 2;
long b = 3;
long c = my_max<long>(a,c);
~~~

~~~cpp
template <class T>
T sum(T x, T y){
    return x + y
}
~~~

According to C++98, there was no error or, at least, not the obvious one for the previous function declaration. This is because
templates occur at compile time, and are not checked until used somewhere else when they generate some real functions according to
their parameter types

** Class Templates **

~~~cpp
template  <class T>
class Node{
public:
    T Value;
    Node<T>* Next;
    Node<T>* Prev;
    Node(T val){
        Value = val;
    }
};
~~~

> A class template is a pattern for making classes, according to the parameters types.

The member functions of a class template are themselves function templates, except that
you supply the template arguments to the class, not the function.

> Every time a different template argument is used, the compiler generates a new class with new member functions.

When a member outside of its class template is being defined, it's needed to repeat the template header.


