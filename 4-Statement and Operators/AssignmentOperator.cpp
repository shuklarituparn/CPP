// Section 8
// Assignment operator (=)

#include <iostream>

using namespace std;

int main() {
    
    int num1 {10};
    int num2 {20};
    
    num1 = 100;

    // We can't do 100=number; as number 100 is a literal and doesn't have a memory location
    
    cout << "num1 is " << num1 << endl;
    cout << "num2 is " << num2 << endl;

    cout << endl;
    return 0;
}

