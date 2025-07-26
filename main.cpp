#include<iostream>
#include<string.h>
using namespace std;
class saving_account
{
protected:
char name[30],address[30];
long long int account_no;
double  balance = 0;
static long long int next_account_no; 
public:
 saving_account() 
 {
    account_no = next_account_no++;
}
void getinfo()
{
cout<<"-----Enter the details of the accountholder-----"<<endl;
cout<<"Name : ";
cin.getline(name,30);
cout<<"Address : ";
cin.getline(address,30);
}
void showInfo()
{
account_no = 1777853659832769;
cout<<"Congrats! Your account has been created!\n";
cout<<"Your details :\n";
cout<<"Name : "<<name<<endl;
cout<<"Address : "<<address<<endl;
cout<<"A/C no. : "<<account_no<<endl;
cout<<"Current Balance : "<<balance<<endl;
}
void deposit()
{
double dep;
cout<<"Enter the amount you want to deposit : "<<endl;
cin>>dep;
balance += dep;
cout<<"Amount deposited successfully!"<<endl;
}
void withdraw()
{
   double with;
   cout<<"Enter the amount you want to withdraw : "<<endl;
   cin>>with;
   if(balance < with )
   {
       cout<<"Insufficient Balance :(";
   }
   else
   {
   balance -= with;
   cout<<"Amount withdrawn successfully.."<<endl;
   }
}

void show()
{
    cout<<"Your current balance is : "<<balance<<endl;
}
};
long long int saving_account::next_account_no = 1777853659832769;
int main()
{
    char ch;
saving_account *c;
saving_account d;
c = &d;
cout<<"Create your account : \n";
c->getinfo();
c->showInfo();
while(1)
{
cout<<"Choose from the following options : \n";
cout<<"'d' = deposit \n'w' = withdraw \n'b' = show balance \n'q'";
cin>>ch;
if(ch == 'd')
{
   c->deposit();
}
else if(ch == 'w')
{
   c->withdraw();
}
else if(ch == 'b')
{
   c->show();
}

else if(ch == 'q')
        {
            cout<<"Thank you for using our service. Goodbye!\n";
            break;
        }
        else
        {
            cout<<"Invalid choice! Please try again.\n";
        }
}
return 0;
}