// Section 14
// Mystring - starting point
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    
    empty.display();  //empty mystring object that calls a no-args constructor
    larry.display(); //larry is mystring object and we initialize it to larry
    stooge.display();  //another object called stooge that we initialize with larry. Using a copy constr.
    
    return 0;
}

