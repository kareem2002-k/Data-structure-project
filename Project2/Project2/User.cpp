#include "User.h"

User::User(const string& username, const string& password,
    const string& phonenum, const string& address,
    const BankAccount& bankAccount, const UserRole& role)
    : username(username), password(password), phonenum(phonenum),
    address(address), bankAccount(bankAccount), role(role) {
}

// Getters
const string& User::getUsername() const {
    return username;
}

void User::setUserId(const std::string& newUserId) {
    userid = newUserId;
}
const string& User::getPassword() const {
    return password;
}

const string& User::getPhonenum() const {
    return phonenum;
}

const string& User::getAddress() const {
    return address;
}

 BankAccount& User::getBankAccount()  {
    return bankAccount;
}

User::UserRole User::getRole() const {
    return role;
}

// Setters
void User::setUsername(const string& newUsername) {
    username = newUsername;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setPhonenum(const string& newPhonenum) {
    phonenum = newPhonenum;
}

void User::setAddress(const string& newAddress) {
    address = newAddress;
}

void User::setBankAccount(const BankAccount& newBankAccount) {
    bankAccount = newBankAccount;
}

void User::setRole(User::UserRole newRole) {
    role = newRole;
}

void User::displayUserDetails(ostream& out) const {
    out << "--------------------------------------\n"
        << "          User DETAILS         \n"
        << "--------------------------------------\n"
        << "Username: " << username << "\n"
        << "Password: " << password << "\n"
        << "Phone Number: " << phonenum << "\n"
        << "Address: " << address << "\n"
        << "Role: " << (role == ADMIN ? "Admin" : "Customer") << "\n"
        << "Bank Account Details: \n" << bankAccount << "\n";
    //        << "--------------------------------------\n";

}

ostream& operator<<(ostream& os, const User& user) {
    user.displayUserDetails(os);
    return os;
}
