// C++ program to show Arrow operator
// used in structure
#include <iostream>
using namespace std;

// Creating the union
union student {
	char name[80];
	int age;
	float percentage;
};

// Creating the union object
union student* emp = NULL;

// Driver code
int main()
{
	// Assigning memory to struct variable emp
	emp = (union student*)
		malloc(sizeof(union student));

	// Assigning value to age variable
	// of emp using arrow operator
	emp->age = 18;

	// DIsplaying the assigned value to the variable
	cout <<""<< emp->age;
}


