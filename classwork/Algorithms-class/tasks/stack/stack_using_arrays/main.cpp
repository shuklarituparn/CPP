#include <iostream>
using namespace std;
 
class Stack{  //class for stack
private:
    int size; //Max size of stack
    int top; //The index of the top of the stack
    int* data; //pointer to the array containing the stack
public:
    Stack(int size); //constructor for the stack that contains the int
    ~Stack(); //destructor for the stack 
    void push(int element); //function to push an element to the stack
    int pop(); //removes the element from the stack
    int peek(int index); //returns the element at the specified index
    int isFull(); //to check if the stack is full
    int isEmpty(); //to check if the stack is empty
    void display(); //to display the stack
    int stackTop(); //returns the element at top without removing it from the stack
};
 
Stack::Stack(int size) {
    this->size = size;  //can use this for methods declared as member functions. Assigning the size to stack
    top = -1; //by default the top is -1. While returning empty stack it'll give error
    data = new int[size];
}
 
Stack::~Stack() {  //destructor that destructs the class struct
    delete[] data; //deleting the stack data
}
 
void Stack::push(int element) { //class method that pushes an int in the stack
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        data[top] = element;
    }
}
 
int Stack::pop() {  //class method that pops out an element from the stack
    int element = 1;
    if (isEmpty()){
        cout << "Stack Underflow!" << endl;
    } else {
        element = data[top];
        top--;
    }
    return element;
}
 
int Stack::peek(int index) { //class method that tells the element at a given index
    int element = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        element = data[top-index+1];
    }
    return element;
}
 
int Stack::isFull() { //class method to check if the stack is full
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int Stack::isEmpty() { //class method to check if the stack is empty
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void Stack::display() { //class method to display the stack
    for (int i=top; i>=0; i--){
        cout << data[i] << " | " << flush;
    }
    cout << endl;
}
 
int Stack::stackTop() { //class method to display the top element of the stack
    if (isEmpty()){
        return -1;
    }
    return data[top];
}
 
 
int main() { //main function
 
    int A[] = {1, 3, 5, 7, 9};
 
    Stack stk(sizeof(A)/sizeof(A[0]));
 
    // Populate stack with array elements
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.push(A[i]);
    }
    stk.push(11);
 
    cout << "Stack full: " << stk.isFull() << endl;
 
    // Display stack;
    cout << "Stack: " << flush;
    stk.display();
 
    // Peek
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;
 
    // Top element
    cout << "Top element: " << stk.stackTop() << endl;
 
    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();
 
    cout << "Stack empty: " << stk.isEmpty() << endl;
 
    return 0;
}