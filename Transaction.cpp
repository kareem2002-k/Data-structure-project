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

std::ostream& operator<<(std::ostream& os, const Transaction& transaction) {
    os << "Date: " << transaction.getDate() << "\n";
    switch (transaction.getType()) {
        case Transaction::DEPOSIT:
            os << "Type: Deposit\n";
            break;
        case Transaction::WITHDRAW:
            os << "Type: Withdrawal\n";
            break;
        case Transaction::BALANCE_INQUIRY:
            os << "Type: Balance Inquiry\n";
            break;
    }
    os << "Amount: $" << std::fixed << std::setprecision(2) << transaction.getAmount() << "\n";
    return os;
}
