/*
Add an Overloaded Constructor to an Existing Class

Given the Dog class defined in Dog.h, add an overloaded constructor that expect a 
std::string and int as parameters.

The constructor should allow us to create  Dog objects as follows:

    Dog fido {"Fido", 4-Statement and Operators};
    Dog spot {"Spot", 5};

Please add your code to the Dog.h file.

You can find my solution by clicking on the solution.txt file on the left pane. 
But please make sure you give it a go yourself first, and only check the solution
 if you really get stuck.
*/


#ifndef __DOG_H__
#define __DOG_H__
#include <string>

class Dog {
private:
    std::string name;
    int age;
public:

//---- WRITE YOUR OVERLOADED CONSTRUCTOR BELOW THIS LINE----

    Dog(std::string n, int a) {
        name = n;
        age = a;
    }

//---- WRITE YOUR OVERLOADED CONSTRUCTOR ABOVE THIS LINE----
    std::string get_name() {return name; }
    void set_name(std::string n) {name = n; }
    int get_age() {return age; }
    void set_age(int a) { age = a;}
    int get_dog_years() { return age * 7; }
    std::string speak() { return "Woof";}
};
#endif
