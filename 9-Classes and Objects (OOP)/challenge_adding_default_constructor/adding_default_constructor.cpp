/*
Add a Default Constructor to an Existing Class

Given the Dog class in Dog.h, add a default no-args constructor that initializes 
the dog's name to "None" and the dog's age to zero.

Please add your code to the Dog.h file.

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
//---- WRITE YOUR NO-ARGS CONSTRUCTOR BELOW THIS LINE----
Dog(){
    name="None";
    age=0;
}


//---- WRITE YOUR NO_ARGS CONSTRUCTOR ABOVE THIS LINE----
//---- DO NOT MODIFY THE CODE BELOW THIS LINE


    string get_name() {return name; }
    void set_name(string n) {name = n; }
    int get_age() {return age; }
    void set_age(int a) { age = a;}
    int get_dog_years() { return age * 7; }
    string speak() { return "Woof";}
};


#endif 