#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                            // No-args contstructor
    Mystring(const char *s);                         // Overloaded contstructor -expects c style literal
    Mystring(const Mystring &source);        // Copy constructor
    ~Mystring();                                          // Destructor
    void display() const; //display methods that display the strings
    int get_length() const;                           // getters- returns current length of the string
    const char *get_str() const;   //returns the pointer to the string
  
};

#endif // _MYSTRING_H_
