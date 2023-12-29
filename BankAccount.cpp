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

void BankAccount::performTransaction(std::string transactionType, double amount) {
    if (transactionType == "deposit") {
        balance += amount;
        Transaction currentTransaction = Transaction(transactionType, amount);
        transactions.append(currentTransaction);
    } else if (transactionType == "withdraw") {

        if (balance >= amount) {
            balance -= amount;
            Transaction currentTransaction = Transaction(transactionType, amount);
            transactions.append(currentTransaction);
        } else {
            cerr << "Insufficient funds for withdrawal." << endl;
            return;
        }
    }
    else if(transactionType == "inquiry"){
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

std::string BankAccount::serialize() const {
    std::ostringstream oss;

    // Serialize account information
    oss << accountNumber << "," << accountType << "," << std::to_string(balance) << ",";

    // Serialize transactions if the list is not empty
    if (transactions.head != nullptr) {
        auto current = transactions.head;

        while (current != nullptr) {
            // Serialize each transaction and add a comma if not the last one
            oss << current->data.serialize();
            current = current->next;
            if (current != nullptr) {
                oss << ",";
            }
        }
    }

    std::cout << "Serialized BankAccount: " << oss.str() << std::endl;

    return oss.str();
}


// Deserialization method implementation
BankAccount BankAccount::deserialize(const std::string& str) {
    std::istringstream iss(str);
    BankAccount bankAccount;
    char comma;

    if (std::getline(iss, bankAccount.accountNumber, ',') &&
        std::getline(iss, bankAccount.accountType, ',')) {
        // Read balance as a string and convert it to double
        std::string balanceStr;
        if (std::getline(iss, balanceStr, ',')) {
            std::istringstream(balanceStr) >> bankAccount.balance;
        }

        // Deserialize transactions
        std::string transactionsStr;
        std::getline(iss, transactionsStr);
        std::istringstream transactionsIss(transactionsStr);
        std::string transactionStr;
        while (std::getline(transactionsIss, transactionStr, ',')) {
            // Call deserialize for each transaction individually
            Transaction transaction = Transaction::deserialize(transactionStr);
            bankAccount.transactions.append(transaction);
        }
    }

    return bankAccount;
}
