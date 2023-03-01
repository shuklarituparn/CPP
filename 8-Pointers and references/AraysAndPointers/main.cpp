#include <iostream>

using namespace std;

int main() {
    
    int scores[] {100, 95, 89};
    
    cout << "Value of scores: " << scores << endl;     
    
    int *score_ptr {scores};
    cout << "Value of score_ptr: " << score_ptr << endl;
    
    cout << "\nArray subscript notation -------------------------" << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl; //going 1 integer apart from score[0]
    cout << scores[2] << endl; //going 2 integer apart from score [0]
    
    cout << "\nPointer subscript notation -------------------------" << endl;
    cout << score_ptr[0] << endl; 
    cout << score_ptr[1] << endl; //a single integer away from the pointer
    cout << score_ptr[2] << endl;
    
    cout << "\nPointer offset notation-------------------------" << endl;
    cout << *score_ptr << endl; //dereferencing= getting to location and returning what's there
    cout << *(score_ptr + 1) << endl; //whatever score pointer is pointing to +1
    cout << *(score_ptr +2) << endl; //whatever score pointer is pointing to +2
    
    cout << "\nArray offset notation-------------------------" << endl;
    cout << *scores << endl; //dereferencing an array
    cout << *(scores + 1) << endl;
    cout << *(scores +2) << endl;
    
    cout << endl;
    return 0;
}

