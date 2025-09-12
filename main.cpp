#include<iostream>
#include<fstream> 
#include<string.h>
using namespace std;

class saving_account 
{
protected:
    char name[30], address[30], username[30], password[10];
    long long int account_no;
    double balance = 0;
    static long long int next_account_no; 
public:
    saving_account() {
        account_no = next_account_no++;
    }

    void signup() {
        cin.ignore(); 
        cout << "Create a new account:\n";
        cout << "Enter username: ";
        cin.getline(username, 30);
        cout << "Enter password: ";
        cin.getline(password, 10);
        cout << "Name: ";
        cin.getline(name, 30);
        cout << "Address: ";
        cin.getline(address, 30);

        
        ofstream auth("userpassword.txt", ios::app);
        auth << username << " " << password << endl;
        auth.close();

        saveToFile();
        cout << "Account created successfully!\n";
    }

    int login() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ifstream auth("userpassword.txt"); // fixed filename
        string u, p;
        while (auth >> u >> p) {
            if (u == username && p == password) {
                auth.close();
                cout << "Login successful!\n";
                loadFromFile();
                return 1;
            }
        }
        auth.close();
        cout << "Invalid credentials!\n";
        return 0;
    }

    void saveToFile() {
        ofstream fout("account.txt");
        fout << name << endl;
        fout << address << endl;
        fout << account_no << endl;
        fout << balance << endl;
        fout.close();
        if (fout.fail()) {
            cout << "File write failed!" << endl;
        } else {
            cout << "File written successfully!" << endl;
        }
    }

    int loadFromFile() {
        ifstream fin("account.txt");
        if (!fin) {
            return 0; 
        }
        fin.getline(name, 30);
        fin.getline(address, 30);
        fin >> account_no;
        fin >> balance;
        fin.close();
        return 1; 
    }

    void showInfo() {
        cout << "\n--- Account Info ---\n";
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Account No: " << account_no << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit() {
        double dep;
        cout << "Enter deposit amount: ";
        cin >> dep;
        balance += dep;
        cout << "Amount deposited successfully!\n";
    }

    void withdraw() {
        double with;
        cout << "Enter withdrawal amount: ";
        cin >> with;
        if (balance < with) {
            cout << "Insufficient Balance :(\n";
        } else {
            balance -= with;
            cout << "Amount withdrawn successfully..\n";
        }
    }

    void show() {
        cout << "Your current balance is: " << balance << endl;
    }
};

long long int saving_account::next_account_no = 1777853659810000;

int main() {
    char ch;
    saving_account *c;
    saving_account d;
    c = &d;

    if (c->loadFromFile()) {
        cout << "Account loaded from file successfully.\n";
        c->showInfo();
    } else {
        cout << "Create your account : \n";
        c->signup();   // fixed: was getinfo()
        c->showInfo();
    }

    while (1) {
        cout << "\nChoose from the following options:\n";
        cout << "'d' = deposit\n'w' = withdraw\n'b' = show balance\n'q' = quit\n";
        cin >> ch;

        if (ch == 'd') {
            c->deposit();
        } else if (ch == 'w') {
            c->withdraw();
        } else if (ch == 'b') {
            c->show();
        } else if (ch == 'q') {
            c->saveToFile();
            cout << "Thank you for using our service. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
