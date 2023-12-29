#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "Transaction.h" // Assuming Transaction class is declared in Transaction.h
#include <sstream>
#include <iomanip>
#include <vector>
#include "Transaction.h"
#include "LinkedList.cpp"
using namespace std;

class BankAccount {
private:
    static int nextAccountNumber;
    string accountNumber;
//    string accountHolderNumber;
    string accountType;
    double balance;
//    LinkedList<Transaction> transactions;
    std::vector<Transaction> transactions;


public:
    BankAccount(const string& accType, double initBalance);
    BankAccount();

    const string& getAccountNumber() const;
//    const string& getAccountHolderName() const;
//    void setAccountHolderName(const string& name);
//    const string& getAccountHolderNumber() const;
//    void setAccountHolderNumber(const string& number);
    const string& getAccountType() const;
    void setAccountType(const string& type);
    double getBalance() const;
    void setBalance(double newBalance);
    vector<Transaction> getTransactionsList() const;

//    void performTransaction(Transaction::TransactionType transactionType, double amount);
    void performTransaction(string transactionType, double amount);
    void displayTransactionHistory();
    void displayAccountDetails(ostream& out) const;

    static BankAccount deserialize(const string &str);

    string serialize() const;

private:
    static string generateAccountNumber();

};
ostream& operator<<(ostream& os, const BankAccount& account);


#endif // BANKACCOUNT_H
