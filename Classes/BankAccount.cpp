#include "BankAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

int BankAccount::nextAccountNumber = 1;

//BankAccount::BankAccount(const string& accType, double initBalance)
//    : accountNumber(generateAccountNumber()), accountType(accType), balance(initBalance) {
//    transactions = LinkedList<Transaction>();
//}
//
//// default constructor
//BankAccount::BankAccount() : accountNumber(generateAccountNumber()), balance(0.0) {
//    transactions = LinkedList<Transaction>();
//}
const string& BankAccount::getAccountNumber() const {
    return accountNumber;
}

BankAccount::BankAccount(const string &accType, double initBalance)
    : accountNumber(generateAccountNumber()), accountType(accType), balance(initBalance) {
    transactions = vector<Transaction>();
}

// new default constructor
BankAccount::BankAccount() : accountNumber(generateAccountNumber()), balance(0.0) {
    transactions = std::vector<Transaction>();
}

//const string& BankAccount::getAccountHolderName() const {
//    return accountHolderName;
//}
//
//void BankAccount::setAccountHolderName(const string& name) {
//    accountHolderName = name;
//}

//const string& BankAccount::getAccountHolderNumber() const {
//    return accountHolderNumber;
//}
//
//void BankAccount::setAccountHolderNumber(const string& number) {
//    accountHolderNumber = number;
//}

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

vector<Transaction> BankAccount::getTransactionsList() const {
    return transactions;
}

// Serialization method
std::string BankAccount::serialize() const {
    std::ostringstream oss;
    oss << accountNumber << "," << accountType << "," << std::to_string(balance) << ",";
    for (const auto& transaction : transactions) {
        oss << transaction.serialize() << ",";
    }
    return oss.str();
}

// Deserialization method
BankAccount BankAccount::deserialize(const std::string& str) {
    std::istringstream iss(str);
    BankAccount bankAccount;
    char comma;
    string accNum = bankAccount.getAccountNumber();
    string accType = bankAccount.getAccountType();
    double balance = bankAccount.getBalance();

    if (std::getline(iss, accNum, ',') &&
        std::getline(iss, accType, ',')) {
        // Read balance as a string and convert it to double
        std::string balanceStr;
        if (std::getline(iss, balanceStr, ',')) {
            std::istringstream(balanceStr) >> balance;
        }

        // Deserialize transactions
        std::string transactionsStr;
        std::getline(iss, transactionsStr);
        std::istringstream transactionsIss(transactionsStr);
        std::string transactionStr;
        while (std::getline(transactionsIss, transactionStr, ',')) {
//            bankAccount.transactions.push_back(Transaction::deserialize(transactionStr));
            Transaction t1 = Transaction::deserialize(transactionStr);
            bankAccount.performTransaction(t1.getType(), t1.getAmount());
        }
    }

    return bankAccount;
}

//void BankAccount::performTransaction(Transaction::TransactionType transactionType, double amount) {
//    if (transactionType == Transaction::DEPOSIT) {
//        balance += amount;
//        Transaction currentTransaction = Transaction(transactionType, amount);
//        transactions.append(currentTransaction);
//    } else if (transactionType == Transaction::WITHDRAW) {
//
//        if (balance >= amount) {
//            balance -= amount;
//            Transaction currentTransaction = Transaction(transactionType, amount);
//            transactions.append(currentTransaction);
//        } else {
//            cerr << "Insufficient funds for withdrawal." << endl;
//            return;
//        }
//    }
//    else if(transactionType == Transaction::BALANCE_INQUIRY){
//        Transaction currentTransaction = Transaction(transactionType, 0);
//        transactions.append(currentTransaction);
//
//        cout<< "your balance inquiry result..."<<balance<<endl;
//    }
//}

void BankAccount::performTransaction(string transactionType, double amount) {
    if (transactionType == "DEPOSIT") {
        balance += amount;
        Transaction currentTransaction = Transaction(transactionType, amount);
        transactions.push_back(currentTransaction);
    } else if (transactionType == "WITHDRAW") {

        if (balance >= amount) {
            balance -= amount;
            Transaction currentTransaction = Transaction(transactionType, amount);
            transactions.push_back(currentTransaction);
        } else {
            cerr << "Insufficient funds for withdrawal." << endl;
            return;
        }
    }
    else if(transactionType == "BALANCE_INQUIRY"){
        Transaction currentTransaction = Transaction(transactionType, 0);
        transactions.push_back(currentTransaction);

        cout<< "your balance inquiry result..."<<balance<<endl;
    }
}

void BankAccount::displayTransactionHistory(){
    //TODO: try to fetch username or change fn location
//    cout<<"TRANSACTION HISTORY FOR: "<< "Usertemp" <<" \n" << transactions;
    cout<<"TRANSACTION HISTORY FOR: "<< "Usertemp" <<" \n";
    // display transactions
    for(const auto & transaction : transactions){
        cout<<transaction;
    }
    cout<<getBalance()<<endl;
}



std::string BankAccount::generateAccountNumber() {
    std::stringstream ss;
    ss << "ACC" << std::setfill('0') << std::setw(5) << nextAccountNumber++;
    return ss.str();  // Add this line to return the generated account number
}

void BankAccount::displayAccountDetails(ostream& out) const {
    out << "--------------------------------------\n"
       << "          BANK ACCOUNT DETAILS         \n"
       << "--------------------------------------\n";
    // "Account Holder: " << account.getAccountHolderName() << "\n"
    out << "Account Number: " << accountNumber << "\n"
       << "Account Type: " << accountType << "\n"
       << "Balance: $" << std::fixed << std::setprecision(2) << balance << "\n"
       << "--------------------------------------\n";
}


std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    account.displayAccountDetails(os);
    return os;
}

