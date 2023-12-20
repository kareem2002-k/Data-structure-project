#include <iostream>
#include <string>
#include "Classes/BankAccount.h"
#include "Classes/Transaction.h"
#include <fstream>
using namespace std;

int main() {

    fstream fout;
    unsigned short x = 8675;
    fout.open("file.dat", ios::out | ios :: binary); // open file for writing as binary
    if (fout)
    {
        fout.write(reinterpret_cast<char*>(&x), sizeof(unsigned short));
        fout.close();
    }
    else
    cout << "Error opening file!\n";

//    // Test the BankAccount class
//    BankAccount account1("Savings", 1500.0);
//    cout << "Initial Account State:\n" << account1;
//
//    BankAccount account2("Checking", 2000.0);
//    cout << "Initial Account State:\n" << account2;
//
//    BankAccount accountM("Checking", 3000.0);
//    // Test BankAccount class
//    cout << "===== BankAccount Class Test =====\n";
//
//
//    BankAccount account3("Savings", 1500.0);
//    cout << "Initial Account State:\n" << account3;
//
//    BankAccount account4("Checking", 3000.0);
//    cout << "Initial Account State:\n" << account4;
//
//    // Test getters and setters
//    // account1.setAccountHolderName("Kareem Updated");
//    account1.setAccountType("Checking");
//    cout << "Updated Account State:\n" << account1;
//
//    // Test deposit and withdrawal
//    account1.performTransaction(Transaction::DEPOSIT, 500.0);
//    account1.performTransaction(Transaction::WITHDRAW, 200.0);
//    cout << "After Deposit and Withdrawal:\n" << account1;
//
//    // Test balance inquiry
//    account1.performTransaction(Transaction::BALANCE_INQUIRY, 0.0);
//
//    // Test transaction history
//    account1.displayTransactionHistory();
//
//    cout << "----------------" << endl;
//    cout << account1;
//    cout << "----------------" << endl;
//
//    // Test the List class
//    LinkedList<BankAccount> accountList;
//    accountList.append(account1);
//    accountList.append(account2);
//    accountList.insert(1, accountM);
//
//    // Display the initial account list
//    cout << "\nInitial Account List:\n" << accountList << endl;
//
//    // Test the remaining functions
//    cout << "\nTesting Remaining LinkedList Functions:\n";
//    cout << "Size of the list: " << accountList.getSize() << endl;
//
//    // Erase an element
//    accountList.erase(0);
//    cout << "\nAfter erasing the first element:\n" << accountList << endl;
//
//    // Insert at a specific index
//    BankAccount accountX("Savings", 3000.0);
//    accountList.insert(1, accountX);
//    cout << "\nAfter inserting at index 1:\n" << accountList << endl;
//
//    // Append an element
//    BankAccount accountY("Checking", 4000.0);
//    accountList.append(accountY);
//    cout << "\nAfter appending:\n" << accountList << endl;
//
//    // Clear the list
//    accountList.clear();
//    cout << "\nAfter clearing the list:\n" << accountList << endl;

    return 0;
}
