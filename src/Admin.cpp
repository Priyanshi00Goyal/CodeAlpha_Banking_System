#include "../include/Admin.h"

#include <iostream>

using namespace std;

// ======================================
// Constructor
// ======================================
Admin::Admin()
{
    username = "admin";
    password = "admin123";
}

// ======================================
// Getters
// ======================================
string Admin::getUsername() const
{
    return username;
}

// ======================================
// Setters
// ======================================
void Admin::setUsername(const string &user)
{
    username = user;
}

void Admin::setPassword(const string &pass)
{
    password = pass;
}

// ======================================
// Login
// ======================================
bool Admin::login()
{
    string enteredUsername;
    string enteredPassword;

    cout << "\n=====================================\n";
    cout << "           ADMIN LOGIN\n";
    cout << "=====================================\n";

    cout << "Username : ";
    cin >> enteredUsername;

    cout << "Password : ";
    cin >> enteredPassword;

    if (enteredUsername == username &&
        enteredPassword == password)
    {
        cout << "\n=====================================\n";
        cout << " Login Successful!\n";
        cout << "=====================================\n";

        return true;
    }

    cout << "\n=====================================\n";
    cout << " Invalid Username or Password!\n";
    cout << "=====================================\n";

    return false;
}
