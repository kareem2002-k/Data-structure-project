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
   

public:
    static int nextAccountNumber;
    std::string accountNumber;
    std::string accountHolderName;
    std::string accountHolderNumber;
    std::string accountType;
    double balance;
    LinkedList<Transaction> transactions;

    BankAccount(const std::string& accHolderName, const std::string& accHolderNumber,
                const std::string& accType, double initBalance);
    // Constructor of BankAccount
       BankAccount() : balance(0.0) , accountNumber(generateAccountNumber()) {
           // Initialize an empty transaction list
           transactions = LinkedList<Transaction>();
       }

    const std::string& getAccountNumber() const;
    const std::string& getAccountHolderName() const;
    void setAccountHolderName(const std::string& name);
    const std::string& getAccountHolderNumber() const;
    void setAccountHolderNumber(const std::string& number);
    const std::string& getAccountType() const;
    void setAccountType(const std::string& type);
    double getBalance() const;
    void setBalance(double newBalance);

    void performTransaction(std::string transactionType, double amount);
    void displayTransactionHistory();
    // Serialization method
       std::string serialize() const;

           // Deserialization method
       static BankAccount deserialize(const std::string& str);


private:
    static std::string generateAccountNumber();
};
std::ostream& operator<<(std::ostream& os, const BankAccount& account);


#endif // BANKACCOUNT_H
