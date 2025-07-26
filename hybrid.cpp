 #include<iostream>
 using namespace std;
class Player 
{
 protected: char name[20]; char gender; int age;
 };


class Physique : public Player
{ protected: float height, weight;
 };
class Location
 { protected: char city[15];
 long int pin;
 };
class Game : public Physique, public Location
 { char game[15];
 public:
 void input()
 { cout<<"\nEnter Player Information";
 cout<<"Name: ";
 cin>>name;
 cout<<"Genger: ";
 cin>>gender;
 cout<<"Age: ";
 cin>>age;
 cout<<"Height and Weight: ";
 cin>>height>>weight; cout<<"City: ";
 cin>>city;
 cout<<"Pincode: ";
 cin>>pin;
 cout<<"Game played: "; cin>>game;
 }
 void show()
 { cout<<"\nPlayer Information";
 cout<<"\nName: "<<name;
 cout<<"\nGenger: "<<gender;
 cout<<"\nAge: "<<age;
 cout<<"\nHeight"<<height;
 cout<<"\nWeight: "<<weight;
 cout<<"\nCity: "<<city;
 cout<<"\nPincode: "<<pin;
 cout<<"\nGame: "<<game;
 }
 };

int main( )
{
 Game g;
 g.input();
 g.show();
 return 0;
 }