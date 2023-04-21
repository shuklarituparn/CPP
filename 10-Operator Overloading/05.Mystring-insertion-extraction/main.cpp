// Section 14
// Overloaded insertion and extraction operators
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;
    
    cout << "Enter the third stooge's first name: ";
    cin >> curly; //overloading the operator to work with mystring object
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    return 0;
}

/*
No difference in declaring friend class in Private or Public. It just means that a 
friend class will have access to attributes

*/

#include <iostream>
#include <cstring>
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
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
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

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
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

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    //non member function named operator insertion operator that has two arguments
    //first argument is an output stream object by reference :: typed as std ostream

 //second argument is reference to the mystring object whose data we wanna insert into output stream

    os << rhs.str; //if friend function
    //os<<obj.get_str(); if not a friend function, using public getters to get the data
    //important to use ostream reference and not just copy the stream
    return os;  //return the output stream reference
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    //two parameters, first is a reference to an input stream whose type is istream
  //second is the reference in which we wanna extract the data into. Modyfying so no const
    char *buff = new char[1000];//array that holds the data we want to enter to mystring object
    in >> buff; //storing the thing that is in input stream to buffer
    rhs = Mystring{buff}; //updating rhs with buffer and it's using the move operator
    delete [] buff; //deleting the buffer
    return in; //returning the input stream reference
}

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);       // Move assignment
    
    void display() const;
    
    int get_length() const;                                       // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_

/*

Stream insertion and the extraction operator are used to extract or insert

DOn't make sense to implement as Member method

When we overload an operator as a member method, the left hand side object must be the 
object of the classs we're overloading.

This means that we'll have to write larry in the left side

larry<<cout   //doesn't make sense

Overloading as a non-member function
*/