/**
 * @file Bypass.h
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */


#ifndef BYPASS_H
#define BYPASS_H

#include <string>
#include "Records.h"
#include "EncryptionMethods.h"

class Bypass {
private:
    std::string encryptApprovalPhrase(const std::string& phrase);
    std::string encryptionMethods;
    const std::string ApprovalPhrase = Methods.caesarEncrypt("approveAdmin", 4);

public:
    void createAdminUser(Records& records);
    void adminLogin(Records& records);
    bool verifyApprovalPhrase(const std::string& inputPhrase);
    void ignoreLogin();
};

#endif
