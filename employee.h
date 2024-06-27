#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"user.h"     // including necessary header files 
#include"stock.h"    // including necessary header files

class employee : public user , public stock               // inheriting user and stock class in employee class 
{
    public:
    employee();                                           // parameterless constructor 
    employee(const string& uname, const string& pass);    // parametrized constructor 
    virtual void login() override;                        // login function inherited from user class 
    void searchforemployee();                             // search item function for employee
    void seeonlineorders();                               // seeing online schedule order function for employee 
    void employeetakingorder();                           // taking order function for admin 
    void generatetransaction();                           // generate transaction function for employee 
    void employeeresponse();                              // employee response to order 
    void employeseeingbestselleremployee();               // seeing best seller employee announced by admin 
    ~employee();                                          // destructor for employee class 
};

#endif