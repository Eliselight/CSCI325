/**
 * @file phonebook.h
 * @author Elise Lightner
 * @date 2024-10-31
 * @brief 
 * 
 * 
 */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include <fstream>

struct Entry {
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    Entry* next;

    Entry();
};

class Phonebook {
private:
    Entry* head;
    Entry* tail;

public:
    Phonebook();
    ~Phonebook();

    void pushFront(Entry &userInfo);
    void pushBack(Entry &userInfo);
    int readFromFile(const std::string fileName);
    int writeToFile(const std::string fileName);
    void insertSorted(Entry &userInfo);
    void lookup(const std::string name);
    bool reverseLookup(const std::string phoneNumber);
    void print();
    void addUser(Entry &userInfo);
    void deleteUser(const std::string name);
};

std::istream& operator>>(std::istream& is, Entry &userInfo);
std::ostream& operator<<(std::ostream& os, const Entry &userInfo);

#endif
