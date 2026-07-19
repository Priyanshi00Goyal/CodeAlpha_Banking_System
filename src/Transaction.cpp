#include "../include/Transaction.h"

// ======================================
// Static Member Initialization
// ======================================
int Transaction::nextTransactionID = 1;

// ======================================
// Default Constructor
// ======================================
Transaction::Transaction()
{
    transactionID = nextTransactionID++;
    accountNumber = 0;
    type = "";
    amount = 0.0;
}

// ======================================
// Parameterized Constructor
// ======================================
Transaction::Transaction(int accNo, const string &t, double amt)
{
    transactionID = nextTransactionID++;
    accountNumber = accNo;
    type = t;
    amount = amt;
}

// ======================================
// Constructor Used While Loading Data
// ======================================
Transaction::Transaction(int id, int accNo, const string &t, double amt)
{
    transactionID = id;
    accountNumber = accNo;
    type = t;
    amount = amt;

    // Keep the next ID greater than all loaded IDs
    if (id >= nextTransactionID)
    {
        nextTransactionID = id + 1;
    }
}

// ======================================
// Getters
// ======================================
int Transaction::getTransactionID() const
{
    return transactionID;
}

int Transaction::getAccountNumber() const
{
    return accountNumber;
}

string Transaction::getType() const
{
    return type;
}

double Transaction::getAmount() const
{
    return amount;
}

// ======================================
// Display Transaction Details
// ======================================
void Transaction::displayTransaction() const
{
    cout << "\n=====================================\n";
    cout << "      TRANSACTION DETAILS\n";
    cout << "=====================================\n";

    cout << "Transaction ID : " << transactionID << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Type           : " << type << endl;
    cout << "Amount         : ₹" << amount << endl;
}
