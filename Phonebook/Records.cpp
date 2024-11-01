#include "Records.h"
#include "EncryptionMethods.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
//int main() {
//cout << "please" << endl;
//return 0;}

Records::Records() {
    // Use the "Methods" global instance correctly.
    adminApprovalPhraseEncrypted = Methods.caesarEncrypt("approveAdmin", 4);
}

string Records::encryptFullName(const string& fullName) {
    // Use the "Methods" global instance correctly.
    return Methods.caesarEncrypt(fullName, 5);
}

string Records::encryptUsername(const string& username) {
    return Methods.reverseEncrypt(username);
}

string Records::encryptPassword(const string& password) {
    return Methods.caesarEncrypt(password, 3);
}

string Records::convertToAccountNumber(const string& generatedPassword) {
    stringstream ss;
    for (char c : generatedPassword) {
        ss << static_cast<int>(c);
    }
    return ss.str();
}

void Records::saveUserInfo(const Log& log, const string& generatedPassword) {
    Record newRecord;

    newRecord.accountNumber = convertToAccountNumber(generatedPassword);
    newRecord.encryptedFullName = encryptFullName(log.nameFirst + " " + log.initialOrName + " " + log.nameLast);
    newRecord.encryptedUsername = encryptUsername(log.username);
    newRecord.encryptedPassword = encryptPassword(log.password);

    userRecords.push_back(newRecord);
}

void Records::addAdmin(const string& adminId, const string& encryptedPassword) {
    adminRecords[adminId] = encryptedPassword;
}

bool Records::checkAdminCredentials(const string& adminId, const string& encryptedPassword) {
    return adminRecords.find(adminId) != adminRecords.end() &&
           adminRecords[adminId] == encryptedPassword;
}

void Records::unlockRecords() {
    cout << "Displaying all records:" << endl;
    for (const Record& record : userRecords) {
        cout << "~" << record.accountNumber << "~" << endl;
        cout << "{" << record.encryptedFullName << "}" << endl;
        cout << "[" << record.encryptedUsername << "]" << endl;
        cout << "(" << record.encryptedPassword << ")" << endl;
    }
}

void Records::saveToFile() {
    ofstream file("user_records.txt");

    if (file.is_open()) {
        for (const Record& record : userRecords) {
            file << "~" << record.accountNumber << "~" << endl;
            file << "{" << record.encryptedFullName << "}" << endl;
            file << "[" << record.encryptedUsername << "]" << endl;
            file << "(" << record.encryptedPassword << ")" << endl;
        }

        file << "# Admin Records #" << endl;
        for (const auto& admin : adminRecords) {
            file << "Admin ID: " << admin.first << ", Encrypted Password: " << admin.second << endl;
        }
        file.close();
    }
}

void Records::loadFromFile() {
    ifstream file("user_records.txt");

    if (!file.is_open()) {
        cout << "Unable to open file to load records." << endl;
        return;
    }

    string line;
    bool readingAdminRecords = false;

    while (getline(file, line)) {
        if (line == "# Admin Records #") {
            readingAdminRecords = true;
            continue;
        }

        if (!readingAdminRecords) {
            if (line[0] == '~') {
                Record record;

                record.accountNumber = line.substr(1, line.size() - 2);
                getline(file, line);
                record.encryptedFullName = line.substr(1, line.size() - 2);
                getline(file, line);
                record.encryptedUsername = line.substr(1, line.size() - 2);
                getline(file, line);
                record.encryptedPassword = line.substr(1, line.size() - 2);

                userRecords.push_back(record);
            }
        } else {
            if (line.rfind("Admin ID:", 0) == 0) {
                size_t idPos = line.find(":") + 2;
                size_t passPos = line.find("Encrypted Password: ") + 20;

                string adminId = line.substr(idPos, passPos - idPos - 18);
                string encryptedPassword = line.substr(passPos);

                adminRecords[adminId] = encryptedPassword;
            }
        }
    }

    file.close();
}

void Records::setRecordsPassword(const string& password, const string& encryptionMethod) {
    encryptedRecordsPassword = Methods.encryptWithMethod(password, encryptionMethod);
}

bool Records::verifyRecordsPassword(const string& passwordAttempt, const string& encryptionMethod) {
    return encryptedRecordsPassword == Methods.encryptWithMethod(passwordAttempt, encryptionMethod);
}
