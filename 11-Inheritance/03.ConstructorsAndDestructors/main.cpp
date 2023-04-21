// Section 15
// Constructors and Destructors
#include <iostream>

using namespace std;

class Base {
private:
  int value;

public:
  Base() : value{0} { cout << "Base no-args constructor" << endl; }  //default constructor
  Base(int x) : value{x} {  //overloaded constructor
    cout << "Base (int) overloaded constructor" << endl;
  }
  ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
  using Base::Base;

private:
  int doubled_value;

public:
  Derived() : doubled_value{0} {
    cout << "Derived no-args constructor " << endl;
  }
  Derived(int x) : doubled_value{x * 2} {
    cout << "Derived (int) overloaded constructor" << endl;
  }
  ~Derived() { cout << "Derived destructor " << endl; }
};

int main() {
    Base b;
 //Base b{100};
  Derived d;
  //Derived d{1000}; //here we a

  return 0;
}

/*
Output:

Base no-args constructor
Base no-args constructor
Derived no-args constructor 
Derived destructor 
Base destructor
Base destructor
*/

/*
here because of the "using" keyword that imports the constructor of the class base in the derived one we can see that the destructor is called two times


*/