#include <cstring>
#include "User.h"

User::User(const char* username, const char* password,
           const char* phonenum, const char* address,
           const BankAccount& bankAccount, const UserRole& role)
        : bankAccount(bankAccount) {  // Initialize bankAccount using the provided BankAccount
    // Copy the input strings to the char arrays
    strncpy(this->username, username, sizeof(this->username) - 1);
    strncpy(this->password, password, sizeof(this->password) - 1);
    strncpy(this->phonenum, phonenum, sizeof(this->phonenum) - 1);
    strncpy(this->address, address, sizeof(this->address) - 1);

    // Null-terminate the char arrays
    this->username[sizeof(this->username) - 1] = '\0';
    this->password[sizeof(this->password) - 1] = '\0';
    this->phonenum[sizeof(this->phonenum) - 1] = '\0';
    this->address[sizeof(this->address) - 1] = '\0';

    // Assign the role
    this->role = role;
}


User::User() {
    // Initialize the char arrays with empty strings
    memset(username, '\0', sizeof(username));
    memset(password, '\0', sizeof(password));
    memset(phonenum, '\0', sizeof(phonenum));
    memset(address, '\0', sizeof(address));

    // Set default BankAccount and role
    bankAccount = BankAccount("", 0.0);
    role = UserRole::CUSTOMER;
}

// Getters
const char* User::getUsername() const {
    return username;
}

const char* User::getPassword() const {
    return password;
}

const char* User::getPhonenum() const {
    return phonenum;
}

const char* User::getAddress() const {
    return address;
}

const BankAccount& User::getBankAccount() const {
    return bankAccount;
}

User::UserRole User::getRole() const {
    return role;
}

// Setters
void User::setUsername(const char* newUsername) {
    strncpy(username, newUsername, sizeof(username) - 1);
    username[sizeof(username) - 1] = '\0';
}

void User::setPassword(const char* newPassword) {
    strncpy(password, newPassword, sizeof(password) - 1);
    password[sizeof(password) - 1] = '\0';
}

void User::setPhonenum(const char* newPhonenum) {
    strncpy(phonenum, newPhonenum, sizeof(phonenum) - 1);
    phonenum[sizeof(phonenum) - 1] = '\0';
}

void User::setAddress(const char* newAddress) {
    strncpy(address, newAddress, sizeof(address) - 1);
    address[sizeof(address) - 1] = '\0';
}

void User::setBankAccount(const BankAccount& newBankAccount) {
    bankAccount = newBankAccount;
}

void User::setRole(User::UserRole newRole) {
    role = newRole;
}

void User::displayUserDetails(std::ostream& out) const {
    out << "--------------------------------------\n"
        << "          User DETAILS         \n"
        << "--------------------------------------\n"
        << "Username: " << username << "\n"
        << "Password: " << password << "\n"
        << "Phone Number: " << phonenum << "\n"
        << "Address: " << address << "\n"
        << "Role: " << (role == ADMIN ? "Admin" : "Customer") << "\n"
        << "Bank Account Details: \n" << bankAccount << "\n";
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    user.displayUserDetails(os);
    return os;
}
