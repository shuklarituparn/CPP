// Section 12
// Passing Pointers 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void swap(int *a, int *b) {
    int temp = *a; //storing the value of X as pointer a is being passed the address of X
    *a = *b; //Now storing value of Y in a as pointer b has address of Y
    *b = temp; //Now storing the value of X in b
}


int main() {
    int x {100}, y {200};
    cout << "\nx: " << x <<  endl;
    cout << "y: " << y <<  endl;
    
    swap(&x, &y);
    
    cout << "\nx: " << x <<  endl;
    cout << "y: " << y <<  endl;
    
    cout  << endl;
    return 0;
}

