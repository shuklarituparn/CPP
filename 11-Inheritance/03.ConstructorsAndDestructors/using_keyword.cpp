#include <iostream>
using namespace std;
class Base {
   public:
      void mulitiplication(int a, int b) {
         cout << "Product: " << a * b << endl;;
      }
};
class Derived : protected Base {
   public:
      using Base::mulitiplication;
};
int main() {
   Derived D;
   // Due to protected inheritance, all the public methods
   // of the base class become protected methods of the
   // derived class. If the using keyword word was not used,
   // calling sum like this would not have been possible.
   D.mulitiplication(10, 20);
   return 0;
}

//here because we used the using keyword we can now use the function multiplication in our class derived

