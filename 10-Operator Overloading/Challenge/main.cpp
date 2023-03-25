// Section 14
// Challenge
#include <iostream>
#include<cstring>
#include "Mystring.h"

using namespace std;

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
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment

    Mystring &operator -(const Mystring &rhs);
    bool operator==(const Mystring &rhs)const;
    bool operator!=(const Mystring &rhs)const;
    bool operator<(const Mystring &rhs)const;
    bool operator>(const Mystring &rhs)const;

    Mystring &operator +(const Mystring &rhs);
    Mystring &operator +=(const Mystring &rhs);
    Mystring &operator *(const Mystring &rhs);
    Mystring &operator +=(const Mystring &rhs);

   
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

int main() {
    
  /* 
    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};

    cout << (a==b) << endl;         // true
    cout << (a!=b) << endl;          // false
    
    b = "george";
    cout << (a==b) << endl;         // false
    //cout << (a!=b) << endl;          // true
    //cout << (a<b) << endl;          // true
    //cout << (a>b) << endl;           // false
    
    Mystring s1 {"FRANK"};
    s1 = -s1;       
    cout << s1 << endl;               // frank              

    //s1 = s1 + "*****";
    //cout << s1 << endl;               // frank*****       
    
    //s1 += "-----";                        // frank*****-----
    //cout << s1 << endl;
    
    //Mystring s2{"12345"};
    //s1 = s2 * 3;
    //cout << s1 << endl;              // 123451234512345
    
    //Mystring s3{"abcdef"};  
    //s3 *= 5;
    //cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef
    
    //Mystring s = "Frank";
    //++s;
    //cout << s << endl;                  // FRANK
    
    //s = -s; 
    //cout << s << endl;                  // frank
    
    //Mystring result;
    //result = ++s;                           
    //cout << s << endl;                  // FRANK
    //cout << result << endl;           // FRANK
    
    //s = "Frank";
    //s++;
    //cout << s << endl;                  // FRANK
    
    s = -s;
    cout << s << endl;                  // frank
    //result = s++;
    //cout << s << endl;                  // FRANK
    //cout << result << endl;           // frank
    */
    
return 0;
}

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
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const{
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}


Mystring& Mystring::operator-(const Mystring &rhs){

    char *buff = new char[std::strlen(rhs.str) + 1];
    strcpy(buff,rhs.str);
    for (size_t i = 0; i < strlen(buff); i++)
    {
        buff[i]= std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete []buff;
    return temp;
}

bool Mystring::operator==(const Mystring &rhs)const{
    if (*this==rhs.str)
    {
       return true;
    }
    else
       return false;
    

}
bool Mystring::operator!=(const Mystring &rhs)const{

    if (*this==rhs.str)
    {
       return false;
    }
    else
       return true;

}

bool Mystring::operator<(const Mystring &rhs)const{



}

bool Mystring::operator>(const Mystring &rhs)const{



}

Mystring & Mystring::operator +(const Mystring &rhs){



}
Mystring & Mystring::operator+=(const Mystring &rhs){



}
Mystring & Mystring::operator *(const Mystring &rhs){



}
Mystring & Mystring::operator +=(const Mystring &rhs){



}
