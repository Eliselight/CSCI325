/**
 * @file Menu.cpp
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */

#include "Menu.h"
#include <iostream>

using namespace std;
//int main(){ cout << "menu" << endl; return 0; }
void Menu::phonebookMenu() {
    int choice;
    Phonebook phonebook;
    string fileName, name, phoneNumber;
    char response;
    Entry userInfo;

    while (true) {
        cout << "Welcome to the UTM Phonebook! You may select one of the following options:" << endl;
        cout << "1. Read a phonebook from a file" << endl;
        cout << "2. Write the phonebook to a file" << endl;
        cout << "3. Print the phonebook" << endl;
        cout << "4. Search for a user's phone number" << endl;
        cout << "5. Reverse lookup by phone number" << endl;
        cout << "6. Add a user" << endl;
        cout << "7. Delete a user" << endl;
        cout << "8. Exit this program" << endl;
	cout << "9. Terminating Session" << endl;
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
       	case 9:
	  cout << "Are you sure you wish to end your session? Please comfirm your decision Y or N:" << endl;
	  cin >> response;
	  if (response = 'Y') {
            cout << "Goodbye" << endl;
	    exit(0);
	  } else if (response == 'N' || response == 'n'){
	    cout << "Returning you to the phonebook menu" << endl;
	    phonebookMenu();
	  } else {
	    cout << "Invalid choice. Please try again." << endl;
	  }
	  break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

void Menu::loginMenu() {
    int choice;
    Bypass bypass;
    Records records;
    Login login;

    while (true) {
        cout << "1. Login as User" << endl;
        cout << "2. Bypass Login (Admin)" << endl;
        cout << "3. Ignore Login (Grading)" << endl;
        cout << "4. Admin Access" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (login.userLogin()) {
                    phonebookMenu();
                }
                break;
            case 2:
                bypass.adminLogin(records);
                break;
            case 3:
                bypass.ignoreLogin();
                break;
            case 4:
                bypass.createAdminUser(records);
                break;
            case 5:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
}
