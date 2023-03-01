/*
Adding public methods that access private class attributes

Given the following Dog class in Dog.h add the following public getter and setter
 methods that get and set each class attribute as follows:

get_name returns the name attribute of the dog 

set_name sets the name attribute of the dog to the string that is passed into the method.

get_age returns the age attribute of the dog

set_age sets the age attribute of the dog to the int passed into the method.

Please add your code to the Dog.h file. The exercise.cpp file should NOT be modified.

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

//---- WRITE YOUR CLASS FUNCTIONS BELOW THIS LINE----
string get_name(){return name;}
void set_name(string name_passed){name= name_passed;}
int get_age(){return age;}
void set_age(int age_entered){age=age_entered;}

//---- WRITE YOUR CLASS FUNCTIONS ABOVE THIS LINE----
};
#endif 
