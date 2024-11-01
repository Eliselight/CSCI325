/**
 * @file EncryptionMethods.h
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */

#ifndef ENCRYPTIONMETHODS_H
#define ENCRYPTIONMETHODS_H

#include <string>

class EncryptionMethods {
public:
    std::string caesarEncrypt(const std::string& text, int shift);
    std::string reverseEncrypt(const std::string& text);
    std::string vigenereEncrypt(const std::string& text, const std::string& key);
    std::string encryptWithMethod(const std::string& text, const std::string& method);
};

// Declare an instance of EncryptionMethods for global use to stop multiple definitions
extern EncryptionMethods Methods;

#endif
