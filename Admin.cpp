#include "Admin.h"
#include <iostream>

// Constructor implementation
Admin::Admin(const string& username, const string& password,
             const string& phonenum, const string& address,
             const BankAccount& bankAccount, const UserRole& role)
        : User(username, password, phonenum, address, bankAccount, ADMIN) {

}

//// Implementation of the pure virtual function
//void Admin::displayDetails() const {
//    std::cout << "Admin: " << name << std::endl;
//}
//
//// Additional member function implementation
//void Admin::manageUsers() const {
//    std::cout << name << " is managing users." << std::endl;

