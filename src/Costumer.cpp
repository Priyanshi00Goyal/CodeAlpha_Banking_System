#include "../include/Customer.h"
#include <limits>

int Customer::nextCustomerID = 1001;

// ===============================
// Default Constructor
// ===============================
Customer::Customer()
{
    customerID = nextCustomerID++;
    name = "";
    phone = "";
    address = "";
}

// ===============================
// Parameterized Constructor
// ===============================
Customer::Customer(int id, const string &n, const string &p, const string &a)
{
    customerID = id;
    name = n;
    phone = p;
    address = a;
}

// ===============================
// Setters
// ===============================
void Customer::setCustomerID(int id)
{
    customerID = id;
}

void Customer::setName(const string &n)
{
    name = n;
}

void Customer::setPhone(const string &p)
{
    phone = p;
}

void Customer::setAddress(const string &a)
{
    address = a;
}

// ===============================
// Getters
// ===============================
int Customer::getCustomerID() const
{
    return customerID;
}

string Customer::getName() const
{
    return name;
}

string Customer::getPhone() const
{
    return phone;
}

string Customer::getAddress() const
{
    return address;
}

// ===============================
// Input Customer Details
// ===============================
void Customer::inputCustomer()
{
    cout << "\n=====================================\n";
    cout << "          ADD CUSTOMER\n";
    cout << "=====================================\n";

    cout << "Generated Customer ID : " << customerID << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name    : ";
    getline(cin, name);

    cout << "Enter Phone   : ";
    getline(cin, phone);

    cout << "Enter Address : ";
    getline(cin, address);
}

// ===============================
// Display Customer Details
// ===============================
void Customer::displayCustomer() const
{
    cout << "\n=====================================\n";
    cout << "        CUSTOMER DETAILS\n";
    cout << "=====================================\n";

    cout << "Customer ID : " << customerID << endl;
    cout << "Name        : " << name << endl;
    cout << "Phone       : " << phone << endl;
    cout << "Address     : " << address << endl;
}
