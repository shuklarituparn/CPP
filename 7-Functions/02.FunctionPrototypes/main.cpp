// Section 11
// Function Prototypes
// Area of Circle and Volume of a Cylinder
#include <iostream>

using namespace std;

// Function prototypes
double calc_volume_cylinder(double radius, double height); //declaring a function that takes two input one of the radius and other of the height 
double calc_area_circle(double); //function returning double and taking a value of type double
void area_circle(); //a function that takes no argument and return no value
void volume_cylinder(); // a function that takes no argument and returns no value

const double pi = 3.14159;

int main() {
    area_circle();      //function call to a function to calculate the area
    volume_cylinder(); //function call to a function to calculate the volume
    return 0;
}

double calc_volume_cylinder(double radius, double height) {
   // return pi *radius * radius * height;
   return calc_area_circle(radius) * height;   //calling another function in this and then returning it after an operation
}

double calc_area_circle(double radius) {
    return pi * radius * radius;            //using a globally declared variable inside a fucntion and then returning the value after an operation on it
}

void area_circle() {   //function with no parameters
    double radius {};   //declaring a variable of type double and it initializing as 0
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl; //calling other function with the local variable
}

void volume_cylinder() {
    double radius {};   //local variable declaration
    double height {}; // local declaration
    cout << "\nEnter the radius of the cylinder: ";
    cin >> radius;
    cout << "Enter the height of the cylinder: ";
    cin >> height;
    cout << "\nThe volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl; 
                                                                                                            //calling a different function in this
}


