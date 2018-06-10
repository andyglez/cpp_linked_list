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

*Function Templates*
~~~
template <class T>
T my_max(T x, T y){
    if(x < y)
        return y;
    return x;
}
~~~

> A function template is a pattern for creating functions, according to the parameter type T.
> Where T intends to represent any type (as for generic)

Please, note the syntax:
template (**keyword**) + angle-brackets (delimit a comma-separated list of parameter types) + function (as it is)

> Template occurs at compile time.

Examines the type of the function argument and from the function argument's type determines the template argument.
Then substitutes that template argument for T and generates a new instance of the function, customized for the template argument.



