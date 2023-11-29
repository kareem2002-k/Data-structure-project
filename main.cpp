#include <iostream>
#include <string>
#include "BankAccount.h"
#include "LinkedList.cpp"  // Assuming the List class is defined in this file
using namespace std;

int main() {
    // Test the BankAccount class
    BankAccount account1("John Doe", "10000", "Savings", 1500.0);
    BankAccount account2("Jane Doe", "10000", "Checking", 2000.0);
    BankAccount accountM("kAREEM", "10000", "Checking", 3000.0);

    // Perform transactions on account1
    account1.performTransaction(Transaction::DEPOSIT, 500.0);
    account1.performTransaction(Transaction::WITHDRAW, 200.0);

    // Display transaction history for account1
    account1.displayTransactionHistory();

    // Display account details
    cout << "Account Details:\n";
    cout << "Account Number: " << account1.getAccountNumber() << endl;
    cout << "Account Holder Name: " << account1.getAccountHolderName() << endl;
    cout << "Account Holder Number: " << account1.getAccountHolderNumber() << endl;
    cout << "Account Type: " << account1.getAccountType() << endl;
    cout << "Balance: " << account1.getBalance() << endl;

    // Test the List class
    List accountList;
    accountList.append(account1);
    accountList.append(account2);
    accountList.insert(accountM, 1);
    
    accountList.erase(0);

    cout << "\nAccount List:\n" << accountList << endl;

    // Update account details in the list
    accountList.updateBalance("AH123", 3000.0);
    accountList.updateName("AH456", "New Jane Doe");
    accountList.updateNumber("AH123", "New Number");

    cout << "\nUpdated Account List:\n" << accountList << endl;

    return 0;
}
