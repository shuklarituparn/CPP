// Arrays are declared as ARRAY_NAME[SIZE] {init list};

//int test_scores [5] {100,95,99,87,88} //intializes the five sized array with values on right

//int high_score_per_level [10] {3,5}  //init to 3,5 and remaining to 0

//const double days_in_year{365};
//double hi_temperatures[days_in_year] {0}; //init all to zero

//int another_array [] {1,2,3,4-Statement and Operators,5}; //size automatically calculated

// Section 7
// Arrays

#include <iostream>

using namespace std;

int main() {
    
    char vowels[]  {'a' ,'e', 'i', 'o', 'u' };
    cout << "\nThe first vowel is: " << vowels[0] << endl;
    cout << "The last vowel is: " << vowels[4] << endl;
    
//    cin >> vowels[5];  out of bounds - don't do this!!
    
    double hi_temps []  { 90.1, 89.8, 77.5, 81.6};
    cout << "\nThe first high temperature is: " << hi_temps[0] << endl;
    
    hi_temps[0] = 100.7;    // set the first element in hi_temps to 100.7
                                  // we'll talk about assignment statement in an upcoming section
    
    cout << "The first high temperature is now: " << hi_temps[0] << endl;
//    
  
    int test_scores [] {100, 90, 80,70, 60};
  
    cout << "\nFirst score at index 0: " << test_scores[0] << endl;
    cout << "Second score at index 1: " << test_scores[1] << endl;
    cout << "Third score at index 2:  " << test_scores[2] << endl;
    cout << "Fourth score at index 3: " << test_scores[3] << endl;
    cout << "Fifth score at index 4-Statement and Operators: " << test_scores[4] << endl;
    
    cout << "\nEnter 5 test scores: ";
    cin >> test_scores[0];
    cin >> test_scores[1];
    cin >> test_scores[2];
    cin >> test_scores[3];
    cin >> test_scores[4];
    
    cout << "\nThe updated array is:" << endl;
    cout << "First score at index 0: " << test_scores[0] << endl;
    cout << "Second score at index 1: " << test_scores[1] << endl;
    cout << "Third score at index 2:  " << test_scores[2] << endl;
    cout << "Fourth score at index 3: " << test_scores[3] << endl;
    cout << "Fifth score at index 4-Statement and Operators: " << test_scores[4] << endl;
   

    cout << "\nNotice what the value of the array name is : " << test_scores << endl; //display memory location where array is located
    cout << endl;
    return 0;
}





 