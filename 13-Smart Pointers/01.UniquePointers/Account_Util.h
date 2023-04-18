#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"

// Utility helper functions for Account * class

void display(const std::vector<Account *> &accounts);  //display method 
void deposit(std::vector<Account *> &accounts, double amount);  //deposit method
void withdraw(std::vector<Account *> &accounts, double amount);  //withddrawal method

#endif