// Section 15
// Deriving our First Class

#include <iostream>


using namespace std;

class Account
{
public:
    double balance;        //balance
    std::string name;       //class attributes       
    void deposit(double amount);     //function to show that the deposit amount
    void withdraw(double amount);
    Account();          //constructor
    ~Account();  //destructor
};

class Savings_Account: public Account{      //class savings account that is derived from class accounts and has the public access to it
public:
    double int_rate; //addition to the saving account class from the account class 
    Savings_Account();  //saving account constructor
    ~Savings_Account();   //saving account destructor
    void deposit(double amount);   //a function inside the class
    void withdraw(double amount);  // second function inside the class
};


Account::Account()     //using the constructor to intialize the class with some value
    :  balance{0.0}, name{"An Account"} {
}

Account::~Account()   //after the constructor, calling the destructor
{
}

void Account::deposit(double amount) {    
    std::cout << "Account deposit called with " << amount  << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
}


Savings_Account::Savings_Account()   //constructor calling 
    : int_rate {3.0} {
}

Savings_Account::~Savings_Account() {    //destructor calling 
}

void Savings_Account::deposit(double amount) {
    std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void Savings_Account::withdraw(double amount) {
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}


int main() { 
    
    // Use the Account class
    cout << "\n=== Account ==================================" << endl;
    Account acc {};
    acc.deposit(2000.0);               
    acc.withdraw(500.0);
    
    cout << endl;
    
    Account *p_acc {nullptr};   //creating an object of type pointer of class Account 
    p_acc = new Account();    //Creating a space on the memory
    p_acc->deposit(1000.0);    //assigning value 1000

    /*
(pointer_name)->(variable_name)

Operation: The -> operator in C or C++ gives the value held by variable_name to structure or union variable pointer_name.
Difference between Dot(.) and Arrow(->) operator:  

The Dot(.) operator is used to normally access members of a structure or union.
The Arrow(->) operator exists to access the members of the structure or the unions using pointers.
    */
    p_acc->withdraw(500.0);
    delete p_acc;  //deleting the pointer after using it

// Use the Savings Account class
    
    cout << "\n=== Savings Account ==========================" << endl;
    Savings_Account sav_acc {}; //creating an object of saving account class
    sav_acc.deposit(2000.0);               
    sav_acc.withdraw(500.0);
    
    cout << endl;
    
    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0); //assigning the value of 100 to the pointer 
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;

    cout << "\n==============================================" << endl;
    return 0;
}

