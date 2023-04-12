// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    // Account(std::string name = "Unamed Account", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};
#endif

/*
The static keyword makes the variable a static class variable, which means that it is shared among all instances of the class, and its lifetime extends beyond the lifetime of any individual object.

The constexpr keyword indicates that the variable is a compile-time constant, which means that its value can be determined at compile-time rather than at runtime.

The const char* type indicates that the variable holds a pointer to a constant character array, which in this case is the string "Unnamed Account".



*/