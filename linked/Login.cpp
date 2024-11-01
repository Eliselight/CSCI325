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
#include "Bypass.h"
#include "Records.h"

using namespace std;

Login::Login() : generatedPassword(""){}
Login::~Login() {}


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
   forcePasswordChange();
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

bool Login::userLogin() {
    string usernameAttempt, passwordAttempt;

    cout << "Enter your username: ";
    cin >> usernameAttempt;

    cout << "Enter your password: ";
    cin >> passwordAttempt;

    if (usernameAttempt == log.username && passwordAttempt == log.password) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Login failed. Incorrect username or password." << endl;
        return false;
    }
}
void Login::showMenu() {
    int choice;
    Bypass bypass;
    Records records;

      cout << "1. Login as User" << endl;
    cout << "2. Bypass Login (Admin)" << endl;
    cout << "3. Ignore Login (Grading)" << endl;
    cout << "4. Admin Access" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            if (userLogin()) {
                cout << "Logged in as user." << endl;
                // Show phonebook menu after successful login
                Phonebook phonebook;
                phonebook.showMenu();
            }
            break;

        case 2:
            bypass.adminLogin(records);  // Allow admin to login via bypass system
            break;

        case 3:
            bypass.ignoreLogin();  // Skip login and go straight to phonebook
            break;

        case 4:
            bypass.createAdminUser(records);  // Create a new admin user
            break;

        case 5:
            cout << "Exiting..." << endl;
            exit(0);
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            showMenu();
            break;
    }
}
