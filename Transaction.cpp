#include "Transaction.h"

Transaction::Transaction(TransactionType transactionType, double transactionAmount)
    : type(transactionType), amount(transactionAmount) {

    // Get current date
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date = std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday) + "/" + std::to_string(1900 + ltm->tm_year);
}

// Implement getters
Transaction::TransactionType Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

const std::string& Transaction::getDate() const {
    return date;
}
