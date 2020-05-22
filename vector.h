#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H
#include "complex.h"
#include <iostream>

template <typename tip>
class vector
{
    complex<tip> *v;
    int dim;
public:
    friend class complex<tip>;
    vector(complex<tip> *vec,int n){
        int i;
        this->dim=n;
        this->v=new complex<tip>[n];
        for(i=0; i<n; i++)
            this->v[i]=vec[i];
    };
    vector(){
        this->dim=0;
        this->v=new complex<tip>[this->dim];
    };
    vector(vector const &vec){
        int i;
        this->dim=vec.dim;
        this->v=new complex<tip>[this->dim];
        for(i=0; i<this->dim; i++)
            this->v[i]=vec.v[i];
    };
    ~vector()=default;
    int get_n()
    {
        return this->dim;
    }
    void set_n(int n)
    {
        this->dim=n;
    }
    complex<tip>* get_v()
    {
        return this->v;
    }
    void set_v(int n)
    {
        delete[] this->v;
        this->v=new complex<tip>[n];
    }
    complex<tip> operator[](const int n) const{
        return this->v[n];
    };
    vector & operator=(const vector &vec){
        int i;
        if(this==&vec)
            return *this;
        if(this->dim>0)
            delete []this->v;
        this->v=new complex<tip>[vec.dim];
        this->dim=vec.dim;
        for(i=0; i<vec.dim; i++)
            this->v[i]=vec.v[i];
        return *this;
    };
    void set_v(int i,complex<tip> x)
    {
        this->v[i]=x;
    }
    friend std::istream  operator >>(std::istream &in, vector<tip> &ob);
    friend std::ostream  operator <<(std::ostream &out,vector<tip> const &ob);
};



#endif
