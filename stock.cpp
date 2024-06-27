#include "stock.h"

stock :: stock() 
{
    // parameterless constructor
    maxitems = 50; 
    items = new string[maxitems];
    price = new double[maxitems];
    quantity = new int[maxitems];
    totalprice = new double[maxitems];
}

void stock :: handlestock() 
{
    cout << "\n\n\t\t **************************************************************************** \n"
              << "\t\t *                                                                          * \n"
              << "\t\t *                   WELCOME TO CDS STOCK HANDLING SYSTEM                   * \n"
              << "\t\t *                                                                          * \n"
              << "\t\t **************************************************************************** \n";

    int c;      // asking user  what he want to do 
    do 
    {
        cout << "\n\n\t\tNow Select What Do You Want To Do\n\n" << "\t\t1. View Stock\n" << "\t\t2. Add New Stock\n" << "\t\t3. Delete Stock\n" << "\t\t4. Search Item\n" << "\t\t5. Quit ---->  ";
        cin >> c;  // asking here 
        cin.clear();
        cin.ignore();

        switch (c) 
        {
            case 1:
            {
                view();    // calling here view function defined below 
                break;
            }
            case 2:
            {
                add();    // calling here add function defined below 
                break;
            }
            case 3:
            {
                deleteitem();  // calling here deleteitem function defined below 
            break;
            }
            case 4:
            {
                search();   // calling here search function defined below 
            break;
            }
            case 5:
            {
                cout << "Quieting Please Wait...";   // quieting when press 5 
                break;
            }
            default:
            {
                cout << "\n\t\tInvalid Input, Please Try Again.\n\n";
                break;
            }
        }
    } 
    while (c != 5);
}

void stock :: view() 
{
    ifstream file("stock.txt");     // opening file in read mode 
    if (!file) 
    {
        cout << "Error In Opening File...\n";  // error if file not found 
        return;
    }

    string header;            // to get header from file in header variable  
    getline(file, header);    // storing header in  header variable 

    cout << left << setw(20) << "Items" << setw(15) << "PricePerItem" << setw(10) << "Quantity" << setw(15) << "TotalPrice" << endl;
    cout << left << setw(20) << "-----" << setw(15) << "------------" << setw(10) << "--------" << setw(15) << "----------" << endl;

    int i = 0;
    while (file >> items[i] >> price[i] >> quantity[i] >> totalprice[i])    // storing data in variables 
    {
        i++;
    }

    file.close(); // closing file here  

    for (int j = 0; j < i - 1; j++)      // here using sorting method to sort items by price 
    {
        for (int k = 0; k < i - j - 1; k++) 
        {
            if (price[k] > price[k + 1]) 
            {
                string tempitem = items[k];
                items[k] = items[k + 1];
                items[k + 1] = tempitem;

                float tempprice = price[k];
                price[k] = price[k + 1];
                price[k + 1] = tempprice;

                int tempquantity = quantity[k];
                quantity[k] = quantity[k + 1];
                quantity[k + 1] = tempquantity;
                
                float temptotalprice = totalprice[k];
                totalprice[k] = totalprice[k + 1];
                totalprice[k + 1] = temptotalprice;
            }
        }
    }
    file.close();   // closing file here  
    for (int k = 0; k < i; k++)   // now displaying data with sorted details 
    {
        cout << left << setw(20) << items[k] << setw(15) << price[k] << setw(10) << quantity[k] << setw(15) << totalprice[k] << endl;
    }
}

void stock :: add() 
{
    cout << "\n\n\t\tHere Is Previous Item List You Can Add Here New Item...\n\n";
    view();   // calling view function here so that stock can display here 

    string addnew;     // to get details of new item which admin is adding in stock
    double price;
    int quantity;
    double totalprice;

    ofstream add("stock.txt", ios::app);   // opening file here in append mode to add new stoc if user wants 
    if (!add) 
    {
        cout <<"Error In Opening File... \n";   // error if file not found 
        return;
    }

    cout << "\n\t\tEnter Name Of New Item ---> ";
    cin >> addnew;    // taking name of item here 

    cout << "\n\t\tEnter Price Of New Item ---> ";
    cin >> price;     // taking price of item here 

    cout << "\n\t\tEnter Quantity Of New Item ---> ";
    cin >> quantity;   // taking quantity of item here 

    cout << "\n\t\tAdding New Item Please Wait.....\n";

    totalprice = price * quantity;   // calculating total price by multiplying price and quantity 

    add << addnew << " "  << price << " " << quantity << " " << totalprice << endl;   // writing all details in text fle of new item

    cout << "\n\t\tNew Item Is Added Successfully \n";  // message that item is added  
}

void stock :: deleteitem() 
{
    cout << "\n\nHere Is Item List...\n\n";
    view();    // calling view function here 

    string del;  
    cout << "\n\t\tEnter The Item Name You Want To Delete ---> ";
    cin >> del;   // asking user which item he want to delete enter that item name 

    ifstream file("stock.txt");  // now opening file in rad mode here 
    if (!file) 
    {
        cout << "\t\tError In Opening File... \n";   // error if file not found 
        return;
    }

    ofstream update("temp.txt");              // making a temporary file for updating data
    if (!update) 
    {
        cout << "\n\t\tError In Opening File...\n\n";   // error if file not found 
        return;
    }

    string header;   // to store header details 
    getline(file, header); // reading the header line

    update << header << endl;     // writing header  in file 

    string itemname;
    double itemprice;
    int itemquantity;
    double itemtotalprice;
    while (file >> itemname >> itemprice >> itemquantity >> itemtotalprice)   // now storing remaining data in variables 
    {
        if (itemname != del) 
        {
            update << itemname << " " << itemprice << " " << itemquantity << " " << itemtotalprice << endl;  // writing data in file
        } 
        else 
        {
            cout << "\n\t\tDeleting Item Please Wait.....\n";
            cout << "\n\t\tItem Deleted Successfully\n";
        }
    }

    file.close();
    update.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");      
}

void stock :: search() 
{
    cout << "\n\n\t\tHere Is Item List...\n\n";
    view();  // calling view function here of stock class 

    string searchitem;
    cout << "\n\t\tEnter The Name Of Item That You Want To Search ---> ";
    cin >> searchitem;   // asking user to enter name of item he want to search 

    ifstream file("stock.txt");   // opening file in read mode 
    if (!file) 
    {
        cout << "\n\t\tError In Opening File...\n\n";   // error if file not found 
        return;
    }

    string header;   // to store 1st line header line 
    getline(file, header);   // storing header text in header variable 
    

    cout << "\n\t\tSearching Item Please Wait.....\n\n";

    bool found = false;

    cout << setw(20) << left << "Items" << setw(15) << right << "PricePerItem" << setw(10) << right << "Quantity" << setw(15) << right << "TotalPrice" << endl;
    cout << setw(20) << left << "-----" << setw(15) << right << "------------" << setw(10) << right << "--------" << setw(15) << right << "----------" << endl;

    string itemname;
    double itemprice;
    int itemquantity;
    double itemtotalprice;
    while (file >> itemname >> itemprice >> itemquantity >> itemtotalprice) 
    {
        if (itemname == searchitem)    // checking if entered name match with the name stored in itemname variable 
        {
            cout << setw(20) << left << itemname << setw(15) << right << itemprice << setw(10) << right << itemquantity << setw(15) << right << itemtotalprice << endl;
            found = true;    // if found then display that item details 
            break;
        }
    }
    file.close();  // closing file here 

    if (!found) 
    {
        cout << "\n\t\tItem Not Found, Try Again\n";   // error if file not found 
    }
}

stock :: ~stock() 
{
    // seleting all dynamic memories 
    delete[] items;
    delete[] price;
    delete[] quantity;
    delete[] totalprice;
}

void stock :: lowstockcheck() 
{
    cout << "\n\n\t\t **************************************************************************** \n"
              << "\t\t *                                                                          * \n"
              << "\t\t *       WELCOME TO CDS LOW STOCK NOTIFICATION HANDLING SYSTEM              * \n"
              << "\t\t *                                                                          * \n"
              << "\t\t **************************************************************************** \n";

    cout << "\n\n\t\tLoading Stock Of \"CAFE DIGITAL SYSTEM\" (CDS)... \n\n";
    cout << "\n\t\tThe Stock Of CDS Is Loaded Successfully.\n\n";

    view();   // calling view function here to see stock 

    char choice;
    cout << "\n\n\t\tDo You Want To See Which Items Are Less Than 15? (Y/N): ";
    cin >> choice;     // asking user weather he wants to see items which are less ten 15 

    if (choice == 'Y' || choice == 'y')   // if press y then open file and proceed 
    {
        ifstream file("stock.txt");   // opening file here in read mode 
        if (!file) 
        {
            cout << "\n\n\t\tError In Opening File...\n\n";  // error if file not found 
        } 
        else 
        {
            cout << "\n\n\t\tStock Of CDS Is Loaded So The Items In Red Colour Are In Less Quantity.\n\n";
            char header[100];
            file.getline(header, 100, '\n');
            cout << left << setw(20) << "Items" << setw(15) << "PricePerItem" << setw(10) << "Quantity" << setw(15) << "TotalPrice" << endl;
            cout << left << setw(20) << "-----" << setw(15) << "------------" << setw(10) << "--------" << setw(15) << "----------" << endl;
            int i = 0;
            while (file >> items[i] >> price[i] >> quantity[i] >> totalprice[i])    // reading data of file in variables 
            {
                i++;
            }
            file.close();  // closing file here 
            const char* color = ANSI_COLOR_RESET;
            for (int k = 0; k < i; k++) 
            {
                if (quantity[k] == 0 )    // now if quantity of item is 0 then that item color with yellow color
                {
                    color = ANSI_COLOR_YELLOW ;
                } 
                else if (quantity[k] > 0 && quantity[k] <= 15)   // now if quantity of item is greater then 0 and less then 15 that item color with red color
                {
                    color = ANSI_COLOR_RED ;
                } 
                else 
                {
                    color = ANSI_COLOR_RESET;  // else default  color 
                }
                cout << color << left << setw(20) << items[k] << setw(15) << price[k] << setw(10) << quantity[k] << setw(15) << totalprice[k] << ANSI_COLOR_RESET << endl;
            }
        }
    } 
    else if (choice == 'N' || choice == 'n')
    {
        cout << "\n\t\tYou Press 'N' Which Means You Don't Want To See CDS Stock.\n";
        cout << "\n\t\tSo Quitting. Please Wait...\n";
        cout << "\n\t\tQuit Successfully.\n";
    } 
    else 
    {
        cout << "\n\t\tInvalid Input. Please Try Again.\n\n";
    }
}

void stock :: adminorderinglowitem() 
{
    cout << endl << "\t\t**************************************************************************** \n"
        << "\t\t*                                                                          * \n"
        << "\t\t*       WELCOME TO CDS LOW STOCK NOTIFICATION HANDLING SYSTEM              * \n"
        << "\t\t*                                                                          * \n"
        << "\t\t**************************************************************************** \n";

    cout << endl << "\t\tLoading Stock Of \"CAFE DIGITAL SYSTEM\" (CDS)... \n\n";

    cout << endl << "\t\tThe Stock Of Is CDS Loaded Successfully\n\n";
    view();   // calling view function here to view stock 

    char choice;
    cout << endl << "\t\tDo You Want To See Which Items Are Less Then 15\n\n";
    cout << endl << "\t\tIf Yes Then Press 'Y' Otherwise Press 'N' To Quit  ---->  ";
    cin >> choice;    // asking user if he wants to see low stock 

    if (choice == 'Y' || choice == 'y')    // if press y then proceed 
    {
        int* price = new int[maxitems];
        int* quantity = new int[maxitems];
        int* totalprice = new int[maxitems];
        char** item = new char*[maxitems];
        for (int i = 0; i < maxitems; ++i)
        {
            item[i] = new char[100];
        }
        fstream file("stock.txt", ios::in);   // here opening file in read mode 

        if (!file) 
        {
            cout << endl << "\t\tError In Opening File...\n\n";   // error if file not found 
        } 
        else 
        {
            cout << endl << "\t\tStock Of CDS Is Loaded So The Items In Red Colour Are In Less Quantity\n\n";
            char header[100];
            file.getline(header, 100, '\n');   // storing 1st line in header variables till line finish
            cout << left << setw(20) << "Items" << setw(15) << "PricePerItem" << setw(10) << "Quantity" << setw(15) << "TotalPrice" << endl;
            cout << left << setw(20) << "-----" << setw(15) << "------------" << setw(10) << "--------" << setw(15) << "----------" << endl;
            int i = 0;
            while (file >> item[i] >> price[i] >> quantity[i] >> totalprice[i])    // storing data from file in variables 
            {
                if (quantity[i] == 0)    // now if quantity of item is 0 then that item color with yellow color
                {
                    cout << ANSI_COLOR_YELLOW;
                } 
                else if (quantity[i] > 0 && quantity[i] <= 15)    // now if quantity of item is greater then 0 and less then 15 that item color with red color
                {
                    cout << ANSI_COLOR_RED;
                } 
                else 
                {
                    cout << ANSI_COLOR_RESET;   // else default color 
                }
                cout << left << setw(20) << item[i] << setw(15) << price[i] << setw(10) << quantity[i] << setw(15) << totalprice[i] << ANSI_COLOR_RESET << endl;
                ++i;
            }
            file.close();   // closing file now 

            string addnew;    // to get new item to be add by admin 
            int q;
            cout << endl << "\t\tTo Place Order Enter Details Here\n\n";
            cout << endl << "\t\tEnter Here Name Of Item You Want To Order ---->  ";
            cin.ignore();
            getline(cin, addnew);
            cout << endl << "\t\tEnter How Much Quantity You Want Of This Item ---->  ";
            cin >> q;   // asking quantity 
            if (q < 0 || q > 1000)    // putting check here 
            {
                cout << endl << "\t\tYou Cannot Order Items Less Than 0 And Greater Than 1000 So Try Again By Entering Valid Quantity\n\n";
            } 
            else 
            {
                fstream add("stockorderbyadmin.txt", ios::app);    // opening new file in write mode (append) to save record of ordered items 
                if (!add) 
                {
                    cout << "Error In Opening File... \n";  // error if file not found 
                } 
                else
                {
                    add << addnew << " " << q << endl;     // writing details in file 
                    cout << endl << "\t\t----->  You Ordered  <----- \n";
                    cout << endl << "\t\t\t" << q << "  " << addnew << endl << endl;
                    cout << endl << "\t\tPlacing Order Please Wait...\n";
                    cout << endl << "\t\tOrder Placed Successfully\n\n";
                }
            }
        }

        delete[] price;    // deleting dynamic memories here 
        delete[] quantity;
        delete[] totalprice;
        for (int i = 0; i < maxitems; ++i)
        {
            delete[] item[i];
        }
        delete[] item;
    }   
    else if (choice == 'N' || choice == 'n')    // if press then exit 
    {
        cout << endl << "You Press 'N' Its Mean You Dont Want To See CDS Stock\n";
        cout << endl << "\t\tSo Quitting Please Wait...\n";
        cout << endl << "\t\tQuit Successfully\n";
    } 
    else 
    {
        cout << endl << "Invalid Input Please Try Again\n\n";
    }
}
