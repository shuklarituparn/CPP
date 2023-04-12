// C++ program for function overriding
#include <bits/stdc++.h>
using namespace std;

class base {
public:
	virtual void print()
	{
		cout << "print base class" <<
				endl;
	}

	void show()
	{
	cout << "show base class" <<
			endl;
	}
};

class derived : public base {
public:

	// print () is already virtual function in
	// derived class, we could also declared as
	// virtual void print () explicitly
	void print()	
	{
		cout << "print derived class" <<
				endl;
	}

	void show()
	{
	cout << "show derived class" <<
			endl;
	}
};

// Driver code
int main()
{
	base* bptr; //base class pointer 
	derived d;  //derived class object d
	bptr = &d; //base class pointer is pointer is pointing to the derived class object d

	// Virtual function, binded at
	// runtime (Runtime polymorphism)
	bptr->print();

    /*
    Here as the function print is declared as Virtual so it can be overriden by the derived class. If a derived class overrides the virtual function then the overriden function will be called based on the type of the object being pointed to

    */

	// Non-virtual function, binded
	// at compile time
	bptr->show();

/*

If a member function is not declared as virtual then it is a non-virtual. When a non-virtual function id callled using a pointer to the base class object that points to the derived class object.

Here the function show() is non-virtual function in the base class "base"
Therefore the function call at compile time and resolved on the type of the pointer which is of the class "base" That's why it the show function of the base class is called

*/
	return 0;
}
