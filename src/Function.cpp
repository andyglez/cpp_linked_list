//
// Created by Andy on 6/13/2018.
//


#include "../hdr/Function.h"

template <class R, class T>
R Function<R,T>::operator()(const T& arg){
    R ret = this->func(arg);
    return ret;
}

template <class R,class T>
void Function<R,T>::operator=(R (*f)(T arg)) {
    this->func = f;
}


