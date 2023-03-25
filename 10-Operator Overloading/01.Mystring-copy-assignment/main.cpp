// Section 14
// Overloading copy assignment
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring a {"Hello"};     //overloaded constructor

    /*
     * Here object that has  a str attribute that's a pointer and the str
     * will be pointing to "Hello"
     */

    Mystring b;  // no-args contructor

    /*
    It calls a no-args constructor and points to an empty string containing a null terminator
    */

    b = a;      // b.operator=(a)

/*
 *   // copy assignment
 *
 *   We want b to copy the hello element but not like the shallow copy
 *   when we point to the same place of the memory that's taken
 *
 *  First step is to de-allocate the string and then create a new space on the string that's n+1
 *  element big
 *
 */

    b = "This is a test";  // b.operator=("This is a test");

    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    Mystring stooges;                   // no-args constructor
    
    empty = stooge;                     // copy assignment operator
    
    empty.display();                      // Larry : 5
    larry.display();                         // Larry : 5
    stooge.display();                     // Larry : 5
    empty.display();                      // Larry : 5
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();                              // Larry, Moe, and Curly : 21
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                        // Larry
                                                                // Moe
                                                                //Curly
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";                              // copy assignment
        
    cout << "=== Loop 3 ================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                     // Changed
                                                            // Changed
                                                            // Changed
    
    return 0;
}

#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment" << std::endl;

    /*
     * //object on lhs is referred by this pointer while the object in the right is passed as RHS.
                    //since we are right hand side to the left hand side we must do a deep copy of rhs attribute and copy them to LHS
            //this will get overwritten so we need to deallocate anything referred by it on the heap
     */
    if (this == &rhs) //comparing for self assignment- if both the element are same. comparing address
        return *this;     //if both the object are same then we just return the object
    delete [] this->str; //deallocate the storage for this string since it's pointing to a string on string/
    str = new char[std::strlen(rhs.str) + 1]; //allocating the data on the string that is 1 more than the string
    std::strcpy(this->str, rhs.str);  //now just copying the string
    return *this;  //return the current by reference to allow chain assignment
                   //if the program has multiple raw pointer then need to deepcopy all
                   //cannot use just "this" as this is a pointer and the program expects a reference
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }




#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs); /*
 *  // Copy assignment
 *
 *  right hand side = const Mystring &rhs //we want const as we don't wanna mess with it
 *
 */
    
    void display() const;

    int get_length() const;                                       // getters
    const char *get_str() const;

};

#endif // _MYSTRING_H_
