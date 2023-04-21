/*

Add more public methods to an existing class

Given an existing Dog class in Dog.h, add the following public method 
to the class:

get_human_years() return the dog's age * 7

speak()  returns the std::string "Woof"

Please add your code in the Dog.h file.

You can find my solution by clicking on the solution.txt file on the left pane.
But please make sure you give it a go yourself first, and only check the solution 
if you really get stuck.

*/


#ifndef __DOG_H__
#define __DOG_H__
#include <string>
using namespace std;

class Dog {
private:
    string name;
    int age;
public:

    string get_name() {return name; }
    void set_name(string n) {name = n; }
    int get_age() {return age; }
    void set_age(int a) { age = a;}
    //---- WRITE YOUR CLASS FUNCTIONS BELOW THIS LINE----
    int get_human_years(){return age*7;}
    string speak(){return "Woof";}
    
    //---- WRITE YOUR CLASS FUNCTIONS ABOVE THIS LINE----
};
#endif 