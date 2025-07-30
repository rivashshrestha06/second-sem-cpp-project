#include<iostream>
#include<fstream> 
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
cin.ignore();
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

void saveToFile()
{
    ofstream fout("account.txt");
    fout << name << endl;
    fout << address << endl;
    fout << account_no << endl;
    fout << balance << endl;
    fout.close();
}

int loadFromFile() 
{
    ifstream in("account.txt");
    if (!in)
    {
        return 0; 
    }
    in.getline(name, 30);
    in.getline(address, 30);
    in >> account_no;
    in >> balance;
    in.close();
    return 1; 
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
  if (c->loadFromFile())
    {
        cout << "Account loaded from file successfully.\n";
        c->showInfo();
    }
    else
    {
        cout<<"Create your account : \n";
        c->getinfo();
        c->showInfo();
    }
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
            c->saveToFile();
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