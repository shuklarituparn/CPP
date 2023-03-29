
//Overloading operators as Non-Member methods
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class Mystring
{
    //operator are non-member function so need to use friend keyword
    friend Mystring operator-(const Mystring &obj);                                        // make lowercase
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);       // concatenate
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);           // equals
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs) ;           // not equals
    friend bool operator<(const Mystring &lhs, const Mystring &rhs) ;            // less than
    friend bool operator>(const Mystring &lhs, const Mystring &rhs) ;            // greater than
    friend Mystring &operator+=( Mystring &lhs, const Mystring &rhs);          // s1 += s2;  concat and assign
    friend Mystring operator*(const Mystring &lhs, int n) ;                               // s1 = s2 * 3;  repeat s2 n times
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                        // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};


int main() {
    cout << boolalpha << endl; //to print true and false instead of 1 and 0
    
    Mystring larry{"Larry"}; 
    Mystring moe{"Moe"};
    Mystring jenny{"Jenny"};
    Mystring lamb{"lamb"};
    larry+=jenny;
    Mystring S2 {"12345"};
    Mystring S1 {"abc"};

    
    lamb=S2*4;
    cout<<S2<<endl;
    cout<<S1<<endl;

    lamb.display();

    Mystring stooge = larry;

    larry.display();                                                                      // Larry
    moe.display();                                                                      // Moe
    
    cout << (larry == moe) << endl;                                         // false
    cout << (larry == stooge) << endl;                                      // true
    cout << (larry<moe) << endl;             //true
    cout << (larry>moe) << endl;       //false
    larry.display();                                                                    // Larry
    Mystring larry2 = -larry;
    larry2.display();                                                                    // larry
     
    Mystring stooges = larry + "Moe";                                     // ok with member function
    //Mystring stooges = "Larry" + moe;                                 // Compiler error
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();      
                                                   // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                                                        //  Moe Larry Curly
    
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
Mystring &Mystring::operator =( Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


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


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *Mystring::get_str() const { return str; }
 
 Mystring operator-(const Mystring &obj){
    char *buff= new char[std::strlen(obj.str)+1];
    std::strcpy(buff,obj.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;

 }                                     
 Mystring operator+(const Mystring &lhs, const Mystring &rhs){
    
    char *buff= new char [std::strlen(lhs.str)+std::strlen(rhs.str)+1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete []buff;
    return temp;
 }      
 bool operator==(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str));

 }         
 bool operator!=(const Mystring &lhs, const Mystring &rhs){
    return !(std::strcmp(lhs.str,rhs.str));
 }         
 bool operator<(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str));
 }         
 bool operator>(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str));
 }          
 Mystring &operator+=( Mystring &lhs, const Mystring &rhs){
    char *buff= new char[std::strlen(lhs.str)+1];
    std::strcpy(buff, lhs.str);
    delete [] lhs.str;
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;

 }       
 Mystring operator*(const Mystring &lhs, int n){

    Mystring temp;
    for (size_t i =1; i <= n; i++)
    {
        temp= temp+ lhs.str;
    }
    return temp;

 }                             
 

