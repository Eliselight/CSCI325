/**
 * @file phonebook.cpp
 * @author Elise Lightner
 * @date 2024-10-24
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

 Phonebook::Phonebook(){
   head = nullptr;
   tail = nullptr;
}

Phonebook::~Phonebook(){
  Entry* current = head;
  while (current!= nullptr){
    Entry* next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  tail = nullptr; 
}

void Phonebook::pushFront(Entry userInfo){
 Entry* newEntry = new Entry{userInfo};
  newEntry->next = head;
  head = newEntry;
  if (tail == nullptr) {                                                                               
      tail = newEntry;                                                                          
    }
}
void Phonebook::pushBack(Entry userInfo){
  Entry* newEntry = new Entry{userInfo};
  if (tail == nullptr) {
    tail = newEntry;
    head = newEntry;
    } 
}
int Phonebook::readFromFile(string fileName){
  ifstream file(fileName);                                                                            
    if (!file.is_open()) {                                                                              
        cout << "Unable to open file: " << fileName  << endl;
        return -1; // Unable to open file
    }
   
    string firstName, lastName, phoneNumber;
    while(file >> firstName >> lastName >> phoneNumber){
          Entry userInfo;
	  userInfo.firstName = firstName;
	  userInfo.lastName = lastName;
	  userInfo.phoneNumber = phoneNumber;
	  userInfo.next = nullptr; insertSorted(userInfo);
    }
    file.close();
    return 0;

}

int Phonebook::writeToFile(string fileName){
   ofstream outputFile(fileName);                                               
  if (!outputFile.is_open()) {                                                                          
    cout << "Could not open the file: " << fileName << endl;   
    return -1;                                           
  }
  Entry* current = head;
 while(current != nullptr){                                                 
   outputFile << current->firstName << " "
	      << current->lastName << " "
	      << current->phoneNumber << endl;
	       current = current->next;
 }
 outputFile.close();
 return 0;
}
void Phonebook::insertSorted(Entry userInfo){
  Entry* newEntry = new Entry{userInfo};
  if(head == nullptr || head->lastName > userInfo.lastName){
    newEntry->next = head;
    head = newEntry;
    if (tail == nullptr) {
      tail = newEntry;
    } else {
      tail->next = newEntry;
      tail = newEntry;                                                                                   
    } 
 
    return;
  }
    Entry* current = head;
    while (current->next != nullptr && current->next->lastName <= userInfo.lastName){
      current = current->next;
    }
    newEntry->next = current->next;
    current->next = newEntry;
    if (newEntry->next == nullptr) {                                                                             
      tail = newEntry;                                                                                
    }            
}
void Phonebook::lookup(string name){
    Entry* current = head;  
    while (current!= nullptr){
    if (current->firstName == name || current->lastName == name){
      cout << "Found:" << current->firstName << ""
	   << current->lastName << " - Phone Number: "
	   << current->phoneNumber << endl;
      return;
    }
    current = current->next;
    
    }
    cout << "User not found.\n";
}

bool Phonebook::reverseLookup(string phoneNumber){
Entry* current = head;
 while (current!= nullptr){
   if (current->phoneNumber == phoneNumber){
     cout << "Found:" << current->firstName << ""
       << current->lastName << " - Phone Number: "
       << current->phoneNumber << endl;
     return true;
   }
   current = current->next;
 }
 cout << "User not found.\n";
 return false;
}

void Phonebook::print(Entry userInfo){
  cout << "First Name: " << userInfo.firstName << ", "
       << "Last Name: " << userInfo.lastName << ", "
       << "Phone Number: " << userInfo.phoneNumber
       << endl;

  return;
}

void Phonebook::deleteUser(string name){
    Entry* current = head;
    Entry* previous = nullptr;
    while (current!= nullptr){
      if (current->firstName == name || current->lastName == name){
	if(previous == nullptr){
	  head = current->next;
	} else {
	  previous->next = current->next;
	}
	if(current == tail){
	  tail = previous;
	}
	delete current;
	cout << "User deleted.\n";
	return;
      }
      previous = current;
      current = current->next;
	}
    cout << "User not found.\n"; 
}
