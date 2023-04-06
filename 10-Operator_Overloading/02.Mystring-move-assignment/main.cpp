// Section 14
// Overloading move constructor and move assignment operator
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    
    Mystring a{"Hello"};
                    // Overloaded constructor
        //it will create an object called a that will store the pointer of type str to "Hello"
    //in the file Mystring.h we declared it in the private section of the class as char *str
    a = Mystring{"Hola"};             
                 // Overloaded constructor then move assignment
        //delete the "hello" point to "Hola" and nullify the pointer pointing to "Hola" 
        //also the destructor gets called after we finish with this
    a = "Bonjour";                         // Overloaded constructor then move assignment

    //after we store bonjour in our "this" the destructor gets called after we exit the main
    
 
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    Mystring stooges;                   // no-args constructor
    
    empty = stooge;                     // copy assignment operator
                                                  // stooge is an l-value
                                //we use the copy when given an l-value
    
    empty = "Funny";                    // move assignment operator
                                                  // "Funny" is an r-valueso using move
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();
    
    vector<Mystring> stooges_vec; //vector of type class Mystring of name stooges_vec
    stooges_vec.push_back("Larry");                // Move constructor
    stooges_vec.push_back("Moe");                // Move constructor
    stooges_vec.push_back("Curly");              // Move constructor    
    
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) //passing the reference of type Myclass and iterating on vectors
        s.display();
        
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";                                      // move assignment
            //passing the reference of type class and actually assigning an r-value
        
    cout << "=== Loop 3 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();
        
    
    return 0;
}

//In the end the destructor for every class member gets called

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
//Overloading a constructor means using the same name to do many functions
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
//Constructor not an assigment that means it makes a new object based on rvalue reference
Mystring::Mystring( Mystring &&source) 
    :str(source.str) { //taking source str pointer and moving it to str
        source.str = nullptr; //nullifying the source string pointer
        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    if (str == nullptr) {
        std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    } else {
         std::cout << "Calling destructor for Mystring : " << str << std::endl;
    }
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
//no const as we wanna modify the right hand attribute
Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) //checking the self-assignment
        return *this;  //return if same
    delete [] str;  //delete the str from the current object
    str = rhs.str; //store the pointer of rhs to the lhs
    rhs.str = nullptr; //nullify the rhs pointer
    return *this;     //returning the pointer
    
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
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);        // Move assignment
    
    void display() const;
    
    int get_length() const;                                       // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_

//In the private area we have the type and in Public the operations with it



