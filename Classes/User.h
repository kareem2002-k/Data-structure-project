#ifndef DATA_STRUCTURE_PROJECT_USER_H
#define DATA_STRUCTURE_PROJECT_USER_H

#include <iostream>
#include "BankAccount.h"

class User {
public:
    enum UserRole {
        ADMIN,
        CUSTOMER
    };

    User(const char* username, const char* password,
         const char* phonenum, const char* address,
         const BankAccount& bankAccount, const UserRole& role);

    User();

    // Getters
    const char* getUsername() const;
    const char* getPassword() const;
    const char* getPhonenum() const;
    const char* getAddress() const;
    const BankAccount& getBankAccount() const;
    UserRole getRole() const;

    // Setters
    void setUsername(const char* newUsername);
    void setPassword(const char* newPassword);
    void setPhonenum(const char* newPhonenum);
    void setAddress(const char* newAddress);
    void setBankAccount(const BankAccount& newBankAccount);
    void setRole(UserRole newRole);

protected:
    char username[256];  
    char password[256];  
    char phonenum[256];  
    char address[256];   
    BankAccount bankAccount;
    UserRole role;

    void displayUserDetails(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif // DATA_STRUCTURE_PROJECT_USER_H
