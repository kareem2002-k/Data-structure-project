#include <iostream>
#include <string>
#include "BankAccount.h"
#include "Transaction.h"
using namespace std;

int main() {
    // Test BankAccount class
    std::cout << "===== BankAccount Class Test =====\n";

    // Test constructor and display
    
    BankAccount account1("Kareem", "12345", "Savings", 1000.0);
    std::cout << "Initial Account State:\n" << account1;

    BankAccount account2("Youssef", "54321", "Checking", 2000.0);
    std::cout << "Initial Account State:\n" << account2;

    BankAccount account3("Omar", "98765", "Savings", 1500.0);
    std::cout << "Initial Account State:\n" << account3;

    BankAccount account4("Ahmed", "56789", "Checking", 3000.0);
    std::cout << "Initial Account State:\n" << account4;

    // Test getters and setters
    account1.setAccountHolderName("Kareem Updated");
    account1.setAccountType("Checking");
    std::cout << "Updated Account State:\n" << account1;

    // Test deposit and withdrawal
    account1.performTransaction(Transaction::DEPOSIT, 500.0);
    account1.performTransaction(Transaction::WITHDRAW, 200.0);
    std::cout << "After Deposit and Withdrawal:\n" << account1;

    // Test balance inquiry
    account1.performTransaction(Transaction::BALANCE_INQUIRY, 0.0);

    // Test transaction history
    account1.displayTransactionHistory();

    // Test Transaction class
    std::cout << "===== Transaction Class Test =====\n";

    // Test constructor and display
    Transaction deposit(Transaction::DEPOSIT, 100.0);
    Transaction withdrawal(Transaction::WITHDRAW, 50.0);
    Transaction balanceInquiry(Transaction::BALANCE_INQUIRY, 0.0);

    std::cout << "Deposit Transaction:\n" << deposit;
    std::cout << "Withdrawal Transaction:\n" << withdrawal;
    std::cout << "Balance Inquiry Transaction:\n" << balanceInquiry;

    // Test LinkedList class
    std::cout << "===== LinkedList Class Test =====\n";

    // Test LinkedList operations
    LinkedList<int> intList;
    intList.insert(0, 1);
    intList.insert(1, 2);
    intList.insert(1, 3);
    std::cout << "Integer LinkedList:\n" << intList;

    intList.erase(1);
    std::cout << "After Erasing at Index 1:\n" << intList;

    // Intensive test for LinkedList
    LinkedList<std::string> stringList;
    stringList.insert(0, "apple");
    stringList.insert(1, "banana");
    stringList.insert(1, "orange");
    std::cout << "String LinkedList:\n" << stringList;

    stringList.erase(1);
    std::cout << "After Erasing at Index 1:\n" << stringList;

    return 0;
}
