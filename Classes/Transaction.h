#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <iomanip>

class Transaction {
public:
//    enum TransactionType {
//        DEPOSIT,
//        WITHDRAW,
//        BALANCE_INQUIRY
//    };

private:
  
public:
    std::string type;
    double amount;
    std::string date;

    Transaction(std::string transactionType, double transactionAmount);

    // Getters for transaction details
    std::string getType() const;
    double getAmount() const;
    const std::string& getDate() const;
    static Transaction deserialize(const std::string& str);
    std::string serialize() const;

    Transaction() : amount(0) {}  // Set default values as needed


};

std::ostream& operator<<(std::ostream& os, const Transaction& transaction);

#endif // TRANSACTION_H
