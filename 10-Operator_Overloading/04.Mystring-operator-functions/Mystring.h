#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
    friend bool operator==(const Mystring &lhs, const Mystring &rhs); //returning element of type bool
    friend Mystring operator-(const Mystring &obj); //returning element of type class
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    Mystring();
    Mystring(const char *s); //overloading constructor
    Mystring(const Mystring &source); //copy constructor (As it has only lhs reference)
    Mystring( Mystring &&source); //Move constructor as it has only rhs reference
    ~Mystring(); //destructor
    
    Mystring &operator=(const Mystring &rhs); //copy assignment
    Mystring &operator=(Mystring &&rhs); //move assignment
   
    void display() const; //getter that displays the string
 
    int get_length() const; //getter returning the string size
    const char *get_str() const;  //getter to return the string
};

#endif // _MYSTRING_H_
