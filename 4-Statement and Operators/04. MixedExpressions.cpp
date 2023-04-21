// Section 8

/*

*Short and char types are always converted into int.

*Type Coercion: conversion of one operand to another data type

*Promotion: Conversion to a higher type: Used in mathematical expression

*Demotion: Conversion to a lower type, :Used with Assignment to lower type

*/
// Mixed Type Expressions
/*
    Ask the user to enter 3 integers
    Calculate the sum of the integers then
    calculate the average of the 3 integers.
    
    Display the 3 integers entered
    the sum of the 3 integers and
    the average of the 3 integers.
*/

#include <iostream>

using namespace std;

int main() {
    int total {};
    int num1 {}, num2 {}, num3 {};
    const int count {3};
    
    cout << "Enter 3 integers separated by spaces: ";
    cin >> num1 >> num2 >> num3;
    
    total = num1 + num2 + num3;
    
    double average {0.0};
    
    average = static_cast<double>(total) / count; //Ask the compiler to convert from int to double
   // average = (double)total/count;  Old-Style
    
    
    cout << "The 3 numbers were: "<< num1 << "," << num2 << "," << num3 << endl;
    cout << "The sum of the numbers is: " << total << endl;
    cout << "The average of the numbers is: " << average << endl;
    
    cout << endl;
    return 0;
}

