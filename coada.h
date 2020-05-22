#ifndef UNTITLED_COADA_H
#define UNTITLED_COADA_H
#include "vector.h"
#include "complex"
#include<iostream>
template<typename tip>
class coada : public vector<tip>
{
public:
    coada &push(const complex<tip> &x);
    coada<tip> pop();
};



#endif
