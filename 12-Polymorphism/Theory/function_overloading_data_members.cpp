// C++ program for function overriding with data members
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;
class Animal {								 // base class declaration.
	public:
	string color = "Black";	
};	
class Dog: public Animal					 // inheriting Animal class.

                                            //inheriting the public attribute called color
{	
public:
	string color = "Grey";	
};
//Driver code
int main(void) {
	Animal d= Dog(); //accessing the field by reference variable which refers to derived
    Dog e;
    //Dog f= Animal();   can't bind the base class to the derived class
	cout<<d.color<<endl;  //object of the class Animal
    cout<<e.color<<endl;	//object of class Dog will be of color grey
}
