#include"admin.h"       // adding header file of admin class 
#include"employee.h"    // adding header file of employee class 
#include"staff.h"       // adding header file of staff/student class 


int main() 
{ 
    int choice;   // to get user choice that for which he want to login 
    while (true)  // infinite loop until 4 is press it works 
    {
        cout <<endl << "\t\t\tWELCOME TO LOGIN PORTAL \n ";
        cout <<endl << "\t\t\t1. Admin \n \t\t\t2. Employee \n \t\t\t3. Staff \n \t\t\t4. Quit \n";
        cout <<endl << "\t\t\tPress 1 , 2 Or 3 To Login  ---->  ";

        cin >> choice;   // taking input 

        user* userptr;  // making pointer of base class user (abstract class)

        switch (choice) 
        {
            case 1: 
            {
                userptr = new admin();  // dynamically allocating memory for admin object
                break;
            }
            case 2: 
            {
                userptr = new employee();  // dynamically allocating memory for employee object
                break;
            }
            case 3:
            {
                userptr = new staff();  // dynamically allocating memory for staff/student object
                break;
            }
            case 4: 
            {
                cout << "Quitting..." << endl;
                return 0; 
            }
            default: 
            {
                cout << "Error, Wrong Selection";
                return 1;
            }
        }
        userptr->login();    // calling login function of user selected choice 
        delete userptr;      // freeing memory for user object 
    }
}
