#include <iostream>
using namespace std;

void can_you_drive(int age) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    const int driving_age {16};
    
    if (age >= driving_age)
        cout << "Yes - you can drive!";
    else 
        cout << "Sorry, come back in " << driving_age - age << " years";
        
    //----WRITE YOUR CODE ABOVE THIS LINE----
}