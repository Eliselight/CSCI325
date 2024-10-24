/**
 * @file Login.h
 * @author Elise Lightner
 * @date 2024-10-24
 * @brief 
 * 
 * 
 */

#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <fstream>

 struct Log {                                                                                          
   std::string nameFirst;                                                                              
   std::string initialOrName;                                                                           
   std::string nameLast;                                                                                
   std::string password;                                                                                
   std::string username;  
 };

 class Login{

 private:

  Log log;
   std::string generatedPassword;
   std::string generatePassword(const Log& log);

  public:
    Login();
    ~Login(); 
    void createAccount();
    void forcePasswordChange();
    void saveAccount();
   std::string getUsername() const;
    bool verifyPassword(const std::string& passwordAttempt);
    void changeUsername();
   
};
#endif
