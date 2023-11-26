#include <string>
#include <iostream>
#include <vector>
#include "Transaction.cpp" // Include Transaction class when available
#include <sstream>  // For stringstream
#include <iomanip>  // For setfill and setw
using namespace std;

class BankAccount {
private:
    static int nextAccountNumber;
    string accountNumber;
    string accountHolderName;
    string accountHolderNumber;
    string accountType;
    double balance;
    vector<Transaction> transactions;

public:
    BankAccount(const string& accHolderName, const string& accHolderNumber,
                const string& accType, double initBalance)
        : accountNumber(generateAccountNumber()), accountHolderName(accHolderName),
          accountHolderNumber(accHolderNumber), accountType(accType), balance(initBalance) {}

    const string& getAccountNumber() const {
        return accountNumber;
    }

    const string& getAccountHolderName() const {
        return accountHolderName;
    }

    void setAccountHolderName(const string& name) {
        accountHolderName = name;
    }

    const string& getAccountHolderNumber() const {
        return accountHolderNumber;
    }

    void setAccountHolderNumber(const string& number) {
        accountHolderNumber = number;
    }

    const string& getAccountType() const {
        return accountType;
    }

    void setAccountType(const string& type) {
        accountType = type;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }

    // Perform a transaction and add it to the transaction history
    void performTransaction(Transaction::TransactionType transactionType, double amount) {
        if (transactionType == Transaction::DEPOSIT) {
            balance += amount;
        } else if (transactionType == Transaction::WITHDRAW) {
            if (balance >= amount) {
                balance -= amount;
            } else {
                cerr << "Insufficient funds for withdrawal." << endl;
                return;
            }
        }

        // Add the transaction to the history
        transactions.emplace_back(transactionType, amount);
    }

    // Display transaction history
    void displayTransactionHistory() const {
        cout << "Transaction History for Account Number " << accountNumber << ":\n";
        cout << setw(20) << "Date" << setw(15) << "Type" << setw(10) << "Amount" << endl;
        cout << string(45, '-') << endl;

        for (const auto& transaction : transactions) {
            cout << setw(20) << transaction.getDate() << setw(15);
            switch (transaction.getType()) {
                case Transaction::DEPOSIT:
                    cout << "Deposit";
                    break;
                case Transaction::WITHDRAW:
                    cout << "Withdrawal";
                    break;
                case Transaction::BALANCE_INQUIRY:
                    cout << "Balance Inquiry";
                    break;
            }
            cout << setw(10) << fixed << setprecision(2) << transaction.getAmount() << endl;
        }
    }

private:
    static string generateAccountNumber() {
        stringstream ss;
        ss << "ACC" << setfill('0') << setw(5) << nextAccountNumber++;
        return ss.str();
    }
};

int BankAccount::nextAccountNumber = 1;

