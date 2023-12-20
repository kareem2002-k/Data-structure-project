#include <iostream>
#include <string>
#include "Classes/BankAccount.h"
#include "Classes/Transaction.h"
#include <fstream>
using namespace std;

int main() {


//    // Test the BankAccount class
   BankAccount account1("Savings", 1090.0);
    fstream();
fstream fout;
    //  unsigned short y = 13848;
    fout.open("flvvvve.dat", ios::out | ios :: binary); // open file for writing as binary
    if (fout)
    {
        fout.write(reinterpret_cast<char*>(&account1), sizeof(BankAccount));
        //fout.write(reinterpret_cast<char*>(&x), sizeof(unsigned short));
        // fout.write(reinterpret_cast<char*>(&y), sizeof(unsigned short));
        fout.close();
    }
    else
        cout << "Error opening file!\n";

    std::ifstream fin;  // Use ifstream for reading
    fin.open("flvvvve.dat", std::ios::in | std::ios::binary);  // Open file for reading as binary

    if (fin.is_open()) {
        BankAccount account2("Checking", 2000.0);  // Create an empty BankAccount object

        // Read the binary data and deserialize into the BankAccount object
        fin.read(reinterpret_cast<char*>(&account2), sizeof(BankAccount));

        fin.close();

        // Now, 'account1' holds the deserialized data
        // You can use 'account1' as needed

      //  std::cout << "Account Name: " << account1.getName() << std::endl;
        std::cout << "Balance: " << account2.getBalance() << std::endl;
    } else {
        std::cout << "Error opening file!\n";
    }



//    // Create an array of BankAccount objects
//    const int NUM_ACCOUNTS = 3;
//    BankAccount accounts[NUM_ACCOUNTS ] = {
//            BankAccount("Savings", 1090.0),
//            BankAccount("Checking", 2000.0),
//            BankAccount("Investment", 5000.0)
//    };
//
//    // Write the array of BankAccount objects to a binary file
//    std::ofstream fout("flvvvve.dat", std::ios::out | std::ios::binary);
//
//    if (fout.is_open()) {
//        fout.write(reinterpret_cast<char*>(&accounts), sizeof(BankAccount) * NUM_ACCOUNTS  );
//        fout.close();
//    } else {
//        std::cout << "Error opening file for writing!\n";
//        return 1;
//    }
//
//    // Read the array of BankAccount objects from the binary file
//    std::ifstream fin("flvvvve.dat", std::ios::in | std::ios::binary);
//
//    if (fin.is_open()) {
//        BankAccount readAccounts[NUM_ACCOUNTS  ];
//
//
//        // Read the binary data and deserialize into the array of BankAccount object
//        fin.read(reinterpret_cast<char*>(&readAccounts), sizeof(BankAccount) * NUM_ACCOUNTS  );
//
//        fin.close();
//
//        // Display the balances of the read accounts
//        for (int i = 0; i < NUM_ACCOUNTS  ; ++i) {
//            std::cout << "Balance for Account " << i + 1 << ": " << readAccounts[i].getBalance() << std::endl;
//        }
//    } else {
//        std::cout << "Error opening file for reading!\n";
//        return 1;
//    }

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
