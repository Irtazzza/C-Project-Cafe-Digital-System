#ifndef USER_H
#define USER_H

#include<iostream>                                 // including all necessary header files here 
#include<cmath>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<chrono>
#include<conio.h>
#include<sstream>
#include<cstring>
using namespace std;

#define ANSI_COLOR_RESET   "\033[0m"                  // using to color text  
#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_YELLOW  "\033[33m"

class user                                            // user class is abstract as it have pure virtual function 
{
    private:                                          // private data members username and password
    string username;
    string password;

    public:
    user();                                          // parameterless constructor 
    user(const string uname, const string pass);     // parametrized constructor 
    string getusername();                            // getter function 
    string getpassword();                            // getter function 
    void setusername(string name);                   // setter function for setting username
    void setpassword(string pass);                   // setter function for setting password
    virtual void login() = 0;                        // login is pure virtual function and it will be implemented in derived class using user class ptr
    void checking(int secs);                         // this function is for stopping function in different places like after user enter name and password

};

#endif