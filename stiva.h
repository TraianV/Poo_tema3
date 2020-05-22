#ifndef UNTITLED_STIVA_H
#define UNTITLED_STIVA_H
#include "vector.h"
#include "complex"
#include<iostream>

template<typename tip>
class stiva  : public vector<tip>
{
public:
    stiva<tip> &push(complex<tip> const &x);
    stiva<tip> pop();
};



#endif
