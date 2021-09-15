#include<iostream>
using namespace std;

class Account{                             //abstract class
	public:
		virtual void bank()=0;          //pure virtual function
};

class Bank:public Account
{
private:
    char BankId[5];
    char name[10];
    char loc[20];

public:
	void bank()
{
	cout<<"class account started"<<endl;
}
    void OpenAccount()
    {
        cout<<"Enter Account ID: ";
        cin>>BankId ;
        cout<<"Enter First Name: ";
        cin>>name;
        cout<<"Enter branch location: ";
        cin >>loc;
        
        cout<<"\naccount created successfully\n";
    }
    void ShowAccount()
    {
    	cout<<"\ndetails of account are :\n";
        cout<<"\nAcc ID:"<<BankId;
        cout<<"\nFirst name:"<<name;
        cout<<"\nBranch location:"<<loc;
        
    }
};

class Customer:virtual public Account
{
	private:
		long int Id;
		char name[10];
		char address[20];
		int phno;
		char acc[10];
	
public:
	
	int balance;
	Customer():balance(10){}
		
	void bank()
	{
	cout<<"class customer started"<<endl;
	}
 
	void DoGeneralEnquiry(){
		cout<<"\nEnter your bank Id (number):";
		cin>>Id;
		cout<<"\nEnter your name: ";
		cin>>name;
		cout<<"\n Enter your address city: ";
		cin>>address;
		cout<<"\ninformation updated !\n";
	}
	
	void DepositMoney(){
		long amt;
        cout << "Enter Amount U want to deposit? ";
        cin >> amt;
        balance = balance + amt;
        cout<<"\namount deposited succesfully\n";
        cout<<"\nbalance amount in account: "<<balance<<endl;
        
	}
	
	void WithdrawMoney(){
		long amt;
		
        cout<<"Enter Amount U want to withdraw? ";
        cin>>amt;
        
        if(amt <= balance)
        {
        balance = balance - amt;
        cout<<"\namount debited!"<<endl;
        cout<<"\nbalance amount: "<<balance<<endl;
    }
        else
            cout<<"Less Balance, cannot withdraw" << endl;
	}
	friend void moneyleft(float money,int balance);
};

class Employee{
int Id;
char name[10];
float money;

public:
	void CollectMoney(){
		cout<<"\nenter money to be collected:";
		cin>>money;
		cout<<"money collected successfully\n";
	}
	void OpenAccount(){
		cout<<"\n open your account:";
		cout<<"\n enter initial value:";
		cin>>money;
		
		if (money>0)
		{
		cout<<"\n congratulations!!";
		}
		else (money==0);
		{
			cout<<"\n account has no money";
		}
	}
	friend void moneyleft(float money,int balance);
};

void moneyleft(float money,int balance){
	balance= balance-money;
	cout<<"\n balance money :"<<balance<<endl;
}

int main()
{
   int c;
   Bank b;
   Customer t;
   Employee e;
   
   cout<<"Aarushi Kumar\tA2305219401\n";
   do{
   cout<<"\n 1. open account \n\n2. show account \n\n 3.enquiry\n\n 4.deposit money \n\n 5.withdraw money\n\n 6.collect money\n\n 7. open account \n\n8.exit"<<endl;
   cout<<"\n\n enter your choice";
   cin>>c;
   switch(c)
   {
        case 1:
        	b.OpenAccount();
            break;
        case 2:
        	b.ShowAccount();
        	break;
        case 3:
        	t.DoGeneralEnquiry();
        	break;
        case 4:
        	t.DepositMoney();
        	break;
        case 5:
        	t.WithdrawMoney();
        	break;
        case 6:
        	e.CollectMoney();
        	break;
        case 7:
        	e.OpenAccount();
        	break;
        case 8:
        	cout<<"have a nice day"<<endl;
        	break;
        default:
        cout<<"\n\nwrong option";
    }
} while (c != 8);
    return 0;
    
}
