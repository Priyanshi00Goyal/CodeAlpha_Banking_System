#ifndef BANK_H
#define BANK_H

#include <vector>

#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

using namespace std;

class Bank
{
private:
    // Data Storage
    vector<Customer> customers;
    vector<Account> accounts;
    vector<Transaction> transactions;

public:
    // Constructor
    Bank();

    // ===============================
    // Customer Management
    // ===============================
    void addCustomer();
    void viewCustomers() const;
    void searchCustomer();

    Customer* findCustomer(int customerID);

    // ===============================
    // Account Management
    // ===============================
    void createAccount();
    void viewAccounts() const;
    void searchAccount();

    Account* findAccount(int accountNumber);

    // ===============================
    // Banking Operations
    // ===============================
    void deposit();
    void withdraw();
    void transferMoney();

    // ===============================
    // Transaction Management
    // ===============================
    void viewTransactions() const;

    // ===============================
    // File Handling
    // ===============================
    void saveCustomers();
    void loadCustomers();

    void saveAccounts();
    void loadAccounts();

    void saveTransactions();
    void loadTransactions();

    // ===============================
    // Dashboard & Statistics
    // (To be implemented later)
    // ===============================
    void dashboard() const;
    void showStatistics() const;
};

#endif // BANK_H
