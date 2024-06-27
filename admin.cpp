#include"admin.h"                     // including admin.h in admin.cpp 

admin :: admin() 
{
    // this is parameterless constructor which will call on creation of admin class object 
} 

admin :: admin(const string& uname, const string& pass) : user(uname, pass) 
{
    // constructor for creating an admin object with specified username and password which comes from the user class
}

void admin :: login() 
{
    admin a1;                   // making object of admin class 
    string usernameinfile;      // variable to store username of admin from file 
    string passwordinfile;      // variable to store password of admin from file 
    bool check = false;         // initializing check with 0

    ifstream file("logindetailsofadmin.txt");    // opening file to read admin details i.e name and password
    if (!file)                                   // checking if file is available or not 
    {
        cout << "Error In Opening File" << endl;
        return;
    }

    file >> usernameinfile >> passwordinfile;        // reading username and password from file in variables 
    file.close();

    do 
    {
        string username;                             // for taking username as input from admin 
        string password;                             // for taking password as input from admin

        int ch;
        cout << endl << "\t\t\tEnter Username Here ---> ";
        cin >> username;                             // taking input here 
        cout << endl << "\t\t\tEnter Password Here ---> ";
        //cin >> password;                             // taking input here 
        ch = getch();    //  this will read character and dont display on console
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
        checking(3);   // calling delay function here which is defined in user class 

        if (username == usernameinfile && password == passwordinfile)    // checking if username and password entered is same as read from file or not 
        {
            check = true;  // if above if condition come true then admin has login 
            cout << endl << "\t\t\tYou Have Logged In Successfully" << endl;

            int choice;     // for taking input of what admin want to perform 
            do 
            {
                cout << endl << "\n\nYOU ARE ADMIN YOU CAN PERFORM FOLLOWING OPERATIONS IN 'C D S' BY SELECTING IT\n" << endl;
                cout << "\t\t 1.  Handle Stock Details \n";
                cout << "\t\t 2.  See Low Stock Items \n";
                cout << "\t\t 3.  Order Items Which Are Low In Quantity \n";
                cout << "\t\t 4.  Items (Search, Add, Remove, Update In Stock) \n";
                cout << "\t\t 5.  Credentials (Add, Remove ) \n";
                cout << "\t\t 6.  Announcement Through Notification \n";
                cout << "\t\t 7.  See (Online Order, Scheduled Order) \n";
                cout << "\t\t 8.  Response To Schedule Orders \n";
                cout << "\t\t 9.  See Complaints \n";
                cout << "\t\t 10. Announce Best Seller Employee \n";
                cout << "\t\t 11. See Low Stock Order Given By Admin \n";
                cout << "\t\t 12. See Order Given By People Present In Cafe \n";
                cout << "\t\t 13. See Sum And Average Of All Items Present In Stock\n";
                cout << "\t\t 0.  Quit\n\n";
                cout << "\t\t Please Select One From Above ---->   ";
                cin >> choice;            // taking input here 

                switch (choice)           // using switch to handle different cases
                {
                    case 1: 
                    {
                        a1.stock::handlestock();             // calling function here from stock class 
                        break;
                    }
                    case 2: 
                    {
                        a1.stock::lowstockcheck();            // calling function here from stock class 
                        break;
                    }
                    case 3: 
                    {
                        a1.stock::adminorderinglowitem();     // calling function here from stock class 
                        break;
                    }
                    case 4: 
                    {
                        a1.stock::handlestock();              // calling function here from stock class 
                        break;
                    }
                    case 5: 
                    {
                        a1.changingcredentials();             // calling function here from admin class 
                        break;
                    }
                    case 6: 
                    {
                        a1.notification();                    // calling function here from admin class       
                        break;
                    }
                    case 7: 
                    {
                        emp.seeonlineorders();                // calling function here from employee class 
                        break;
                    }
                    case 8: 
                    {
                        a1.adminresponse();                   // calling function here from admin class 
                        break;
                    }
                    case 9: 
                    {
                        a1.seecomplaints();                   // calling function here from admin class 
                        break;
                    }
                    case 10: 
                    {
                        a1.annoucebestselleremployee();       // calling function here from admin class 
                        break;
                    }
                    case 11: 
                    {
                        a1.lowstockorderbyadmin();            // calling function here from admin class 
                        break;
                    }
                    case 12: 
                    {
                        a1.seeorderofpeoplesittingincafe();   // calling function here from admin class 
                        break;
                    }
                    case 13: 
                    {   
                        a1.seesumaverage();                   // calling function here from admin class            
                        break; 
                    }                
                    case 0:                                   // if user press 0 then go back to login portal 
                    {
                        cout << "Quitting..." << endl;
                        break;
                    }
                    default:                                  // for invalid inputs 
                    {
                        cout << "Invalid Option, Please Try Again" << endl;
                        break;
                    }
                }
            } 
            while (choice != 0);                              // till choice is not zero menu will displayed
        } 
        else 
        {
            cout << "Incorrect Username Or Password, Please Try Again To Login" << endl;
        }
    } 
    while (!check);
}

void admin :: notification() const
{
    int choice;     // to take input from user that if he want to view add or remove notification  
    do 
    {
        cout << "\t\t****************************************************************************\n"
                "\t\t*                                                                          *\n"
                "\t\t*              WELCOME TO CDS NOTIFICATION MANAGEMENT SYSTEM                *\n"
                "\t\t*                                                                          *\n"
                "\t\t****************************************************************************\n";

        cout << "\n\t\tSelect What You Want To Do\n\n";
        cout << "\t\t1. Add Notification\n"
                "\t\t2. View And Remove Notifications\n"
                "\t\t3. To Quit ----> ";

        cin.clear();                   // to remove input buffers 
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                string notification;               

                ofstream addnoti("notification.txt", ios :: app);     // opening notification text file in append add new detail in file without removing previous

                cout << "\n\t\tEnter Notification Here That You Want To Add ---> \n\n";
                cin.ignore();
                getline(cin, notification);     // taking input tha is to be added in text file 

                addnoti << notification << endl;   // adding notification in text file 
                addnoti.close();                   // closing file 

                cout << "\n\t\tYour Notification Is Added Successfully.\n";
                break;
            }

            case 2: 
            {
                string view[100];     // making array to store notifications
                int linenumber = 1;   // to display line number with every notification  

                ifstream viewnoti("notification.txt");   // again opening notification text file to read notifications

                cout << endl << endl;
                cout << endl << "\t\tLoading Notifications Please Wait...\n\n\t\tNotifications Loaded Successful\n\n";
                cout << "\t\tCDS Latest Notifications Are \n\n";

                while (getline(viewnoti, view[linenumber]) && linenumber < 10)    // now loading data from file 
                {
                    cout << linenumber << ". " << view[linenumber] << endl;       // displaying text 
                    linenumber++;
                }
                viewnoti.close();

                char removechoice;  // variable to ask user if he want to remove notification or not 
                int notiremove;

                cout << endl << "\t\tIf You Want To Remove Any Notification Press 'Y', Otherwise Press 'N' ---> ";
                cin >> removechoice;  // asking 

                if (removechoice == 'Y' || removechoice == 'y') 
                {
                    cout << "\t\tEnter The Notification Number You Want To Remove ---> ";
                    cin >> notiremove;    

                    ofstream remfile("notification.txt");    // opening file again  

                    for (int i = 1; i < linenumber; i++) 
                    {
                        if (i == notiremove) continue;
                        remfile << view[i] << endl;
                    }
                    remfile.close();
                    cout << "\n\t\tSelected Notification Is Removed.\n";
                } 
                else if (removechoice == 'N' || removechoice == 'n')      // if press n then go back 
                {
                    cout << endl << "\n\t\tYou Pressed 'N', So It Means You Don't Want To Remove Any Notification.\n";
                } 
                else 
                {
                    cout << endl << "\n\t\tInvalid Input. Please Enter a Valid Input.\n";
                }

                break;
            }

            case 3:    // for exiting 
            {
                cout << endl << "\n\t\tQuitting Please Wait...\n\n\t\tQuitting Done.\n\n";
                break;
            }

            default:       // for wrong input 
            {
                cout << endl << "\n\t\tInvalid Option Selected. Please Select a Valid Option To Proceed.\n";
                break;
            }
        }
    } 
    while (choice != 3);     
    cout << endl << "\n\t\tQuitting Please Wait...\n\n\t\tQuitting Done.\n\n";
}

void admin :: changingcredentials() 
{
    int choice;                 // to taking input from admin to know of what user he want to change credentials 

    cout << "\t\t **************************************************************************** \n"
            "\t\t *                                                                          * \n"
            "\t\t *              WELCOME TO CDS CREDENTIALS CONTROL PORTAL                   * \n"
            "\t\t *                                                                          * \n"
            "\t\t **************************************************************************** \n";  
    
    cout << endl << "\t\t----> From Here You Can Change The Credentials Details Of Anyone <----\n\n";
    // displaying for asking admin of which person he want to change credentials 
    cout << endl << "\t\tYou Can Change The Credentials Of Following Users By Selecting One Of Them\n\n";
    cout << endl << "\t\t1. Admin\n\n"
                    "\t\t2. Employee\n\n"
                    "\t\t3. Staff/Student\n\n"
                    "\t\t4. Quit ---->  ";    
    cin >> choice;   // npw taking input 

    switch (choice) 
    {
        case 1: 
        {
            string name;
            string password;
            bool changingadmin = false;

            ifstream adminfile("logindetailsofadmin.txt");     // opening text file here in which credentials of admin are saved
            if (!adminfile) 
            {
                cout << "\t\tError In Opening File...";
                return;
            }

            cout << "\n\t\tCurrent Username For Admin Login Is ----> ";    // displaying current username of admin
            adminfile >> name;
            cout << name << endl;

            cout << "\n\t\tCurrent Password For Admin Login Is ----> ";    // displaying current password name of admin
            adminfile >> password;
            cout << password << endl;

            adminfile.close();

            cout << endl << "\t\tNow If You Want To Change Admin UserName And Password Then Press 'Y' Otherwise Press 'N' ----> ";
            char ch;   // for asking user that he want to change credentials or not 
            cin >> ch;

            if (ch == 'Y' || ch == 'y') 
            {
                cout << endl << "\t\tEnter New Username Here ----> ";   // taking new username 
                cin >> name;

                cout << endl << "\t\tEnter New Password Here ----> ";   // taking new password 
                cin >> password;

                ofstream newadminfile("logindetailsofadmin.txt");   // opening file in write mode 
                if (!newadminfile) 
                {
                    cout << "\t\tError In Opening File...";
                    return;
                }
                newadminfile << name << " " << password << endl;   // writing new name and password in file 
                newadminfile.close();
                changingadmin = true;
            }

            if (changingadmin)        // if bool is 1 then 
            {
                cout << endl << "\t\tWait UserName And Password Is Changing...\n\n";
                cout << endl << "\t\tThanks For Waiting\n\n";
                cout << endl << "\t\tAdmin Login Credentials Changed Successfully \n";
            } 
            else    // else display not changed
            {
                cout << endl << "\t\tAdmin Login Credentials Not Changed \n";
            }
            break;
        }

        case 2: 
        {

            string name; 
            string password;
            bool changeemployee = false;

            ifstream employeefile("logindetailsofemployee.txt");   // opening text file here in which credentials of employee are saved
            if (!employeefile) 
            {
                cout << "\t\tError In Opening File...";
                return;
            }

            cout << "\n\t\tCurrent Username For Employee Login Is ----> ";   // displaying current username of employee
            employeefile >> name;
            cout << name << endl;

            cout << "\n\t\tCurrent Password For Employee Login Is ----> ";   // displaying current password of admin
            employeefile >> password;
            cout << password << endl;

            employeefile.close();

            cout << endl << "\t\tNow If You Want To Change Employee UserName And Password Then Press 'Y' Otherwise Press 'N' ----> ";
            char ch;
            cin >> ch;

            if (ch == 'Y' || ch == 'y') 
            {
                cout << endl << "\t\tEnter New Username Here ----> ";   // taking new username
                cin >> name;

                cout << endl << "\t\tEnter New Password Here ----> ";   // taking new password
                cin >> password;

                ofstream newemployeefile("logindetailsofemployee.txt"); // opening file in write mode
                if (!newemployeefile) 
                {
                    cout << "\t\tError In Opening File...";
                    return;
                }

                newemployeefile << name << " " << password << endl;  // writing new name and password in file 
                newemployeefile.close();

                changeemployee = true;
            }

            if (changeemployee) 
            {
                cout << endl << "\t\tWait UserName And Password Is Changing...\n\n";
                cout << endl << "\t\tThanks For Waiting\n\n";
                cout << endl << "\t\tEmployee Login Credentials Changed Successfully \n";
            } 
            else 
            {
                cout << endl << "\t\tEmployee Login Credentials Not Changed \n";
            }
            break;
        }

        case 3: 
        {
            string name;
            string password;
            bool changestaff = false;

            ifstream stafffile("logindetailsofstaff.txt");  // opening text file here in which credentials of staff are saved
            if (!stafffile) 
            {
                cout << "\t\tError In Opening File...";
                return;
            }

            cout << "\n\t\tCurrent Username For Staff/Student Login Is ----> ";   // displaying current username of staff
            stafffile >> name;
            cout << name << endl;

            cout << "\n\t\tCurrent Password For Staff/Student Login Is ----> ";   // displaying current password of employee
            stafffile >> password;
            cout << password << endl;

            stafffile.close();

            cout << endl << "\t\tNow If You Want To Change Staff/Student UserName And Password Then Press 'Y' Otherwise Press 'N' ----> ";
            char ch;
            cin >> ch;

            if (ch == 'Y' || ch == 'y') 
            {
                cout << endl << "\t\tEnter New Username Here ----> ";    // taking new username
                cin >> name;

                cout << endl << "\t\tEnter New Password Here ----> ";   // taking new password
                cin >> password;

                ofstream newstafffile("logindetailsofstaff.txt");  // opening file in write mode
                if (!newstafffile) 
                {
                    cout << "\t\tError In Opening File...";
                    return;
                }

                newstafffile << name << " " << password << endl;  // writing new name and password in file 
                newstafffile.close();

                changestaff = true;
            }

            if (changestaff) 
            {
                cout << endl << "\t\tWait UserName And Password Is Changing...\n\n";
                cout << endl << "\t\tThanks For Waiting\n\n";
                cout << endl << "\t\tStaff/Student Login Credentials Changed Successfully \n";
            } 
            else 
            {
                cout << endl << "\t\tStaff/Student Login Credentials Not Changed \n";
            }
            break;
        }

        case 4: 
        {
            cout << endl << "\t\tQuitting Please Wait...\n\n\t\tQuitting Done\n\n";
            break;
        }

        default: 
        {
            cout << endl << "\t\tInvalid Option Selected Please Select Valid Option To Proceed\n";
            break;
        }
    }
}

void admin :: seecomplaints() const 
{
    char choice;          // for asking admin if he want to see complaints or not 
    cout << endl << "\t\t **************************************************************************** \n"
        "\t\t *                                                                          * \n"
        "\t\t *                    WELCOME TO CDS COMPLAINT SYSTEM                       * \n"
        "\t\t *                                                                          * \n"
        "\t\t **************************************************************************** \n";
    string name;
    string com;

    cout << "\n\n\t\tIf You Want To See Complaints Given By Staff/Students Then Press 'Y' Otherwise Press 'N' ----> ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') 
    { 
        ifstream file("complain.txt");      // opening complaint text file here 

        if (!file) 
        { 
            cout << "\t\tError In Opening File \"complain.txt\" \n\n";
        } 
        else 
        {  
            cout << endl << "\t\tLoading Complaints...\n\n";
            cout << endl << "\t\tComplaints Loaded Successfully\n\n";

            cout << left << setw(20) << "Customer Name" << setw(25) << "Complaint" << endl;   // for displaying on console
            cout << left << setw(20) << "--------------" << setw(25) << "--------" << endl;

            while (file >> name >> ws && getline(file, com))     // reading complaints from file  
            {
                cout << left << setw(20) << name << setw(25) << com << endl;   // displaying complaints 
            }

            file.close();
        } 
    }  
    else if (choice == 'N' || choice == 'n')     // if press n then dont display complaints  
    {   
        cout << "\t\tYou press 'N' Its Mean You Don't Want To See Complaints Of Staff/Students\n\n";
    }  
    else 
    {   
        cout << "\t\tInvalid Input Please Enter Valid Input To Proceed\n\n";
    }  
} 

void admin :: adminresponse() 
{
    cout << "\t\t **************************************************************************** \n"
         << "\t\t *                                                                          * \n"
         << "\t\t *               WELCOME TO CDS RESPONDING ONLINE ORDERS PORTAL             * \n"
         << "\t\t *                                                                          * \n"
         << "\t\t **************************************************************************** \n";

    char res; // res variable is for confirming from admin that he want to see online orders or not

    cout << endl << "\t\tDo You Want To Respond To Online Orders\n\t\tIf Yes Then Press 'Y' Otherwise Press 'N' ---->  ";
    cin >> res;

    const int s = 100;
    string header;
    string* name = new string[s];             
    string* time = new string[s];
    string* item = new string[s];
    int* quantity = new int[s];
    int i = 0;

    cout << endl << endl;

    if (res == 'Y' || res == 'y')    // is yes then opening file 
    { 
        ifstream file("onlineorders.txt");       // opening file in read mode

        if (!file) 
        {
            cout << endl << "\t\tError In Opening File...\n\n";  // if file is not available then error 
        }
        else 
        { 
            cout << left << setw(20) << "Customer Name" << setw(10) << "Item" << setw(10) << "Quantity" << setw(25) << "Order Schedule Time" << endl;
            cout << left << setw(20) << "--------------" << setw(10) << "-----" << setw(10) << "--------" << setw(25) << "--------------------" << endl;

            while (i < s && file >> name[i] >> item[i] >> quantity[i])    // reading data from file in variables 
            {
                getline(file, time[i]); // read the rest of the line to get the time
                cout << left << setw(20) << name[i] << setw(10) << item[i] << setw(10) << quantity[i] << setw(25) << time[i] << endl;
                i++;
            }
            file.close();

            string n;     // for asking admin that he want to respond to which order 

            cout << endl << "\n\t\tTo Which Order You Want To Respond Enter That Order UserName ---->  ";
            cin.ignore(); 
            getline(cin, n);   

            cout << endl << "\t\tSearching For Username...\n\n\n";
            bool found = false;

            cout << left << setw(20) << "Customer Name" << setw(10) << "Item" << setw(10) << "Quantity" << setw(25) << "Order Schedule Time" << endl;
            cout << left << setw(20) << "--------------" << setw(10) << "-----" << setw(10) << "--------" << setw(25) << "--------------------" << endl;

            for (int k = 0; k < i; k++) 
            {
                if (name[k] == n)     // if entered name match with the name stored in name string then proceed 
                {
                    cout << setw(20) << name[k] << setw(10) << item[k] << setw(10) << quantity[k] << setw(25) << time[k] << endl;
                    found = true;

                    string response; 

                    cout << endl << "\t\tNow Enter Your Response Here\n\t\t";
                    getline(cin, response);  // taking respond of admin here 

                    ofstream file("responsebyadmin.txt", ios :: app);   // opening file in write mode to add response of admin
                    if (!file) 
                    {
                        cout << endl << "\t\tError In Opening File...\n\n";
                    }
                    else 
                    {
                        file << name[k] << " " << response << endl;         // writing response in file
                        cout << endl << "\t\tAdding Your Response...\n";
                        cout << endl << "\t\tResponse Added Successfully";
                    }
                    break;
                }
            }
            if (!found)    // if admin enter incorrect name then display not match 
            {
                cout << endl << "\t\tThe User You Enter Is Not Available\n\n";
                cout << endl << "\t\tPlease Make Sure That The Spelling You Enter Matches With The Spelling Shown In List \n\n";
            }
        } 
    } 

    else if (res == 'N' || res == 'n')   // exit when entered n 
    {
        cout << endl << "\t\tYou Press 'N' Its Mean That You Don't Want To Give Response To Orders\n\n";
    }
    else 
    {
        cout << endl << "\t\tInvalid Input. Try Again";
    }

    delete[] name;                       // deleting dynamic memory 
    delete[] time;
    delete[] item;
    delete[] quantity;
} 

void admin:: lowstockorderbyadmin() 
{
    cout << "\t\t **************************************************************************** \n"
            "\t\t *                                                                          * \n"
            "\t\t *               WELCOME TO CDS SEEING LOW STOCK ORDERS PORTAL              * \n"
            "\t\t *                                                                          * \n"
            "\t\t **************************************************************************** \n";

    char ask;    // variable to ask admin that he want to see low stock order or not  

    cout << endl << "\t\tDo You Want To See Orders That You Placed Of Low Stock\n\n";
    cout << endl << "\t\tIf Yes Then Press 'Y' Otherwise Press 'N' To Quit ---->  ";
    cin >> ask;  // asking 
    
    int s = 50;
    string* item = new string[s];
    string* q = new string[s];
    int i = 0;

    if (ask == 'Y' || ask == 'y')     // if press y then opening file in read mode 
    {
        ifstream file("stockorderbyadmin.txt");           // opening file here 

        if (!file) 
        {
            cout << endl << "\t\tError In Loading File...\n\n";   // error if file is not found 
        }
        else 
        {
            cout << endl << "\t\tLoading Your Orders Please Wait...\n";
            cout << endl << "\t\tOrders Loaded Successfully\n\n";

            cout << left << setw(20) << "Item Name" << setw(25) << "Order Quantity" << endl;   // displaying on concole 
            cout << left << setw(20) << "--------------" << setw(25) << "--------------" << endl;

            string itemname;     // to get itemname from file in variable (itemname)
            while (file >> itemname)   // storing name from file 
            {
                file >> q[i];         // storing quantity of that item in q[i]
                item[i] = itemname;
                i++;
            }    
        }
        for (int k = 0; k < i; ++k) 
        {
            cout << left << setw(20) << item[k] << setw(25) << q[k] << endl;   // now displaying on screen items and quantity ordered
        }
        delete[] item;
        delete[] q;
        file.close();  // closing file here 
        }    
    
        else if (ask == 'N' || ask == 'n')    // if press n then dont show orders 
        {
            cout << endl << "\t\tYou press 'N' Its Mean You Don't Want To See Low Stock Orders Given By Admin\n\n";
        }
        else 
        {
            cout << endl << "\t\tInvalid Input Please Enter Valid Input To Proceed\n\n";
        }
}

void admin::annoucebestselleremployee() 
{
    cout << "\t\t **************************************************************************** \n"
        << "\t\t *                                                                          * \n"
        << "\t\t *         WELCOME TO CDS ANNOUNCING BEST SELLING EMPLOYEE PORTAL           * \n"
        << "\t\t *                                                                          * \n"
        << "\t\t **************************************************************************** \n";

    char see;      // to take input from admin weather he wants to see best seller or not 
    cout << endl << "\t\tDo You Want To See All Order And See Who Completed Them\n";
    cout << endl << "\t\tIf Yes Then Press 'Y' Otherwise Press 'N' To Quit ---->  ";
    cin >> see;   // asking form admin 

    if (see == 'Y' || see == 'y')    // if press y then proceed 
    {
        cout << endl << "\t\tLoading All Details Please Wait...\n\n";
        cout << endl << "\t\tDetails Loaded Successful\n\n";

        ifstream file("detailsofemployetakingorder.txt");   // opening file in read mode 
        if (!file) 
        {
            cout << endl  << "Error In Opening File" << endl;   // error if file not found 
            return;
        }

        const int s = 30;
        string *orderby = new string[s];          // variables to stores data from file and to display on console
        string *table = new string[s];
        string *item = new string[s];
        string *quantity = new string[s];
        string *ordertakenby = new string[s];
        string *orderdetail = new string[s];
        int i = 0;

        cout << left << setw(15) << "Order By" << setw(15) << "Table No" << setw(10) << "Item" << setw(15) << "Quantity" << setw(20) << "Order Taken By" << setw(20) << "Order Details 'Y' Mean Completed" << endl;
        cout << left << setw(15) << "--------" << setw(15) << "--------" << setw(10) << "----" << setw(15) << "--------" << setw(20) << "---------------" << setw(20) << "--------------------------------" << endl;

        while (file >> orderby[i] >> table[i] >> item[i] >> quantity[i] >> ordertakenby[i] >> orderdetail[i])    // reading data in variables 
        {
            cout << left << setw(15) << orderby[i] << setw(15) << table[i] << setw(10) << item[i] << setw(15) << quantity[i] << setw(20) << ordertakenby[i] << setw(20) << orderdetail[i] << endl;
            i++;
        }

        file.close();

        string bestseller;      // to store best seller  here 
        int maxorderstaken = 0; // to count orders 

        for (int j = 0; j < i; j++)    // this loop run through each employee
        {
            int currentorder = 0;  // initializing this variable to 0 to to count order taken by j employee
            for (int k = 0; k < i; k++) 
            {
                if (ordertakenby[k] == ordertakenby[j])   // if order was taken by the current employee (k) then increment the ordercount by 1
                {
                    currentorder++;
                }
            }
            if (currentorder > maxorderstaken)    // here checking if the current employee has taken more orders than the previous maximum
            {
                maxorderstaken = currentorder;    // here updating max orders taken by employee 
                bestseller = ordertakenby[j];     // here updating bestsellers by name
            }
        }
        char a;  // asking if admin want to see best seller 
        cout << endl << "\t\tNow Do You Want To See Best Seller Employee If Yes Press 'Y' Otherwise Press 'N' To Quit ---->  ";
        cin >> a;  // asking 
        cin.ignore();

        if (a == 'Y' || a == 'y')   // if yes then displaying best seller and orders taken by him 
        {
            cout << "\n\n\t\tBest Seller Employee is: " << bestseller << endl;
            cout << "\t\tTotal Orders Taken: " << maxorderstaken << endl;
            string message;      // variable to get message from admin for best seller          
            cout << endl << "\t\tEnter Any Message You Want To Give To Best Seller Employee ---> ";
            cin >> ws;
            getline(cin, message);

            ofstream file2("bestselleremployee.txt", ios::app);   // opening file in write mode
            if (!file2) 
            {
                return;
            }

            file2 << bestseller << " " << message << endl;   // writing admin message and emp name in file 
            cout << endl << "\t\tAdding Your Message Please Wait...\n\n";
            cout << endl << "\t\tMessage Added Successful\n\n";
            file2.close();
        } 
        else if (a == 'N' || a == 'n')   // if no then back  
        {
            cout << endl << "\n\t\tYou Press 'N' It Means That You Don't Want To Announce Best Seller Employee\n";
            cout << endl << "\t\tSo Quitting Please Wait...\n\n\t\tQuitting Done\n\n";
        } 
        else 
        {
            cout << endl << "\t\tInvalid Input Please Enter Valid Input To Proceed\n\n";
        }
        delete[] orderby;    // deleting dynamic memories 
        delete[] table;
        delete[] item;
        delete[] quantity;
        delete[] ordertakenby;
        delete[] orderdetail;
    } 
    else if (see == 'N' || see == 'n') 
    {
        cout << endl << "\n\t\tYou Press 'N' It Means That You Don't Want To See Details And Not Want To Announce Best Seller Employee\n";
        cout << endl << "\t\tSo Quitting Please Wait...\n\n\t\tQuitting Done\n\n";
    } 
    else 
    {
        cout << endl << "\t\tInvalid Input Please Enter Valid Input To Proceed\n\n";
    }
}

void admin :: seeorderofpeoplesittingincafe()
{
    cout << "\t\t **************************************************************************** \n"
         << "\t\t *                                                                          * \n"
         << "\t\t *               WELCOME TO CDS PORTAL OF SEEING PRESENT ORDERS             * \n"
         << "\t\t *                                                                          * \n"
         << "\t\t **************************************************************************** \n";

    char porder;      // variable for seeing present orders 
    cout << endl << "\t\tIf You Want To See Present Orders Then Press 'Y' Otherwise Press 'N' To Quit ---->   ";
    cin >> porder;   // asking user if he wants to see orders 

    if (porder == 'Y' || porder == 'y')   // if press y then show orders 
    {
        cout << endl << "\t\tLoading Orders Please Wait...\n";
        cout << endl << "\t\tOrders Loaded Successfully\n\n";

        const int s = 100;
        string *orderby = new string[s];     
        string *table = new string[s];   
        string *item = new string[s];    
        int *quantity = new int[s];      
        int i = 0;

        ifstream file("orders.txt");    // opening orders file here in read mode 
        if (!file)
        {
            cout << endl << "\t\tError In Opening File...\n\n";   // error if file not found
        }
        else
        {
            cout << left << setw(20) << "Order By" << setw(15) << "Table No" << setw(15) << "Item" << setw(10) << "Quantity" << endl;
            cout << left << setw(20) << "--------" << setw(15) << "--------" << setw(15) << "----" << setw(10) << "--------" << endl;

            while (i < s && file >> orderby[i] >> table[i] >> item[i] >> quantity[i])   // reading data frm file in variables 
            {
                i++;
            }

            file.close();   // closing file 

            for (int k = 0; k < i; k++)   // displaying now data no console 
            {
                cout << left << setw(20) << orderby[k] << setw(15) << table[k] << setw(15) << item[k] << setw(10) << quantity[k] << endl;
            }
        }

        delete[] orderby;   // deleting dynamic memories 
        delete[] table;   
        delete[] item;   
        delete[] quantity; 
    }
    else if (porder == 'N' || porder == 'n')   // if press n then exit 
    {
        cout << endl << "\t\tYou Press 'N' It Means That You Want To Quit\n\t\tQuitting Please Wait...\n\t\tQuitting Done\n\n";
    }
    else
    {
        cout << endl << "\t\tInvalid Input. Please Try Again By Entering Valid Input.\n\n";
    }
}

void admin :: seesumaverage() 
{
    cout << "\t\t **************************************************************************** \n"
                "\t\t *                                                                          * \n"
                "\t\t *            WELCOME TO CDS PORTAL OF SEEING SUM AND AVERAGE OF STOCK      * \n"
                "\t\t *                                                                          * \n"
                "\t\t **************************************************************************** \n";

    const int s = 100;
    char header[50];
    string* item = new string[s];
    double* price = new double[s];
    int* quantity = new int[s];
    int* totalp = new int[s];
    int i = 0;

    double sumofquantity = 0;       // variables to store sum averages of stock price quantity 
    double sumoftotalp = 0;
    double avgofquantity = 0;   
    double avgoftotalp = 0;     

    char c;  // for asking user whether he wants to see sum average of stock or not   
    char a;  // for asking user whether he wants to see sum or average of stock 

    cout << endl << "\t\tDo You Want To See The Sum And Average Of Quantity And Total Price\n\n";
    cout << endl << "\t\tIf Yes Press 'Y' Otherwise Press 'N' To Quit ---->  ";

    cin >> c;

    if (c == 'Y' || c == 'y') 
    {   
        fstream file("stock.txt", ios::in);   // opening stock file here in read mode 
        if (!file) 
        {
            cout << endl << "\t\tError In Opening File...\n\n";  // error if file not found
        }
        else 
        {
            file.getline(header, 50, '\n');

            cout << left << setw(20) << "Items" << setw(15) << "PricePerItem" << setw(10) << "Quantity" << setw(15) << "TotalPrice" << endl;
            cout << left << setw(20) << "-----" << setw(15) << "------------" << setw(10) << "--------" << setw(15) << "----------" << endl;

            while (file >> item[i] >> price[i] >> quantity[i] >> totalp[i])    // reading data from  file in variables 
            {
                i++;
            }

            file.close();   // noe closing file 

            for (int k = 0; k < i; k++)    // displaying data on console 
            {
                cout << left << setw(20) << item[k] << setw(15) << price[k] << setw(10) << quantity[k] << setw(15) << totalp[k] << endl;
            }

            for (int l = 0; l < i; l++) 
            {
                sumofquantity += quantity[l];      // adding all quantities here 
                sumoftotalp += totalp[l];          // adding all prices here 
            }

            avgofquantity = sumofquantity / i;    // dividing quantity by i to get average of quantities 
            avgoftotalp = sumoftotalp / i;        // dividing price by i to get average of prices

            cout << endl << "\t\tIf You Want To See The Sum Of All Quantity And Sum Of Total Price Then Press 'S'\n\n";
            cout << endl << "\t\tOr If You Want To See The Average Of All Quantity And Average Of Total Price Then Press 'A'\n\n";
            cout << endl << "\t\tOr If You Want To Exit Then Press 'E'  ----> ";
            cin >> a;   // asking user now if h want to see sum average of price and quantity or not  

            if (a == 'S' || a == 's')   // is press y then show sum of all quantities
            {
                cout << endl << "\t\t------------------------------------------------------\n";
                cout << endl << "\t\tSum Of All Quantity Is         ----> " << sumofquantity;
                cout << endl << "\t\tSum Of All TotalPrice Is       ----> " << "Rs : " << sumoftotalp;
                cout << endl << "\n\t\t------------------------------------------------------\n";
            }
            else if (a == 'A' || a == 'a')   // is press a then show average of all quantities
            {
                cout << endl << "\t\t---------------------------------------------------------\n";
                cout << endl << "\t\tAverage Of All Quantity Is         ----> " << avgofquantity;
                cout << endl << "\t\tAverage Of All TotalPrice Is       ----> " << "Rs : " << avgoftotalp;
                cout << endl << "\n\t\t---------------------------------------------------------\n";
            }
            else if (a == 'E' || a == 'e') 
            {
                cout << endl << "\t\tExiting Please Wait...\n\n\t\tExited Successful\n\n";
            }
            else {
                cout << endl << "\t\tInvalid Input Please Try Again By Entering Valid Input\n\n";
            }
        } 
    }
    else if (c == 'N' || c == 'n')   // if press n then exit 
    {
        cout << endl << "\t\tQuitting Please Wait...\n\n\t\tQuit Successful\n\n";
    }
    else 
    {
        cout << endl << "\t\tInvalid Input Please Try Again By Entering Valid Input\n\n";
    }
    delete[] item;   // deleting dynamic memories 
    delete[] price;
    delete[] quantity;
    delete[] totalp;
}  

admin :: ~admin()
{
    // destructor of admin class 
}
