#include"order.h"

void order :: searchandorderfood() 
{
    int choice;        // for asking user what he want to do weather he want to see menu or search or order food 
    do 
    {
        cout << endl << "\t\t **************************************************************************** \n"
            "\t\t *                                                                          * \n"
            "\t\t *                   WELCOME TO CDS FOOD ORDERING SYSTEM                    * \n"
            "\t\t *                                                                          * \n"
            "\t\t **************************************************************************** \n";

        char c;
        char o;
        string food;
        string name;
        int table;
        int quan;

        cout << endl << "\t\t Select What Do You Want To Do \n\n"
            "\t\t 1. See Menu Only \n"
            "\t\t 2. Search And Order Food \n"
            "\t\t 3. Quit  --->  ";
        cin >> choice;         // asking here 

        switch (choice)        // using switch to handle different cases 
        {
        case 1: 
        {
            cout << endl << "\n\n---> This Is The Complete Menu Of \"CAFE DIGITAL SYSTEM (CDS)\"  <---\n\n";
            view();           // calling view function which is inherited from stock class
            break;
        }
        case 2: 
        {
            cout << endl << "\t\tDo You Want To Search Food If Yes Then Press 'Y' --->  ";
            cout << endl << "\t\tOr If You Want To Order Food Then Press 'O' --->  ";
            cin >> c;   // asking  weather orderer want to search or order food 

            if (c == 'Y' || c == 'y') 
            {
                cin.ignore();
                search();     // calling search function which is inherited from stock class
            }
            else if (c == 'O' || c == 'o')    // if press o then its mean orderer wants to order food 
            {
                const int s = 100;
                char header[50];
                string* item = new string[s];          // variables to store data 
                double* price = new double[s];
                int* quantity = new int[s];
                int* totalprice = new int[s];
                int i = 0;
                double tbill = 0;
                double titem = 0;

                ifstream file("stock.txt");          // now here opening stock file in read mode 

                if (!file) 
                {
                    cout << endl << "Error In Opening File...\n";   // error if file not open 
                }

                file.getline(header, 50, '\n'); 

                while (file >> setw(21) >> item[i] >> price[i] >> quantity[i] >> totalprice[i])   // storing data in files 
                {
                    i++;
                }

                file.close();   // closing file 

                cout << endl << "\t\t----> Available Food Is <---- \n";
                view();     // again calling here view function which is inherited from stock class

                cout << endl << endl;

                cout << endl << "\t\tPlease Enter Your Name Here ---> ";   // taking user name of orderer 
                cin.ignore();
                getline(cin, name);

                cout << endl << "\t\tPlease Enter Your Table Number Here ---> ";   // taking table number of orderer 
                cin >> table;

                do 
                {
                    cout << endl << "\t\tEnter Food Name You Want To Order ---> ";  // taking food which he want to eat from orderer 
                    cin.ignore();
                    getline(cin, food);

                    cout << endl << "\t\tHow Much Quantity You Want Of This Food ---> ";   // asking quantity of food from orderer 
                    cin >> quan;

                    bool spell = false;    // initializing spell to 0 

                    for (int k = 0; k < i; k++)      
                    {
                        if (item[k] == food && quan <= quantity[k])   // if name of food and quantity entered are valid then proceed 
                        {
                            spell = true;   // and if above if is true then spell comes 1 
                            break;
                        }
                        
                    }

                    if (spell == true)   // now if spell is 1 
                    {
                        fstream update("stock.txt", ios::out | ios::trunc);   // then updating stock file 

                        if (!update) 
                        {
                            cout << "Error In Opening File...\n";  // error if file is not available 
                        }
                        else 
                        {
                            update << header << endl;
                            for (int k = 0; k < i; k++) 
                            {
                                if (item[k] == food) 
                                {
                                    quantity[k] -= quan;    // reducing quantity 
                                    totalprice[k] = price[k] * quantity[k];   
                                }
                                update << item[k] << " " << price[k] << " " << quantity[k] << " " << totalprice[k] << endl;  // updating stock in file 
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

                        tbill += titem;   // this is to calculate total price 

                        fstream order("orders.txt", ios::app);    // now opening file to save orders given by orderer 
                        if (!order) 
                        {
                            cout << endl << "\t\tError In Opening File... \n";  // error if file not found 
                        }
                        else 
                        {
                            order << name << " " << table << " " << food << " " << quan << endl;    // if file found then printing this on console
                        }
                        cout << endl << "\n\n\n\t\t-----> Your Order Details <----- \n\n";   // printing order details on screen 
                        cout << endl << "\t\tYour Name          ------>   " << name << endl;
                        cout << endl << "\t\tYour Table No      ------>   " << table << endl;
                        cout << endl << "\t\tYour Ordered Item  ------>   " << food << endl;
                        cout << endl << "\t\tQuantity Of Item   ------>   " << quan << endl;
                        cout << endl << "\t\tYour Total Bill Is ------>   " << "Rs : " << tbill << endl << endl;
                    }
                    else 
                    {
                        cout << endl << "\n\n\t\t-----> Sorry Your Order Failed <-----\n ";    // if spell is 0 then order failed 
                        cout << endl << "\n\t\tMake Sure You Spell Correctly And Enter Quantity Less Than Quantity Given In Menu \n\n";
                    }

                    cout << endl << "\t\tDo You Want To Order More Items If Yes Then Press 'Y' OtherWise Press 'N' To See Your Total Bill ---->  ";
                    cin >> o;
                } 
                while (o == 'Y' || o == 'y');   
                cout << endl << "\t\tCalculating Your Bill Please Wait...\n";
                cout << endl << "\n\t\tYour Total Bill Is ------>   " << " Rs : " << tbill << endl << endl;

                delete[] item;     // deleting all dynamic memories 
                delete[] price;
                delete[] quantity;
                delete[] totalprice;
            }
            else 
            {
                cout << endl << "\t\tInvalid Input Please Try Again By Entering Valid Input\n\n";
            }
            break;
        }
        case 3:    // if user press 3 then quit 
        {
            cout << endl << "\t\tYou Have Quit \n\t\tQuitting Please Wait...\n\n\t\tQuitting Done\n\n";
            break;
        }
        default: 
        {
            cout << "Invalid Input";
        }
        }
    } 
    while (choice != 3);
}

void order :: scheduleorder() 
{
    
    cout << endl << "\t\t **************************************************************************** \n"
                "\t\t *                                                                          * \n"
                "\t\t *                   WELCOME TO CDS ONLINE SCHEDULE ORDER PORTAL            * \n"
                "\t\t *                                                                          * \n"
                "\t\t **************************************************************************** \n";
                
    string name;              // variables to store data 
    string password;
    string nameinfile;
    string passinfile;
    string nameu; 
    string food;
    string time;
    int quan;
    
    ifstream file("logindetailsofonlineuser.txt");    // opening file in read mode 
    if (!file) 
    {
        cout << "Error in opening file. \n\n";       // error if file not found 
    }
    while (file >> nameinfile >> passinfile);      // reading data from file 
    
    cout << endl << endl;       
    cout << endl << "\t\tTo Place Your Order You First Need To Login With Your Id\n";
    cout << endl << "\t\t-----> So To Proceed Please <----- \n\n";

    cout << endl << "\t\tEnter Your UserName Here ----->  ";   
    cin >> name;    // taking username form user here 
    
    cout << endl << "\t\tEnter Your Password Here ----->  ";
    //cin >> password;    // taking password form user here 
    int ch;
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
    
    char menu; // to see menu                

    bool login = false;
    while (file >> nameinfile >> passinfile) 
    {
    if (name == nameinfile && password == passinfile)    // if details entered match with file details then login 
    {
        login = true;
        break;
    }
    }

    if (login = true)    // if login is 1 then proceed 
    {
        cout << endl << "\t\t-----> Logging In Please Wait <-----\n\n";
        cout << endl << "\t\tYou Have Successfully Logged In To Your ID\n";
        cout << endl << "\t\tNow You Can Schedule Your Order\n\n";
        
        cout << endl << "\t\t  Press 'M' To See CDS Menu \n\n" ;
        cout << endl << "\t\t  Or Press 'E' To Exit ---->  ";
        cin >> menu;
        
        if (menu == 'M' || menu == 'm') 
        {
            cout << endl << "\t\t ---> Available Menu Is <--- \n\n";
            view();            // calling view function of stock class here     
            const int s = 100;           
            char header[50];
            string* item = new string[s];
            double* price = new double[s];
            int* quantity = new int[s];
            int* totalp = new int[s];
            int i = 0;

            fstream file("stock.txt", ios :: in);   // now opening stock fie in read mode 
            if (!file) 
            {
                cout << "Error In Opening File...\n";
            }
            file.getline(header, 50);
            while (file >> setw(21) >> item[i] >> price[i] >> quantity[i] >> totalp[i])    // storing data in variables 
            {
                i++;
            }

            file.close();   // closing file here 

            cout << endl << endl;

            cout << endl << "\t\tPlease Enter Your Name Here ---> ";     // taking name of  orderer
            cin.ignore();
            getline(cin, nameu);
            
            cout << endl << "\t\tEnter Food Name You Want To Order ---> ";  // asking food from orderer 
            getline(cin, food);

            time = getcurrenttime();   // generating time using user class function 

            cout << endl << "\t\tHow Much Quantity You Want Of This Food ---> ";  
            cin >> quan;   // asking quantity from orderer 
            
            bool spell = false;    // spell for checking spelling and quantity 

            for (int k = 0; k < i; k++) 
            {
                if (item[k] == food && quan <= quantity[k])    // if spell and quantity are valid then proceed 
                { 
                    spell = true;
                    break;
                }
            }

            if (spell == true) 
            {
                fstream update("stock.txt", ios::out | ios::trunc);  // opening file again to update it 

                if (!update) 
                {
                    cout << "Error In Opening File...\n";
                } 
                else 
                {
                    update << header << endl;  

                    for (int k = 0; k < i; k++) 
                    {
                        if (item[k] == food && quan <= quantity[k])    
                        {
                            quantity[k] -= quan;   // reducing items here 
                            totalp[k] = price[k] * quantity[k];
                        }
                        update << item[k] << " " << price[k] << " " << quantity[k] << " " << totalp[k] << endl;
                    }
                }
                
                bool found;
                double bill;

                for (int k = 0; k < i; k++) 
                {
                    if (item[k] == food)  // Changed comparison method for string
                    {
                        found = true;
                        bill = price[k] * quan;
                        break;
                    }
                }

                if (found == true)                
                {
                    fstream order("onlineorders.txt", ios::app);   // now opening file in read  mode to save record of schedule orders

                    if (!order) 
                    {
                        cout << endl << "\t\tError In Opening File... \n";  // error if file not found 
                    } 
                    else 
                    {
                        order << nameu << " " << food << " " << quan << " " << time << endl;
                    }

                    cout << endl << endl;
                    cout << endl << " \t\t\t\t  -----> Your Order Details <----- \n\n";   // displaying order  details here 
                    cout << endl << " \t\t\t   Your Name          ------>   " << nameu << endl;
                    cout << endl << " \t\t\t   Your Schedule Time ------>   " << time  << endl;
                    cout << endl << " \t\t\t   Your Ordered Item  ------>   " << food  << endl;
                    cout << endl << " \t\t\t   Quantity Of Item   ------>   " << quan  << endl << endl;
                    cout << endl << " \t\t\t   Your Total Bill Is ------>   " << bill  << endl << endl;
                    cout << endl << " \t\t\t   Scheduling Your Order Please Wait...\n";
                    cout << endl << " \t\t\t   Your Order Is Scheduled \n\n";
                }
            } 
            else 
            {
                cout << endl << "\n\n\t\t-----> Sorry Your Order Failed <-----\n ";
                cout << endl << "\n\t\tMake Sure You Spell Correctly And Enter Quantity Less Than Quantity Given In Menu \n\n";
            }

            delete[] item;    // deleting all dynamic memories 
            delete[] price;
            delete[] quantity;
            delete[] totalp;
        }
    } 
    else 
    {
        cout << endl << "\nPlease Enter Your Correct UserName And Password To Login \n\n";
    }
}

