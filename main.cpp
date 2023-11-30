#include <iostream>
#include <string>
#include "BankAccount.h"
#include "Transaction.h"
using namespace std;

int main() {
    // Test the BankAccount class
    BankAccount account1("John Doe", "10000", "Savings", 1500.0);
    BankAccount account2("Jane Doe", "10000", "Checking", 2000.0);
    BankAccount accountM("KAREEM", "10000", "Checking", 3000.0);

    // Perform transactions on account1
    account1.performTransaction(Transaction::DEPOSIT, 500.0);
    account1.performTransaction(Transaction::WITHDRAW, 200.0);
    account1.performTransaction(Transaction::BALANCE_INQUIRY, 8888.0);
    // Display transaction history for account1
    account1.displayTransactionHistory();

    cout << "----------------" << endl;
    cout << account1;
    cout << "----------------" << endl;

    // Test the List class
    LinkedList<BankAccount> accountList;
    accountList.append(account1);
    accountList.append(account2);
    accountList.insert(1, accountM);

    // Display the initial account list
    cout << "\nInitial Account List:\n" << accountList << endl;

    // Test the remaining functions
    cout << "\nTesting Remaining LinkedList Functions:\n";
    cout << "Size of the list: " << accountList.getSize() << endl;

    // Erase an element
    accountList.erase(0);
    cout << "\nAfter erasing the first element:\n" << accountList << endl;

    // Insert at a specific index
    BankAccount accountX("John X", "10001", "Savings", 3000.0);
    accountList.insert(1, accountX);
    cout << "\nAfter inserting at index 1:\n" << accountList << endl;

    // Append an element
    BankAccount accountY("John Y", "10002", "Checking", 4000.0);
    accountList.append(accountY);
    cout << "\nAfter appending:\n" << accountList << endl;

    // Clear the list
    accountList.clear();
    cout << "\nAfter clearing the list:\n" << accountList << endl;

    return 0;
}
