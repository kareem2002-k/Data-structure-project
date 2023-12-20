#ifndef DATA_STRUCTURE_PROJECT_ADMIN_H
#define DATA_STRUCTURE_PROJECT_ADMIN_H

#include "User.h" // Include the base class header

// Derived class for admins
class Admin : public User {
public:
    // Constructor
    Admin(const string& username, const string& password,
          const string& phonenum, const string& address,
          const BankAccount& bankAccount, const UserRole& role);

    // Implementation of the pure virtual function
//    void displayDetails() const override;

    // Additional member function specific to admins
    void manageUsers() const;
};

#endif //DATA_STRUCTURE_PROJECT_ADMIN_H
