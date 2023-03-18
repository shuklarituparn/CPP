#include <iostream>
#include <cstring>
#include <cctype> //for tolower
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
        str = new char[std::strlen(source.str)+ 1];
        std::strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment operator
Mystring &Mystring::operator=( Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *Mystring::get_str() const { return str; }


// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {  //passing reference of both side
  //we're declaring the constructor as not as the member function that's why taking both side
    return (std::strcmp(lhs.str, rhs.str) == 0); //comparing it to 0 to return true or false 
    //if string is same then 0=0 true. If it's not then anything comparing to 0 will give false
}

// Make lowercase
Mystring operator-(const Mystring &obj) {  
    char *buff = new char[std::strlen(obj.str) + 1]; //area on memory to store the lowercase 
                                            //copy of the the string
    std::strcpy(buff, obj.str);  //copy the string
    for (size_t i=0; i<std::strlen(buff); i++)  //looping through the buffer (buff-copy of the usr given string)
        buff[i] = std::tolower(buff[i]); //converting buffer to lower case
    Mystring temp {buff}; //return temporary Mystring object using this buffer
    delete [] buff; //deleting buffer to not leake memory
    return temp; //return the object temp
}

// Concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str); //copying the lhs string to buff
    std::strcat(buff, rhs.str);  //concatenating the rhs string to buff
    Mystring temp {buff};
    delete [] buff;
    return temp;
}






