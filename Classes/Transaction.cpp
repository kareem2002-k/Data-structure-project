#include "Transaction.h"

//Transaction::Transaction(TransactionType transactionType, double transactionAmount)
//    : type(transactionType), amount(transactionAmount) {
//
//    // Get current date
//    time_t now = time(0);
//    tm* ltm = localtime(&now);
//    date = std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday) + "/" + std::to_string(1900 + ltm->tm_year);
//}

// Implement getters
//Transaction::TransactionType Transaction::getType() const {
//    return type;
//}

string Transaction::getType() const {
    return type;
}

// Constructor
Transaction::Transaction(const std::string& transactionType, double transactionAmount)
        : type(transactionType), amount(transactionAmount) {

    // Get current date
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date = std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday) + "/" + std::to_string(1900 + ltm->tm_year);
}

// default constructor
Transaction::Transaction() : type(), amount(0.0) {}

double Transaction::getAmount() const {
    return amount;
}

const std::string& Transaction::getDate() const {
    return date;
}

// Serialization method
std::string Transaction::serialize() const {
    return type + "|" + std::to_string(amount) + "|" + date;
}

// Deserialization method
Transaction Transaction::deserialize(const std::string& str) {
    std::istringstream iss(str);
    Transaction transaction;
    char pipe;

    if (std::getline(iss, transaction.type, '|') &&
        iss >> transaction.amount >> pipe) {
        std::getline(iss, transaction.date);
    }

    return transaction;
}

std::ostream& operator<<(std::ostream& os, const Transaction& transaction) {
    os << "--------------------------------------\n";
    os << "              TRANSACTION              \n";
    os << "--------------------------------------\n";
    os << "Date: " << transaction.getDate() << "\n";
//    switch (transaction.getType()) {
//        case Transaction::DEPOSIT:
//            os << "Type:    Deposit\n";
//            break;
//        case Transaction::WITHDRAW:
//            os << "Type:    Withdrawal\n";
//            break;
//        case Transaction::BALANCE_INQUIRY:
//            os << "Type:    Balance Inquiry\n";
//            break;
//    }
    os << "Type:    " << transaction.getType() << "\n";
    os << "Amount:  $" << std::fixed << std::setprecision(2) << transaction.getAmount() << "\n";
    os << "--------------------------------------\n";
    os << "\n";
    os << "--------------------------------------\n";
    return os;
}


