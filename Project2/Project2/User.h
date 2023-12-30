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

    void setUserId(const std::string& newUserId);
    // Getters
protected: std::string userid;

public:
    const string& getUsername() const;
    const string& getPassword() const;
    const string& getPhonenum() const;
    const string& getAddress() const;
     BankAccount& getBankAccount() ;
    UserRole getRole() const;
    BankAccount bankAccount;

    // Setters
    void setUsername(const string& newUsername);
    void setPassword(const string& newPassword);
    void setPhonenum(const string& newPhonenum);
    void setAddress(const string& newAddress);
    void setBankAccount(const BankAccount& newBankAccount);
    void setRole(UserRole newRole);

public:
    string username;
    string password;
    string phonenum;
    string address;
   
    UserRole role;

    void displayUserDetails(ostream& out) const;

    friend ostream& operator<<(ostream& os, const User& user);
};

#endif //DATA_STRUCTURE_PROJECT_USER_H
