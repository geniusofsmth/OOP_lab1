#include "polinom.h"
#include "math.h"

TPolinom::TPolinom(number x,number y,number z)
{
    a = x;
    b = y;
    c = z;
}

number TPolinom::value(number x)
{
    return (a*x*x+b*x+c);
}

int TPolinom::roots(number* x)
{
    int ret = 0;
    number d=b*b-4*a*c;
    if(d<0)
    {
        ret=0;
    }
    if(d==0)
    {
        ret=1;
        x[0]=(-b+sqrt(d))/(2*a);
        x[1]=x[0];
    }
    if(d>0)
    {
        ret=2;
        x[0]=(-b+sqrt(d))/(2*a);
        x[1]=(-b-sqrt(d))/(2*a);
    }
    return ret;
}

ostream& operator<<(ostream& os, TPolinom& p)
{
    //os<<p.a<<"x^2+" <<p.b<<"x+" << p.c ;
    //os<<p.a<<"x^2+" << "( " << p.b << ") " << "x+" <<"( " << p.c ;
    if (p.b>0 && p.c>0)
    {
        os<<p.a<<"x^2+" <<p.b<<"x+" << p.c ;
    }

    if (p.b < 0 && p.c > 0)
    {
        os<<p.a<<"x^2" <<p.b<<"x+" << p.c ;
    }

    if (p.b > 0 && p.c < 0)
    {
        os<<p.a<<"x^2+" <<p.b<<"x" << p.c ;
    }

    if (p.b < 0 && p.c < 0)
    {
        os<<p.a<<"x^2" <<p.b<<"x" << p.c ;
    }

    return os;
}
