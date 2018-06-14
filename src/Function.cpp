//
// Created by Andy on 6/13/2018.
//


#include "../hdr/Function.h"

template <class R, class T>
R Function<R,T>::operator()(const T& arg){
    return R(arg * 10);
}
