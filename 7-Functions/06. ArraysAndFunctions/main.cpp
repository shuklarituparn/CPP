// Section 11
// Arrays and functions
#include <iostream>

using namespace std;

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value);

void print_array(const int arr[], size_t size) {  // const
    for (size_t i{0}; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
   // arr[0] = 50000; // bug
}

// set each array element to value
void set_array(int arr[], size_t size, int value) {
    for (size_t i{0}; i < size; ++i)  
        arr[i] = value;
}

int main() {
    int my_scores[] {100, 98, 90, 86, 84};  //decalaring an int array with a pre defined elements
    
    print_array(my_scores, 5);   //calling function print array with two parameters. First array and the second is the size
    set_array(my_scores, 5, 100); //setting each element of the 5 size array as 100
    print_array(my_scores, 5); //printing the array of the size 5
    print_array(my_scores, 5);
    
    cout << endl;
    return 0;
}

