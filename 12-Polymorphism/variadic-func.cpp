// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void print()
{
	cout << "I am empty function and "
			"I am called at last.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	cout << var1 << endl;

	print(var2...);
}

// Driver code
int main()
{
	print(1, 2, 3.14,
		"Pass me any "
		"number of arguments",
		"I will print\n");

	return 0;
}


/*
The compilation of the above code happens like this

Firstly, the compiler resolves the statement into 

cout<< 1 <<endl ;
print(2, 3.14, "Pass me any number of arguments", 
      "I will print\n");

Now, the compiler finds a print() function which can take those arguments and in result executes the variadic print() function again in a similar manner: 

cout<< 2 <<endl ;
print(3.14, "Pass me any number of arguments", 
      "I will print\n");

Again, it is resolved into the following forms : 

cout<< 3.14 <<endl ;
print("Pass me any number of arguments", 
      "I will print\n");

cout<< "Pass me any number of arguments" <<endl ;
print("I will print\n");

cout<< "I will print\n" <<endl ;
print();

Now, at this point, the compiler searches for a function overload whose match is the empty function i.e. the function which has no argument. This means that all functions that have 1 or more arguments are matched to the variadic template and all functions that with no argument are matched to the empty function.

*/

