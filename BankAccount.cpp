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
        Transaction currentTransaction = Transaction(transactionType, amount);
        transactions.append(currentTransaction);
    } else if (transactionType == Transaction::WITHDRAW) {

        if (balance >= amount) {
            balance -= amount;
            Transaction currentTransaction = Transaction(transactionType, amount);
            transactions.append(currentTransaction);
        } else {
            cerr << "Insufficient funds for withdrawal." << endl;
            return;
        }
    }
    else if(transactionType == Transaction::BALANCE_INQUIRY){
        Transaction currentTransaction = Transaction(transactionType, 0);
        transactions.append(currentTransaction);

        cout<< "your balance inquiry result..."<<balance<<endl;
    }
}

void BankAccount::displayTransactionHistory(){

    cout<<"TRANSACTION HISTORY FOR: "<<accountHolderName<<" \n" <<transactions;
    cout<<getBalance()<<endl;
}



std::string BankAccount::generateAccountNumber() {
    std::stringstream ss;
    ss << "ACC" << std::setfill('0') << std::setw(5) << nextAccountNumber++;
    return ss.str();  // Add this line to return the generated account number
}

std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "--------------------------------------\n";
    os << "          BANK ACCOUNT DETAILS         \n";
    os << "--------------------------------------\n";
    os << "Account Holder: " << account.getAccountHolderName() << "\n";
    os << "Account Number: " << account.getAccountNumber() << "\n";
    os << "Account Type:   " << account.getAccountType() << "\n";
    os << "Balance:        $" << std::fixed << std::setprecision(2) << account.getBalance() << "\n";
    os << "--------------------------------------\n";
    return os;
}

