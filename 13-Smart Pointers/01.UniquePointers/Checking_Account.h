#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account: public Account {    //A interface class of name Checking_account 
private:
    static constexpr const char *def_name = "Unnamed Checking Account";  //each method of the class has static constexpr meaning it is an interface and can be overwritten
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);     
    virtual bool withdraw(double) override;  //virtual function that has override which means that they are using the account interface declared earlier
    virtual bool deposit(double) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Checking_Account() = default;  //using the default keyword here so that we don't accidently delete the main class in place of this derived one
};

#endif // _CHECKING_ACCOUNT_H_
