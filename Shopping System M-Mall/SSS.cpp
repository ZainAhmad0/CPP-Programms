#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include<ctime>
#include <stdio.h>
#include <fstream>

using namespace std; 

struct shopitem
{
    string product="";
    int price=0;
};

void welcome()
{
    cout << "\n\n                                     --- WELCOME TO Multan-Mall Shopping Store --- \n\n";
}

void menu(int &op)
{
    cout << "1. User Login" << endl;
    cout << "2. Admin Login " << endl;
    cout << "\nPlease enter Valid option:    ";
    cin >> op;
}

int lenth_of_file_finder()  // it will find the number of lines in the files, so that that number of strings would be created to load all data.
{
    int taker_1;
    taker_1 = 0;
    string temp5 = "";
    ifstream inventory("Inventory.txt", fstream::app);
    while (getline(inventory, temp5))
        ++taker_1;
    return taker_1;

}
int j = 0;
int totalbill = 0;
ofstream cart_2("Cart.txt", ios::trunc);
ifstream cart_1("Cart.txt", ios::trunc);
ofstream receipt("Receipt.txt", ios::trunc);
int cart()
{

    ifstream inventory("Inventory.txt", fstream::app);
    string temp = "";
    int choice_of_user = 0;
    int sr_no = 0;
    int peices = 0;
    int length_f = 0;
    cout << "\nBuy Anything: Press Any Digit                     Go back to User/Admin Login Portal: Press 0     ";
    cin >> choice_of_user;
    cout << endl;
    if (choice_of_user == 0)
    {
        return 1;
    }
    while (choice_of_user != 1000)
    {

        cout << "\nEnter Serial No Of item You Want to buy:     ";
        cin >> sr_no;
        int rs;
        length_f = lenth_of_file_finder();
        if (sr_no > 0 && sr_no <= (length_f / 2))
        {
            cout << "\nNumber Of Peices you want to buy of product Sr.No #" << sr_no << ":      ";
            cin >> peices;
            ifstream inventory("Inventory.txt", fstream::app);
            for (int i = 0; i < length_f; i++)
            {

                getline(inventory, temp);

                if (i == ((sr_no * 2) - 2))
                {

                    fflush(stdin);
                    cart_2 << ++j << ": " << peices << " x " << temp;
                    fflush(stdin);
                    getline(inventory, temp);
                    rs = 0;
                    rs = stoi(temp);
                    rs = rs * peices;
                    totalbill = rs + totalbill;
                    cart_2 << " @ " << rs << endl;
                    break;
                }
            }

            cout << "\n                                           Serial No #" << sr_no << " Product Added to Cart " << endl << endl;
        }
        else
        {
            cout << "\nYou Entered Invalid Serial No. Please Re-Enter Correct Serial Number" << endl << endl;
            continue;

        }

        cout << "\n1: Want To buy more: Press 0\n2: View Current cart & buy again: Press 2\n3: Print Receipt: Press 4\n4: Exit : Press Any digit Other Than 0,2,4" << endl;
        cin >> choice_of_user;
        cout << endl;
        if (choice_of_user == 0)
        {
            continue;
        }
        else if (choice_of_user == 2)
        {
            ifstream cart_1("Cart.txt", ios::app);
            while (!cart_1.eof())
            {
                getline(cart_1, temp);
                cout << temp << endl;
            }
            continue;
        }
        else if (choice_of_user == 4)
        {

            cout << "\n\n                                   ---  Multan-Mall Shopping Store --- \n";


            receipt << "                                             ---  Multan-Mall Shopping Store --- \n" << endl;
            time_t tt;
            // Declaring variable to store return value of
            // localtime()
            struct tm * ti;
            // Applying time()
            time (&tt);
            // Using localtime()
            ti = localtime(&tt);

            cout << "\nCurrent Day, Date and Time is = "<< asctime(ti)<<endl;



            receipt << endl<<"Current Day, Date and Time is = "<< asctime(ti)<< endl;
            receipt << endl;
            receipt << "Details of Product Listed Below" << endl << endl;
            cout << "Details of Product Listed Below" << endl << endl;
            ifstream cart_1("Cart.txt", ios::app);
            ofstream reorder;
            int i=3;
            reorder.open("reorder.txt", ios::app);
            while (!cart_1.eof())
            {
                getline(cart_1, temp);
                cout << temp << endl;
                receipt << temp << endl;
                temp[0]=' ';temp[1]=' ';temp[2]=' ';
                reorder << temp << endl;
            }
            receipt << endl << "Total Bill:  Rs " << totalbill << " Only" << endl;
            cout << endl << "Total Bill:  Rs " << totalbill << " Only" << endl;
            cout << "Thank you For Shopping from Multan-Mall Shopping Store" << endl;
            receipt << "Thank you For Shopping from Multan-Mall Shopping Store" << endl;
            cout << "                                       ----------------------------------" << endl;
            receipt << "                                       -----------------------------------" << endl;
            string line;
            float profit=0;
            float const profitval=0.3;
            ifstream Pfile("profit.txt",ios::app);

            profit = (float(totalbill)*profitval);
            for(int i=0; i<9; i++)
            {
                Pfile>>temp;
            }
            Pfile>>temp;
            profit=profit+stoi(temp);
            ofstream profitfile ("profit.txt");
            profitfile << "Your total Profit of complete current sale is: "<<profit<<endl;
            return 0;
        }
        choice_of_user = 1000;

    }




}

void profit()
{
    string str="";
    ifstream profitfile;
    profitfile.open("profit.txt",ios::app);
        getline(profitfile, str);
        cout << endl<<str << endl;
        cout<<endl<<"                                                     --- "<<endl;
}

void reorder()
{
    string str="";
    ifstream reorderfile;
    reorderfile.open("reorder.txt");
    while (!reorderfile.eof())
    {
        getline(reorderfile, str);
        cout << str << endl;
    }
       cout<<endl<<"                                                     --- "<<endl;
    reorderfile.close();
}



int userlogin()
{
    int k=1;
    int j=0;
    fflush(stdin);
    ifstream userfile("userID.txt", fstream::app);

    string userid="", userpass_temp="",userpass="", str="", pass="";
    bool success = false;
    cout << "\nEnter Numeric User ID:   ";
    cin>> userid;
    fflush(stdin);
    cout << "Enter Password:    ";
   char ch;
   ch = _getch();
   while(ch != 13) {//character 13 is enter
      userpass.push_back(ch);
      cout << '*';
      ch = _getch();
   }

    if (!userfile.is_open())
    {
        cout << "Sorry, File failed to open" << endl;

    }
    while (!userfile.eof())
    {
        fflush(stdin);
        getline(userfile, str);
        if (userid == str)
        {
            getline(userfile, pass);
            if (userpass == pass)
            {
                cout << "\n                       ------- USER LOGIN SUCCESSFUL ------- \n" << endl;
                success = true;
            }
            break;
        }
    }
    if (!success)
    {
        cout << "\nSorry Login Failed, You have entered Invalid credentials. Please try again .... \n" << endl;
        return 0;
    }
    return 1;
}

int adminlogin()
{
    fflush(stdin);
    string adminid, adminpass, str, pass;
    bool success = false;
    cout << "\nEnter Numeric Admin ID:    ";
    cin >> adminid;
    fflush(stdin);
    cout << "Enter Password:   ";
       char ch;
   ch = _getch();
   while(ch != 13) {//character 13 is enter
      adminpass.push_back(ch);
      cout << '*';
      ch = _getch();
   }

    ifstream adminfile;
    adminfile.open("adminID.txt", fstream::app);


    if (!adminfile.is_open())
    {
        cout << "\nSorry, File failed to open" << endl;

    }
    while (!adminfile.eof())
    {
        getline(adminfile, str);
        if (adminid == str)
        {
            getline(adminfile, pass);
            if (adminpass == pass)
            {
                cout << "\n                       ------- ADMIN LOGIN SUCCESSFUL ------- \n" << endl;
                success = true;
            }
            break;
        }
    }
    if (!success)
    {
        cout << "\nSorry Login Failed, You have entered Invalid credentials. Please Try again...\n" << endl;
        return 0;
    }
    return 1;

}

void inventory()
{
    int size_of_inventory = 0;
    size_of_inventory = lenth_of_file_finder();
    string *info_inventry1_product = new string[size_of_inventory];
    string *info_inventry_price = new string[size_of_inventory];

    ifstream inventoryy;
    inventoryy.open("Inventory.txt", fstream::app);


    if (!inventoryy.is_open())
    {
        cout << "\nSorry, File failed to open" << endl;
        delete[]info_inventry1_product;
        delete[]info_inventry_price;
        return;
    }
    cout << "                      Here are the some products we are offering " << endl;
    cout << "\nProduct Name " << "                    " << "Product Price ( Rs )" << endl;

    int i = 0;
int lengthh=0;
int var=0;
    for (int i = 0; i < (size_of_inventory / 2); i++)
    {
        getline(inventoryy, info_inventry1_product[i]);
        cout << endl << i + 1 << ": " << info_inventry1_product[i];
        lengthh=0;
var=0;
        lengthh=info_inventry1_product[i].length();
        if(lengthh<=15)
            {
                while(lengthh!=15)
                {
                    lengthh++;
                    var++;
                }
                var=var+20;
                for(int i=0; i<var; i++)
                    cout<<" ";
            }
            else if(lengthh>15)
            {
                while(lengthh!=15)
                {
                    lengthh--;
                    var++;
                }
                var=20-var;
                for(int i=0; i<var; i++)
                    cout<<" ";
            }
        getline(inventoryy, info_inventry_price[i]);
        cout << info_inventry_price[i] << endl;
    }
    cout << endl << endl;
    cout << "                                                   ****************\n\n" << endl;
    delete[]info_inventry1_product;
    delete[]info_inventry_price;
}

void EDITinventory()
{
    ofstream inventoryfile;
    inventoryfile.open("Inventory.txt", fstream::app);
    inventoryfile.seekp(0, ios::end); // it is used that every time new data would be entered, it will start entering from the end line of the file.

    int admin_choice;
    int size = 0;

    cout << "\n\n";

    cout << "1: Add Item in inventory" << endl;
    cout << "2: Delete Item in inventory" << endl;
    cout << "3: Edit Item in Inventory" << endl;
    cout << "4. View Profit" << endl;
    cout << "5. View items to be reordered" << endl << endl;
    cout << "Please Enter Your choice Admin:     ";

    cin >> admin_choice;

    switch (admin_choice)
    {
    case 1:
    {
        cout << "\nHow many items you want to enter admin:     ";
        cin >> size;
        cout << endl;
        shopitem *info = new shopitem[size];
        inventoryfile.seekp(0, ios::end);
        for (int i = 0; i < size; i++)
        {
            inventoryfile.seekp(0, ios::end); // it is used that every time new data would be entered, it will start entering from the end line of the file.
            fflush(stdin);
            cout << "Enter #" << i + 1 << " product name:   ";
            getline(cin, info[i].product);
            inventoryfile << info[i].product << endl;
            fflush(stdin);
            cout << "Enter #" << i + 1 << " Price in Rs:    ";
            cin >> info[i].price;
            inventoryfile << info[i].price << endl;
            cout << endl;
        }
        cout << endl << endl << "                                         --- " << size << " Items Successfully Entered In The Inventory ---" << endl;
        break;
    }
    case 2:
    {
        int choice = 0;
        int length = 0;
        cout << endl << "Enter Serial No Of the item:    ";
        cin >> choice;
        length = lenth_of_file_finder();
        string *info_file = new string[length];
        if (choice > 0 && choice <= (length / 2))
        {
            ifstream inventoryy("Inventory.txt", fstream::app);

            for (int counter_for_file = 0; counter_for_file < length; counter_for_file++)
            {
                fflush(stdin);
                getline(inventoryy, info_file[counter_for_file]);

            }  // this loop will fill all the data of the files in the strings.

        }
        else
        {
            cout << "\nInvalid Serial Number Entered " << endl << endl;
            return;
        }


        info_file[(choice * 2) - 1] = "";
        info_file[(choice * 2) - 2] = "";
        ofstream inventoryy("Inventory.txt", fstream::trunc);

        for (int counter_for_file = 0; counter_for_file < length; counter_for_file++)
        {
            if (counter_for_file == ((choice * 2) - 1) || counter_for_file == ((choice * 2) - 2))
            {
                continue;
            }
            inventoryy << info_file[counter_for_file] << endl;

        }
        cout << endl << endl << "                                         --- Item Successfully Deleted from The Inventory ---" << endl;
        break;

    }

    case 3:
    {
        int choice = 0;
        int length = 0;
        cout << endl << "Enter Serial No Of the item:    ";
        cin >> choice;
        length = lenth_of_file_finder();
        string *info_file = new string[length];
        if (choice > 0 && choice <= (length / 2))
        {
            ifstream inventoryy("Inventory.txt", fstream::app);

            for (int counter_for_file = 0; counter_for_file < length; counter_for_file++)
            {
                fflush(stdin);
                getline(inventoryy, info_file[counter_for_file]);

            }  // this loop will fill all the data of the files in the strings.

        }
        else
        {
            cout << "\nInvalid Serial Number Entered " << endl << endl;
            return;
        }
        fflush(stdin);
        cout << "\n\nEnter #" << choice << " product name:     ";
        getline(cin, info_file[(choice * 2) - 2]);
        fflush(stdin);
        cout << "\nEnter #" << choice << " Price:     ";
        getline(cin, info_file[(choice * 2) - 1]);
        ofstream inventoryy("Inventory.txt", fstream::trunc);

        for (int counter_for_file = 0; counter_for_file < length; counter_for_file++)
        {
            inventoryy << info_file[counter_for_file] << endl;

        }
        cout << endl << endl << "                                         --- Item Successfully Update in The Inventory ---" << endl;
        break;
    }

    case 4:
    {
        profit();
        break;
    }
    case 5:
    {
        reorder();
        break;
    }
    default:
    cout<<"\nInvalid Choice Entered ... "<<endl;

    }  // switch end bracket
}
void AgainAdminChoice()
{
    int option=1;
    cout<<"\n - Stay in Admin Portal : Press 1\n - Go Back To Main Menu: Press 0"<<endl;
    cin>>option;
    cout<<endl;
    while(option!=0)
    {
        inventory();
        EDITinventory();
    cout<<"\n - Stay in Admin Portal : Press 1\n - Go Back To Main Menu: Press 0"<<endl;
    cin>>option;
    cout<<endl;
    }
}



int main()
{

    int op = 1;
    welcome();
    while (op == 1 || op == 2)
    {
        menu(op);
        if (op == 1)
        {
            if (userlogin() == 1)
            {
                inventory();
                op = cart();
            }

        }
        else if (op == 2)
        {
            if (adminlogin() == 1)
            {
                inventory();
                EDITinventory();
                AgainAdminChoice();
            }

        }

    }
    return 0;
}
