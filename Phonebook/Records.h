/**
 * @file Records.h
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */

#ifndef RECORDS_H
#define RECORDS_H

#include <string>
#include <vector>
#include <map>
#include "EncryptionMethods.h"
#include "Login.h"

struct Record {
    std::string accountNumber;
    std::string encryptedFullName;
    std::string encryptedUsername;
    std::string encryptedPassword;
};

class Records {
private:
    std::vector<Record> userRecords;
    std::map<std::string, std::string> adminRecords;
    std::string adminApprovalPhraseEncrypted;
    std::string encryptedRecordsPassword;
    std::string encryptFullName(const std::string& fullName);
    std::string encryptUsername(const std::string& username);
    std::string encryptPassword(const std::string& password);
    std::string convertToAccountNumber(const std::string& generatedPassword);

public:
    Records();
    void saveUserInfo(const Log& log, const std::string& generatedPassword);
    void addAdmin(const std::string& adminId, const std::string& encryptedPassword);
    bool checkAdminCredentials(const std::string& adminId, const std::string& encryptedPassword);
    void unlockRecords();
    void saveToFile();
    void loadFromFile();
    void setRecordsPassword(const std::string& password, const std::string& encryptionMethod);
    bool verifyRecordsPassword(const std::string& passwordAttempt, const std::string& encryptionMethod);
};

#endif
