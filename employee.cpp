#include"employee.h"


employee :: employee() 
{
    // this is employee parameterless constructor 
} 

employee :: employee(const string& uname, const string& pass) : user(uname, pass) 
{
    // this is employee parametrized constructor 
}

void employee :: login() 
{
    employee emp;
    ifstream file("logindetailsofemployee.txt");      // opening login details file for employee 
    if (!file) 
    {
        cout << "Error In Opening File" << endl;      // error if file not found 
        return;
    }

    string usernameinfile;                            // variable to store name from file  
    string passwordinfile;                            // variable to store name from file 
    bool check = false;                               // using bool variable and initialize it with 0

    do 
    {
        string username;                              // variable to store name from employee
        string password;                              // variable to store password from employee
        int ch;
        
        cout << endl << "\t\t\tEnter Username Here ---> ";
        cin >> username;                              // taking input here 
        cout << endl << "\t\t\tEnter Password Here ---> ";
        //cin >> password;
        ch = getch();
        while ((ch = getch()) != '\r' && ch != '\n')   // '\r' for carriage return '\n' for newline (enter key)
        { 
            if (ch == 8)   // backspace
            { 
                if (!password.empty()) 
                {
                    cout << "\b \b"; // here move cursor back, erase character, move cursor back again
                    password.pop_back(); // now remove the last character from the password
                }
            } 
            else 
            {
                password.push_back(ch);
                cout << "*"; // display asterisk for each character entered
            }
        }
        
        cout << endl << endl  << "\t\t\tChecking Please Wait..." << endl << endl;
        checking(3);                   // calling checking function which is defined in use class 
        file.clear();
        file.seekg(0, ios::beg);

        while (file >> usernameinfile >> passwordinfile)         // storing name in variables from file 
        {
            if (username == usernameinfile && password == passwordinfile)    // if name and password match with entered details then login
            {
                check = true;
                cout << endl << "\t\t\tYou Have Logged In Successfully" << endl;

                int choice;    // to take input  for what employee want to do after loging in 
                do 
                {
                    cout << "\n\nYOU ARE EMPLOYEE YOU CAN PERFORM FOLLOWING OPERATIONS IN 'C D S' BY SELECTING IT\n";
                    cout << "\t\t 1. Take Orders\n";
                    cout << "\t\t 2. Search Items\n";
                    cout << "\t\t 3. Generate Transactions\n";
                    cout << "\t\t 4. See Online Orders\n";
                    cout << "\t\t 5. Respond To Orders\n";
                    cout << "\t\t 6. See Best Seller Employee\n";
                    cout << "\t\t 0. Quit\n\n";
                    cout << "\t\t Please Select One From Above  ";
                    
                    cin >> choice;    // taking input here 

                    switch (choice)  // using switch to handle different cases 
                    {
                        case 1:
                        {
                            emp.employeetakingorder();
                            break;
                        }
                        case 2:
                        {
                            emp.searchforemployee();
                            break;
                        }
                        case 3:
                        {
                            emp.generatetransaction();
                            break;
                        }
                        case 4:
                        {
                            emp.seeonlineorders();
                            break;
                        }
                        case 5:
                        {
                            emp.employeeresponse();
                            break;
                        }
                        case 6:
                        {
                            emp.employeseeingbestselleremployee();
                            break;
                        }
                        case 0:
                        {
                            cout << "Quitting..." << endl;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Option, Please Try Again" << endl;
                            break;
                        }
                    }
                } 
                while (choice != 0);    // dont return until 0 is press 
                break; 
            }
        }

        if (!check) 
        {
            cout << "Incorrect Username Or Password, Please Try Again To Login" << endl;
        }
    } 
    while (!check);

    file.close();
}

void employee :: searchforemployee()
{
    cout << "\t\t **************************************************************************** \n"
            << "\t\t *                                                                          * \n"
            << "\t\t *                WELCOME TO CDS ITEM SEARCH PORTAL FOR EMPLOYEE            * \n"
            << "\t\t *                                                                          * \n"
            << "\t\t **************************************************************************** \n";
        
        char c;          // to  take input from employee weather he want to search or not 
        cout <<endl <<"\t\tDo You Want To Search Item From CDS Stock\n\n\t\tIf Yes Then Press 'Y' OtherWise Press 'N' To Quit ---->  ";
        
        cin >> c;       // taking input 
        
        if (c == 'Y' || c == 'y')
        {
        cout <<endl <<"\t\tLoading List Please Wait...\n\n";
        cin.ignore();
        search();      // calling search which is in stock class 
        } 
        else if (c == 'N' || c == 'n')   // if press n the exit 
        {
        cout <<endl <<"\t\tYou Press 'N' Its Mean That You Dont Want To Search Any Item\n\n\t\tSo Quieting Please Wait...\n\n\t\tQuiting Done\n\n";
        } 
        else 
        {
        cout <<endl <<"\n\t\tInvalid Input Please Try Again By Entering Valid Input\n\n";
        }
} 

void employee :: seeonlineorders() 
{
    cout << "\t\t **************************************************************************** \n"
            "\t\t *                                                                          * \n"
            "\t\t *               WELCOME TO CDS VIEWING ONLINE ORDERS PORTAL                * \n"
            "\t\t *                                                                          * \n"
            "\t\t **************************************************************************** \n";

    char choice;    // for confirming weather employee wants to view orders or not 

    cout << endl << "\t\t---> Do You Want To View Online Orders <---\n";
    cout << endl << "\t\tIf Yes Then Press 'Y' Otherwise Press 'N' To Exit ---->  ";

    cin >> choice;  // confirming here 

    if (choice == 'Y' || choice == 'y')    // if press y then show orders 
    {   

        cout << endl << "\t\tLoading Online Orders Please Wait...\n\n";
        cout << endl << "\t\tOnline Orders Loaded Successfully\n\n";

        const int s = 100;            // variables to store data from file 
        string name[s];
        string time[s];
        string item[s];
        int* quantity = new int[s];
        int i = 0;

        fstream file("onlineorders.txt", ios::in);    // opening text file in read mode 
        if (!file) 
        {
            cout << "Error in Opening File...\n";    // error if file not found 
        }
        else 
        {
            cout << left << setw(20) << "Customer Name" << setw(10) << "Item" << setw(10) << "Quantity" << setw(25) << "Order Schedule Time" << endl;
            cout << left << setw(20) << "--------------" << setw(10) << "-----" << setw(10) << "--------" << setw(25) << "--------------------" << endl;

        while (i < s && file >> name[i] >> item[i] >> quantity[i])    // storing input in variables fro file
        {
            getline(file, time[i]); // reading the rest of the line to get the time
            cout << left << setw(20) << name[i] << setw(10) << item[i] << setw(10) << quantity[i] << setw(25) << time[i] << endl;
            i++;
        }

            file.close();   // closing file 
        }
        delete[] quantity;    // deleting dynamic array 

    }  
    else if (choice == 'N' || choice == 'n')    // if press n then exit 
    {
        cout << endl << "\t\tYou Press 'N' Its Mean That You Dont Want To Give Response To Orders\n\n";
    }
    else 
    {
        cout << endl << "\t\tInvalid Input Try Again\n\n";
    }
}

void employee :: employeetakingorder() 
{
    cout << "\t\t **************************************************************************** \n"
         << "\t\t *                                                                          * \n"
         << "\t\t *                   WELCOME TO CDS TAKE ORDERS PORTAL                      * \n"
         << "\t\t *                                                                          * \n"
         << "\t\t **************************************************************************** \n";

    char choice;                // for asking weather employee wants to take order or not 
    string food;                
    string name;
    int table;
    int quan;
    double tbill = 0;
    double titem = 0;
    char a;  // for more items 

    cout << endl <<"\t\tDo You Want To Take Order From Students Staff/Student\n\n"<< "\t\tIf Yes Then Press 'Y' Otherwise Press 'N' To Quit  ----> ";
    cin >> choice;  // asking here 

    if (choice == 'Y' || choice == 'y')   // if press y then proceed 
    {  
        cout << endl << "\t\tYou Are Now Taking Order From Staff/Student\n\n";
        cout << endl << "\t\tViewing Menu To Staff/Student\n\n";
        view();  

        char c;   
        cout << endl << "\t\tIf You Want To Order Food Then Press 'O' Otherwise Press 'N' ---> ";
        cin >> c;   // asking weather employee wants to take order or not 

        if (c == 'O' || c == 'o')   // if press o then mean order is taken 
        {   
            const int s = 100;      // variables to store data such as item quantity 
            string header;
            string* item = new string[s];
            double* price = new double[s];
            int* quantity = new int[s];
            int* totalp = new int[s];
            int i = 0;

            fstream file("stock.txt", ios :: in);    // now opening stock file in read mode 
            if (!file) 
            {
                cout << endl <<"\t\tError In Opening File...\n\n";
            }

            getline(file, header);

            while (file >> setw(21) >> item[i] >> price[i] >> quantity[i] >> totalp[i])    // storing data in variables 
            {
                i++;
            }

            file.close(); 

            cout << endl << "\t\tPlease Enter Your Name Here ---> ";   //taking name from person who is ordering 
            cin.ignore();
            getline(cin, name);

            cout << endl << "\t\tPlease Enter Your Table Number Here ---> ";  // asking table number 
            cin >> table;

            do
            {  
                cout << endl << "\t\tEnter Food Name You Want To Order ---> ";   // asking food that he wants 
                cin.ignore();
                getline(cin, food);
                
                cout << endl << "\t\tHow Much Quantity You Want Of This Food ---> ";  // asking how much quantity he wants 
                cin >> quan;

                bool spell = false; // spell for checking spelling and quantity 

                for (int k = 0; k < i; k++) 
                {   
                    if (item[k] == food && quan <= quantity[k]) 
                    {
                        spell = true;  // if spell true then proceed 
                        break;
                    }
                } 

                if (spell == true) 
                {      
                    fstream update("stock.txt", ios::out | ios::trunc);

                    if (!update) 
                    {
                        cout << endl <<"\t\tError In Opening File...\n";
                    } 
                    else 
                    {
                        update << header << endl;     

                        for (int k = 0; k < i; k++) 
                        {
                            if (item[k] == food) 
                            {
                                quantity[k] -= quan;       // reducing quantity from stock 
                                totalp[k] = price[k] * quantity[k];   // calculating price 
                            }
                            update << item[k] << " " << price[k] << " " << quantity[k] << " " << totalp[k] << endl;
                        }
                    }

                    for (int k = 0; k < i; k++) 
                    {
                        if (item[k] == food)      
                        {
                            titem = price[k] * quan;       
                            break;
                        }
                    }

                    tbill += titem;

                    cout << endl << "\n\n\n\t\t-----> Your Order Details <----- \n\n";   // showing bill here 
                    cout << endl << "\t\tYour Name          ------>   " << name << endl;
                    cout << endl << "\t\tYour Table No      ------>   " << table << endl;
                    cout << endl << "\t\tYour Ordered Item  ------>   " << food << endl;
                    cout << endl << "\t\tQuantity Of Item   ------>   " << quan << endl;
                    cout << endl << "\t\tYour Total Bill Is ------>   " << "Rs : " << tbill << endl << endl;
                }                  
                else   // if spell is 0 then failed to order 
                {
                    cout << endl << "\n\n\t\t-----> Sorry Your Order Failed <-----\n ";
                    cout << endl << "\n\t\tMake Sure You Spell Correctly And Enter Quantity Less Than Quantity Given In Menu \n\n";
                }

                cout << endl << "\t\tDo You Want To Order More Items If Yes Then Press 'Y' Otherwise Press 'N' To See Your Total Bill ---->  ";
                cin >> a;

            } 
            while (a == 'Y' || a == 'y'); // continue until user press y 

            cout << endl <<"\t\tCalculating Your Bill Please Wait...\n";
            cout << endl <<"\n\t\tYour Total Bill Is ------>   " << " Rs : " << tbill << endl << endl;

            // here starting best seller employee
            
            string n;  // for taking name from employee to add it to best seller employee
            string nameinfile;
            char oc;  // for asking weather employee completed order 
            
            cout <<endl <<"\t\tAsking From Employee\n\n";
            cout << endl <<"\t\tHave You Completed Your Order If Yes Then Press 'Y' Otherwise Press 'N' ---> ";  
            cin >> oc;
            
            if (oc == 'Y' || oc == 'y') 
            {  
                cout << endl <<"\t\tYou Have Taken Order Now Adding It To Best Seller Employee System\n\n";
                cout << endl <<"\t\tYou Only Need To Enter Your UserName Here --->  ";
                cin.ignore();
                getline(cin, n);
                
                ifstream employlogindetail("logindetailsofemployee.txt");   // reading file here 
    
                if (!employlogindetail) 
                {
                    cout << endl << "Error in opening file. \n\n";   // error if file not found 
                }
                
                bool c = false;
        
                while (employlogindetail >> nameinfile)       // storing name 
                {
                    if (n == nameinfile) 
                    {
                        cout <<endl <<"\n\t\tChecking UserName Please Wait...\n";
                        cout <<endl <<"\t\tUserName Match Congrats\n\n";
                        c = true;
                        break;
                    }
                }
                
                if (!c) 
                {
                    cout <<endl <<"\t\tChecking Enter UserName Please Wait...\n\n";
                    cout <<endl <<"\t\tSorry Entered UserName Did Not Match. Try Again By Entering Correct UserName\n\n";
                }
                
                if (c == true) 
                {
                    cout <<endl <<"\t\tYou Have Completed Your Order So Adding Your Name To Best Seller Employee System\n\n";
                }
                
                fstream order("detailsofemployetakingorder.txt", ios :: app);    // opening new file here to save record of admin who is taking  order 
    
                if (!order) 
                {
                    cout << endl <<"\t\tError In Opening File... \n";
                } 
                else 
                {
                    order << name << " " << table << " " << food << " " << quan << " " << n <<" " <<oc <<endl;
                }
                
            }
            
            else if (oc == 'N' || oc == 'n') 
            {
                cout <<endl <<"\t\tYou Have Not Complete Your Order So Please Complete Your Order To Add Yourself In Best Seller Employee System\n"; 
            }
            
            else 
            {
                cout <<endl <<"\t\tInvalid Input. Please Enter Valid Input To Proceed\n\n";
            }  
        }  
        
        else if (c == 'O' || c == 'o') 
        {
            cout <<endl <<"\t\tSorry User Did Not Want To Order Food. Try To Take Order From Any Other User\n\n";
        }
        
        else 
        {
            cout << endl << "\t\tInvalid Input. Please Try Again By Entering Valid Input\n\n";
        }
        
    }   // if end
    
    else if (choice == 'N' || choice == 'n') 
    {
        cout <<endl <<"You Press 'N' Which Means You Don't Want To Take Order\n\n\t\tQuitting Please Wait...\n\n\t\tQuitting Done\n\n";
    }  
    else 
    {
        cout <<endl <<"\t\tInvalid Input. Please Try Again By Entering Valid Input\n\n";
    }
}

void employee :: generatetransaction() 
{
    cout << "\t\t **************************************************************************** \n"
         << "\t\t *                                                                          * \n"
         << "\t\t *                WELCOME TO CDS GENERATION TRANSACTIONS SYSTEM             * \n"
         << "\t\t *                                                                          * \n"
         << "\t\t **************************************************************************** \n";

    const int s = 100;
    string* orderby = new string[s];
    string* table = new string[s];
    string* item = new string[s];
    int* quantity = new int[s];

    char d;   // for asking weather employee wants to deliver order to staff
    cout << endl << "\t\tDo You Want To Deliver Order To Staff/Student If Yes Then Press 'Y' Otherwise Press 'N' To Quit --->  ";
    cin >> d;  // asking  

    if (d == 'Y' || d == 'y') 
    {
        cout << endl << "\t\tLoading Orders Please Wait...\n\n";
        cout << endl << "\t\tOrders Loaded Successful\n\n";

        ifstream file("orders.txt");   // opening file here in read mode 
        if (!file) 
        {
            cout << endl << "\t\tError In Opening File...\n\n";  // error if file not found 
        }
        else 
        {         
            cout << left << setw(20) << "Order By" << setw(15) << "Table No" << setw(15) << "Item" << setw(10) << "Quantity" << endl;
            cout << left << setw(20) << "--------" << setw(15) << "--------" << setw(15) << "----" << setw(10) << "--------" << endl;

            int i = 0;
            while (i < s && file >> orderby[i] >> table[i] >> item[i] >> quantity[i])    // storing  data in variables 
            {
                cout << left << setw(20) << orderby[i] << setw(15) << table[i] << setw(15) << item[i] << setw(10) << quantity[i] << endl;   // displaying data here
                i++;           
            }

            file.close();   // closing file here 

            char g;    // asking employee weather he wants to generate transaction of order  or not 
            string ordern;     

            cout << endl << "\t\tDo You Want To Generate Digital Transaction By Delivering Order\n\n\t\tIf Yes Then Press 'Y' Otherwise Press 'N' To Quit --->  ";
            cin >> g;   // asking 

            if (g == 'Y' || g == 'y') 
            {
                cout << endl << "\t\tEnter Order By Name Of Which You Want To And Generate Transaction ---> ";
                cin.ignore();
                getline(cin, ordern);    // taking name of order 

                bool found = false;

                for (int k = 0; k < i; ++k) 
                {
                    if (orderby[k] == ordern)    // if name match with the name present in file then proceed  
                    {
                        found = true;

                        cout << endl << endl;

                        cout << left << setw(20) << "Order By" << setw(15) << "Table No" << setw(15) << "Item" << setw(10) << "Quantity" << endl;
                        cout << left << setw(20) << "--------" << setw(15) << "--------" << setw(15) << "----" << setw(10) << "--------" << endl;

                        cout << left << setw(20) << orderby[k] << setw(15) << table[k] << setw(15) << item[k] << setw(10) << quantity[k] << endl;

                        int price;    // taking price from employee to generate bill 
                        cout << endl << "\t\tYou Can See Item And Its Quantity So Now Enter Its Price To Generate Bill ---> ";
                        cin >> price;

                        cout << endl << "\t\tGenerating Bill Please Wait...\n";
                        cout << endl << "\t\tBill Generated Successful\n\n";

                        cout << endl << "\t\t\t  -----------------------------------------------\n";   // printing order details 
                        cout << endl << "\t\t\t   Order By         ----> " << orderby[k] << endl;
                        cout << endl << "\t\t\t   Table No         ----> " << table[k] << endl;
                        cout << endl << "\t\t\t   Total Bill = Rs  ----> " << price << endl;
                        cout << endl << "\t\t\t  -----------------------------------------------\n";

                        break;
                    }
                }

                if (!found) 
                {
                    cout << "\t\tName Not Found. Try Again By Entering Valid Name \n";
                }
            }
            else if (g == 'N' || g == 'n')   // if press n then exit 
            {
                cout << endl << "\t\tYou press 'N'. It Means You Don't Want To Quit\n\n\t\tQuitting Please Wait...\n\n\t\tQuitting Done\n";
            }
            else 
            {
                cout << endl << "\t\tInvalid Input. Please Enter Valid Input To Proceed\n\n";
            }
        }
    }
    else if (d == 'N' || d == 'n') 
    {
        cout << endl << "\t\tQuitting Please Wait...\n\t\tQuit Done Successful";
    }
    else 
    {
        cout << endl << "\t\tInvalid Input. Please Enter Valid Input To Proceed\n\n";
    }
    delete[] orderby;          // deleting dynamic memories 
    delete[] table;
    delete[] item;
    delete[] quantity;
}

void employee :: employeeresponse() 
{
    cout << "\t\t **************************************************************************** \n"
         << "\t\t *                                                                          * \n"
         << "\t\t *               WELCOME TO CDS RESPONDING ONLINE ORDERS PORTAL             * \n"
         << "\t\t *                                                                          * \n"
         << "\t\t **************************************************************************** \n";

    char res; // res for confirming

    cout << endl << "\t\tDo You Want To Respond To Online Orders\n\t\tIf Yes Then Press 'Y' Otherwise Press 'N' ---->  ";
    cin >> res;

    const int s = 100;
    string* name = new string[s];             // variables to store details from file 
    string* time = new string[s];
    string* item = new string[s];
    int* quantity = new int[s];
    int i = 0;

    cout << endl << endl;

    if (res == 'Y' || res == 'y') 
    { 
        ifstream file("onlineorders.txt");   // opening file in read mode 

        if (!file) 
        {
            cout << endl << "\t\tError In Opening File...\n\n";   // error if file not found 
        }
        else 
        {   // displaying on console 
            cout << left << setw(20) << "Customer Name" << setw(10) << "Item" << setw(10) << "Quantity" << setw(25) << "Order Schedule Time" << endl;
            cout << left << setw(20) << "--------------" << setw(10) << "-----" << setw(10) << "--------" << setw(25) << "--------------------" << endl;

            while (i < s && file >> name[i] >> item[i] >> quantity[i])   // storing data from file in variables 
            {
                getline(file, time[i]); // reading the rest of the line to get the time
                cout << left << setw(20) << name[i] << setw(10) << item[i] << setw(10) << quantity[i] << setw(25) << time[i] << endl;
                i++;
            }
            file.close();

            string n;    // to take name of order to which employee wants to response 

            cout << endl << "\n\t\tTo Which Order You Want To Respond Enter That Order UserName ---->  ";
            cin.ignore();
            getline(cin, n);

            cout << endl << "\t\tSearching For Username...\n\n\n";

            bool found = false;  // setting found to 0 

            cout << left << setw(20) << "Customer Name" << setw(10) << "Item" << setw(10) << "Quantity" << setw(25) << "Order Schedule Time" << endl;
            cout << left << setw(20) << "--------------" << setw(10) << "-----" << setw(10) << "--------" << setw(25) << "--------------------" << endl;

            for (int k = 0; k < i; k++) 
            {
                if (name[k] == n)     // if name matches with file name 
                {
                    cout << setw(20) << name[k] << setw(10) << item[k] << setw(10) << quantity[k] << setw(25) << time[k] << endl;
                    found = true;     // then found is 1 

                    string response;    // for taking response of employee about order 

                    cout << endl << "\t\tNow Enter Your Response Here\n\t\t";
                    getline(cin, response);

                    ofstream file("responsebyemployee.txt", ios::app);   // opening file in write mode 
                    if (!file)   
                    {
                        cout << endl << "\t\tError In Opening File...\n\n";  // error if file not found 
                    }
                    else 
                    {
                        file << name[k] << " " << response << endl;   // writing name of order with admin response in file 
                        cout << endl << "\t\tAdding Your Response...\n";
                        cout << endl << "\t\tResponse Added Successfully";
                    }
                    break;
                }
            }
            if (!found)     // if found is 0 then not order not available 
            {
                cout << endl << "\t\tThe User You Enter Is Not Available\n\n";
                cout << endl << "\t\tPlease Make Sure That The Spelling You Enter Matches With The Spelling Shown In List \n\n";
            }
        } 
    } 

    else if (res == 'N' || res == 'n')   // if press n then exit 
    {
        cout << endl << "\t\tYou Press 'N' Its Mean That You Don't Want To Give Response To Orders\n\n";
    }
    else 
    {
        cout << endl << "\t\tInvalid Input. Try Again";
    }

    delete[] name;   // deleting all dynamic memories 
    delete[] time;
    delete[] item;
    delete[] quantity;
} 

void employee :: employeseeingbestselleremployee()
{
    cout << "\t\t **************************************************************************** \n"
         << "\t\t *                                                                          * \n"
         << "\t\t *             WELCOME TO CDS SEEING BEST SELLER EMPLOYEE PORTAL            * \n"
         << "\t\t *                                                                          * \n"
         << "\t\t **************************************************************************** \n";

    const int s = 20;
    char see;    // for asking employee weather he wants tto see best seller nor not 
    cout << endl << "\t\tDo You Want To See Best Seller Employee And Admin Message\n";
    cout << endl << "\t\tIf Yes Then Press 'Y' Otherwise Press 'N' To Quit ---->  ";
    cin >> see;  // asking gere 

    if (see == 'Y' || see == 'y')   // if yes then open file 
    {
        cout << endl << "\t\tLoading Page Please Wait...\n\n";
        cout << endl << "\t\tPage Loaded Successfully\n\n";

        string *ename = new string[s];
        string *m = new string[s];     
        int i = 0;

        ifstream file("bestselleremployee.txt");   // noe opening file here in read mode 
        if (!file)
        {
            cout << endl << "\t\tError In Opening File\n\n";   // error if file not found 
        }
        else
        {   // printing in console 
            cout << left << setw(20) << "-----------" << setw(15) << "----------------" << endl;
            cout << left << setw(20) << "Employee ID" << setw(15) << "Message By Admin" << endl;
            cout << left << setw(20) << "-----------" << setw(15) << "----------------" << endl;

            while (i < s && file >> ename[i] >> m[i])    // storing data from file in variables 
            {
                cout << left << setw(20) << ename[i] << setw(15) << m[i] << endl;   // printing data 
                i++;
            }
            file.close();  // closing files 
        }

        delete[] ename;    // deleting all dynamic memories 
        delete[] m;  
    }
    else if (see == 'N' || see == 'n')   // if press n then exit 
    {
        cout << endl << "\t\tYou Press 'N' It Means That You Want To Quit\n\t\tQuitting Please Wait...\n\t\tQuitting Done\n\n";
    }
    else
    {
        cout << endl << "\t\tInvalid Input Please Try Again By Entering Valid Input\n\n";
    }
}

employee :: ~employee()
{
    // destructor of class employee 
}