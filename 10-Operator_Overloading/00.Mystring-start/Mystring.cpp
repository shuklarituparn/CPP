#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor //It get's called on declaration of Mystring a; when we don't give any value
Mystring::Mystring() 
    : str{nullptr} {  //object that has a pointer in it called str. Initializing that pointer with null
    str = new char[1]; //Instead of leaving, we wanna store '/0' in that to make empty string
    *str = '\0';  //dereferencing the pointer and putting terminator there
}

// Overloaded constructor
Mystring::Mystring(const char *s)  //Example we passing here Mystring a {"Hello"};
    : str {nullptr} {   //checking for the case when our string has  a nullptr
        if (s==nullptr) {
            str = new char[1];  //if it's a nullptr then making it store a terminator
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1]; //allocating +1 character on the heap
            std::strcpy(str, s); //calling strcpy to copy string to str
                                            //don't wanna mess with hello as it is const
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) //source is the object hello
     : str{nullptr} { //initializing with nullptr
        str = new char[std::strlen(source.str )+ 1];//new memory on heap equal to the source string
        std::strcpy(str, source.str); //copying the string-deep copy
}

// Destructor
Mystring::~Mystring() { //deallocating the memory
    delete [] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
 const char *Mystring::get_str() const { return str; }




