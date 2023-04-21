// Section 15
// Base class initialization
#include <iostream>

using namespace std;

class Base {
private:
  int value;

public:
  Base() : value{0} { cout << "Base no-args constructor" << endl; }
  Base(int x) : value{x} {
    cout << "Base (int) overloaded constructor" << endl;
  }
  ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
private:
  int doubled_value;

public:
  Derived() : Base{}, doubled_value{0} {  //derived class is initialized with base class constructor with value 0
    cout << "Derived no-args constructor " << endl;
  }
  Derived(int x) : Base{x}, doubled_value{x * 2} {
    cout << "Derived (int) constructor" << endl;
  }
  ~Derived() { cout << "Derived destructor " << endl; }
};

int main() {
    Derived d;
  //Derived d{1000};
  return 0;
}

/*
OUTPUT:

Base no-args constructor
Derived no-args constructor 
Derived destructor 
Base destructor

*/

/*

Here the base class constructor is called first and then its used to iniatialize the derived class constructor.

Now after the derived class goes out of the scope the destructor for the derived class is called. Now when the derived class is gone, and there's no use of the base class constructor it's destructor is called


*/