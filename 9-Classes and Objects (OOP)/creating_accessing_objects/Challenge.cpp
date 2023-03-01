/*Creating and Accessing Objects

We have already declared a C++ class named Dog  that is located in Dog.h 
(we'll learn about header files later in this section).

In the test_dog  function create a Dog  object named spot  and, using the . operator, 
set the name  attribute to the string "Spot"  and the age  attribute to 5 .

You can find my solution by clicking on the solution.txt file on the left pane.
But please make sure you give it a go yourself first, and only check the solution
if you really get stuck.


*/

#include "Dog.h"


Dog test_dog() {
//---- WRITE YOUR CODE BELOW THIS LINE----

Dog spot;
spot.name= {"Spot"};
spot.age=5;


//---- WRITE YOUR CODE ABOVE THIS LINE----
//---- DO NOT CHANGE THE CODE BELOW----
    return spot;
}