/*

Logical Operators and Operator Precedence - Can you work?

In this exercise you will create a program that determines the eligibility of an individual applying for a job as a 
delivery driver.

In order for the individual to be eligible, they must be 18  years of age or older, or be above the age of  15  and 
have their parents consent to work.

Additionally they must possess a valid social security number and have no driving accidents.

Let the variable age  represent the individual's age, and the boolean variables parental_consent  
represent parental consent, ssn  represent a valid social security number, and accidents   represent whether they have 
had any car accidents.

For this exercise you will write your code within the parenthesis of the if statement provided.

In the case that the person cannot work, do not display any output - our tester assumes no output means the person 
can't work.

*/
#include <iostream>
using namespace std;

void logical_operators(int age, bool parental_consent, bool ssn, bool accidents) {
    
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    if ((age>=18||(age>=16&&parental_consent))&&ssn && !accidents)//WRITE ALL YOUR CODE WITHIN THE PARENTHESES
        cout << "Yes, you can work.";
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    return;
}