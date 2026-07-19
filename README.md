# 🏦 Bank Management System (C++)

A console-based **Bank Management System** developed using **Object-Oriented Programming (OOP)** principles in C++. This project allows an administrator to manage customers, bank accounts, transactions, and fund transfers while storing data permanently using text files.

---

## 📌 Features

### 👨‍💼 Admin Authentication
- Secure admin login
- Username & password verification
- Prevents unauthorized access

### 👤 Customer Management
- Add new customers
- Automatically generates unique Customer IDs
- View all customers
- Search customers by Customer ID

### 💳 Account Management
- Create bank accounts
- Automatically generates unique Account Numbers
- Supports:
  - Savings Account
  - Current Account
- View all accounts
- Search accounts by Account Number

### 💰 Banking Operations
- Deposit money
- Withdraw money
- Transfer money between accounts
- Balance validation
- Prevents invalid transactions

### 📜 Transaction History
- Records every:
  - Deposit
  - Withdrawal
  - Transfer In
  - Transfer Out
- View complete transaction history

### 💾 File Handling
Data is automatically saved and loaded using text files.

Stored files:
- customers.txt
- accounts.txt
- transactions.txt

---

# 🛠️ Tech Stack

- **Language:** C++
- **Concepts Used:**
  - Object-Oriented Programming (OOP)
  - Classes & Objects
  - Encapsulation
  - Constructors
  - Static Members
  - File Handling
  - STL Vector
  - Modular Programming

---

# 📂 Project Structure

```
Bank-Management-System/
│
├── include/
│   ├── Admin.h
│   ├── Account.h
│   ├── Bank.h
│   ├── Customer.h
│   └── Transaction.h
│
├── src/
│   ├── Admin.cpp
│   ├── Account.cpp
│   ├── Bank.cpp
│   ├── Customer.cpp
│   ├── Transaction.cpp
│   └── main.cpp
│
├── data/
│   ├── accounts.txt
│   ├── customers.txt
│   └── transactions.txt
│
├── LICENSE
├── README.md
└── .gitignore
```

---

# 🚀 How to Run

### Clone the repository

```bash
git clone https://github.com/your-username/Bank-Management-System.git
```

### Move into the project

```bash
cd Bank-Management-System
```

### Compile

```bash
g++ src/*.cpp -Iinclude -o bank
```

### Run

```bash
./bank
```

---

# 🔑 Default Admin Credentials

```
Username : admin
Password : admin123
```

---

# 📋 Menu

```
1. Add Customer
2. View Customers
3. Create Account
4. View Accounts
5. Search Customer
6. Search Account
7. Deposit Money
8. Withdraw Money
9. Transfer Money
10. View Transactions
0. Exit
```

---

# 📷 Sample Output

```
=====================================
       BANK MANAGEMENT SYSTEM
=====================================

1. Add Customer
2. View Customers
3. Create Account
4. View Accounts
5. Search Customer
6. Search Account
7. Deposit Money
8. Withdraw Money
9. Transfer Money
10. View Transactions
0. Exit
```

---

# 🎯 Concepts Demonstrated

- Object-Oriented Design
- Data Encapsulation
- Constructor Overloading
- Static Data Members
- Modular Code Organization
- Dynamic Data Storage using STL Vector
- Persistent Storage using File Handling
- Menu-Driven Console Application

---

# 📈 Future Improvements

- Password encryption
- Multiple admin accounts
- Delete customer/account
- Update customer details
- Transaction date & time
- Interest calculation
- Monthly statements
- Account locking
- Better input validation
- Database (MySQL/SQLite) integration
- GUI version using Qt

---

# 👩‍💻 Author

**Priyanshi Goyal**

- 💼 Aspiring Software Engineer
- 🌱 Learning C++, DSA, Python & Full-Stack Development

---

## ⭐ If you found this project helpful, consider giving it a star!
