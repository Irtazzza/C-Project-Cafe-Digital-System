#ifndef ORDER_H
#define ORDER_h

#include"user.h"                               // including necessary header files 
#include"stock.h"                              // including necessary header files 

class order : public stock                     // inheriting stock class in order class  
{
    public:
    string getcurrenttime()                    // function to get current time 
    {
    auto now = chrono :: system_clock::now();
    time_t currenttime = chrono :: system_clock :: to_time_t(now);
    return ctime(&currenttime);
    }
    void searchandorderfood();                 // search and order food function
    void scheduleorder();                      // schedule order function 

};


#endif