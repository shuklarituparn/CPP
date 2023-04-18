#include "Account.h"

Account::Account(std::string name, double balance) //default constructor
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {  //deposit method
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {  //withdrawal method
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

void Account::print(std::ostream &os) const  {   //print method
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}

