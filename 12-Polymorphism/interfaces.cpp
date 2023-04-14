#include <iostream>

class Printable {
public:
    virtual void print() const = 0; //virtual function should be declared to zero
};

/*
In this example, there is an interface called Printable, which defines a single method called print(). This interface is then implemented by two classes: Circle and Square. Both of these classes provide their own implementation of the print() method, which outputs a message to the console describing the shape.

The printShapes() function takes an array of Printable objects, and loops through them, calling the print() method on each one. This function doesn't need to know anything about the specific types of shapes being printed - it just needs to know that they all implement the Printable interface.

In the main() function, an array of Printable pointers is created, containing a Circle and a Square. These objects are then passed to the printShapes() function, which prints out information about each shape.

*/

class Circle : public Printable {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void print() const override {  //here override is used in the redefinition of the function in the derived class
        std::cout << "Circle with radius " << radius << std::endl;
    }
};//while using override the derived function should not have new arguments or definitions.

class Square : public Printable {
private:
    double sideLength;
public:
    Square(double l) : sideLength(l) {}

    void print() const override {
        std::cout << "Square with side length " << sideLength << std::endl;
    }
};

//basically an interface acts a template for the classes. It only contains a virtual function that is over-riden in the subsequent classes

void printShapes(Printable* shapes[], int numShapes) {
    for (int i = 0; i < numShapes; i++) {
        shapes[i]->print();
    }
}

int main() {
    Circle c(2.0);
    Square s(3.0);

    Printable* shapes[2]; //array of pointer of type base class that has two values
    shapes[0] = &c; //the first pointer stores the address of the class circles
    shapes[1] = &s; //the second pointer stores the address of the class squares

    printShapes(shapes, 2); //calling the print shapes function on this array 

    return 0;
}


/*
Rules While Using Interfaces

    Declare only pure virtual functions. (No definition)
    For pure virtual functions assign only 0.
    Cannot create an instance of the class.
    We can create a pointer to the instance of the derived class with a reference of a base abstract class.
*/