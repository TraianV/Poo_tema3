#include<iostream>
#include<fstream>
#include"complex"
#include"vector.h"
#include "stiva.h"
#include "coada.h"
#include<string.h>

int main()
{
    char s[50];
    int n,i,c,d;
    float o,p,q,r,ok1,ok2;
    complex<float> x;
    stiva<float> a;
    coada<float> b;
    std::ifstream f("date.in");
    std::cout<<"Scrieti in fisierul atasat comenzile:\n";
    std::cout<<"push stiva a+bi=adaugare la stiva numarul complex a+bi(daca b=0 scrieti doar a, iar daca a este 0 scrieti doar bi)\n";
    std::cout<<"push coada a+bi=la fel ca la stiva\n";
    std::cout<<"pop stiva=elimina ultimul element din stiva\n";
    std::cout<<"pop coada=eleimina primul element din coada\n";
    std::cout<<"afis stiva=afisaza pe ecran stiva\n";
    std::cout<<"afis coada=afisaza pe ecran coada\n";
    while(f.get(s,50))
    {
        f.get();
        o=0;
        p=0;
        q=0;
        r=0;
        c=1;
        d=1;
        ok1=1;
        ok2=1;
        if(strstr(s,"afis stiva"))
            std::cout<<"Stiva: "<<a<<std::endl;
        else if(strstr(s,"afis coada"))
            std::cout<<"Coada: "<<b<<std::endl;
        else if(strstr(s,"pop stiva"))
            a.pop();
        else if( strstr(s,"pop coada"))
            b.pop();
        else if(strstr(s,"push stiva"))
        {
            i=11;
            if(s[i]=='i')
            {
                o=0;
                q=1;
            }
            if(s[i]=='-')
            {
                ok1=-1;
                i++;
            }
            else
            {
                ok1=1;
            }
            for(; i<strlen(s)-1 &&  s[i]!='+'   &&  s[i]!='-'   &&     s[i]!='.'    &&  s[i]!='i'; i++)
                o=o*10+s[i]-48;
            if(s[i]=='i' && q!=1)
                q=o;
            if(s[i]=='i'  &&  s[i-1]==' ')
                q=1;
            else if(s[i]=='i'    &&  s[i-1]=='-')
            {
                q=-1;
                i++;
            }
            if(s[i]=='.')
            {
                i++;
                for(; s[i]!='+'  &&  s[i]!=-'-'  &&  i<strlen(s)-1  &&  s[i]!='i'; i++)
                {
                    p=p*10+s[i]-48;
                    c*=10;
                }
                while(c>1)
                {
                    p/=10;
                    c/=10;
                }
                o+=p;
            }
            o*=ok1;
            if(s[i]=='i' && q!=1)
            {
                q=o;
                o=0;
            }
            if(s[i]=='-'    &&  q!=-1)
            {
                ok2=-1;
                i++;
            }
            else
            {
                ok2=1;
                i++;
            }
            for(; i<strlen(s)-1  &&  s[i]!='i'   &&  s[i]!='.'; i++)
                q=q*10+s[i]-48;
            if(s[i]=='i'    &&  q==0)
                q=1;
            if(s[i]=='.')
            {
                i++;
                for(; s[i]!=i; i++)
                {
                    r=r*10+s[i]-48;
                    d*=10;
                }
                while(d>1)
                {
                    r/=10;
                    d/=10;
                }
                q+=r;
            }
            q*=ok2;
            x.set_re(o);
            x.set_im(q);
            a.push(x);
        }
        else if(strstr(s,"push coada"))
        {
            i=11;
            if(s[i]=='i')
            {
                o=0;
                q=1;
            }
            if(s[i]=='-')
            {
                ok1=-1;
                i++;
            }
            else
            {
                ok1=1;
            }
            for(; i<strlen(s)-1 &&  s[i]!='+'   &&  s[i]!='-'   &&     s[i]!='.'    &&  s[i]!='i'; i++)
                o=o*10+s[i]-48;
            if(s[i]=='i' && q!=1)
                q=o;
            if(s[i]=='i'  &&  s[i-1]==' ')
                q=1;
            else if(s[i]=='i'    &&  s[i-1]=='-')
            {
                q=-1;
                i++;
            }
            if(s[i]=='.')
            {
                i++;
                for(; s[i]!='+'  &&  s[i]!=-'-'  &&  i<strlen(s)-1  &&  s[i]!='i'; i++)
                {
                    p=p*10+s[i]-48;
                    c*=10;
                }
                while(c>1)
                {
                    p/=10;
                    c/=10;
                }
                o+=p;
            }
            o*=ok1;
            if(s[i]=='i' && q!=1)
            {
                q=o;
                o=0;
            }
            if(s[i]=='-'    &&  q!=-1)
            {
                ok2=-1;
                i++;
            }
            else
            {
                ok2=1;
                i++;
            }
            for(; i<strlen(s)-1  &&  s[i]!='i'   &&  s[i]!='.'; i++)
                q=q*10+s[i]-48;
            if(s[i]=='i'    &&  q==0)
                q=1;
            if(s[i]=='.')
            {
                i++;
                for(; s[i]!=i; i++)
                {
                    r=r*10+s[i]-48;
                    d*=10;
                }
                while(d>1)
                {
                    r/=10;
                    d/=10;
                }
                q+=r;
            }
            q*=ok2;
            x.set_re(o);
            x.set_im(q);
            b.push(x);
        }
    }
    f.close();
    return 0;
}
