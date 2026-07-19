#include <iostream>
#include <limits>

#include "../include/Admin.h"
#include "../include/Bank.h"

using namespace std;

int main()
{
    Bank bank;
    Admin admin;

    cout << "=====================================\n";
    cout << "       BANK MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << "Developed By : Priyanshi Goyal\n";
    cout << "Language     : C++\n";
    cout << "Version      : 1.0\n";
    cout << "=====================================\n";

    if (!admin.login())
    {
        return 0;
    }

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        MAIN MENU\n";
        cout << "=====================================\n";
        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Create Account\n";
        cout << "4. View Accounts\n";
        cout << "5. Search Customer\n";
        cout << "6. Search Account\n";
        cout << "7. Deposit Money\n";
        cout << "8. Withdraw Money\n";
        cout << "9. Transfer Money\n";
        cout << "10. View Transactions\n";
        cout << "0. Exit\n";
        cout << "=====================================\n";
        cout << "Enter Choice : ";

        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a number: ";
        }

        switch (choice)
        {
        case 1:
            bank.addCustomer();
            break;

        case 2:
            bank.viewCustomers();
            break;

        case 3:
            bank.createAccount();
            break;

        case 4:
            bank.viewAccounts();
            break;

        case 5:
            bank.searchCustomer();
            break;

        case 6:
            bank.searchAccount();
            break;

        case 7:
            bank.deposit();
            break;

        case 8:
            bank.withdraw();
            break;

        case 9:
            bank.transferMoney();
            break;

        case 10:
            bank.viewTransactions();
            break;

        case 0:
            cout << "\n=====================================\n";
            cout << " Thank You For Using\n";
            cout << " Bank Management System\n";
            cout << " Have A Great Day!\n";
            cout << "=====================================\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}
