#include "BankAccount.h"
#include <iostream>
#include <iomanip>

int BankAccount::nextAccountNumber = 1;

BankAccount::BankAccount(const std::string& accHolderName, const std::string& accHolderNumber,
                         const std::string& accType, double initBalance)
    : accountNumber(generateAccountNumber()), accountHolderName(accHolderName),
      accountHolderNumber(accHolderNumber), accountType(accType), balance(initBalance) {}

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

    transactions.emplace_back(transactionType, amount);
}

void BankAccount::displayTransactionHistory() const {
    std::cout << "Transaction History for Account Number " << accountNumber << ":\n";
    std::cout << std::setw(20) << "Date" << std::setw(15) << "Type" << std::setw(10) << "Amount" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    for (const auto& transaction : transactions) {
        std::cout << std::setw(20) << transaction.getDate() << std::setw(15);
        switch (transaction.getType()) {
            case Transaction::DEPOSIT:
                std::cout << "Deposit";
                break;
            case Transaction::WITHDRAW:
                std::cout << "Withdrawal";
                break;
            case Transaction::BALANCE_INQUIRY:
                std::cout << "Balance Inquiry";
                break;
        }
        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << transaction.getAmount() << std::endl;
    }
}

std::string BankAccount::generateAccountNumber() {
    std::stringstream ss;
    ss << "ACC" << std::setfill('0') << std::setw(5) << nextAccountNumber++;
    return ss.str();
}
