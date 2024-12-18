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
#include <map>

// Struct to store the record information for each user
struct Record {
    std::string accountNumber;
    std::string encryptedFullName;
    std::string encryptedUsername;
    std::string encryptedPassword;
};

class Records {
private:
    std::vector<Record> userRecords;  // Vector to store multiple user records

    // Admin credentials stored as userNumber -> encryptedPassword
    std::map<std::string, std::string> adminRecords;

    // Helper functions for encryption (each method encrypts differently)
    std::string encryptFullName(const std::string& fullName);
    std::string encryptUsername(const std::string& username);
    std::string encryptPassword(const std::string& password);

    // Convert the generated password into an account number (numeric)
    std::string convertToAccountNumber(const std::string& generatedPassword);

public:
    // Save the user information to records from the login system
    void saveUserInfo(const Log& log, const std::string& generatedPassword);

    // Add a new admin with Admin ID and encrypted password
    void addAdmin(const std::string& adminId, const std::string& encryptedPassword);

    // Check if the admin credentials are correct (Admin ID and encrypted password)
    bool checkAdminCredentials(const std::string& adminId, const std::string& encryptedPassword);

    // Unlock the records for viewing (only accessible by admins)
    void unlockRecords();

    // Write the user records and admin records to a file
    void saveToFile();

    // Load the user and admin records from a file (if needed)
    void loadFromFile();
};

#endif
