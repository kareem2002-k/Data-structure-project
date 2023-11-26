#include <iostream>
#include <string>
#include "BankAccount.cpp"
#include "LinkedList.cpp"
using namespace std;

// Main function for testing
int main() {
    BankAccount account1("123456", "John Doe", "A123", "Savings", 1000.0);
    BankAccount account2("789012", "Jane Doe", "B456", "Checking", 2000.0);

    List bankAccountList;
    bankAccountList.insert(account1, 0);
    bankAccountList.insert(account2, 1);

    cout << "Bank Accounts:\n" << bankAccountList << endl;

    return 0;
}
