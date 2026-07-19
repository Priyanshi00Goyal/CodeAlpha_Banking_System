#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

class Transaction
{
private:
    // Static member to generate unique Transaction IDs
    static int nextTransactionID;

    int transactionID;
    int accountNumber;
    string type;
    double amount;

public:
    // Constructors
    Transaction();
    Transaction(int accNo, const string &t, double amt);
    Transaction(int id, int accNo, const string &t, double amt);

    // Destructor
    ~Transaction() = default;

    // Getters
    int getTransactionID() const;
    int getAccountNumber() const;
    string getType() const;
    double getAmount() const;

    // Display Transaction Details
    void displayTransaction() const;
};

#endif // TRANSACTION_H
