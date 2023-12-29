#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Transaction {
public:
//    enum TransactionType {
//        DEPOSIT,
//        WITHDRAW,
//        BALANCE_INQUIRY
//    };

private:


//    TransactionType type;
    string type;
    double amount;
    string date;

public:
    Transaction(const string &transactionType, double transactionAmount);
    Transaction();
//    Transaction(TransactionType transactionType, double transactionAmount);

    // Getters for transaction details
//    TransactionType getType() const;
    string getType() const;
    double getAmount() const;
    const string& getDate() const;

    string serialize() const;

    static Transaction deserialize(const string &str);
};

ostream& operator<<(ostream& os, const Transaction& transaction);

#endif // TRANSACTION_H
