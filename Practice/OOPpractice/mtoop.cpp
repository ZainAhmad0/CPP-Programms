#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    float accountBalance;
    string accountHolderName;
    string dateOfOpeningAcc;
    string accountType;
public:
    Bank();
    Bank(float,string);
    void deposit(float);
    void withdraw(float);
    virtual void calculateProfit();
    float getAccountBalance();
    string getAccountHolderName();
    void addProfitToSavingAccount(float);
    void setAccountType(string);
    string getAccountType();
};

Bank :: Bank()
{
    accountBalance=0;
    dateOfOpeningAcc= "1/1/2000";
}

Bank :: Bank(float balance,string date)
{
    accountBalance=balance;
    dateOfOpeningAcc=date;
}

void Bank :: deposit(float addBalance)
{
    accountBalance+=addBalance;
}

void Bank :: withdraw(float deductBalance)
{
    if(accountBalance>=deductBalance)
    {
        accountBalance=accountBalance-deductBalance;
    }
    else
    return ;
}

void Bank :: calculateProfit()
{

}

float Bank :: getAccountBalance()
{
    return accountBalance;
}

string Bank :: getAccountHolderName()
{
    return accountHolderName;
}

void Bank :: addProfitToSavingAccount(float addProfit)
{
    accountBalance+=addProfit;
}

class SavingAccount : public Bank
{
public:
    void calculateProfit();    
};

void Bank :: setAccountType(string typeOfAccount)
{
    accountType=typeOfAccount;
}

string Bank ::  getAccountType()
{
    return accountType;
}

void SavingAccount :: calculateProfit()
{
    float tempBalance;
    tempBalance = Bank::getAccountBalance();
    float profit;
    profit = (((tempBalance)/100)/5); 
    Bank::addProfitToSavingAccount(profit);    
}

int main()
{
    int choice;
    Bank *obj = new Bank [100];
    cout<<"1 : Create Account (Max upto 100 accounts)"<<endl;
    cout<<"2 : Deposit Amount"<<endl;
    cout<<"3 : Withdraw money"<<endl;
    cout<<"4 : Show Accounts "<<endl;
    cout<<"Please Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            string name="";
            string dateOfOpeningAccount="";
            string accountType="";
            cout<<"Enter Name : ";
            getline(cin,name);
            cout<<"Enter Date Of Opening Account (dd/mm/yy) : ";
            getline(cin,dateOfOpeningAccount);
            cout<<"Enter Account Type (Current/Saving) : ";
            getline(cin,accountType);
             
        }
    }
    
}
