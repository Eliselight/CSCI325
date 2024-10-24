/**
 * @file Records.h
 * @author Elise Lightner
 * @date 2024-10-24
 * @brief 
 * 
 * 
 */

#ifndef RECORDS_H
#define RECORDS_H

#include <string>
#include <vector>
#include "Login.h"  // Import the Log struct from the Login system

// Struct to store the record information for each user
typedef struct Record {
    std::string encryptedUsername;
    std::string encryptedPassword;
    std::string encryptedFullName;
} Record;

class Records {
private:
    std::vector<Record> userRecords;  // Vector to store multiple user records

    // Encryption methods for each piece of information
    std::string encryptUsername(const std::string& username);  // Caesar cipher for username
    std::string encryptPassword(const std::string& password);  // Reverse Caesar cipher for password
    std::string encryptFullName(const std::string& fullName);  // XOR cipher for full name

public:
    // Save the user information to records from the login system
    void saveUserInfo(const Log& log);

    // Write the user records to a file
    void saveToFile();

    // Print the current records (for testing purposes)
    void printRecords() const;

    // Load records from a file (if needed)
    void loadRecordsFromFile();
};

#endif
