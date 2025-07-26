#include <iostream>
using namespace std;

// Base Class
class Student {
protected:
    string name;
    int rollNo;

public:
    void inputStudentDetails() {
        cout << "Enter student name: ";
        cin>>name;
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void displayStudentDetails()  {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

// Derived from Student
class Exam : public Student {
protected:
    float marks[3];

public:
    void inputMarks() {
        cout << "Enter marks for 3 subjects:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayMarks(){
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << " Marks: " << marks[i] << endl;
        }
    }
};

// Derived from Exam
class Result : public Exam {
private:
    float total;

public:
    void calculateTotal() {
        total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
    }

    void displayResult() {
        cout << "\n--- Student Result ---\n";
        displayStudentDetails();
        displayMarks();
        cout << "Total Marks: " << total << endl;
    }
};

// Driver Code
int main() {
    Result r;
    r.inputStudentDetails();
    r.inputMarks();
    r.calculateTotal();
    r.displayResult();

    return 0;
}
