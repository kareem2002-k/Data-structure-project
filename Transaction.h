#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    std::string date;

public:
    Transaction(TransactionType transactionType, double transactionAmount);

    // Getters for transaction details
    TransactionType getType() const;
    double getAmount() const;
    const std::string& getDate() const;
};

#endif // TRANSACTION_H
