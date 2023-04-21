//Short circuiting the logical operator


#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Short circuiting
	// logical "||"(OR)
	int a = 1, b = 1, c = 1;

	// a and b are equal
	if (a == b || c++) {
		cout << "Value of 'c' will"
			<< " not increment due"
			<< " to short-circuit"
			<< endl;
	}
	else {
		cout << "Value of 'c' "
			<< " is incremented as there"
			<< " is no short-circuit"
			<< endl;
	}

	// Short circuiting
	// logical "&&"(OR)

	if (a == b && c++) {
		cout << "Value of 'c' will"
			<< " increment as there"
			<< " is no short circuit"
			<< endl;
	}
	else {
		cout << "Value of 'c' will"
			<< " not increment due to short circuit"
			<< endl;
	}
}
