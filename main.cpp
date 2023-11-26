#include <iostream>
#include <string>
#include "BankAccount.cpp"
#include "LinkedList.cpp"
using namespace std;

// Main function for testing
int main() {
    List accountList;

    // Add accounts to the list
    accountList.append(BankAccount("John Doe", "AH123", "Savings", 1500.0));
    accountList.append(BankAccount("Jane Doe", "AH456", "Checking", 2000.0));
    accountList.append(BankAccount("Alice Smith", "AH789", "Savings", 3000.0));

    // Display the initial list
    cout << "Initial List:\n" << accountList << endl;

    // Update account information
    accountList.insert(BankAccount("Bob Johnson", "AH999", "Checking", 2500.0), 1);
    accountList.erase(2);

    // Display the updated list
    cout << "Updated List:\n" << accountList << endl;

    return 0;
}