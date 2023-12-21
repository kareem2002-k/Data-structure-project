#ifndef DATA_STRUCTURE_PROJECT_USER_H
#define DATA_STRUCTURE_PROJECT_USER_H

#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

class User {
public:
    enum UserRole {
        ADMIN,
        CUSTOMER
    };

    User(const string& username, const string& password,
         const string& phonenum, const string& address,
         const BankAccount& bankAccount, const UserRole& role);

    // Getters
    const string& getUsername() const;
    const string& getPassword() const;
    const string& getPhonenum() const;
    const string& getAddress() const;
    const BankAccount& getBankAccount() const;
    UserRole getRole() const;

    // Setters
    void setUsername(const string& newUsername);
    void setPassword(const string& newPassword);
    void setPhonenum(const string& newPhonenum);
    void setAddress(const string& newAddress);
    void setBankAccount(const BankAccount& newBankAccount);
    void setRole(UserRole newRole);

protected:
    string username;
    string password;
    string phonenum;
    string address;
    BankAccount bankAccount;
    UserRole role;

    void displayUserDetails() const;
};

#endif //DATA_STRUCTURE_PROJECT_USER_H
