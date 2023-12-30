#include "MyForm2h.h"
#include "homeform.h"
#include "depositform.h"
#include <iostream>
#include <string>
#include "BankAccount.h"
#include "Transaction.h"
#include <fstream>
#include "vector"
#include "User.h"



using namespace::std;

using namespace System;
using namespace System::Windows::Forms;
[STAThread]



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



void main() {

    // Create a linked list of BankAccount objects with transactions
    vector<BankAccount> accounts;
    vector<User> users;



    // Create three dummy accounts
    User dummy1(User::CUSTOMER, "John", "Doe", "john@example.com", "password123", "123456789", 1000.0,"kareem");
    User dummy2(User::CUSTOMER, "Jane", "Smith", "jane@example.com", "securepass", "987654321", 1500.0,"ahmed");
    User dummy3(User::ADMIN, "Admin", "User", "admin@example.com", "adminpass", "555555555", 5000.0,"samir");



    dummy1.getBankAccount().performTransaction("deposit", 100);
    dummy1.getBankAccount().performTransaction("deposit", 300);

    dummy2.getBankAccount().performTransaction("deposit", 400);
    dummy2.getBankAccount().performTransaction("deposit", 500);



    dummy3.getBankAccount().performTransaction("deposit", 200);
    dummy3.getBankAccount().performTransaction("deposit", 300);

    users.emplace_back(dummy1);
    users.emplace_back(dummy2);
    users.emplace_back(dummy3);

   
    
    
    // Your encryption key (make sure it's a strong key in a real scenario)
    std::string encryptionKey = "SecretKey";



    // Serialize each object in the linked list and encrypt
    std::vector<std::string> encryptedStrings;

    for (const auto& account : users) {
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
    }
    else {
        std::cerr << "Unable to open the file for writing." << std::endl;
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
        for (std::string& s : lines) {
            std::cout << s << std::endl;
        }

        // Decrypt each string and deserialize
        std::vector<User> decryptedAccounts;
        for (const auto& encryptedString : lines) {
            std::string decryptedString = xorEncryptDecrypt(encryptedString, encryptionKey);
            User decryptedAccount = User::deserialize(decryptedString);
            decryptedAccounts.push_back(decryptedAccount);
        }
        decryptedAccounts.pop_back();

        // Print decrypted bank accounts
        std::cout << "Decrypted Bank Accounts: " << std::endl;
        for (const auto& account : decryptedAccounts) {
            cout << account << endl;
        }

        // Close the file
        inFile.close();
    }
    else {
        std::cerr << "Unable to open the file for reading." << std::endl;
    }


	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::homeform form;


	Application::Run(% form);


}