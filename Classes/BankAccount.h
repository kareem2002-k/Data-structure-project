#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Transaction.h"
#include "LinkedList.cpp"
using namespace std;

class BankAccount {
private:

public:
    static int nextAccountNumber;
    string accountNumber;
    string accountHolderName;
    string accountHolderNumber;
    string accountType;
    double balance;
    LinkedList<Transaction> transactions;

    BankAccount(const string& accHolderName, const string& accHolderNumber,
                const string& accType, double initBalance);
    // Constructor of BankAccount
       BankAccount() : balance(0.0) , accountNumber(generateAccountNumber()) {
           // Initialize an empty transaction list
           transactions = LinkedList<Transaction>();
       }

    const string& getAccountNumber() const;
    const string& getAccountHolderName() const;
    void setAccountHolderName(const string& name);
    const string& getAccountHolderNumber() const;
    void setAccountHolderNumber(const string& number);
    const string& getAccountType() const;
    void setAccountType(const string& type);
    double getBalance() const;
    void setBalance(double newBalance);

    void performTransaction(string transactionType, double amount);
    void displayTransactionHistory();
    // Serialization method
       string serialize() const;

           // Deserialization method
       static BankAccount deserialize(const string& str);


private:
    static string generateAccountNumber();
};
ostream& operator<<(ostream& os, const BankAccount& account);


#endif // BANKACCOUNT_H
