#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "Transaction.h" // Assuming Transaction class is declared in Transaction.h
#include <sstream>
#include <iomanip>
#include <Transaction.h>
#include <LinkedList.cpp>
using namespace std;

class BankAccount {
private:
    static int nextAccountNumber;
    string accountNumber;
//    string accountHolderNumber;
    string accountType;
    double balance;
    LinkedList<Transaction> transactions;

public:
    BankAccount(const string& accType, double initBalance);

    const string& getAccountNumber() const;
//    const string& getAccountHolderName() const;
//    void setAccountHolderName(const string& name);
//    const string& getAccountHolderNumber() const;
//    void setAccountHolderNumber(const string& number);
    const string& getAccountType() const;
    void setAccountType(const string& type);
    double getBalance() const;
    void setBalance(double newBalance);

    void performTransaction(Transaction::TransactionType transactionType, double amount);
    void displayTransactionHistory();

private:
    static string generateAccountNumber();
};
ostream& operator<<(ostream& os, const BankAccount& account);


#endif // BANKACCOUNT_H
