//
// Created by Andy on 6/13/2018.
//

template <class R, class T>
class Function{
    R (*func)(T arg);
public:
    Function(R (*f)(T arg)) : func(f){}
    virtual void operator=(R (*f)(T arg));
    virtual R operator()(const T& arg);
};
