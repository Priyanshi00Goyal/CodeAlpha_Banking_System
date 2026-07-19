#include "../include/Bank.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// ======================================
// Constructor
// ======================================
Bank::Bank()
{
    loadCustomers();
    loadAccounts();
    loadTransactions();
}

// ======================================
// Add Customer
// ======================================
void Bank::addCustomer()
{
    Customer customer;

    customer.inputCustomer();

    customers.push_back(customer);

    saveCustomers();

    cout << "\n=====================================\n";
    cout << " Customer Added Successfully!\n";
    cout << "=====================================\n";
}

// ======================================
// View Customers
// ======================================
void Bank::viewCustomers() const
{
    if (customers.empty())
    {
        cout << "\nNo Customers Found.\n";
        return;
    }

    cout << "\n=====================================\n";
    cout << "          ALL CUSTOMERS\n";
    cout << "=====================================\n";

    for (const Customer &customer : customers)
    {
        customer.displayCustomer();
    }
}

// ======================================
// Create Account
// ======================================
void Bank::createAccount()
{
    Account account;

    account.createAccount();

    // Check whether Customer exists
    Customer *customer = findCustomer(account.getCustomerID());

    if (customer == nullptr)
    {
        cout << "\nCustomer ID Not Found.\n";
        cout << "Account Creation Failed.\n";
        return;
    }

    accounts.push_back(account);

    saveAccounts();

    cout << "\n=====================================\n";
    cout << " Account Created Successfully!\n";
    cout << "=====================================\n";
}

// ======================================
// View Accounts
// ======================================
void Bank::viewAccounts() const
{
    if (accounts.empty())
    {
        cout << "\nNo Accounts Found.\n";
        return;
    }

    cout << "\n=====================================\n";
    cout << "          ALL ACCOUNTS\n";
    cout << "=====================================\n";

    for (const Account &account : accounts)
    {
        account.displayAccount();
    }
}
// ======================================
// Deposit
// ======================================
void Bank::deposit()
{
    int accountNo;
    double amount;

    cout << "\n=====================================\n";
    cout << "            DEPOSIT\n";
    cout << "=====================================\n";

    cout << "Enter Account Number : ";
    cin >> accountNo;

    Account *account = findAccount(accountNo);

    if (account == nullptr)
    {
        cout << "\nAccount Not Found.\n";
        return;
    }

    cout << "Enter Amount : ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\nInvalid Deposit Amount.\n";
        return;
    }

    account->deposit(amount);

    transactions.push_back(
        Transaction(
            accountNo,
            "Deposit",
            amount
        )
    );

    saveAccounts();
    saveTransactions();

    cout << "\nDeposit Successful!\n";
}

// ======================================
// Withdraw
// ======================================
void Bank::withdraw()
{
    int accountNo;
    double amount;

    cout << "\n=====================================\n";
    cout << "           WITHDRAW\n";
    cout << "=====================================\n";

    cout << "Enter Account Number : ";
    cin >> accountNo;

    Account *account = findAccount(accountNo);

    if (account == nullptr)
    {
        cout << "\nAccount Not Found.\n";
        return;
    }

    cout << "Enter Amount : ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\nInvalid Withdrawal Amount.\n";
        return;
    }

    if (!account->withdraw(amount))
    {
        return;
    }

    transactions.push_back(
        Transaction(
            accountNo,
            "Withdraw",
            amount
        )
    );

    saveAccounts();
    saveTransactions();

    cout << "\nWithdrawal Successful!\n";
}

// ======================================
// Transfer Money
// ======================================
void Bank::transferMoney()
{
    int senderAccNo;
    int receiverAccNo;
    double amount;

    cout << "\n=====================================\n";
    cout << "         FUND TRANSFER\n";
    cout << "=====================================\n";

    cout << "Enter Sender Account Number : ";
    cin >> senderAccNo;

    Account *sender = findAccount(senderAccNo);

    if (sender == nullptr)
    {
        cout << "\nSender Account Not Found.\n";
        return;
    }

    cout << "Enter Receiver Account Number : ";
    cin >> receiverAccNo;

    Account *receiver = findAccount(receiverAccNo);

    if (receiver == nullptr)
    {
        cout << "\nReceiver Account Not Found.\n";
        return;
    }

    if (senderAccNo == receiverAccNo)
    {
        cout << "\nSender and Receiver Accounts Cannot Be Same.\n";
        return;
    }

    cout << "Enter Amount : ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "\nInvalid Amount.\n";
        return;
    }

    if (!sender->withdraw(amount))
    {
        return;
    }

    receiver->deposit(amount);

    transactions.push_back(
        Transaction(
            senderAccNo,
            "Transfer Out",
            amount
        )
    );

    transactions.push_back(
        Transaction(
            receiverAccNo,
            "Transfer In",
            amount
        )
    );

    saveAccounts();
    saveTransactions();

    cout << "\n=====================================\n";
    cout << " Transfer Successful!\n";
    cout << "=====================================\n";
}
// ======================================
// Find Customer
// ======================================
Customer* Bank::findCustomer(int customerID)
{
    for (Customer &customer : customers)
    {
        if (customer.getCustomerID() == customerID)
        {
            return &customer;
        }
    }

    return nullptr;
}

// ======================================
// Find Account
// ======================================
Account* Bank::findAccount(int accountNumber)
{
    for (Account &account : accounts)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            return &account;
        }
    }

    return nullptr;
}

// ======================================
// Search Customer
// ======================================
void Bank::searchCustomer()
{
    int customerID;

    cout << "\n=====================================\n";
    cout << "         SEARCH CUSTOMER\n";
    cout << "=====================================\n";

    cout << "Enter Customer ID : ";
    cin >> customerID;

    Customer *customer = findCustomer(customerID);

    if (customer == nullptr)
    {
        cout << "\nCustomer Not Found.\n";
        return;
    }

    cout << "\nCustomer Found Successfully!\n";

    customer->displayCustomer();
}

// ======================================
// Search Account
// ======================================
void Bank::searchAccount()
{
    int accountNumber;

    cout << "\n=====================================\n";
    cout << "          SEARCH ACCOUNT\n";
    cout << "=====================================\n";

    cout << "Enter Account Number : ";
    cin >> accountNumber;

    Account *account = findAccount(accountNumber);

    if (account == nullptr)
    {
        cout << "\nAccount Not Found.\n";
        return;
    }

    cout << "\nAccount Found Successfully!\n";

    account->displayAccount();
}

// ======================================
// View Transactions
// ======================================
void Bank::viewTransactions() const
{
    if (transactions.empty())
    {
        cout << "\nNo Transactions Found.\n";
        return;
    }

    cout << "\n=====================================\n";
    cout << "       TRANSACTION HISTORY\n";
    cout << "=====================================\n";

    for (const Transaction &transaction : transactions)
    {
        transaction.displayTransaction();
    }
}
// ======================================
// Save Customers
// ======================================
void Bank::saveCustomers()
{
    ofstream file("data/customers.txt");

    if (!file)
    {
        cout << "\nError: Unable to open customers.txt for writing.\n";
        return;
    }

    for (const Customer &customer : customers)
    {
        file
            << customer.getCustomerID() << ","
            << customer.getName() << ","
            << customer.getPhone() << ","
            << customer.getAddress()
            << endl;
    }

    file.close();
}

// ======================================
// Load Customers
// ======================================
void Bank::loadCustomers()
{
    customers.clear();

    ifstream file("data/customers.txt");

    if (!file)
        return;

    string line;
    int maxCustomerID = 1000;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id, name, phone, address;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, address);

        try
        {
            int customerID = stoi(id);

            Customer customer(
                customerID,
                name,
                phone,
                address
            );

            customers.push_back(customer);

            if (customerID > maxCustomerID)
                maxCustomerID = customerID;
        }
        catch (...)
        {
            // Skip corrupted record
        }
    }

    file.close();

    // Keep next generated ID unique
    Customer temp;
    temp.setCustomerID(maxCustomerID + 1);
}

// ======================================
// Save Accounts
// ======================================
void Bank::saveAccounts()
{
    ofstream file("data/accounts.txt");

    if (!file)
    {
        cout << "\nError: Unable to open accounts.txt for writing.\n";
        return;
    }

    for (const Account &account : accounts)
    {
        file
            << account.getAccountNumber() << ","
            << account.getCustomerID() << ","
            << account.getAccountType() << ","
            << account.getBalance()
            << endl;
    }

    file.close();
}

// ======================================
// Load Accounts
// ======================================
void Bank::loadAccounts()
{
    accounts.clear();

    ifstream file("data/accounts.txt");

    if (!file)
        return;

    string line;
    int maxAccountNo = 50000;

    while (getline(file, line))
    {
        stringstream ss(line);

        string accNo, custID, type, balance;

        getline(ss, accNo, ',');
        getline(ss, custID, ',');
        getline(ss, type, ',');
        getline(ss, balance);

        try
        {
            int accountNumber = stoi(accNo);

            Account account(
                accountNumber,
                stoi(custID),
                type,
                stod(balance)
            );

            accounts.push_back(account);

            if (accountNumber > maxAccountNo)
                maxAccountNo = accountNumber;
        }
        catch (...)
        {
            // Skip corrupted record
        }
    }

    file.close();

    // Keep next generated Account Number unique
    Account temp;
    temp.setAccountNumber(maxAccountNo + 1);
}
// ======================================
// Save Transactions
// ======================================
void Bank::saveTransactions()
{
    ofstream file("data/transactions.txt");

    if (!file)
    {
        cout << "\nError: Unable to open transactions.txt for writing.\n";
        return;
    }

    for (const Transaction &transaction : transactions)
    {
        file
            << transaction.getTransactionID() << ","
            << transaction.getAccountNumber() << ","
            << transaction.getType() << ","
            << transaction.getAmount()
            << endl;
    }

    file.close();
}

// ======================================
// Load Transactions
// ======================================
void Bank::loadTransactions()
{
    transactions.clear();

    ifstream file("data/transactions.txt");

    if (!file)
        return;

    string line;
    int maxTransactionID = 0;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string accountNo;
        string type;
        string amount;

        getline(ss, id, ',');
        getline(ss, accountNo, ',');
        getline(ss, type, ',');
        getline(ss, amount);

        try
        {
            int transactionID = stoi(id);

            Transaction transaction(
                transactionID,
                stoi(accountNo),
                type,
                stod(amount)
            );

            transactions.push_back(transaction);

            if (transactionID > maxTransactionID)
            {
                maxTransactionID = transactionID;
            }
        }
        catch (...)
        {
            // Skip corrupted records
        }
    }

    file.close();
}
