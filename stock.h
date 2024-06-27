#ifndef STOCK_H
#define STOCK_H

#include"user.h"                           // including here user.h file 

class stock 
{
    private:                               // making data members private   
    string* items;
    double* price;
    int* quantity;
    double* totalprice;
    int maxitems;

    public:                                // making members functions public here 
    stock();                               // constructor of stock class 
    void handlestock();                    // function to handle stock details       
    void view();                           // this function is to view stock 
    void add();                            // this function is to add new item in stock 
    void deleteitem();                     // this function is to delete item from stock 
    void search();                         // this function is to search any item from stock
    void lowstockcheck();                  // this function is to check items which are low in quantity
    void adminorderinglowitem();           // to see low stock items order by admin
    ~stock();                              // destructor 
};

#endif 
