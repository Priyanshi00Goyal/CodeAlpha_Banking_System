#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    // Static member to generate unique Account Numbers
    static int nextAccountNumber;

    int accountNumber;
    int customerID;
    string accountType;
    double balance;

public:
    // Constructors
    Account();
    Account(int accNo, int custID, const string &type, double bal);

    // Destructor
    ~Account() = default;

    // Setters
    void setAccountNumber(int accNo);
    void setCustomerID(int custID);
    void setAccountType(const string &type);
    void setBalance(double bal);

    // Getters
    int getAccountNumber() const;
    int getCustomerID() const;
    string getAccountType() const;
    double getBalance() const;

    // Member Functions
    void createAccount();
    void displayAccount() const;

    void deposit(double amount);
    bool withdraw(double amount);
};

#endif // ACCOUNT_H
