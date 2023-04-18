// Section 17
// Unique Pointers 
#include <iostream>
#include <memory>  //use of the memory library so that we can use the smart pointers 
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main() {
   // Test *t1 = new Test {1000};
   //  delete t1;
//   std::unique_ptr<Test> t1 {new Test{100}};
//   std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
//   
//   std::unique_ptr<Test> t3;
//   t3 = std::move(t1);
//   if (!t1) 
//       std::cout << "t1 is nullptr" << std::endl;
       
       std::unique_ptr<Account> a1 = std::make_unique<Checking_Account> ("Moe", 5000); //creating a unique pointer of the type class and having a name a1. and of object checking account
       std::cout << *a1 << std::endl; //dereferencing the pointer and printing the value
       a1->deposit(5000); //using the pointer to assign the value (or to deposit 5000)
       std::cout << *a1 << std::endl;//dereferencing the pointer and printing the value, it now shows 10000

       std::vector<std::unique_ptr<Account>> accounts;  //creating a vector of unique pointers of the type Account and the name accounts

       accounts.push_back( make_unique<Checking_Account>("James", 1000));//adding the data by just using the vector method of push_back (here making an unique pointer of the object checking_account)
       accounts.push_back( make_unique<Savings_Account>("Billy", 4000, 5.2));//here making the unique pointer of the obejct saving account and initializing it with data
       accounts.push_back( make_unique<Trust_Account>("Bobby", 5000, 4.5));

        for (const auto &acc: accounts)  //dereferencing the pointer and using the auto keyword and printing them
            std::cout << *acc << std::endl;
       return 0;
}

