 #include <iostream>
#include <string>
#include "BankAccount.h"
#include "Transaction.h"
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

    cout<<"----------------"<<endl;
    cout << account1;
    cout<<"----------------"<<endl;



    // Test the List class
    LinkedList<BankAccount> accountList;
    accountList.append(account1);
    accountList.append(account2);
    accountList.insert(1, accountM);
    
    accountList.erase(0);

    cout << "\nAccount List:\n" << accountList << endl;

    return 0;
}
