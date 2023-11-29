#include "BankAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

int BankAccount::nextAccountNumber = 1;

BankAccount::BankAccount(const string& accHolderName, const string& accHolderNumber, const string& accType, double initBalance)
    : accountNumber(generateAccountNumber()), accountHolderName(accHolderName),
      accountHolderNumber(accHolderNumber), accountType(accType), balance(initBalance) {}

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

    transactions.emplace_back(transactionType, amount);
}

void BankAccount::displayTransactionHistory() const {
    cout << "Transaction History for Account Number " << accountNumber << ":\n";
    cout << setw(20) << "Date" << setw(15) << "Type" << setw(10) << "Amount" << endl;
    cout << string(45, '-') << endl;

    for (const auto& transaction : transactions) {
        cout << setw(20) << transaction.getDate() << setw(15);
        switch (transaction.getType()) {
            case Transaction::DEPOSIT:
                cout << "Deposit";
                break;
            case Transaction::WITHDRAW:
                cout << "Withdrawal";
                break;
            case Transaction::BALANCE_INQUIRY:
                cout << "Balance Inquiry";
                break;
        }
        cout << setw(10) << fixed << setprecision(2) << transaction.getAmount() << endl;
    }
}

string BankAccount::generateAccountNumber() {
    stringstream ss;
    ss << "ACC" << setfill('0') << setw(5) << nextAccountNumber++;
    return ss.str();
}
