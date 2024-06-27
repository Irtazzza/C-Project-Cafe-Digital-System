#include "user.h"


// user class member functions definations 
user :: user()                                               // parameterless constructor of user class  
{

}

user::user(const string uname, const string pass)           // parametrized constructor of user class 
{
    username = uname;
    password = pass;
}

void user :: checking(int secs) 
{
    int milliseconds = secs * 1000;
    Sleep(milliseconds);
}

string user :: getusername()                                // getter function 
{
    return username;
}

string user :: getpassword()                                // getter function 
{ 
    return password;
}

void user :: setusername(string name)                       // setter function 
{
    username = name;
}

void user :: setpassword(string pass)                       // setter function 
{
    password = pass;
}