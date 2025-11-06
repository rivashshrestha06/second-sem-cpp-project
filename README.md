# 🏦 KhEC Mini-Bank (In Development)

A C++ console-based banking system — built with real-world OOP principles.

![GitHub last commit](https://img.shields.io/github/last-commit/rivashshrestha06/second-sem-cpp-project?style=for-the-badge&color=4CAF50)  
![C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)  
![Status](https://img.shields.io/badge/Status-In%20Development-yellow?style=for-the-badge)  

---

## 📘 Overview

KhEC Mini-Bank is an ongoing C++ project that simulates a mini banking system for Khwopa Engineering College students.  
It lets users create, log in, deposit, withdraw, and delete accounts — all while persisting data to text files.

This project serves as both a practical OOP demonstration and a foundation for future expansion into more advanced features such as interest calculation, transaction history, and admin control panels.

---

## 🧩 Current Functionalities

### ✅ Account Management
- Create new user accounts  
- Auto-generate unique account numbers  
- Store and retrieve account details from files  

### ✅ Login System
- Secure password input using `getch()`  
- Validates credentials from `userpassword.txt`  

### ✅ Transactions
- Deposit with amount validation  
- Withdraw with exception handling for insufficient balance  
- Persistent balance updates  

### ✅ File Handling
- Each account stored in its own file (`<account_no>.txt`)  
- Global user list (`userpassword.txt`)  
- Auto-incrementing account number stored in `next_account_no.txt`  

### ✅ Account Deletion
- Deletes local account file and removes entry from user list  

### ✅ Quality-of-Life Features
- Console UI with color (`system("color 0A")`) and clear screen  
- Creation date for each account  
- Exception handling for user input  

---

## ⚙️ Technologies & Concepts Used

| Concept                      | Usage                                                      |
|-------------------------------|-----------------------------------------------------------|
| Object-Oriented Programming   | Abstract classes, inheritance, polymorphism             |
| File Handling                 | Persistent storage using fstream                        |
| Exception Handling            | Input validation and error control                       |
| Encapsulation & Access Control| Protected/private data members                            |
| Static Data Members           | Auto-tracking of account numbers                         |
| Time & Date Functions         | Record creation time for accounts                        |
| Password Masking              | Secure console input using `<conio.h>`                   |

---

## 📂 Current File Structure

second-sem-cpp-project/
│
├── Minibank.cpp # Main source code
├── next_account_no.txt # Tracks next account number
├── userpassword.txt # Username-password mapping
├── <account_no>.txt # Individual account details
└── README.md # Project documentation


---

## 🧰 Requirements
- **Compiler:** g++, MinGW, or Visual Studio  
- **OS:** Windows (uses `conio.h` and `system("cls")`)  
- **Language Standard:** C++11 or later  

---

## 🖥️ How to Run

**Compile:**
```bash
g++ Minibank.cpp -o Minibank.exe

---

**Run**
./Minibank.exe

Follow on-screen options to create, log in, and manage accounts.

---

## 🧠 Planned / Upcoming Features

* 🚀 Under Development — Coming Soon!
* 💹 Interest calculation for savings accounts
* 📜 Transaction history log per account
* 🔒 Password reset and recovery system
* 👨‍💼 Admin mode (view, search, delete users)
* 🏦 Support for multiple account types (e.g., current, fixed deposit)
* 💾 Encrypted data storage
* 📈 Enhanced UI with menu animations

---

## ⚠️ Known Limitations

* Works only on Windows (due to conio.h)
* No encryption for stored credentials (plaintext in files)
* No multi-threading (single-user runtime)
* Basic input validation (does not yet handle all edge cases)

---

## 👨‍💻 Author

Rivash Shrestha
Bachelor in Computer Engineering
Khwopa Engineering College
Purbanchal University
Nepal
📧 rivashshrestha5@gmail.com
🌐 GitHub: @rivashshrestha06

---

## 🧾 License

This project is open-source for learning and academic purposes.
You’re free to modify or extend it with credit to the author.

---

## 🧱 Project Status

🟡 Version: Early Development (v0.8 Prototype)
🧩 Goal: Build a complete mini banking suite with admin and transaction tracking
🧠 Next milestone: Add transaction history + admin dashboard