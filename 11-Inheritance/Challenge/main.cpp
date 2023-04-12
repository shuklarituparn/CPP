// Section 15
// Challenge
#include "Account.h"
#include "Account_Util.h"
#include "Savings_Account.h"
#include <iostream>
#include <vector>

using namespace std;

class Checking_Account : public Account {

private:
  string name_;
  double balance_;
  double fee_;

public:
  Checking_Account();
  Checking_Account(string name, double balace);
  void withdrawal(double amount);
  void deposit(double amount);
  void display(const std::vector<Checking_Account> &accounts);
};
class Trust_Account : public Account {

private:
  string name_;
  double balance_;
  double interest_rate_;

public:
  Trust_Account();
  Trust_Account(string name, double balance);
  void withdrawal(double amount);
  void deposit(double amount);
   void display(const std::vector<Trust_Account> &accounts);
};

int main() {
  cout.precision(2);
  cout << fixed;

  // Accounts
  vector<Account> accounts;
  accounts.push_back(Account{});
  accounts.push_back(Account{"Larry"});
  accounts.push_back(Account{"Moe", 2000});
  accounts.push_back(Account{"Curly", 5000});

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 2000);

  // Savings

  vector<Savings_Account> sav_accounts;
  sav_accounts.push_back(Savings_Account{});
  sav_accounts.push_back(Savings_Account{"Superman"});
  sav_accounts.push_back(Savings_Account{"Batman", 2000});
  sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

  display(sav_accounts);
  deposit(sav_accounts, 1000);
  withdraw(sav_accounts, 2000);
/*
  vector<Checking_Account> check_accounts;
  vector<Trust_Account> trust_accounts;
  check_accounts.push_back(Checking_Account{"HUman", 5000});
  check_accounts.push_back(Checking_Account{});
  withdraw(check_accounts, 1000);
*/

    Checking_Account account1{ "human", 5000};
    account1.withdrawal(2000);
    account1.deposit(3000);
    Trust_Account account2{"richaf", 50000};
    account2.withdrawal(5000);
    account2.deposit(6000);

    cout<<account1;
    cout<<account2;
  return 0;
}

Checking_Account::Checking_Account()
    : name_("no name"), balance_(0.0), fee_(1.50) {}
Checking_Account::Checking_Account(string name, double balance)
    : name_(name), balance_(balance), fee_(1.50) {}
void Checking_Account::withdrawal(double amount) {
  if (balance_ > amount) {
    balance_ = balance_ - (amount + 1.50);
    cout << "Thank you for withdrawing :" << (amount + 1.50) << endl;
    cout << "Your balance is " << balance_ << endl;
  } else {
    cout << "Low funds" << endl;
  }
}

void Checking_Account::deposit(double amount) {
  balance_ = balance_ + amount;
  cout << "Thank you for depositing: " << amount << endl;
  ;
  cout << "You have a balance of: " << balance_ << endl;
}

Trust_Account::Trust_Account()
    : name_{"No name"}, balance_(0.0), interest_rate_(0.01) {}

Trust_Account::Trust_Account(string name, double balance)
    : name_(name), balance_(balance), interest_rate_(0.01) {}
void Trust_Account::withdrawal(double amount) {
  int count = 0;
  if (balance_ > amount && count < 4) {
    if (amount > (0.2 * balance_)) {
      cout << "You can't withdraw this much";
      return;
    } else {
      balance_ = balance_ - amount;
      cout << "Thank you for withdrawing: " << amount << endl;
      cout << "your current balance is: " << balance_ << endl;
      ;
      count++;
    }

  } else {
    cout << "Sorry but you can't withdraw this much" << endl;
  }
}
void Trust_Account::deposit(double amount) {

  if (amount >= 5000) {
    balance_ = balance_ + (amount + 50);
  } else {
    balance_ = balance_ + amount;
  }
  cout << "Thank you for depositing: " << amount << endl;
  cout << "Your balance is: " << balance_ << endl;
}
void display(const std::vector<Checking_Account> &accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}
void display(const std::vector<Trust_Account> &accounts) {
    std::cout << "\n=== Checking Accounts ====================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << acc << std::endl;
}
