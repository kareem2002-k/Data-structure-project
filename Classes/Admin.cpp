#include "Admin.h"
#include <iostream>

// Constructor implementation
Admin::Admin(const string& username, const string& password,
             const string& phonenum, const string& address,
             const BankAccount& bankAccount, const User::UserRole& role)
        : User(username.c_str(), password.c_str(), phonenum.c_str(), address.c_str(), bankAccount, role) {

}

//// Implementation of the pure virtual function
//void Admin::displayDetails() const {
//    std::cout << "Admin: " << name << std::endl;
//}
//
//// Additional member function implementation
//void Admin::manageUsers() const {
//    std::cout << name << " is managing users." << std::endl;

