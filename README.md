# C++ Generic Linked List implementation #

This project represents an introduction to C++ where some of the language's main topics are presented according to it's use in
the source files. Between them are some basic ground rules of the language's features such as:
  * Generic Programming
  * Memory Management
  * Object Oriented Programming
  * Operator Overloading
  * Functional Programming

This work, neither source code or this file, does not cover until the latest C++ version, so some features may be lost if looking
for the complete subject within the ones mentioned earlier.

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

**Class Templates**

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

## Memory Management ##

Programmers generally deal with five areas of memory:

  * Global name space
  * The Heap
  * Registers
  * Code space
  * The Stack

Local variables are on the stack, along with function parameters. Code is in code space and, of course, global variables
are in global namespace. The registers are used for internal housekeeping functions, such as keeping track of the top of
the stack and the instruction pointer. Just about all remaining memory is given over to the heap.

> The stack is cleaned automatically when a function returns.

The advantage to the heap is that the memory previously reserved remains available until the programmer explicitly free it.
The problem is that the programmer has full responsibility of that data he stores on the heap.

Using the **new** keyword represents an internal call to reserve memory on the heap. Its return value is a pointer.
In order to take care of that so called responsibility, there is the **delete** keyword, which free that memory previously reserved.

**Operations with pointers**

There are three main operations with pointers **&** means *address of*, __*__ has two meanings, in an expression represents
*the object pointed at by* and in a declaration is *a pointer to an object*.


**Passing Pointers to Functions**

**By value**

~~~cpp
void by_value(int x){
    x = 2;
}
void function_parameters_examples(){
    int arg = 1;
    by_value(arg);
    cout << arg << endl; // Prints 1
}
~~~

> C++ does not pass a variable to a function, instead passes the value contained within the variable at the time of the call.

**By pointer**

~~~cpp
void by_pointer(int* x){
    *x = 2;
}
void function_parameters_examples(){
    int arg = 1;
    by_pointer(&arg);
    cout << arg << endl; // Prints 2
}
~~~

> A pointer variable is just another name for it's memory address.

**By reference**

~~~cpp
void by_reference(int& x){
    x = 2;
}
void function_parameters_examples(){
    int arg = 1;
    by_reference(arg);
    cout << arg << endl; // Prints 2
}
~~~

> It's nothing but a shorthand for passing argument by address making possible not to hassle with pointers.

**typedef**
Is one of the language's keywords and its use is only for renaming complex types so code can be more readable.
Most of pointer variables and instances of some class template are a couple examples of its use.

## Object Oriented Programming ##

The language provides an interface for working with groups of data which are called objects and such interface has the
name of classes, which are templates for creating different instances of those objects, and holds, possibly, all types
of data necessary to describe them.

Keyword **struct** can also be used to describe an object, the main difference is that public declaration of its members
is assumed and can be omitted.

Objects are created and destroyed meanwhile classes persist, so C++ has some member functions to interact with instantiation,
these are called constructors and destructors.

~~~cpp
class Node{
public:
    Node(int val);
    ~Node();
}
~~~

As member functions, constructors can receive arguments and can be overridden, which means that there will be more than
one way to construct an object.

Arguments can also be set to a default value:

~~~cpp
class Node{
public:
    Node(int val = 0);
}
~~~

The rules for the order of construction of objects are as follows:
  * Local and static objects are constructed in the order in which their declarations are invoked.
  * Static objects are constructed only once.
  * All global objects are constructed before *main()* and in no particular order.
  * Members are constructed in the order in which they are declared in the class.
  * Destructors are invoked in the reverse order from constructors.

> A static variable that is local to a function retains its values from one function invocation to the next.
>
> A global variable is a variable declared on a parent scope to its context of use.

**Types of constructors**

Whenever a class is defined with no member constructors, C++ creates one by default, with no parameters and everything
inside the class definition goes to binary zero. This is called the default constructor.

There are, of course, the constructors user defined, with overloads as will.

According to the syntax A::A(A&), where A is the name of the class represents a special type of constructor called the
*copy constructor*, it's called copy because it creates a new object with a different address in memory but the same values
as the object given by parameter or, at least, a customized copy of it.

~~~cpp
template <class T>
class LinkedList{
public:
    typedef Node<T> Node;
    Node* First;
    LinkedList(T first);
    LinkedList(LinkedList<T>& list);
    virtual ~LinkedList();
};
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    Node* f = list.First;
    this->First = new Node(*f);
}
template <class T>
LinkedList<T>::~LinkedList() {
    delete First;
}
~~~

**Destructors**

The syntax is similar to a constructor with the exception for a tilde (~).
Every local variable is deleted automatically when the instance is call to deletion, but care most be taken with heap
memory variables, so they have to be manually freed, this is the main use of destructor.

> Destructors should be marked virtual, so in a class hierarchy a child class can redefine what it should delete.

A child class may add some pointer fields in difference to its original parent class, for that reason the destructor must
be overridden and, doing so, avoid memory leaks.

## Operator overloading ##

Is just another way to make a function call but with no parenthesis for parameters on its call syntax.
  * If it's a unary operator then one argument, else if it's a binary operator then two arguments.
  * If the operator is defined as a global function then it's previous case or if it's a member function then zero arguments
   for unary, one for binary and the object becomes a left-hand argument.

**Restrictions**
  * It's impossible to combine operators that have no meaning in C.
  * It's not allowed to change the evaluation precedence of operators.
  * It's always the same number of arguments for each operator.

**Increment and Decrement**

The main dilemma is within their prefix and postfix syntax, so the two operator functions are differentiated from each other
since, underneath, they have different signatures, that is given from the number of arguments.

So, prefix increment or decrement really calls an operator function with no arguments, and postfix increment or decrement
really calls the same operator function but with a dummy constant parameter.

~~~cpp
template <class T>
class LinkedList{
public:
    typedef Node<T> Node;
    Node* First;
    LinkedList();
    LinkedList(T first);

    virtual T operator[](int index);
    T At(int index);
}

template <class T>
const T LinkedList<T>::operator[](const int index) {
    return At(index);
}
template <class T>
const T LinkedList<T>::At(int index) {
    Node *iter = First;
    while (iter != NULL && --index > 0){
        iter = iter->Next;
    }
    if(index != 0){
        throw new out_of_range("Index exceeds the list's size");
    }
    return iter->Value;
}
~~~

**C Macros**

In C, one of the ways to preserve efficiency is through the use of *macros*, which allows to make function calls without
the normal overhead. This is given because it's real implementation goes to the preprocessor which replaces all macro calls
directly from with it's code.

There are two main problems with it's use:
  * A macro seems to behave like a normal function call, but it doesn't always act like one.
  * In C++, the preprocessor has no permission to access class member data.

> The solution for the last problem is given by *inline* functions

**Inline Functions**

They are expanded in place just like macros, but they do have access to member class data because their expansion takes
place within the compiler.

> Any function defined within a class body is automatically inline.

In a non-class function it can be specified with the keyword *inline*.
Just the same way as macros, *inline* functions are best suited for small functions because it replicates it's code in
place, so for a very large function whenever it's expansion takes place doesn't really represent any performance gain.

As with any function, the compiler holds the function type in its symbol table and when its body parses without error
the code for the function body is also brought into the symbol table.

**Const**

The concept of constant was created to draw a line between what changes and what doesn't.
It's first use comes from a change of practice to use the preprocessor keyword **#DEFINE**.

A const defaults to an internal linkage which means that the compiler doesn't reserve memory for it, unless is more of a
data structure, like an array, in that case it can be called 'a piece of storage that cannot be changed', the same can be
given for a const with an external linkage, specified with keyword **extern**, thus is remains accessible through out a project.

> Pointers can be made const.

*Pointer to const*

~~~cpp
const int* u;
~~~

It is better read "u is a pointer, which point to a const int".

Note that no initialization is required because u is pointer that points to anything, but the value pointed is the one who
doesn't change.

*const Pointer*

~~~cpp
int d = 1;
int* const w = &d;
~~~

This is now read "w is a constant pointer to an int".

In this case the compiler requires that it be given an initial value.

*const Pointer to const*

~~~cpp
int d = 1;
const int* const x = &d;
int const* const y = &d;
~~~

It works the same for x and y, now neither the pointer or the object can change.

In functions works the same logic, but the main difference is when passing arguments and returning them between functions.
C++, when encounters with a case like that, creates the necessary temporary objects, which are const by nature. So it's a
feature to keep in mind since this is an error-prone situation.

The use of const with classes is little more complicated, for instance, to guarantee the const attribute of a class object
only a const member function may be called for a const object.

> The use of const inside a class means "This is constant for the lifetime of the object".

For that reason is that a const must be already initialized inside the main body of the constructor.
Then, const for classes exist only on run time execution but there is a way for having const from before, at compiling time.
For that purpose the const must be declared **static**, which in this situation means "this is from the class regardless of
how many objects are created".

~~~cpp
static const int size = 100;
~~~

> **static const** always requires an initialization at the point of definition.

## Functional Programming ##

**Functors**

Classes have many uses, one of them is to replace functions.
This is given by the function call operator which lets an object behave like a function, it's only needed an overload for
operator() for getting to that goal.

> It can take any number of arguments and can have any return type.

The objects that are instances of classes with such behavior are usually called *functors* or *function object*. In next
versions of C++ like C++11 the idea of functional programming gets more complete with the introduction of lambda expressions
but, still, functors are a great solution for many problems.

**Pointers to functions**

There is another way of approaching functional programming within C++, that is using pointer to functions, allowing to handle
functions as first-class citizen which means that a function can be passed as a argument, can be assigned as a variable a be
called under different names.

So, addressing both knowledge, functors and pointers to functions, in addition to templates there can be made a much wider
solution.

~~~cpp
template <class R, class T>
class Function{
    R (*func)(T arg);
public:
    Function(R (*f)(T arg)) : func(f){}
    virtual void operator=(R (*f)(T arg));
    virtual R operator()(const T& arg);
};

template <class R, class T>
R Function<R,T>::operator()(const T& arg){
    R ret = this->func(arg);
    return ret;
}

template <class R,class T>
void Function<R,T>::operator=(R (*f)(T arg)) {
    this->func = f;
}
~~~

