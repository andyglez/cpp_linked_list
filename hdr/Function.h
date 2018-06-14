//
// Created by Andy on 6/13/2018.
//

template <class R, class T>
class Function{
public:
    virtual R operator()(const T& arg);
};
