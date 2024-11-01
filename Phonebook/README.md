# UTM Phonebook Project

## Overview
This project is a C++ implementation of a simple linked list-based phonebook. It allows users to manage contact information, providing various features like adding, deleting, and searching contacts. The project also includes a secure login system for user authentication, administrative access, and an option to bypass the login for grading the phonebook.

## Features
- **Phonebook Management**:
  - Add new contacts
  - Delete existing contacts
  - Search for contacts by name or phone number
  - Load and save contacts from/to a text file (`phonebook.txt`)
  - Print all contacts in the phonebook

- **Login System**:
  - User login using either username or first and last name
  - Password-based authentication with forced password change if necessary
  - Admin access control for viewing and modifying records
  - Ability to create new user accounts

- **Admin and Bypass Options**:
  - Create a new admin user with a 10-digit admin ID and encrypted password
  - Bypass login for quick access (useful for grading purposes)
  - Administrative functions are secured with encryption mechanisms

- **Encryption**:
  - Admin approval and user records are stored in encrypted form using multiple encryption methods including Caesar and Vigenere ciphers.
  - Usernames, passwords, and other sensitive data are encrypted for security.

## File Structure
- **Source Code**:
  - `main.cpp`: Main entry point of the program.
  - `Phonebook.h` / `Phonebook.cpp`: Manages the linked list structure for the phonebook.
  - `EncryptionMethods.h` / `EncryptionMethods.cpp`: Provides different encryption methods for secure data handling.
  - `Login.h` / `Login.cpp`: Handles user login and account creation.
  - `Records.h` / `Records.cpp`: Manages user and admin records.
  - `Bypass.h` / `Bypass.cpp`: Handles the bypass functionality and admin creation.
  - `Menu.h` / `Menu.cpp`: Manages user interaction through a menu system.

- Data Files:
  - phonebook.txt: Contains sample phonebook data, which can be used for loading and saving contacts.

- Build File:
  - Makefile: complies all the files into an exacutabled code

### Building the Project
To compile the project, run the following command in the terminal:
```bash
make
