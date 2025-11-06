#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
class Bank;
class accounts
{
protected:
    string name, address, username, password;
    long long int account_no;
    double balance;
    double amount;
    static long long int next_account_no;
    accounts() 
    {
        balance = 0.0;
        account_no = next_account_no++;
    }
public:
    virtual void displayInfo() = 0; // pure virtual
    virtual void withdraw() = 0;    // pure virtual
    virtual void deposit() 
    {
        cout<<"Enter the amount to deposit : ";
        cin >> amount;
        try 
        {
        if (amount <= 0)
            throw "\nInvalid deposit amount!\n";
        }
        catch (const char* e) 
        {
            cout << e << endl;
            return;
        }

        balance += amount;
         cout << "Deposited " << amount << " successfully.\n";
         saveToFile();
    }

    virtual string getCreationDate() 
    { 
        return "N/A";
    }
    virtual void saveToFile() = 0;
    virtual int loadFromFile() = 0;
    static void saveNextAccountNo() 
    {
        ofstream file("next_account_no.txt");
        if (file.is_open()) 
        {
            file << next_account_no;
            file.close();
        }
    }

    static void loadNextAccountNo() 
    {
        ifstream file("next_account_no.txt");
        if (file.is_open()) 
        {
            file >> next_account_no;
            file.close();
        } 
        else    
        {
        next_account_no = 20251100; // default starting number
        saveNextAccountNo();
        }
    }
 friend class Bank;
};
long long int accounts::next_account_no = 20251100;

class saving_account : public accounts 
{
private:
    time_t creationTime; 
public:
    saving_account(string n, string u, string p, string addr, double bal)
    {
        name = n;
        username = u;
        password = p;
        address = addr;
        balance = bal;
        creationTime = time(0);
    }
    
    string getCreationDate() 
    {
        string s = ctime(&creationTime);
        if(!s.empty() && s.back() == '\n') 
        {
            s.pop_back();
        }
        return s;
    }

    void withdraw() 
    {
        double with;
        cout << "Enter withdrawal amount: ";
        cin >> with;
        try 
        {
            if (with <= 0)
                throw "\nInvalid withdrawal amount!\n";
            if (with > balance)
                throw "\nInsufficient balance!\n";
        }
        catch (const char* e) 
        {
            cout << e << endl;
            return;
        }
            balance -= with;
            cout << "Amount withdrawn successfully..\n";
        saveToFile();
    }
    
    void displayInfo()
    {
        cout << "Account No: " << account_no << "\nName: " << name
             << "\nBalance: " << balance<< endl;
    }

    void saveToFile() override 
    {
    ofstream file(to_string(account_no) + ".txt");
    try 
    {
    if (!file)
        throw "\nError saving data!\n";
    }
    catch (const char* e) 
    {
    cout << e << endl;
    return;
    }

    file << "Username : "<< username << "\n" <<"Password : "<< password << "\n" 
         <<"Name : "<< name << "\n" <<"Address : "<< address << "\n" <<"Balance : "<< balance << "\n" 
         <<"Account created on : "<< ctime(&creationTime);
    file.close();
    }

    int loadFromFile() override
{
    ifstream file(to_string(account_no) + ".txt");
    try 
    {
    if (!file)
        throw "\nFailed to open file!!!\n";
    }
    catch (const char* e) 
    {
        cout << e << endl;
        return 0;
    }

    string line;
    string loadcreationTime;
    // Read username
    getline(file, line);
    username = line.substr(line.find(":") + 2);

    // Read password
    getline(file, line);
    password = line.substr(line.find(":") + 2);

    // Read name
    getline(file, line);
    name = line.substr(line.find(":") + 2);

    // Read address
    getline(file, line);
    address = line.substr(line.find(":") + 2);

    // Read balance
    getline(file, line);
    balance = stod(line.substr(line.find(":") + 2));

    // Read account creation time
    getline(file, line);
    loadcreationTime = line.substr(line.find(":") + 2);

    file.close();
    return 1; // success
}

};
    
class Bank
{
protected:
    accounts* accountsArray[100];
    int accountCount = 0;
public:
    accounts* getAccount(int index)
    {
    return accountsArray[index];
    }
    void signup() 
    {
        string uname, pwd, nm, addr;
        double bal;
        char type;
        cin.ignore();

        cout << "Create a new account:\n";

        cout << "Enter username: ";
        getline(cin, uname);

        cout << "Enter password: ";
        int i = 0;
        char ch;
        while (1) 
        {
            ch = getch();
            if (ch == 13) //ASCII of Enter key = 13
            {
                break;
            } 
            else if (ch == 8) 
            { 
                if (!pwd.empty()) 
                {
                    pwd.pop_back();
                    cout << "\b \b";
                }
            } 
            else 
            {
                pwd.push_back(ch);
                cout << '*';
            }
        }
        try 
        {
            if (pwd.length() < 8)
            throw "\nPassword must be at least 8 characters long!\n";
        }
        catch (const char* e) 
        {
            cout << e << endl;
            return;
        }
        cout << endl;

        cout << "Name: ";
        getline(cin, nm);

        cout << "Address: ";
        getline(cin, addr);

        cout << "Initial deposit: ";
        cin >> bal;
        try 
        {
            if (bal < 1000)
                throw "\nMinimum initial deposit is Rs. 1000\n";
        }
        catch (const char* e) 
        {
        cout << e << endl;
        return;
        }

        cin.ignore();
        accountsArray[accountCount++] = new saving_account(nm, uname, pwd, addr, bal);
        accountsArray[accountCount-1]->saveToFile();
        accounts::saveNextAccountNo();
        // save login info to file
        ofstream auth("userpassword.txt", ios::app);
        auth << uname << " " << pwd << " " << accountsArray[accountCount-1]->account_no << endl;
        auth.close();
        accounts::saveNextAccountNo();
        cout << "Account created successfully!\n";
    }

    void loadAccounts()
{
    ifstream file("userpassword.txt");
    string uname, pwd;
    long long accNo;
    while (file >> uname >> pwd >> accNo)
    {
        saving_account* acc = new saving_account("", uname, pwd, "", 0);
        acc->account_no = accNo;
          if (acc->loadFromFile()) 
        {
            accountsArray[accountCount++] = acc;
        }
        else
        {
            cout << "Warning: Could not load account file for " << uname << endl;
            delete acc; 
        }
    }

    file.close();
}

    void displayAccounts()
    {
        for(int i = 0; i < accountCount; i++)
        {
            accountsArray[i]->displayInfo();
            cout << "Created on: " << accountsArray[i]->getCreationDate() << "\n\n";
        }
    }

    int login()
{
    string uname, pwd;
    cout << "Enter your username: ";
    cin >> uname;

    cout << "Enter your password: ";
    int i = 0;
    char ch;
    pwd = "";
    while (1)
    {
        ch = getch();
        if (ch == 13) break; // Enter key
        else if (ch == 8)
        {
            if (!pwd.empty())
            {
                pwd.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            pwd.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;

    // Search in accounts array for the matching username
    for (int j = 0; j < accountCount; j++)
    {
        if (uname == accountsArray[j]->username && pwd == accountsArray[j]->password)
        {
            cout << "Login successful!\n";
            accountsArray[j]->loadFromFile(); // load account info
            return j; // return index of logged-in account
        }
    }
    try 
    {
        throw "\nInvalid username or password!\n";
    }
    catch (const char* e) 
    {
        cout << e << endl;
        return -1;
    }
}

void deleteAccount(int index)
{
    string password;
    cout << "Enter your password to confirm account deletion: ";
    password = "";
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13) break;
        else if (ch == 8)
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*';
        }
    }
    try 
    {
    if (password != accountsArray[index]->password)
        throw "\nPassword mismatch! Account deletion cancelled.\n";
    }
    catch (const char* e) 
    {
    cout << e << endl;
    return;
    }

    cout << endl;

    // Withdraw all money
    double totalBalance = accountsArray[index]->balance;
    if(totalBalance > 0)
    {
        cout << "Withdrawing all remaining balance: " << totalBalance << endl;
        accountsArray[index]->balance = 0;
    }

    // Delete account file
    string filename = to_string(accountsArray[index]->account_no) + ".txt";
    if (remove(filename.c_str()) == 0)
        cout << "Account file deleted successfully.\n";
    else
        cout << "Warning: Could not delete account file.\n";

    // Remove from userpassword.txt
    ifstream infile("userpassword.txt");
    ofstream temp("temp.txt");
    string uname, upass;
    long long accNo;
    while (infile >> uname >> upass >> accNo)
    {
        if (accNo != accountsArray[index]->account_no)
        {
            temp << uname << " " << upass << " " << accNo << endl;
        }
    }
    infile.close();
    temp.close();
    remove("userpassword.txt");
    rename("temp.txt", "userpassword.txt");

    // Remove from accountsArray
    delete accountsArray[index];
    for (int i = index; i < accountCount - 1; i++)
    {
        accountsArray[i] = accountsArray[i + 1];
    }
    accountCount--;

    cout << "Account deleted successfully.\n";
}

};

void rules()
{
    cout << "Rules:\n"
         << "- Minimum initial deposit for any account: 1000\n"
         << "- Withdrawal amount cannot exceed current balance.\n"
         << "- General Rules:\n"
         << "    * Always provide correct personal details during signup.\n"
         << "    * Bank reserves the right to update rules at any time.\n";
}

int main()
{
    accounts::loadNextAccountNo();
    Bank bank;
    bank.loadAccounts();
    char choice;
    system("cls");
    system("color 0A");
    cout<<"Welcome to KhEC Mini-Bank!!\n";
    while(1)
    {
    cout<<"\nPlease choose from the below options:\n"<<endl
    <<"1. Create an account\n2. Login\n3. Rules\n4. Exit\nYour choice : ";
    cin>>choice;
    switch (choice)
    {
        case '1':
                bank.signup(); // create new account
                break;

            case '2':
            {    
            int accIndex = bank.login();
                if (accIndex != -1)
                    {
                        char subChoice;
                        do {
                            cout << "1. Deposit\n2. Withdraw\n3. Display Info\n4. Delete Account\n5. Logout\nChoice: ";
                            cin >> subChoice;
                            switch(subChoice)
                                {
                                    case '1':
                                                bank.getAccount(accIndex)->deposit();
                                                break;
                                    case '2':
                                                bank.getAccount(accIndex)->withdraw();
                                                break;
                                    case '3':
                                                bank.getAccount(accIndex)->displayInfo();
                                                break;

                                    case '4':
                                                bank.deleteAccount(accIndex);
                                                subChoice = '5';
                                                break;

                                    case '5':
                                                cout << "Logging out...\n";
                                                break;
                                    default:
                                                cout << "Invalid choice.\n";
                                }
                            } while(subChoice != '5');
                    }    
                }
                break;
            case '3':
                    rules();
                    break;

            case '4':
                cout << "Thank you for using our mini-bank!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    accounts::saveNextAccountNo();
    return(0);
}
