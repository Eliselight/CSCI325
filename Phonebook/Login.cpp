/**
 * @file Login.cpp
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */

#include "Login.h"
#include <iostream>
#include <string>
#include "EncryptionMethods.h"

using namespace std;
//int main(){
//cout << "hello" << endl;
//return 0;
//}
Login::Login() {}

Login::~Login() {}

string Login::generatePassword(const Log& log) {
    return log.initialOrName + log.nameFirst + log.nameLast + "123"; // Example password generation
}

void Login::createAccount() {
    cout << "Enter First Name: ";
    cin >> log.nameFirst;
    cout << "Enter Middle Initial or Nickname: ";
    cin >> log.initialOrName;
    cout << "Enter Last Name: ";
    cin >> log.nameLast;

    generatedPassword = generatePassword(log);
    cout << "Your generated password is: " << generatedPassword << endl;

    string confirmPassword;
    cout << "Please enter the generated password to continue: ";
    cin >> confirmPassword;

    if (confirmPassword == generatedPassword) {
        forcePasswordChange();
    } else {
        cout << "Passwords do not match. Account creation failed." << endl;
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
	 changeUsername();
    } else {
        cout << "Passwords do not match. Please try again." << endl;
        forcePasswordChange();
    }
}

Log Login::getUserInfo() const {
    return log;
}

string Login::getUsername() const {
    return log.username;
}

bool Login::verifyPassword(const string& passwordAttempt) {
    return log.password == passwordAttempt;
}

void Login::changeUsername() {
    cout << "Enter a new username: ";
    cin >> log.username;
    cout << "Username successfully updated to: " << log.username << endl;
   
}

bool Login::userLogin() {
    string usernameAttempt, passwordAttempt, firstNameAttempt, lastNameAttempt;
    int failedAttempts = 0;

    cout << "Enter Username or First and Last Name: ";
    cin >> usernameAttempt;

    if (usernameAttempt == log.username && !usernameAttempt.empty()) {
        cout << "Enter Password: ";
        cin >> passwordAttempt;

        if (verifyPassword(passwordAttempt)) {
            cout << "Login successful." << endl;
            return true;
        } else {
            failedAttempts++;
            cout << "Invalid username or password." << endl;
            return false;
        }
    } else {
        cout << "Username not found. Please enter your First and Last Name: ";
        cin.ignore();
        getline(cin, firstNameAttempt);
	getline(cin, lastNameAttempt);

        if (firstNameAttempt == log.nameFirst && lastNameAttempt == log.nameLast) {
            cout << "Enter Password for " << log.nameFirst << " " << log.nameLast << ": ";
            cin >> passwordAttempt;

            if (verifyPassword(passwordAttempt)) {
                cout << "Login successful." << endl;
                cout << "Reminder: Your username is " << log.username << endl;
                return true;
            } else {
                failedAttempts++;
                cout << "The system does not believe you are " << log.nameFirst << " " << log.nameLast << ". Sorry, terminating the program." << endl;
                exit(0);
            }
        } else {
            cout << "Welcome, new user!" << endl;
            createAccount();
            return true;
        }
    }

    if (failedAttempts > 0) {
        cout << "You had " << failedAttempts << " failed login attempts." << endl;
    }

    cout << "Enter Password instead of Username. Please re-enter Username to continue: ";
    cin >> usernameAttempt;

    if (usernameAttempt == log.username) {
        cout << "Login successful." << endl;
        forcePasswordChange();
        return true;
    } else {
        cout << "Invalid Username. Terminating the program." << endl;
        exit(0);
    }

    return false;
}
