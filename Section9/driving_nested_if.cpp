/*

Nested If Statements - Can you Drive?

In this exercise you will use nested if  statements to decide if someone can drive. Let's assume that anyone 16 or older can legally drive, but they must also own a car to drive.

If the person is not 16 or older then you should display, "Sorry, come back in n  years and be sure you own a car when you come back.", where n is how many years until the person turns 16 year old.

If the person is 16 or older but they do NOT own a car, then your program should display, "Sorry, you need to buy a car before you can drive!" .

If the person is 16 or older and they DO own a car, then your program should display, "Yes - you can drive!"

The age  will be provided for you, you do NOT need to declare age .We will also automatically provide a boolean variable named has_car  which will be true  if the person owns a car or false  otherwise.  Our test cases will provide different values for age  and has_car  to test your code.

Please do NOT provide '\n ' or endl  in your display statements.

You can find my solution by clicking on the solution.txt file on the left pane. But please make sure you give it a go yourself first, and only check the solution if you really get stuck.

*/

#include <iostream>
using namespace std;

void can_you_drive(int age, bool has_car) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    const int driving_age {16};
    
    if(age>=driving_age && has_car)
        cout<<"Yes - you can drive!";
    if(age>=driving_age && !has_car)
        cout<<"Sorry, you need to buy a car before you can drive!";
    if(age<16)
        cout<<"Sorry, come back in "<<driving_age-age<< " years and be sure you own a car when you come back.";
    
    
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

/*

#include <iostream>
using namespace std;

void can_you_drive(int age, bool has_car) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    const int driving_age {16};
    
    if (age >= driving_age) {
        if (has_car) {
            cout << "Yes - you can drive!";
        } else {
            cout << "Sorry, you need to buy a car before you can drive!";
        }
        
    } else {
        cout << "Sorry, come back in " << driving_age - age << " years and be sure you own a car when you come back.";
    }
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
}








*/