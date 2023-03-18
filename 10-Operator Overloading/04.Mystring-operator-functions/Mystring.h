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
    Mystring(const Mystring &source);
    Mystring( Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
   
    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif // _MYSTRING_H_
