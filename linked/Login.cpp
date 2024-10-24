/**
 * @file Login.cpp
 * @author Elise Lightner
 * @date 2024-10-24
 * @brief 
 * 
 * 
 */

#include "Login.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

Login::Login() :
  generatedPassword(""){}

string Login::generatePassword(const Log& log){
  stringstream ss;
  ss << log.nameFirst[0] <<log.initialOrName[0] << log.nameLast[0]
     << static_cast<int>(log.nameFirst[0])
     << static_cast<int>(log.initialOrName[0])
     << static_cast<int>(log.nameLast[0]);
  return ss.str();
}
void Login::createAccount(){
   cout << "Enter your first name: ";
   cin >> log.nameFirst;

   cout << "Enter your middle name or initial: ";
   cin >> log.initialOrName;

   cout << "Enter your last name: ";
   cin >> log.nameLast;
   
   generatedPassword = generatePassword(log);
   
 cout << "Your generated password is: " << generatedPassword << endl;
 cout << "Please re-enter your password to confirm: ";
 string confirmPassword;
 cin >> confirmPassword;
 
 if (verifyPassword(confirmPassword)) {
   log.password = generatedPassword;
   cout << "Password confirmed!" << endl;
   } else {
   cout << "Passwords do not match. Please try again." << endl;
   createAccount();
 }
   
}
void Login::forcePasswordChange() {
    cout << "As a security measure, you must change your password now." << endl;
    cout << "Hint: Use the month of your birth (1-12) to make a strong password." << endl;

    string newPassword;
    cout << "Enter your new password: ";
    cin >> newPassword;

    string confirmNewPassword;
    cout << "Re-enter your new password to confirm: ";
    cin >> confirmNewPassword;

    if (newPassword == confirmNewPassword) {
        log.password = newPassword;
        cout << "Your password has been successfully changed!" << endl;
    } else {
        cout << "Passwords do not match. Please try again." << endl;
        forcePasswordChange();
    }
}
void Login::saveAccount(){
   ofstream file("accounts.txt", ios::app);
    if (file.is_open()) {
        file << "Username: " << log.username << ", "
             << "Name: " << log.nameFirst << " " << log.initialOrName << " " << log.nameLast << ", "
             << "Password: " << log.password << endl;
        file.close();
        cout << "Account saved successfully." << endl;
    } else {
        cout << "Unable to open file for saving account details." << endl;
    }
}
string Login::getUsername() const{
  return log.username;
}
bool Login::verifyPassword(const string& passwordAttempt){
  return passwordAttempt == generatedPassword;

}
void Login::changeUsername(){
  cout << "Would you like to change your username? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter a new username: ";
        cin >> log.username;
        cout << "Your username is now: " << log.username << endl;
    } else {
        cout << "Username remains unchanged." << endl;
    }

}

