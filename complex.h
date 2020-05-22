#ifndef UNTITLED_COMPLEX_H
#define UNTITLED_COMPLEX_H
#include <fstream>
template <typename tip>
class complex
{
    float re,im;
public:
    complex(tip x,tip y){this->re=x;this->im=y;};
    complex(complex const &ob){this->re=ob.re;this->im=ob.im;};
    complex(){re=0;im=0;};
    ~complex()=default;
    float get_re()
    {
        return this->re;
    }
    float get_im()
    {
        return this->im;
    }
    complex& operator =(complex const &)=default;
    void set_re(tip x)
    {
        this->re=x;
    }
    void set_im(tip x)
    {
        this->im=x;
    }
    friend std::istream & operator >>(std::istream &, complex<tip> &ob);
    friend std::ostream & operator <<(std::ostream &, const complex<tip> &ob);
};
#endif