#include "vector.h"
#include "complex.h"
#include<fstream>
template <typename tip>
std::istream & operator >> (std::istream &in, complex<tip> &r)
{
    float x,y;
    in>>x;
    in>>y;
    r.set_re(x);
    r.set_im(y);
    return in;
}
template<typename tip>
std::ostream & operator << (std::ostream &out,const complex<tip> &r)
{
    if(r.re!=0)
        out<<r.re;
    if(r.im==1  &&  r.re!=0)
        out<<"+i";
    else if(r.im==1 && r.re==0)
        out<<"i";
    else if(r.im==-1)
        out<<"-i";
    else if(r.im>0)
        out<<'+'<<r.im<<'i';
    else if(r.im<0)
        out<<r.im<<'i';
    return out;
}
