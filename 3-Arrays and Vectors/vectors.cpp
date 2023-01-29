/*

* Vector is an array that can grow and shrink at execution time

* Similar to array

* Very Efficient

* Can provide bounds checking

* Can use a lot of cool function like sort, reverse, find etc.

######################################################################################################

DECLARING A Vector

#include<vector>

std::vector <char> vowels; //ELEMENT_TYPE are declared in angled brackets

std::vector <int> test_scores;

****************INITIALIZING A VECTOR****************************************************************

vector <char> vowels (5);
vector <int> test_scores (10);

vector <char> vowels{'a','e','i','o','u'}; //creating a dynamic array or vector with size and values in {}

vector <int> test_scores{100,98,89,85,93};

vector<double> hi_temperature (365,80.0)//creating a dynamic array with 365 size and value 80.0

*/

/*Characteristics:

* first element is at index 0

*last element is at index size-1

*[]- no checking to see if you're out of bounds

*provides many functions that do bound checking

*Elements initialized to zero

*Very Efficient

*Iteration(looping) is often used to process

#########################ACCESSING VECTOR ELEMENTS###############################################

If we want to access a specific element from  a vector we use keyword "at"

                       vector_name.at(element_index)

                  ex:
                       test_scores.at(1);

##############################ADDING ELEMENTS TO THE VECTOR#########################################

Suppose we got our vector of 5 element and we want to add an element to it.

In that case we use a keyword "push_back"

The syntax looks like "vector_name.push_back(element)"

vector <int> test_scores{100,95,99}; //size is 3

test_scores.push_back(80);  //100,95,99,80

Removal or Deletion in a Vector of Vectors

Elements can be removed from a vector of vectors using the pop_back() function of C++ STL.

Below example demonstrates the removal operation in a vector of vectors. The code removes elements from a 2D vector by using the pop_back() function and then displays the matrix.
Syntax:

vector_name[row_position].pop_back()

*/

// Section 7
// Vectors

#include <iostream>
#include <vector>   // don't forget this in order to use vectors

using namespace std;

int main() {
    
//    vector <char> vowels;         // empty 
//    vector <char> vowels (5);      // 5 initialized to zero 
    vector <char> vowels {'a' , 'e', 'i', 'o', 'u'};
    
    cout << vowels[0] << endl;
    cout << vowels[4] << endl;
    
//    vector <int> test_scores (3);  // 3 elements all initialized to zero
//   vector <int> test_scores (3, 100); // 3 elements all initialized to 100
    
      vector <int> test_scores {100, 98, 89};
    
    cout << "\nTest scores using array syntax:" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\nTest scores using vector syntax:" << endl;
    
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl;
    
    cout << "\nEnter 3 test scores: ";
    cin  >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);
    
    cout << "\nUpdated test scores: " << endl;
    
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    

    cout << "\nEnter a test score to add to the vector: ";
    
    int score_to_add {0};
    cin >> score_to_add;
    
    test_scores.push_back(score_to_add);
    
    cout << "\nEnter one more test score to add to the vector: ";
    
    cin >> score_to_add;
    
    test_scores.push_back(score_to_add);
    
     cout << "\nTest scores are now: " << endl;
    
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;
    
    cout << "\nThere are now " << test_scores.size() << " scores in the vector" << endl;
    
  //  cout << "This should cause an exception!!" << test_scores.at(10) << endl;

    // Example of a 2D-vector
    
    vector <vector<int>> movie_ratings 
    {   
        {1, 2, 3, 4},
        {1, 2, 4, 4},
        {1, 3, 4, 5}
    };

    cout << "\nHere are the movie rating for reviewer #1 using array syntax :" << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings[0][2] << endl;
    cout << movie_ratings[0][3] << endl;
    
     cout << "\nHere are the movie rating for reviewer #1 using vector syntax :" << endl;
    cout << movie_ratings.at(0).at(0) << endl;
    cout << movie_ratings.at(0).at(1) << endl;
    cout << movie_ratings.at(0).at(2) << endl;
    cout << movie_ratings.at(0).at(3) << endl;
    
    cout << endl;
    return 0;
}


