/**
 * @file EncryptionMethods.cpp
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */

#include "EncryptionMethods.h"
#include <algorithm>
#include <string>
#include <cctype> //for isalpha, islower, toupper according to google
#include <iostream> 
using namespace std;

//int main() {
//cout << "Working" << endl;
//return 0;
//}

  
EncryptionMethods Methods;

// Caesar Cipher Encryption
string EncryptionMethods::caesarEncrypt(const string& text, int shift) {
    string encryptedText;
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encryptedText += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            encryptedText += c; // Non-alphabetical characters are left unchanged
        }
    }
    return encryptedText;
}

// Reverse Encryption
string EncryptionMethods::reverseEncrypt(const string& text) {
    string reversedText = text;
    reverse(reversedText.begin(), reversedText.end());
    return reversedText;
}

// Vigenere Cipher Encryption
string EncryptionMethods::vigenereEncrypt(const string& text, const string& key) {
    string encryptedText;
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char keyChar = key[keyIndex % keyLength];
            int keyShift = tolower(keyChar) - 'a';
            encryptedText += static_cast<char>((c - base + keyShift) % 26 + base);
            keyIndex++;
        } else {
            encryptedText += c; // Non-alphabetical characters are left unchanged
        }
    }
    return encryptedText;
}

// General Encryption Method Handler
string EncryptionMethods::encryptWithMethod(const string& text, const string& method) {
    if (method == "A" || method == "Caesar") {
        return caesarEncrypt(text, 4); // Example shift
    } else if (method == "B" || method == "Reverse") {
        return reverseEncrypt(text);
    } else if (method == "C" || method == "Vigenere") {
        return vigenereEncrypt(text, "KEY"); // Example key for Vigenere
    } else {
        return text; // Return as-is if the method is not recognized
    }
}
