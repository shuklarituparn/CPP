#include <iostream>
using namespace std;
class Base {
public:
  void greet() {
    cout << "Hello from Base" << endl;
    ;
  }
};
class Derived : Base {
public:
  using Base::greet; //using the function greet from base
  void greet(string s) {
    cout << "Hello from " << s << endl;
    // Instead of recursing, the greet() method
    // of the base class is called.
    greet();   //calling the greet function
  }
};
int main() {
  Derived D;
  D.greet("Derived");
  return 0;
}