#include <string>
#include <iostream>
#include <vector>
#include "Transaction.cpp" // Include Transaction class when available
#include <sstream>  // For stringstream
#include <iomanip>  // For setfill and setw
using namespace std;

class BankAccount {
private:
    static int nextAccountNumber; // Static variable to generate unique account numbers
    string accountNumber;
    string accountHolderName;
    string accountHolderNumber;
    string accountType;
    // vector<Transaction> transactions;  // Uncomment when Transaction class is defined
    double balance;

public:
    // Constructor
    BankAccount(const string& accHolderName, const string& accHolderNumber,
                const string& accType, double initBalance)
        : accountNumber(generateAccountNumber()), accountHolderName(accHolderName),
          accountHolderNumber(accHolderNumber), accountType(accType), balance(initBalance) {}

    // Getters and Setters
    const string& getAccountNumber() const {
        return accountNumber;
    }

    const string& getAccountHolderName() const {
        return accountHolderName;
    }

    void setAccountHolderName(const string& name) {
        accountHolderName = name;
    }

    const string& getAccountHolderNumber() const {
        return accountHolderNumber;
    }

    void setAccountHolderNumber(const string& number) {
        accountHolderNumber = number;
    }

    const string& getAccountType() const {
        return accountType;
    }

    void setAccountType(const string& type) {
        accountType = type;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }

private:
    // Generate a unique account number using a static variable
    static string generateAccountNumber() {
        stringstream ss;
        ss << "ACC" << setfill('0') << setw(5) << nextAccountNumber++;
        return ss.str();
    }
};
