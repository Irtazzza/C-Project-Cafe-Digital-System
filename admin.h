#ifndef ADMIN_H
#define ADMIN_H

#include"user.h"                            // including base class header file
#include"stock.h"                           // including stock class header file
#include"employee.h"                        // including employee class header file 

class admin : public user , public stock   // here admin class is publicly inherited from user and stock class 
{
    private:
    employee emp;
    
    public:
    admin();                                               // parameterless constructor
    admin(const string& uname, const string& pass);        // parametrized constructor
    virtual void login() override;                         // overridden login function from the base class user(abstract class)
    void notification() const;                             // notification function 
    void changingcredentials();                            // changing credentials function for admin 
    void seecomplaints() const;                            // seeing complaints function for admin                  
    void adminresponse();                                  // function for admin to respond to orders 
    void lowstockorderbyadmin();                           // admin ordering low stock function    
    void annoucebestselleremployee();                      // function for announcing best seller employee 
    void seeorderofpeoplesittingincafe();                  // function for seeing order  
    void seesumaverage();                                  // function for calculating sum and average of stock present in cafe 
    ~admin();                                              // destructor 
};

#endif