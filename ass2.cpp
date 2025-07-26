#include<iostream>
using namespace std;
class base1
{
    protected: int z;
    private : int y;
    public : int x;
    void set_value(int xx, int yy, int zz)
    {
        x = xx;
        y = yy;
        z = zz;
    }
    void display1()
    {
        cout<<"\nX = "<<x;
        cout<<"\nY = "<<y;
        cout<<"\nZ = "<<z;
    }
};
class base2
{
    protected : int a;
    private : int b;
    public : int c;
    void set_values(int aa, int bb, int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
    void display2()
    {
        cout<<"\nA = "<<a;
        cout<<"\nB = "<<b;
        cout<<"\nC = "<<c;
    }
};
class derived :public base1, private base2
{
    public :
    void display()
    {
        a = 100;
        c = 200;
        cout<<"\nValue of X in derived class = "<<x;
        cout<<"\nValue of Z in derived class = "<<z;
        cout<<"\nValue of A in derived class = "<<a;
        cout<<"\nValue of C in derived class = "<<c;
    }
};
int main()
{
    derived d;
    d.set_value(10,20,30);
    cout<<"\n Value of X in main = "<<d.x;
    return 0;
}