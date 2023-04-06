// Section 8
// Equality Operators

#include <iostream>

using namespace std;

int main() {
    
    bool equal_result {false};
    bool not_equal_result {false};
    
    int num1{}, num2{};
    
    cout << boolalpha;      // will display true/false instead of 1/0 for booleans
    
/* // To compare two integers
   
    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;
    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);
    cout << "Comparision result (equals) : " << equal_result << endl;
    cout << "Comparision result (not equals) : " << not_equal_result << endl;

*/   
/*
 // To compare two characters 
   char char1{}, char2{};
   cout << "Enter two characters separated by a space: ";
   cin >> char1 >> char2;
   equal_result = (char1 == char2);
   not_equal_result = (char1 != char2);
   cout << "Comparision result (equals) : " << equal_result << endl;
   cout << "Comparision result (not equals) : " << not_equal_result << endl;
*/   
    
      double double1{}, double2{};
/*  // To compare two doubles

     cout << "Enter two doubles separated by a space: ";
     cin >> double1 >> double2;
     equal_result = (double1 == double2);
     not_equal_result = (double1 != double2);
     cout << "Comparision result (equals) : " << equal_result << endl;
     cout << "Comparision result (not equals) : " << not_equal_result << endl;
*/ 

// To compare doubles and an integer
    cout << "Enter an integer and a double separated by a space: ";
    cin >> num1 >> double1;
    equal_result = (num1 == double1);
    not_equal_result = (num1 != double1);
    cout << "Comparision result (equals) : " << equal_result << endl;
    cout << "Comparision result (not equals) : " << not_equal_result << endl;

    // for computer 11.0 and 10.999999999 are almost same as it stores floating values by approx.


    cout << endl;
    return 0;
}

