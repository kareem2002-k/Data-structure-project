#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Transaction {
public:
    enum TransactionType {
        DEPOSIT,
        WITHDRAW,
        BALANCE_INQUIRY
    };

private:
    TransactionType type;
    double amount;
    string date;

public:
    Transaction(TransactionType transactionType, double transactionAmount);

    // Getters for transaction details
    TransactionType getType() const;
    double getAmount() const;
    const string& getDate() const;
};

ostream& operator<<(ostream& os, const Transaction& transaction);

#endif // TRANSACTION_H
