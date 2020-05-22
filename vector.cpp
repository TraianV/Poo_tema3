#include "vector.h"
#include "complex.h"
#include "stiva.h"
#include "coada.h"
#include<fstream>
template<typename tip>
std::istream &operator >> (std::istream & in, vector<tip> & vec)
{
    int i;
    if(vec.dim>0)
        delete []vec.v;
    std::cout<<"Dimensiunea vectorului: ";
    in>>vec.dim;
    vec.v=new complex<float>[vec.dim];
    for(i=0; i<vec.dim; i++)
        in>>vec.v[i];
    return in;
}

template<typename tip>
std::ostream &operator<<(std::ostream & out, vector<tip> const &vec)
{
    int i;
    for(i=0; i<vec.dim; i++)
        out<<vec.v[i]<<' ';
    return out;
}
