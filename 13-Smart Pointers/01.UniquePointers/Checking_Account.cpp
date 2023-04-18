#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)  //overloaded constructor 
    : Account {name, balance} {
}

bool Checking_Account::deposit(double amount) { //deposit method
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount) { //withdrawal method
    amount += per_check_fee;
    return Account::withdraw(amount);
}
 
void Checking_Account::print(std::ostream &os) const {  //print method
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance  << "]";  
}


