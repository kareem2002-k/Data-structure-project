#include <string>
#include <iostream>
#include <vector>
#include "Transaction.cpp"
using namespace std;

class BankAccount{
    private:
        string accountNumber;
        string accountHolderName;
        string accountHolderNumber;
        string accountType;
        vector<Transaction> transactions;
        double balance;
};