#include "BankAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

int BankAccount::nextAccountNumber = 1;

BankAccount::BankAccount(const string& accHolderName, const string& accHolderNumber, const string& accType, double initBalance)
    : accountNumber(generateAccountNumber()), accountHolderName(accHolderName),
      accountHolderNumber(accHolderNumber), accountType(accType), balance(initBalance) {
    transactions = LinkedList<Transaction>();
}

const string& BankAccount::getAccountNumber() const {
    return accountNumber;
}

const string& BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

void BankAccount::setAccountHolderName(const string& name) {
    accountHolderName = name;
}

const string& BankAccount::getAccountHolderNumber() const {
    return accountHolderNumber;
}

void BankAccount::setAccountHolderNumber(const string& number) {
    accountHolderNumber = number;
}

const string& BankAccount::getAccountType() const {
    return accountType;
}

void BankAccount::setAccountType(const string& type) {
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
            cerr << "Insufficient funds for withdrawal." << endl;
            return;
        }
    }

    Transaction currentTransaction = Transaction(transactionType, amount);
    transactions.append(currentTransaction);
}

void BankAccount::displayTransactionHistory(){

    std::cout<<"TRANSACTION HISTORY FOR: "<<accountHolderName<<" \n" <<transactions;
}



std::string BankAccount::generateAccountNumber() {
    std::stringstream ss;
    ss << "ACC" << std::setfill('0') << std::setw(5) << nextAccountNumber++;
}

std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "Account Holder: " << account.getAccountHolderName() << "\n"
       << "Account Number: " << account.getAccountNumber() << "\n"
       << "Account Type: " << account.getAccountType() << "\n"
       << "Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
    return os;
}