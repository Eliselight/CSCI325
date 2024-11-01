/**
 * @file Bypass.cpp
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */



#include "Bypass.h"
#include "Login.h"
#include "phonebook.h"
#include <iostream>

using namespace std;
//int main(){cout << "good" << endl;return 0;}

Login login;
Phonebook phonebook;

string Bypass::encryptApprovalPhrase(const string& phrase) {
  return Methods.caesarEncrypt(phrase, 4);
}

bool Bypass::verifyApprovalPhrase(const string& inputPhrase) {
   return ApprovalPhrase == encryptApprovalPhrase(inputPhrase);
}

void Bypass::createAdminUser(Records& records) {
 string adminId, approvalPhrase, adminPassword, encryptionMethod;

  cout << "Enter a 10-digit Admin ID: ";
  cin >> adminId;

  if (adminId.length() != 10 || !isdigit(adminId[0])) {
      cout << "Invalid Admin ID. It must be exactly 10 digits." << endl;
      return;
  }
  cout << "Enter the approval phrase to confirm admin creation: ";
  cin.ignore();
  getline(cin, approvalPhrase);

  if (verifyApprovalPhrase(approvalPhrase)) {
      cout << "Admin creation approved!" << endl;

      cout << "Create your Admin password (phrase): ";
      getline(cin, adminPassword);

        cout << "Select encryption for password:" << endl;
      cout << "A. Caesar" << endl;
      cout << "B. Reverse" << endl;
      cout << "C. Vigenere" << endl;
      cin >> encryptionMethod;
      string encryptedPassword = Methods.encryptWithMethod(adminPassword, encryptionMethod);

      records.addAdmin(adminId, encryptedPassword);
      records.saveToFile();

      cout << "Admin account created successfully!" << endl;
  } else {
      cout << "Approval phrase is incorrect. Admin creation failed." << endl;
  }
}

void Bypass::adminLogin(Records& records) {
   string adminId, adminPassword, encryptionMethod;

  cout << "Enter your 10-digit Admin ID: ";
  cin >> adminId;

  cout << "Enter your Admin password (phrase): ";
  cin.ignore();
  getline(cin, adminPassword);
    
  cout << "Enter the encryption method for password: ";
  getline(cin, encryptionMethod);

  string encryptedPassword = Methods.encryptWithMethod(adminPassword, encryptionMethod);

  if (records.checkAdminCredentials(adminId, encryptedPassword)) {
      cout << "Admin login successful. You now have access to admin functions." << endl;
     records.unlockRecords();
  } else {
     cout << "Admin login failed. Incorrect Admin ID or password." << endl;
  }
}

void Bypass::ignoreLogin() {
    string skippass;
    string skipaccept = "SkipKericson";
    cout << "To skip login just enter the ignore password: ";
    cin >> skippass;

    if (skippass == skipaccept) {
        cout << "Bypassing login and jumping directly to the Phonebook..." << endl;
	  int choice;
    Phonebook phonebook;
    string fileName, name, phoneNumber;
    char response;
    Entry userInfo;

    while (true) {
        cout << "Welcome to the UTM Phonebook! You may select one of th\
e following options:" << endl;
        cout << "1. Read a phonebook from a file" << endl;
        cout << "2. Write the phonebook to a file" << endl;
        cout << "3. Print the phonebook" << endl;
        cout << "4. Search for a user's phone number" << endl;
        cout << "5. Reverse lookup by phone number" << endl;
        cout << "6. Add a user" << endl;
        cout << "7. Delete a user" << endl;
        cout << "8. Exit this program" << endl;
        //cout << "9. Terminating Session" << endl;
        cout << "Please enter your choice: ";
	cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the filename to read from: ";
                cin >> fileName;
                phonebook.readFromFile(fileName);
                break;
            case 2:
                cout << "Enter the filename to save to: ";
                cin >> fileName;
                phonebook.writeToFile(fileName);
                break;
            case 3:
                phonebook.print();
                break;
            case 4:
                cout << "Enter name to begin search: ";
                cin.ignore();
                getline(cin, name);
                phonebook.lookup(name);
                break;
            case 5:
                cout << "Enter phone number to begin search: ";
                cin >> phoneNumber;
                phonebook.reverseLookup(phoneNumber);
                break;
            case 6:
                phonebook.addUser(userInfo);
                break;
            case 7:
                cout << "Enter the name of the contact to delete: ";
                cin.ignore();
                getline(cin, name);
		  phonebook.deleteUser(name);
                break;
            case 8:
                cout << "Exiting the phonebook..." << endl;
                return;
         default:
                cout << "Invalid choice. Please try again." << endl;
                break;
	}
    }
       
    } else {
        cout << "Incorrect password. Returning to login menu." << endl;
        Login login;
        login.userLogin();
    }
}
