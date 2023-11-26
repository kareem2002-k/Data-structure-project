#include <iostream>
#include <string>
#include "BankAccount.cpp"
#include "LinkedList.cpp"
using namespace std;

int main() {
    // Test the updated classes

    // Create a bank account
    BankAccount account("John Doe", "AH123", "Savings", 1500.0);

    // Perform transactions
    account.performTransaction(Transaction::DEPOSIT, 500.0);
    account.performTransaction(Transaction::WITHDRAW, 200.0);

    // Display transaction history
    account.displayTransactionHistory();

    return 0;
}