// Section 14
// Overloading operators as member methods
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class Mystring{
private:
    char *str;      // pointer to a char[] that hold a C-style string
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
public:
    Mystring();                                                          // No-args constructor
    Mystring(const char *s);                                      // Overloaded constructor
    Mystring(const Mystring &source);                     // Copy constructor
    Mystring( Mystring &&source);                          // Move constructiror
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);    // Copy assignment
    Mystring &operator=(Mystring &&rhs);          // Move assignment

    Mystring operator-() const;                             // make lowercase
    Mystring operator+(const Mystring &rhs) const;        // concatenate
    bool operator==(const Mystring &rhs) const; //const method as don't wanna change anything
    
    bool operator<(const Mystring &rhs)const;
    bool operator>(const Mystring &rhs)const;

    Mystring &operator +=(const Mystring &rhs);
    Mystring operator*(int n) const;   //const as we are not modifying the output
    Mystring& operator*=(int n);  //overloading the *= operator
    
    void display() const;

    int get_length() const;                                        // getters
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

    S1*=4;
    
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

bool Mystring::operator<(const Mystring &rhs)const{

if (std::strcmp(str,rhs.str)<0)
{
    return true;
}
else 
    return false;



}
bool Mystring::operator>(const Mystring &rhs)const{

if (std::strcmp(str,rhs.str)>0)
{
    return true;
}
else
    return false;
}

Mystring & Mystring::operator +=(const Mystring &rhs){

std::strcat(str, rhs.str);
return *this;

}

Mystring Mystring::operator*(int n) const{

    Mystring temp;

    for (size_t i = 1; i <= n; i++)
    {
        temp= temp+ *this;
    }
    return temp;

}


// Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Make lowercase
Mystring Mystring::operator-() const {//expect no parameters and is const
    char *buff= new char[std::strlen(str) + 1];//area on memory to store the lowercase 
    std::strcpy(buff, str);//copy the string
    for (size_t i=0; i<std::strlen(buff); i++)//looping through the buffer (buff-copy of the usr given string)
        buff[i] = std::tolower(buff[i]);//converting buffer to lower case
    Mystring temp {buff};//return temporary Mystring object using this buffer
    delete [] buff;//deleting buffer to not leake memory
    return temp;//return the object temp
}

// Concatentate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
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

Mystring& Mystring::operator*=(int n){
     for (size_t i = 1; i <=n; i++)
     {
        *this = *this*n;
     }
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




/*

Unary operators as the member methods

Unary operators work with one operand

++, --, -, !

*****************************SYNTAX********************************

ReturnType Type::operatorOp();
*/

