#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Transaction.h"
#include "LinkedList.cpp"
class BankAccount {
private:
    static int nextAccountNumber;
    std::string accountNumber;
    std::string accountHolderName;
    std::string accountHolderNumber;
    std::string accountType;
    double balance;
    LinkedList<Transaction> transactions;

public:
    BankAccount(const std::string& accHolderName, const std::string& accHolderNumber,
                const std::string& accType, double initBalance);

    const std::string& getAccountNumber() const;
    const std::string& getAccountHolderName() const;
    void setAccountHolderName(const std::string& name);
    const std::string& getAccountHolderNumber() const;
    void setAccountHolderNumber(const std::string& number);
    const std::string& getAccountType() const;
    void setAccountType(const std::string& type);
    double getBalance() const;
    void setBalance(double newBalance);

    void performTransaction(Transaction::TransactionType transactionType, double amount);
    void displayTransactionHistory();

private:
    static std::string generateAccountNumber();
};
std::ostream& operator<<(std::ostream& os, const BankAccount& account);


#endif // BANKACCOUNT_H
