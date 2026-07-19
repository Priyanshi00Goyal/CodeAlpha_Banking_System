#include "../include/Account.h"
#include <limits>

int Account::nextAccountNumber = 50001;

// ======================================
// Default Constructor
// ======================================
Account::Account()
{
    accountNumber = nextAccountNumber++;
    customerID = 0;
    accountType = "";
    balance = 0.0;
}

// ======================================
// Parameterized Constructor
// ======================================
Account::Account(int accNo, int custID, const string &type, double bal)
{
    accountNumber = accNo;
    customerID = custID;
    accountType = type;
    balance = bal;
}

// ======================================
// Setters
// ======================================
void Account::setAccountNumber(int accNo)
{
    accountNumber = accNo;
}

void Account::setCustomerID(int custID)
{
    customerID = custID;
}

void Account::setAccountType(const string &type)
{
    accountType = type;
}

void Account::setBalance(double bal)
{
    balance = bal;
}

// ======================================
// Getters
// ======================================
int Account::getAccountNumber() const
{
    return accountNumber;
}

int Account::getCustomerID() const
{
    return customerID;
}

string Account::getAccountType() const
{
    return accountType;
}

double Account::getBalance() const
{
    return balance;
}

// ======================================
// Create Account
// ======================================
void Account::createAccount()
{
    cout << "\n=====================================\n";
    cout << "         CREATE ACCOUNT\n";
    cout << "=====================================\n";

    cout << "Generated Account Number : " << accountNumber << endl;

    cout << "Enter Customer ID : ";
    cin >> customerID;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Account Type Validation
    while (true)
    {
        cout << "Enter Account Type (Savings/Current): ";
        getline(cin, accountType);

        if (accountType == "Savings" || accountType == "Current")
            break;

        cout << "Invalid Account Type! Please enter Savings or Current.\n";
    }

    // Initial Balance Validation
    while (true)
    {
        cout << "Enter Initial Balance : ";
        cin >> balance;

        if (balance >= 0)
            break;

        cout << "Balance cannot be negative.\n";
    }

    cout << "\nAccount Created Successfully!\n";
}

// ======================================
// Display Account
// ======================================
void Account::displayAccount() const
{
    cout << "\n=====================================\n";
    cout << "         ACCOUNT DETAILS\n";
    cout << "=====================================\n";

    cout << "Account Number : " << accountNumber << endl;
    cout << "Customer ID    : " << customerID << endl;
    cout << "Account Type   : " << accountType << endl;
    cout << "Balance        : ₹" << balance << endl;
}

// ======================================
// Deposit
// ======================================
void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "\nInvalid deposit amount.\n";
        return;
    }

    balance += amount;

    cout << "\n₹" << amount << " deposited successfully.\n";
    cout << "Current Balance : ₹" << balance << endl;
}

// ======================================
// Withdraw
// ======================================
bool Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "\nInvalid withdrawal amount.\n";
        return false;
    }

    if (amount > balance)
    {
        cout << "\nInsufficient Balance.\n";
        return false;
    }

    balance -= amount;

    cout << "\n₹" << amount << " withdrawn successfully.\n";
    cout << "Current Balance : ₹" << balance << endl;

    return true;
}
