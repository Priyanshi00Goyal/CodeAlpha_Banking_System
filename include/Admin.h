#ifndef ADMIN_H
#define ADMIN_H

#include <string>

using namespace std;

class Admin
{
private:
    // Login Credentials
    string username;
    string password;

public:
    // Constructor
    Admin();

    // Destructor
    ~Admin() = default;

    // Login Function
    bool login();

    // Getters (Useful for future expansion)
    string getUsername() const;

    // Setters (Useful for changing credentials later)
    void setUsername(const string &user);
    void setPassword(const string &pass);
};

#endif // ADMIN_H
