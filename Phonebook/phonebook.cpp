/**
 * @file phonebook.cpp
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */

#include "phonebook.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
//int main(){
// cout << "working" << endl;
//return 0;
//}
istream& operator>>(istream& is, Entry& userInfo) {
    is >> userInfo.firstName;
    is >> userInfo.lastName;
    is >> userInfo.phoneNumber;
    return is;
}

ostream& operator<<(ostream& os, const Entry& userInfo) {
    os << userInfo.firstName << " "
       << userInfo.lastName << " "
       << userInfo.phoneNumber;
    return os;
}

Entry::Entry() {
    next = nullptr;
}

Phonebook::Phonebook() {
    head = nullptr;
    tail = nullptr;
}

Phonebook::~Phonebook() {
    Entry* current = head;
    while (current != nullptr) {
        Entry* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

void Phonebook::pushFront(Entry &userInfo) {
    Entry* newEntry = new Entry(userInfo);
    newEntry->next = head;
    head = newEntry;
    if (tail == nullptr) {
        tail = newEntry;
    }
}

void Phonebook::pushBack(Entry &userInfo) {
    Entry* newEntry = new Entry(userInfo);
    if (tail == nullptr) {
        head = newEntry;
        tail = newEntry;
    } else {
        tail->next = newEntry;
        tail = newEntry;
    }
}

int Phonebook::readFromFile(const string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Unable to open file: " << fileName << endl;
        return -1;
    }

    Entry userInfo;
    while (file >> userInfo) {
        insertSorted(userInfo);
    }
    file.close();
    cout << "Phonebook loaded successfully from " << fileName << endl;
    return 0;
}

int Phonebook::writeToFile(const string fileName) {
    ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        cout << "Could not open the file: " << fileName << endl;
        return -1;
    }

    Entry* current = head;
    for (current = head; current; current = current->next) {
        outputFile << *current << endl;
    }

    outputFile.close();
    cout << "Phonebook saved successfully to " << fileName << endl;
    return 0;
}

void Phonebook::insertSorted(Entry &userInfo) {
    Entry* newEntry = new Entry(userInfo);
    if (head == nullptr || head->lastName > userInfo.lastName) {
        newEntry->next = head;
        head = newEntry;
        if (tail == nullptr) {
            tail = newEntry;
        }
        return;
    }
    
    Entry* current = head;
    while (current->next != nullptr && current->next->lastName <= userInfo.lastName) {
        current = current->next;
    }
    newEntry->next = current->next;
    current->next = newEntry;

    if (newEntry->next == nullptr) {
        tail = newEntry;
    }
}

void Phonebook::lookup(const string name) {
    Entry* current = head;
    while (current != nullptr) {
        if (current->firstName == name || current->lastName == name) {
            cout << "Found: " << current->firstName << " "
                 << current->lastName << " - Phone Number: "
                 << current->phoneNumber << endl;
            return;
        }
        current = current->next;
    }
    cout << "User not found.\n";
}

bool Phonebook::reverseLookup(const string phoneNumber) {
    Entry* current = head;
    for (current = head; current; current = current->next) {
        if (current->phoneNumber == phoneNumber) {
            cout << "Found: " << current->firstName << " "
                 << current->lastName << " - Phone Number: "
                 << current->phoneNumber << endl;
            return true;
        }
    }
    cout << "User not found.\n";
    return false;
}

void Phonebook::print() {
    Entry* current = head;
    if (!current) {
        cout << "Phonebook is empty." << endl;
        return;
    }
    for (current = head; current; current = current->next) {
        cout << "First Name: " << current->firstName << ", "
             << "Last Name: " << current->lastName << ", "
             << "Phone Number: " << current->phoneNumber << endl;
    }
}

void Phonebook::addUser(Entry &userInfo) {
    cout << "Enter the contact details (first name, last name, phone number): ";
    cin >> userInfo;
    insertSorted(userInfo);
    cout << "Contact added successfully: " << userInfo.firstName << " "
         << userInfo.lastName << ", " << userInfo.phoneNumber << endl;
}

void Phonebook::deleteUser(const string name) {
    Entry* current = head;
    Entry* previous = nullptr;

    for (current = head; current; current = current->next) {
        if (current->firstName == name || current->lastName == name) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            cout << "User deleted.\n";
            return;
        }

        previous = current;
    }

    cout << "User not found.\n";
}
