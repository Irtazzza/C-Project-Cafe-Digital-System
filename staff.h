#ifndef STAFF_H
#define STAFF_H

#include"user.h"                             // including all necessary headers files here 
#include"stock.h"                            // including all necessary headers files here 
#include"order.h"                            // including all necessary headers files here 

class staff : public user , public order     // staff class is publicly inherited from user and order class 
{
    public:
    staff();                                              // parameterless constructor 
    staff(const string& uname, const string& pass);       // parametrized constructor 
    virtual void login() override;                        // login function which is inherited from user here we are overriding it  
    void givecomplaints();                                // giving complaints function for staff/students
    void seenotifications() const;                        // seeing notification function 
    void searchforstaff();                                // search food items function for staff/students
    void seeresponse();                                   // seeing response of order function for staff/students
    ~staff();                                             // destructor 
};

#endif