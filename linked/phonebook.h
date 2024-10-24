/**
 * @file phonebook.h
 * @author Elise Lightner
 * @date 2024-10-23
 * @brief 
 * 
 * 
 */

#ifndef PHONEBOOK_H                                                                                  
#define PHONEBOOK_H

#include <fstream>
#include <string>

class Phonebook{
  
  private:

  struct Entry {                                                                                        
    std::string firstName;                                                                              
    std::string lastName;                                                                               
    std::string phoneNumber;                                                                            
    Entry* next;                                                                                        
  };
  Entry* head;
  Entry* tail;

  public:
  Phonebook();
  ~Phonebook();
  
  void pushFront(Entry userInfo); 
  void pushBack(Entry userInfo); 
  int readFromFile(std::string fileName);
  int writeToFile(std::string fileName);
  void insertSorted(Entry userInfo);
  void lookup(std::string name);  //if (current->firstName == name || current->lastName == name) {} for the function                                                                       
  bool reverseLookup(std::string phoneNumber);                                                          
  void print(Entry userInfo);                                                                                  
  void deleteUser(std::string name); // same goes for this one
     

};
#endif
