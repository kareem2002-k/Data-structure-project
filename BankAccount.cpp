#include "BankAccount.h"
#include <iostream>
#include <iomanip>

int BankAccount::nextAccountNumber = 1;

BankAccount::BankAccount(const std::string& accHolderName, const std::string& accHolderNumber,
                         const std::string& accType, double initBalance)
    : accountNumber(generateAccountNumber()), accountHolderName(accHolderName),
      accountHolderNumber(accHolderNumber), accountType(accType), balance(initBalance) {
    //transactions = LinkedList<Transaction>();
}

const std::string& BankAccount::getAccountNumber() const {
    return accountNumber;
}

const std::string& BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

void BankAccount::setAccountHolderName(const std::string& name) {
    accountHolderName = name;
}

const std::string& BankAccount::getAccountHolderNumber() const {
    return accountHolderNumber;
}

void BankAccount::setAccountHolderNumber(const std::string& number) {
    accountHolderNumber = number;
}

const std::string& BankAccount::getAccountType() const {
    return accountType;
}

void BankAccount::setAccountType(const std::string& type) {
    accountType = type;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(double newBalance) {
    balance = newBalance;
}

void BankAccount::performTransaction(Transaction::TransactionType transactionType, double amount) {
    if (transactionType == Transaction::DEPOSIT) {
        balance += amount;
    } else if (transactionType == Transaction::WITHDRAW) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cerr << "Insufficient funds for withdrawal." << std::endl;
            return;
        }
    }

    //Transaction currentTransaction = Transaction(transactionType, amount);
    //transactions.append(currentTransaction);
}



std::string BankAccount::generateAccountNumber() {
    std::stringstream ss;
    ss << "ACC" << std::setfill('0') << std::setw(5) << nextAccountNumber++;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "Account Holder: " << account.getAccountHolderName() << "\n"
       << "Account Number: " << account.getAccountNumber() << "\n"
       << "Account Type: " << account.getAccountType() << "\n"
       << "Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
    return os;
}