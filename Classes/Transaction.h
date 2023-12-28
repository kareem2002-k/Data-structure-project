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
    std::string type;
    double amount;
    string date;

public:
    Transaction(std::string transactionType, double transactionAmount);
    Transaction() : amount(0) {}  // Set default values as needed


    // Getters for transaction details
    std::string getType() const;
    double getAmount() const;
    const string& getDate() const;
    std::string serialize() const;
    static Transaction deserialize(const std::string& str);

};

ostream& operator<<(ostream& os, const Transaction& transaction);

#endif // TRANSACTION_H
