#include <iostream>
#include <string>
#include "BankAccount.hpp"
#include "Transaction.hpp"
#include <fstream>
#include "vector"
using namespace::std;

// Function to perform XOR encryption/decryption
std::string xorEncryptDecrypt(const std::string& input, const std::string& key) {
    std::string output;
    for (size_t i = 0; i < input.length(); ++i) {
        output += input[i] ^ key[i % key.length()];
    }
    return output;
}

std::vector<std::string> splitString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = input.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(input.substr(start));
    return tokens;
}

int main() {
    // Create a linked list of BankAccount objects with transactions
       vector<BankAccount> accounts;


       // Create dummy BankAccount objects with transactions
       BankAccount account1;
       account1.accountType = "Savings";
       account1.balance = 1000;
    account1.performTransaction("deposit", 100.0);
    account1.performTransaction("deposit", 800.0);

    
    accounts.emplace_back(account1);

       BankAccount account2;
       account2.accountType = "Checking";
       account2.balance = 2000;
    account2.performTransaction("deposit", 100.0);
    account2.performTransaction("deposit", 800.0);


    accounts.emplace_back(account2);



    BankAccount account3;
    account3.accountType = "Checking";
    account3.balance = 200;
    account3.performTransaction("deposit", 100.0);
    account3.performTransaction("deposit", 800.0);


 accounts.emplace_back(account3);

    BankAccount account4;
    account4.accountType = "Checking";
    account4.balance = 200;
    account4.performTransaction("deposit", 100.0);
    account4.performTransaction("deposit", 800.0);


 accounts.emplace_back(account4);


for(BankAccount acc : accounts){
    cout <<acc<<endl;
}


    // Your encryption key (make sure it's a strong key in a real scenario)
    std::string encryptionKey = "SecretKey";
    
    

    // Serialize each object in the linked list and encrypt
    std::vector<std::string> encryptedStrings;
    
    for (const auto& account : accounts) {
        std::string serializedObject = account.serialize();
        std::string encryptedString = xorEncryptDecrypt(serializedObject, encryptionKey);
        encryptedStrings.push_back(encryptedString);
    }


  
    
    // Open a binary file for writing
    std::ofstream outFile("encrypted_bank_accounts.bin", std::ios::binary);

    if (outFile.is_open()) {
        // Write the encrypted strings to the file, separated by a newline character
        for (const auto& encryptedString : encryptedStrings) {
            outFile << encryptedString << "/012210/";
        }

        // Close the file
        outFile.close();

        std::cout << "Bank accounts encrypted and stored in 'encrypted_bank_accounts.bin'" << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
        return 1;
    }

    // Open the file for reading
    std::ifstream inFile("encrypted_bank_accounts.bin", std::ios::binary);

    if (inFile.is_open()) {
        std::ifstream inFile("encrypted_bank_accounts.bin", std::ios::binary);

        // Read the content of the file into a single string
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        std::string fileContent = buffer.str();

        // Split the content into lines based on the terminator "/012210/"
        std::vector<std::string> lines = splitString(fileContent, "/012210/");
        for(std::string &s : lines){
            std::cout << s << std::endl;
        }

        // Decrypt each string and deserialize
        std::vector<BankAccount> decryptedAccounts;
        for (const auto& encryptedString : lines) {
            std::string decryptedString = xorEncryptDecrypt(encryptedString, encryptionKey);
            BankAccount decryptedAccount = BankAccount::deserialize(decryptedString);
            decryptedAccounts.push_back(decryptedAccount);
        }
        decryptedAccounts.pop_back();

        // Print decrypted bank accounts
        std::cout << "Decrypted Bank Accounts: " << std::endl;
        for (const auto& account : decryptedAccounts) {
            cout <<account <<endl;
        }

        // Close the file
        inFile.close();
    } else {
        std::cerr << "Unable to open the file for reading." << std::endl;
        return 1;
    }

    return 0;
}
