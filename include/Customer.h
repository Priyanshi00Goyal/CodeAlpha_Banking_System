#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    // Static member to generate unique Customer IDs
    static int nextCustomerID;

    int customerID;
    string name;
    string phone;
    string address;

public:
    // Constructors
    Customer();
    Customer(int id, const string &n, const string &p, const string &a);

    // Destructor
    ~Customer() = default;

    // Setters
    void setCustomerID(int id);
    void setName(const string &n);
    void setPhone(const string &p);
    void setAddress(const string &a);

    // Getters
    int getCustomerID() const;
    string getName() const;
    string getPhone() const;
    string getAddress() const;

    // Member Functions
    void inputCustomer();
    void displayCustomer() const;
};

#endif // CUSTOMER_H
