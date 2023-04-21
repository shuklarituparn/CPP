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




