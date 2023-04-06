// Section 14
// Overloading operators as non-member (global) methods
#include <iostream>
#include <vector>
#include "Mystring.h"


using namespace std;

int main() {
    
    Mystring larry {"Larry"};
    larry.display();                                        // Larry
    
    larry = -larry;   //larry1.operator-()
                      //overloading the unary "-" operator that changes it to lowercase
    larry.display();                                        // larry
    
    cout << boolalpha << endl;
    Mystring moe{"Moe"};
    Mystring stooge = larry;
    
    cout << (larry == moe) << endl;             // false, here larry and moe are Mystring objects
    cout << (larry == stooge) << endl;          // true
        
  //  Mystring stooges = larry + "Moe";   
    Mystring stooges = "Larry" + moe;           // Now OK with non-member function
    stooges.display();                                      // LarryMoe
    
    Mystring two_stooges = moe + " " + "Larry";     
    two_stooges.display();                               // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                            // Moe larry Curly             

    return 0;
}

/*

Since these are not member function we don't have the pointer "this" referring to the left 
side of the data

Since we need access to the private attributes in the objects, these non-member function 
should be declared as a friend function of our original class.

Decalring as the friend function will help us to use the getters

In case of the unary operator there's only one parameter, In case of the binary operator
there's two parameters

 
*/