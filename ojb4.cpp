#include<iostream>
using namespace std;
#include<conio.h>
class rect
{
private:
float l,b;
public:
rect()
{}
rect(float x,float y)
{
l=x;b=y;
}
float getarea()
{
return(l*b);
}
};
class square:public rect
{
public:
square(float x):rect(x,x)
{}
};
int main()
{

rect r(2,3);
square s(2);
cout<<"\nArea of rectangle is:\t"<<r.getarea();
cout<<"\nArea of square is:\t"<<s.getarea();
return(0);
}