#include<iostream>
using namespace std;
class person
{
    char name[10],add[10];
    public:
    void getdata()
    {
        cout<<"Name of the person is : ";
        cin>>name;
        cout<<"\nAddress of the person is : ";
        cin>>add;
    }
    void putdata()
    {
        cout<<"Name of the person is : "<<name;
        cout<<"\nAddress of the person is : "<<add;
    }
};
class employee:public person
{
    char company[10];
    float salary;
    public:
    void getempdata()
    {
        cout<<"\nName of the company : ";
        cin>>company;
        cout<<"\nSalary of the employee is : ";
        cin>>salary;
    }
    void putempdata()
    {
        cout<<"\nName of the company : "<<company;
        cout<<"\nSalary of the employee is : "<<salary;
    }
};
int main()
{
    struct employee e;
    e.getdata();
    e.getempdata();
    e.putdata();
    e.putempdata();
    return 0;
}