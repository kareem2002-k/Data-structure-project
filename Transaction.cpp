#include <iostream>
#include <string>
#include <vector>
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
    Transaction(TransactionType transactionType, double transactionAmount)
        : type(transactionType), amount(transactionAmount) {

        // Get current date
        time_t now = time(0);
        tm* ltm = localtime(&now);
        date = to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday) + "/" + to_string(1900 + ltm->tm_year);
     
    }

    // Getters for transaction details
    TransactionType getType() const {
        return type;
    }

    double getAmount() const {
        return amount;
    }

    const string& getDate() const {
        return date;
    }
};