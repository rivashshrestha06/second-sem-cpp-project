#include<iostream>
using namespace std;
class rect
{
    float l,b;
    public:
    rect()
    {}
    rect(float x,float y)
    {
        l = x;
        b = y;
    }
    float getarea()
    {
        return(l*b);
    }
    float getlength()
    {
        return(l);
    }
    float getbreadth()
    {
        return(b);
    }
};

class square:public rect
{
    public:
    square (float x):rect(x,x)
    {}
};

int main()
{
    rect r(2,3);
    square s(2);
    cout<<"\nLength of rectangle is : \t"<<r.getlength();
    cout<<"\nBreadth of rectangle is : \t"<<r.getbreadth();
    cout<<"\nLength of square is : \t"<<s.getlength();
    cout<<"\nBreadth of square is : \t"<<s.getbreadth();
    cout<<"\nArea of rectangle is : \t"<<r.getarea();
    cout<<"\nArea of square is : \t"<<s.getarea();
    return 0;
}