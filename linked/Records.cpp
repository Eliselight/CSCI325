/**
 * @file Records.cpp
 * @author Elise Lightner
 * @date 2024-10-24
 * @brief 
 * 
 * 
 */

#include "Records.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Encrypt full name with Caesar cipher (shift by 5 positions)
string Records::encryptFullName(const string& fullName) {
    string encrypted;
    for (char c : fullName) {
        encrypted += static_cast<char>(c + 5);  // Shift by 5 positions
    }
    return encrypted;
}

// Reverse the username for encryption
string Records::encryptUsername(const string& username) {
    string reversed = username;
    reverse(reversed.begin(), reversed.end());  // Reverse the string
    return reversed;
}

// Encrypt password with Caesar cipher (shift by 3 positions)
string Records::encryptPassword(const string& password) {
    string encrypted;
    for (char c : password) {
        encrypted += static_cast<char>(c + 3);  // Shift by 3 positions
    }
    return encrypted;
}

// Convert generated password into a numeric account number
string Records::convertToAccountNumber(const string& generatedPassword) {
    stringstream ss;
    for (char c : generatedPassword) {
        ss << static_cast<int>(c);  // Convert each character to its ASCII value
    }
    return ss.str();  // Return the concatenated ASCII values as a string
}

// Save the user information from the Login system to the records
void Records::saveUserInfo(const Log& log, const string& generatedPassword) {
    // Create a Record struct for this user
    Record newRecord;
    
    // Convert the generated password to an account number
    newRecord.accountNumber = convertToAccountNumber(generatedPassword);
    
    // Encrypt the user's full name
    newRecord.encryptedFullName = encryptFullName(log.nameFirst + " " + log.initialOrName + " " + log.nameLast);
    
    // Encrypt the username
    newRecord.encryptedUsername = encryptUsername(log.username);
    
    // Encrypt the password
    newRecord.encryptedPassword = encryptPassword(log.password);
    
    // Add the new record to the vector of userRecords
    userRecords.push_back(newRecord);

    cout << "User information saved to records." << endl;
}

// Save all records to a file in the specified format
void Records::saveToFile() {
    ofstream file("user_records.txt");

    if (file.is_open()) {
        for (const Record& record : userRecords) {
            file << "~" << record.accountNumber << "~" << endl;
            file << "{" << record.encryptedFullName << "}" << endl;
            file << "[" << record.encryptedUsername << "]" << endl;
            file << "(" << record.encryptedPassword << ")" << endl;
            file << endl;  // Separate each record with a blank line
        }
        file.close();
        cout << "Records successfully saved to file." << endl;
    } else {
        cout << "Unable to open file to save records." << endl;
    }
}

// Print the current records (for debugging purposes)
void Records::printRecords() const {
    for (const Record& record : userRecords) {
        cout << "~" << record.accountNumber << "~" << endl;
        cout << "{" << record.encryptedFullName << "}" << endl;
        cout << "[" << record.encryptedUsername << "]" << endl;
        cout << "(" << record.encryptedPassword << ")" << endl;
        cout << endl;  // Separate each record with a blank line
    }
}
