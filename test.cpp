#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Transaction {
public:
    std::string type;
    int amount;
    std::string date;

    // Serialization method
    std::string serialize() const {
        return type + "|" + std::to_string(amount) + "|" + date;
    }

    // Deserialization method
    static Transaction deserialize(const std::string& str) {
        std::istringstream iss(str);
        Transaction transaction;
        char pipe;

        if (std::getline(iss, transaction.type, '|') &&
            iss >> transaction.amount >> pipe) {
            std::getline(iss, transaction.date);
        }

        return transaction;
    }
};

class BankAccount {
public:
    static int nextAccountNumber;
    std::string accountNumber;
    std::string accountType;
    int balance;
    std::vector<Transaction> transactions;

    // Serialization method
    std::string serialize() const {
        std::ostringstream oss;
        oss << accountNumber << "," << accountType << "," << std::to_string(balance) << ",";
        for (const auto& transaction : transactions) {
            oss << transaction.serialize() << ",";
        }
        return oss.str();
    }

    // Deserialization method
    static BankAccount deserialize(const std::string& str) {
        std::istringstream iss(str);
        BankAccount bankAccount;
        char comma;

        if (std::getline(iss, bankAccount.accountNumber, ',') &&
            std::getline(iss, bankAccount.accountType, ',')) {
            // Read balance as a string and convert it to double
            std::string balanceStr;
            if (std::getline(iss, balanceStr, ',')) {
                std::istringstream(balanceStr) >> bankAccount.balance;
            }

            // Deserialize transactions
            std::string transactionsStr;
            std::getline(iss, transactionsStr);
            std::istringstream transactionsIss(transactionsStr);
            std::string transactionStr;
            while (std::getline(transactionsIss, transactionStr, ',')) {
                bankAccount.transactions.push_back(Transaction::deserialize(transactionStr));
            }
        }

        return bankAccount;
    }


private:
    static std::string generateAccountNumber();
};

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
    // Create an array of BankAccount objects with transactions
    std::vector<BankAccount> accounts;

    accounts.clear();
    BankAccount account1;
    account1.accountNumber = "wjtw36";
    account1.accountType = "kare3ty3yem";
    account1.balance = 40000;
    account1.transactions.push_back({"DEPOSIT", 500, "2023-01-01"});
    account1.transactions.push_back({"WITHDRAW", 200, "2023-01-02"});
    accounts.push_back(account1);

    BankAccount account3;
    account3.accountNumber = "sdgerg";
    account3.accountType = "egrth";
    account3.balance = 10;
    account3.transactions.push_back({"DEPOSIT", 200000, "2023-01-03"});
    accounts.push_back(account3);

    BankAccount account2;
    account2.accountNumber = "36367rsththr";
    account2.accountType = "336G?E?T#^T";
    account2.balance = 500000;
    account2.transactions.push_back({"DEPOSIT", 1000, "2023-01-03"});
    accounts.push_back(account2);

    BankAccount account6;
    account6.accountNumber = "34get??$#%";
    account6.accountType = "g35gggg543";
    account6.balance = 40000;
    account6.transactions.push_back({"DEPOSIT", 500, "2023-01-01"});
    account6.transactions.push_back({"WITHDRAW", 200, "2023-01-02"});
    accounts.push_back(account6);

    BankAccount account4;
    account4.accountNumber = "3422seacsg4";
    account4.accountType = "345346dfgedr??#$5";
    account4.balance = 10;
    account4.transactions.push_back({"DEPOSIT", 200000, "2023-01-03"});
    accounts.push_back(account4);

    BankAccount account5;
    account5.accountNumber = "5253r5sf??%235";
    account5.accountType = "2355230o-fk09k3r2???)#%$)@#^%";
    account5.balance = 500000;
    account5.transactions.push_back({"DEPOSIT", 1000, "2023-01-03"});
    accounts.push_back(account5);









    // Your encryption key (make sure it's a strong key in a real scenario)
    std::string encryptionKey = "SecretKey";

    // Serialize each object in the array and encrypt
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
            std::cout << "Account Number: " << account.accountNumber << std::endl;
            std::cout << "Account Type: " << account.accountType << std::endl;
            std::cout << "Balance: " << account.balance << std::endl;
            std::cout << "Transactions:" << std::endl;
            for (const auto& transaction : account.transactions) {
                std::cout << "  Type: " << transaction.type << ", Amount: " << transaction.amount
                          << ", Date: " << transaction.date << std::endl;
            }
            std::cout << std::endl;
        }

        // Close the file
        inFile.close();
    } else {
        std::cerr << "Unable to open the file for reading." << std::endl;
        return 1;
    }

    return 0;
}
