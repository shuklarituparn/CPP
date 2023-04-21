// C++ Program to demonstrate
// the Virtual Function
#include <iostream>
using namespace std;

// Declaring a Base class
class GFG_Base {

public:
	// virtual function
	virtual void display()
	{
		cout << "Called virtual Base Class function" <<
				"\n\n";
	}

	void print()
	{
		cout << "Called GFG_Base print function" <<
				"\n\n";
	}
};

// Declaring a Child Class
class GFG_Child : public GFG_Base {

public:
	void display()
	{
		cout << "Called GFG_Child Display Function" <<
				"\n\n";
	}

	void print()
	{
		cout << "Called GFG_Child print Function" <<
				"\n\n";
	}
};

// Driver code
int main()
{
	// Create a reference of class GFG_Base
	GFG_Base* base; //base pointer

	GFG_Child child; //child object

	base = &child;  //storing the reference of the child object in the base class

	// This will call the virtual function
	base->GFG_Base::display();  //base pointer calling the display method

    //since the display method is the virtual function so it will call the display in the derived class

	// this will call the non-virtual function
	base->print();  // Print is the non virtual function so it'll print it from the base class
}
