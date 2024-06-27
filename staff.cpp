#include"staff.h"

staff :: staff() 
{
    // this is parameterless constructor 
} 

staff :: staff(const string& uname, const string& pass) : user(uname, pass) 
{
    // this is parametrized constructor 
}

void staff :: login() 
{
    staff s1;
    string usernameinfile;                   // variables to store username from file 
    string passwordinfile;                   // variables to store password from file 
    bool check = false; 

    ifstream file("logindetailsofstaff.txt");       // opening file here in read mode 
    if (!file) 
    {
        cout << "Error In Opening File" << endl;    // error if file not found 
        return;
    }

    file >> usernameinfile >> passwordinfile;       // storing name and password from file in variables 
    file.close();                                   // closing file here 
    do 
    {
        string username;                            // variables to take username as input in console 
        string password;                            // variables to take password as input in console 
        int ch;

        cout << endl << "\t\t\tEnter Username Here ---> ";
        cin >> username;   // taking username here 
        cout << endl << "\t\t\tEnter Password Here ---> ";
        //cin >> password; // taking password here 

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

        if (username == usernameinfile && password == passwordinfile)    // checking if entered details matched with file details
        {
            cout << endl << endl  << "\t\t\tChecking Please Wait..." << endl << endl;
            checking(3);
            check = true;   // if yes  then login 
            cout << endl << "\t\t\tYou Have Logged In Successfully" << endl;

            int choice;    // to ask staff what he want to do after login  
            do 
            {
                cout << "\n\n\t\t YOU ARE STUDENT/STAFF YOU CAN PERFORM FOLLOWING OPERATIONS IN 'C D S' \n";
                cout << "\t\t 1. Search And Order Food \n";
                cout << "\t\t 2. Give Complaints \n";
                cout << "\t\t 3. Search Items \n";
                cout << "\t\t 4. Give And Schedule Order \n";
                cout << "\t\t 5. See Notifications \n";
                cout << "\t\t 6. See Response \n";
                cout << "\t\t 0. Quit \n\n";
                cout << "\t\t Please Select One From Above ---> ";
                
                cin >> choice;  // asking here 

                switch (choice) // using switch to handle different cases 
                {
                    case 1:
                    {
                        s1.order::searchandorderfood();
                        break;
                    }
                    case 2:
                    {
                        s1.givecomplaints();
                        break;
                    }
                    case 3:
                    {
                        s1.searchforstaff();
                        break;
                    }
                    case 4:
                    {
                        s1.order::scheduleorder();
                        break;
                    }
                    case 5:
                    {
                        s1.seenotifications();
                        break;
                    }
                    case 6:
                    {
                        s1.seeresponse();
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
            while (choice != 0);  // when choice is 0 then exit 
        } 
        else 
        {
            cout << "Incorrect Username Or Password, Please Try Again To Login" << endl;
        }
    } 
    while (!check);
}

void staff :: givecomplaints() 
{
    char choice;    // to ask staff weather he want to give complaint or not 
    
    cout << "\t\t **************************************************************************** \n"
            "\t\t *                                                                          * \n"
            "\t\t *                   WELCOME TO CDS COMPLAINT PORTAL                        * \n"
            "\t\t *                                                                          * \n"
            "\t\t **************************************************************************** \n";

    cout << "\n\n\t\tIf You Want To Give Any Complain Then Press 'Y' Otherwise Press 'N' ---->  ";
    cin >> choice;  // asking here 
    cin.ignore();

    if (choice == 'Y' || choice == 'y')    // if yes then proceed 
    {   
        string complain; 
        string name;
        ofstream addcomplain("complain.txt", ios :: app);  // opening file  in write mode to write complaints 

        int select;    // asking which type of complaint staff want to give 

        cout << "\t\tSelect About What Do You Want To Complain \n\n";
        cout << "\t\t 1. Related Food \n"
                "\t\t 2. Related Employee \n"
                "\t\t 3. Related Cleanliness \n"
                "\t\t 4. Or Any Other  ----> ";

        cin >> select;  // asking here 
        cin.ignore();

        switch (select)  // using switch to handle different cases 
        {
            case 1:
            {
                cout << "\n\t\tPlease Enter Your Name Here ---->  ";
                getline(cin, name);
                cout << "\n\t\tPlease Enter Your Complain Here ----> ";
                getline(cin, complain);
                break;
            }
            case 2:
            {
                cout << "\n\t\tPlease Enter Your Name Here ---->  ";
                getline(cin, name);
                cout << "\n\t\tPlease Enter Your Complain Here ----> ";
                getline(cin, complain);
                break;
            }
            case 3:
            {
                cout << "\n\t\tPlease Enter Your Name Here ---->  ";
                getline(cin, name);
                cout << "\n\t\tPlease Enter Your Complain Here ----> ";
                getline(cin, complain);
                break;
            }
            case 4:
            {
                cout << "\n\t\tPlease Enter Your Name Here ---->  ";
                getline(cin, name);
                cout << "\n\t\tPlease Enter Your Complain Here ----> ";
                getline(cin, complain);
                break;
            }
        }

        addcomplain << name << " " << complain << endl;    // adding complaints to text file with name 
        addcomplain.close();

        cout << "\n\t\tSubmitting Your Complain Please Wait...";
        cout << "\n\t\tYour Complain Is Submitted. Thank You\n";
    } 
    else if (choice == 'N' || choice == 'n')   // if press n then it mean staff dont want to add complaint  
    {  
        cout << "\n\t\tYou Press 'N' It Means That You Don't Want To Add Any Complaint\n";
    } 
    else 
    {  
        cout << "\n\t\tInvalid Input\n";
    }
}

void staff :: seenotifications() const 
{
    char choice;  // for asking staff weather he wants to see notifications or not 

    cout << "\t\t **************************************************************************** \n"
            "\t\t *                                                                          * \n"
            "\t\t *                   WELCOME TO CDS NOTIFICATION VIEWING PORTAL             * \n"
            "\t\t *                                                                          * \n"
            "\t\t **************************************************************************** \n";

    cout << "\t\tIf You Want To See Notification Of CDS Then Press 'Y' Otherwise Press 'N': ";
    cin >> choice;  // asking here 

    if (choice == 'Y' || choice == 'y')    // if press y then open file 
    {  
        ifstream file("notification.txt"); // here opening file in read mode 

        if (!file) 
        {  
            cout << "\t\tERROR IN OPENING FILE \"notification.txt\"\n\n";  // error if file not found 
        } 
        else 
        {  
            string line;
            int lineNumber = 1;

            cout << "\nNotifications Are \n\n";

            while (getline(file, line))   // storing data in variables 
            {
                cout << lineNumber << ". " << line << endl;   // displaying data here 
                lineNumber++;
            }
            file.close();
        } 
    } 
    else if (choice == 'N' || choice == 'n')   // if press n then exit 
    {  
        cout << "\t\tYou press 'N' Its Mean You Don't Want To View Latest Notifications\n";
    } 
    else 
    {  
        cout << "\t\tInvalid Input...\n";
    } 
}   

void staff:: searchforstaff()
{
    cout << "\t\t **************************************************************************** \n"
            << "\t\t *                                                                          * \n"
            << "\t\t *                WELCOME TO CDS ITEM SEARCH PORTAL FOR STAFF               * \n"
            << "\t\t *                                                                          * \n"
            << "\t\t **************************************************************************** \n";
        
        char c;      // for asking staff weather he wants to search items from stockk 
        cout <<endl <<"\t\tDo You Want To Search Item From CDS Stock\n\n\t\tIf Yes Then Press 'Y' OtherWise Press 'N' To Quit ---->  ";
        
        cin >> c;   // asking here 
        
        if (c == 'Y' || c == 'y')  // if press y then proceed 
        {
        cout <<endl <<"\t\tLoading List Please Wait...\n\n";
        cin.ignore();
        search();  // calling search function here which is from stock class as order class is inherited from stock so its mean all function of stock are in order and in staff we inherited order so by this process search is called here 
        } 
        else if (c == 'N' || c == 'n')   // if press n then its mean staff dont want to search item from stock 
        {
        cout <<endl <<"\t\tYou Press 'N' Its Mean That You Dont Want To Search Any Item\n\n\t\tSo Quieting Please Wait...\n\n\t\tQuiting Done\n\n";
        } 
        else 
        {
        cout <<endl <<"\n\t\tInvalid Input Please Try Again By Entering Valid Input\n\n";
        }
} 

void staff::seeresponse() 
{
    cout << endl << "\t\t **************************************************************************** \n"
         << "\t\t *                                                                          * \n"
         << "\t\t *                WELCOME TO CDS SEEING RESPONSE TO ORDER PORTAL            * \n"
         << "\t\t *                                                                          * \n"
         << "\t\t **************************************************************************** \n";

    char see;                // for confirming yes or no
    string name;             // variables to take name as input 
    string password;         // variables to take password as input
    string nameinfile;       // variables to store name from file 
    string passinfile;       // variables to store password from file 

    string* data = new string[30];
    string* response = new string[30];

    cout << endl << "\t\tBy Logging In With Your ID You Can See Response Given To Your Orders\n\n";
    cout << endl << "\t\tSo Do You Want To Login If Yes Then Press 'Y' Otherwise Press 'N' ---->  ";
    cin >> see;    // asking weather staff want to login or not 

    if (see == 'Y' || see == 'y')   // if yes then proceed 
    { 
        cout << endl << "\t\tLogin Page Loading...\n";
        cout << endl << "\t\tEnter Your UserName Here ----->  ";   
        cin >> name;      // taking name as input here 
        cout << endl << "\t\tEnter Your Password Here ----->  ";
        cin >> password;  // taking password as input here 

        fstream file("logindetailsofonlineuser.txt", ios::in);   // now opening file in read mode where details are saved

        if (!file) 
        {
            cout << endl << "\t\tError In Opening File...\n\n";  // error if file not found 
        }
        else 
        { 
            bool loggedIn = false;
            while (file >> nameinfile >> passinfile)      // storing data from file in variables 
            {
                if (name == nameinfile && password == passinfile)  // if entered details matched with file details then login 
                { 
                    loggedIn = true;
                    cout << endl << "\t\tYou Have Successfully Logged In\n\n";
                    break; // Exit the loop if login successful
                }
            }
            
            if (!loggedIn)
            {
                cout << endl << "\t\tLogin Failed. Invalid Username or Password.\n\n";
                return; // Exit function if login failed
            }

            int select; // for user to select which response he want to see
            cout << endl << "\t\tNow Select Response Of Whom You Want To See\n\n";
            cout << endl << "\t\t1. Admin Response\n\t\t2. Employee Response\n\t\t3. Quit ---->  ";
            cin >> select;  // asking staff of which person they want to see response 
            switch (select) // using switch to handle different cases 
            { 
            case 1: 
            {
                cout << endl << "\t\tLoading Responses Of Admin...\n\n";
                cout << endl << "\t\tResponses Loaded Successfully\n\n";
                fstream file1("responsebyadmin.txt", ios::in);   // opening file in read mode here in which response are saved 
                if (!file1) 
                {
                    cout << endl << "\t\tError In Opening File...\n\n";  // error if file not found 
                }
                else 
                {
                    cout << setw(20) << left << "Order Schedule By " << setw(15) << right << "Response From Admin " << endl;
                    cout << setw(20) << left << "-----------------" << setw(15) << right << "-----------------------" << endl;
                    int i = 0;
                    while (file1 >> data[i]) 
                    {
                        string temp;
                        getline(file1, temp);
                        response[i] = temp.substr(temp.find(' ') + 1); //  taking response after the first space
                        cout << setw(20) << left << data[i] << setw(15) << right << response[i] << endl;
                        i++;
                    }                       
                    file1.close();
                }
                break;
            }
            case 2: 
            {
                cout << endl << "\t\tLoading Responses Of Employee...\n\n";
                cout << endl << "\t\tResponses Loaded Successfully\n\n";

                fstream file2("responsebyemployee.txt", ios::in);   // opening file in read mode here in which response are saved 
                if (!file2)
                {
                    cout << endl << "\t\tError In Opening File...\n\n";  // error if file not found 
                }
                else 
                {
                    cout << setw(20) << left << "OrderScheduleBy " << setw(15) << right << "ResponseFromEmployee " << endl;
                    cout << setw(20) << left << "---------------" << setw(15) << right << "---------------------" << endl;

                    int j = 0;
                    while (file2 >> data[j]) 
                    {
                        string temp;
                        getline(file2, temp);
                        response[j] = temp.substr(temp.find(' ') + 1); // taking response after the first space
                        cout << setw(20) << left << data[j] << setw(15) << right << response[j] << endl;
                        j++;
                    }
                    file2.close();
                } 
                break;
            } 
            case 3:     // if 3 is press then quit 
            { 
                cout << endl << "\t\tYou Have Quit Seeing Response Portal\n\n\t\tQuitting...\n\n\t\tQuitting Done\n";
                break;
            } 

            default: 
            {
                cout << endl << "\t\tInvalid Input Please Try Again\n";
            }
            } 
        } 
    } 
    else if (see == 'N' || see == 'n')    // if press n then exit 
    {
        cout << endl << "\t\tYou Press 'N' Its Mean You Don't Want To See Any Response\n\n\t\tThanks For Visiting Bye\n";
    }
    else
    {
        cout << endl << "\t\tInvalid Input Please Try Again\n";
    }
    delete[] data;             // deleting all dynamic memories 
    delete[] response;
}

staff :: ~staff()
{
    // destructor of staff class 
}
