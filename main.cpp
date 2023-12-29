#include <iostream>
#include <string>
#include "Classes/BankAccount.h"
#include "Classes/Transaction.h"
#include "Classes/User.h"
#include <fstream>
//#include <vector>
#include <cstring>
//
//using namespace std;
//
//int main() {
//
//    // Test the BankAccount class
//    BankAccount account1("Savings", 1090.0);
//    User user1("JohnDoe", "password123", "123456789",
//               "123 Main St", account1, User::UserRole::CUSTOMER);
//
//    ofstream fout; // Use ofstream for writing
//    fout.open("file.bin", ios::out | ios::binary); // open file for writing as binary
//    if (fout) {
////        fout.write((char*)(&user1), sizeof(User));
//        const char* testData = "Hello, this is a test data!";
//        size_t dataSize = strlen(testData);
//
//        // Write the binary data to the file
//        fout.write(testData, dataSize);
//
//        // Close the file
//        fout.close();
//    } else {
//        cout << "Error opening file for writing!\n";
//        return 1;
//    }
//
//    ifstream fin;  // Use ifstream for reading
//    fin.open("file.bin", ios::in | ios::binary);  // Open file for reading as binary
//
//    if (fin) {
////        User testUser;
////        fin.read((char*)(&testUser), sizeof(User));
//        // Find the length of the file
//        fin.seekg(0, std::ios::end);
//        size_t fileSize = fin.tellg();
//        fin.seekg(0, std::ios::beg);
//
//        // Allocate memory to store the content of the file
//        char* fetchedData = new char[fileSize];
//
//        // Read the binary data from the file
//        fin.read(fetchedData, fileSize);
//
//        // Close the file
//        fin.close();
//
//        // Display the fetched data
//        std::cout << "Fetched Data: " << fetchedData << std::endl;
//
//        // Free the allocated memory
//        delete[] fetchedData;
//        // Now, 'testUser' holds the deserialized data
////        cout << testUser;
//    } else {
//        cout << "Error opening file!\n";
//    }
//
//
////    // Create an array of BankAccount objects
////    const int NUM_ACCOUNTS = 3;
////    BankAccount accounts[NUM_ACCOUNTS ] = {
////            BankAccount("Savings", 1090.0),
////            BankAccount("Checking", 2000.0),
////            BankAccount("Investment", 5000.0)
////    };
////
////    // Write the array of BankAccount objects to a binary file
////    std::ofstream fout("flvvvve.dat", std::ios::out | std::ios::binary);
////
////    if (fout.is_open()) {
////        fout.write(reinterpret_cast<char*>(&accounts), sizeof(BankAccount) * NUM_ACCOUNTS  );
////        fout.close();
////    } else {
////        std::cout << "Error opening file for writing!\n";
////        return 1;
////    }
////
////    // Read the array of BankAccount objects from the binary file
////    std::ifstream fin("flvvvve.dat", std::ios::in | std::ios::binary);
////
////    if (fin.is_open()) {
////        BankAccount readAccounts[NUM_ACCOUNTS  ];
////
////
////        // Read the binary data and deserialize into the array of BankAccount object
////        fin.read(reinterpret_cast<char*>(&readAccounts), sizeof(BankAccount) * NUM_ACCOUNTS  );
////
////        fin.close();
////
////        // Display the balances of the read accounts
////        for (int i = 0; i < NUM_ACCOUNTS  ; ++i) {
////            std::cout << "Balance for Account " << i + 1 << ": " << readAccounts[i].getBalance() << std::endl;
////        }
////    } else {
////        std::cout << "Error opening file for reading!\n";
////        return 1;
////    }
//
////    cout << "Initial Account State:\n" << account1;
////
////    BankAccount account2("Checking", 2000.0);
////    cout << "Initial Account State:\n" << account2;
////
////    BankAccount accountM("Checking", 3000.0);
////    // Test BankAccount class
////    cout << "===== BankAccount Class Test =====\n";
////
////
////    BankAccount account3("Savings", 1500.0);
////    cout << "Initial Account State:\n" << account3;
////
////    BankAccount account4("Checking", 3000.0);
////    cout << "Initial Account State:\n" << account4;
////
////    // Test getters and setters
////    // account1.setAccountHolderName("Kareem Updated");
////    account1.setAccountType("Checking");
////    cout << "Updated Account State:\n" << account1;
////
////    // Test deposit and withdrawal
////    account1.performTransaction(Transaction::DEPOSIT, 500.0);
////    account1.performTransaction(Transaction::WITHDRAW, 200.0);
////    cout << "After Deposit and Withdrawal:\n" << account1;
////
////    // Test balance inquiry
////    account1.performTransaction(Transaction::BALANCE_INQUIRY, 0.0);
////
////    // Test transaction history
////    account1.displayTransactionHistory();
////
////    cout << "----------------" << endl;
////    cout << account1;
////    cout << "----------------" << endl;
////
////    // Test the List class
////    LinkedList<BankAccount> accountList;
////    accountList.append(account1);
////    accountList.append(account2);
////    accountList.insert(1, accountM);
////
////    // Display the initial account list
////    cout << "\nInitial Account List:\n" << accountList << endl;
////
////    // Test the remaining functions
////    cout << "\nTesting Remaining LinkedList Functions:\n";
////    cout << "Size of the list: " << accountList.getSize() << endl;
////
////    // Erase an element
////    accountList.erase(0);
////    cout << "\nAfter erasing the first element:\n" << accountList << endl;
////
////    // Insert at a specific index
////    BankAccount accountX("Savings", 3000.0);
////    accountList.insert(1, accountX);
////    cout << "\nAfter inserting at index 1:\n" << accountList << endl;
////
////    // Append an element
////    BankAccount accountY("Checking", 4000.0);
////    accountList.append(accountY);
////    cout << "\nAfter appending:\n" << accountList << endl;
////
////    // Clear the list
////    accountList.clear();
////    cout << "\nAfter clearing the list:\n" << accountList << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//
//class InnerObject {
//public:
//    std::string innerAttribute1;
//    std::string innerAttribute2;
//
//    // Constructor
//    InnerObject(const std::string& innerAttr1, const std::string& innerAttr2)
//            : innerAttribute1(innerAttr1), innerAttribute2(innerAttr2) {}
//
//    // Serialization method
//    std::string serialize() const {
//        return innerAttribute1 + "|" + innerAttribute2;
//    }
//
//    // Deserialization method
//    static InnerObject deserialize(const std::string& str) {
//        std::istringstream iss(str);
//        std::string innerAttr1, innerAttr2;
//        std::getline(iss, innerAttr1, '|');
//        std::getline(iss, innerAttr2, '|');
//        return InnerObject(innerAttr1, innerAttr2);
//    }
//};
//
//class MyObject {
//public:
//    std::string attribute1;
//    std::string attribute2;
//    std::vector<InnerObject> innerObjects;
//
//    // Constructor
//    MyObject(const std::string& attr1, const std::string& attr2, const std::vector<InnerObject>& innerObjs)
//            : attribute1(attr1), attribute2(attr2), innerObjects(innerObjs) {}
//
//    // Serialization method
//    std::string serialize() const {
//        std::string serializedInnerObjects;
//        for (const auto& innerObj : innerObjects) {
//            serializedInnerObjects += innerObj.serialize() + ",";
//        }
//
//        return attribute1 + "|" + attribute2 + "|" + serializedInnerObjects;
//    }
//
//    // Deserialization method
//    static MyObject deserialize(const std::string& str) {
//        std::istringstream iss(str);
//        std::string attr1, attr2, serializedInnerObjects;
//        std::getline(iss, attr1, '|');
//        std::getline(iss, attr2, '|');
//        std::getline(iss, serializedInnerObjects);
//
//        // Deserialize inner objects
//        std::istringstream innerIss(serializedInnerObjects);
//        std::string innerObjectStr;
//        std::vector<InnerObject> innerObjects;
//        while (std::getline(innerIss, innerObjectStr, ',')) {
//            innerObjects.push_back(InnerObject::deserialize(innerObjectStr));
//        }
//
//        return MyObject(attr1, attr2, innerObjects);
//    }
//};
//
//// Function to perform XOR encryption/decryption
//std::string xorEncryptDecrypt(const std::string& input, const std::string& key) {
//    std::string output;
//    for (size_t i = 0; i < input.length(); ++i) {
//        output += input[i] ^ key[i % key.length()];
//    }
//    return output;
//}
//
//int main() {
//    // Create an array of objects with nested arrays
//    std::vector<MyObject> objects;
//    objects.push_back(MyObject("Value1", "Value2", {InnerObject("Inner1", "Inner2")}));
//    objects.push_back(MyObject("Value3", "Value4", {InnerObject("Inner3", "Inner4"), InnerObject("Inner5", "Inner6")}));
//
//    // Your encryption key (make sure it's a strong key in a real scenario)
//    std::string encryptionKey = "SecretKey";
//
//    // Serialize each object in the array and encrypt
//    std::vector<std::string> encryptedStrings;
//    for (const auto& obj : objects) {
//        std::string serializedObject = obj.serialize();
//        std::string encryptedString = xorEncryptDecrypt(serializedObject, encryptionKey);
//        encryptedStrings.push_back(encryptedString);
//    }
//
//    // Open a binary file for writing
//    std::ofstream outFile("encrypted_objects_with_arrays.bin", std::ios::binary);
//
//    if (outFile.is_open()) {
//        // Write the encrypted strings to the file, separated by a newline character
//        for (const auto& encryptedString : encryptedStrings) {
//            outFile << encryptedString << '\n';
//        }
//
//        // Close the file
//        outFile.close();
//
//        std::cout << "Objects with arrays encrypted and stored in 'encrypted_objects_with_arrays.bin'" << std::endl;
//    } else {
//        std::cerr << "Unable to open the file for writing." << std::endl;
//        return 1;
//    }
//
//    // Open the file for reading
//    std::ifstream inFile("encrypted_objects_with_arrays.bin", std::ios::binary);
//
//    if (inFile.is_open()) {
//        // Read the contents of the file into a vector of strings
//        std::vector<std::string> encryptedFromFile;
//        std::string encryptedString;
//        while (std::getline(inFile, encryptedString)) {
//            encryptedFromFile.push_back(encryptedString);
//        }
//
//        // Decrypt each string and deserialize
//        std::vector<MyObject> decryptedObjects;
//        for (const auto& encryptedString : encryptedFromFile) {
//            std::string decryptedString = xorEncryptDecrypt(encryptedString, encryptionKey);
//            MyObject decryptedObject = MyObject::deserialize(decryptedString);
//            decryptedObjects.push_back(decryptedObject);
//        }
//
//        // Close the file
//        inFile.close();
//
//        // Print decrypted objects
//        std::cout << "Decrypted Objects with Arrays: " << std::endl;
//        for (const auto& obj : decryptedObjects) {
//            std::cout << "Attribute1: " << obj.attribute1 << ", Attribute2: " << obj.attribute2 << std::endl;
//            std::cout << "Inner Objects:" << std::endl;
//            for (const auto& innerObj : obj.innerObjects) {
//                std::cout << "  Inner Attribute1: " << innerObj.innerAttribute1 << ", Inner Attribute2: " << innerObj.innerAttribute2 << std::endl;
//            }
//            std::cout << std::endl;
//        }
//    } else {
//        std::cerr << "Unable to open the file for reading." << std::endl;
//        return 1;
//    }
//
//    return 0;
//}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Function to perform XOR encryption/decryption
string xorEncryptDecrypt(const string& input, const string& key) {
    string output;
    for (size_t i = 0; i < input.length(); ++i) {
        output += input[i] ^ key[i % key.length()];
    }
    return output;
}

vector<string> splitString(const string& input, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = input.find(delimiter, start)) != string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(input.substr(start));
    return tokens;
}


#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

// Function to create random accounts and push them to the vector
//void createRandomAccounts(std::vector<BankAccount>& accounts, int numAccounts) {
//    // Seed for random number generation
////    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
////    std::srand(static_cast<unsigned>(seed));
//    std::random_device rd;
//    std::mt19937 gen(rd());
//
//
//    for (int i = 0; i < numAccounts; ++i) {
//        // Randomize account type (Savings or Checking)
////        std::string randomAccountType = (std::rand() % 2 == 0) ? "Savings" : "Checking";
//        std::uniform_int_distribution<> distribution(0, 1);
//        std::string randomAccountType = (distribution(gen) == 0) ? "Savings" : "Checking";
//
//        // Generate random initial balance
//        std::uniform_real_distribution<> balanceDistribution(1000.0, 50000.0);
//        double randomInitialBalance = balanceDistribution(gen);
////        double randomInitialBalance = static_cast<double>(std::rand() % 5000 + 500);
//
//        // Create a random account
//        BankAccount randomAccount(randomAccountType, randomInitialBalance);
//
//        // Perform random transactions (e.g., DEPOSIT and WITHDRAW)
////        int numTransactions = std::rand() % 5 + 1;
////        for (int j = 0; j < numTransactions; ++j) {
////            std::string transactionType = (std::rand() % 2 == 0) ? "DEPOSIT" : "WITHDRAW";
////            double transactionAmount = static_cast<double>(std::rand() % 1000 + 100);
////            randomAccount.performTransaction(transactionType, transactionAmount);
////        }
//        std::uniform_int_distribution<> transactionCountDistribution(0, 3);
//        int numTransactions = transactionCountDistribution(gen);
//        for (int j = 0; j < numTransactions; ++j) {
//            // Generate a random number to determine transaction type
//            std::uniform_int_distribution<> transactionTypeDistribution(0, 1);
//            std::string transactionType = (transactionTypeDistribution(gen) == 0) ? "DEPOSIT" : "WITHDRAW";
//
//            // Generate random transaction amount
//            std::uniform_real_distribution<> transactionAmountDistribution(100.0, 1000.0);
//            double transactionAmount = transactionAmountDistribution(gen);
//
//            // Perform the transaction
//            randomAccount.performTransaction(transactionType, transactionAmount);
//        }
//
//        // Push the random account to the vector
//        accounts.push_back(randomAccount);
//    }
//}

int main() {
    // Vector to store the accounts
//    std::vector<BankAccount> accounts;
//    accounts.clear();

    // Create 50 random accounts
//    createRandomAccounts(accounts, 50);

    // Display the account details
//    std::cout << "Randomly Generated Accounts before encryption: " << std::endl;
//    for (const auto& account : accounts) {
//        std::cout << account << std::endl;
//    }


//    BankAccount account1("Savings", 1090.0);
//
//    account1.performTransaction("DEPOSIT", 500.0);
//    account1.performTransaction("WITHDRAW", 200.0);
//
//    accounts.push_back(account1);
//
//    BankAccount account3("Savings", 1500.0);
//    account3.performTransaction("DEPOSIT", 200000.0);
//
//    accounts.push_back(account3);
//
//    BankAccount account2("Checking", 2000.0);
//    account2.performTransaction("DEPOSIT", 1000.0);
//
//    accounts.push_back(account2);
//
//    BankAccount account6("Checking", 3000.0);
//    account6.performTransaction("DEPOSIT", 1000.0);
//    account6.performTransaction("WITHDRAW", 400.0);
//
//    accounts.push_back(account6);
//
//    BankAccount account4("Checking", 3000.0);
//    account4.performTransaction("DEPOSIT", 1000.0);
//
//    accounts.push_back(account4);
//
//    BankAccount account5("Checking", 3000.0);
//    account5.performTransaction("DEPOSIT", 1000.0);
//
//    accounts.push_back(account5);

    // Your encryption key (make sure it's a strong key in a real scenario)
    string encryptionKey = "SecretKey";

    // Serialize each object in the array and encrypt
    vector<string> encryptedStrings;

//    for (const auto& account : accounts) {
//        string serializedObject = account.serialize();
//        string encryptedString = xorEncryptDecrypt(serializedObject, encryptionKey);
//        encryptedStrings.push_back(encryptedString);
//    }



    // Open a binary file for writing
//    std::ofstream outFile("encrypted_bank_accounts.bin", std::ios::binary);

//    if (outFile.is_open()) {
//        // Write the encrypted strings to the file, separated by a newline character
//        for (const auto& encryptedString : encryptedStrings) {
//            outFile << encryptedString << "/012210/";
//        }
//
//        // Close the file
//        outFile.close();
//
//        cout << "Bank accounts encrypted and stored in 'encrypted_bank_accounts.bin'\n" << endl;
//    } else {
//        cerr << "Unable to open the file for writing." << endl;
//        return 1;
//    }

    // Open the file for reading
    std::ifstream inFile("encrypted_bank_accounts.bin", std::ios::binary);

    if (inFile.is_open()) {
        std::ifstream inFile("encrypted_bank_accounts.bin", std::ios::binary);


        // Read the content of the file into a single string
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        string fileContent = buffer.str();


        // Split the content into lines based on the terminator "/012210/"
        vector<string> lines = splitString(fileContent, "/012210/");
        cout<<"Printing encrypted:\n"<<endl;
        for(string &s : lines){
            cout << s << endl;
        }


        // Decrypt each string and deserialize
        vector<BankAccount> decryptedAccounts;
        for (const auto& encryptedString : lines) {
            string decryptedString = xorEncryptDecrypt(encryptedString, encryptionKey);
            BankAccount decryptedAccount = BankAccount::deserialize(decryptedString);
            decryptedAccounts.push_back(decryptedAccount);
        }
        decryptedAccounts.pop_back();


        // Print decrypted bank accounts
        cout << "Decrypted Bank Accounts: " << endl;
        for (const auto& account : decryptedAccounts) {
            cout << "Account Number: " << account.getAccountNumber() << endl;
            cout << "Account Type: " << account.getAccountType() << endl;
            cout << "Balance: " << account.getBalance() << endl;
            cout << "Transactions:" << endl;
            for (const auto& transaction : account.getTransactionsList()) {
                cout << " Type: " << transaction.getType() << ", Amount: " << transaction.getAmount()
                          << ", Date: " << transaction.getDate() << endl;
            }
            cout << endl;
        }

        // Close the file
        inFile.close();
    } else {
        cerr << "Unable to open the file for reading." << endl;
        return 1;
    }

    return 0;
}
