//C++ program to check matching parenthesis using stack

#include <iostream>
#include <cstring>
using namespace std;
 
class Stack{
private:
    int size; //size of the stack 
    int top; //the top of the stack 
    char* String; //the pointer to the char array or the string that we are checking
public:
    Stack(int size);  //default constructor that takes an int input
    ~Stack();  //destructor
    void push(char x); //class method to push a character in the stack
    char pop();  //class method to pop out a character from the stack
    char peek(int index); //method to check the element at the given index in the stack
    int isFull(); //to check if the stack is full
    int isEmpty(); //to check if the stack is empty
    void display(); //to display the elements of the stack
    char stackTop(); //to display the top of the stack
};
 
Stack::Stack(int size) {
    this->size = size;
    top = -1;
    String = new char[size]; //we are creating a new string based of the size that the user is entering 
}
 
Stack::~Stack() {
    delete[] String;  //deleting the string 
}
 
void Stack::push(char element) {  //push function
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        String[top] = element;
    }
}
 
char Stack::pop() { //popping the character from the stack
    char element = 1;  
    if (isEmpty()){
        cout << "Stack Underflow!" << endl;
    } else {
        element = String[top];
        top--;
    }
    return element;
}
 
char Stack::peek(int index) {  //method to peek in the stack 
    char element = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        element = String[top-index+1];
    }
    return element;
}
 
int Stack::isFull() {  //checking if the stack is full
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int Stack::isEmpty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void Stack::display() {
    for (int i=top; i>=0; i--){
        cout << String[i] << " | " << flush;
    }
    cout << endl;
}
 
char Stack::stackTop() {
    if (isEmpty()){
        return -1;
    }
    return String[top];
}
 
bool isBalanced(char* exp){
 
    // Create a stack
    Stack stk((int)strlen(exp));
 
    // Process expression
    for (int i=0; i<strlen(exp); i++){
 
        // ( found: Push to stack
        if (exp[i] == '('){
            stk.push(exp[i]);
 
            // ( found
        } else if (exp[i] == ')'){
 
            // ) and stack is empty: Unbalanced expression
            if (stk.isEmpty()){
                return false;
 
                // ) and stack is not empty
            } else {
                stk.pop();
            }
        }
    }
 
    // If stack is empty then balanced else unbalanced
    return stk.isEmpty() ? true : false;
 
}
 
int main() {
 
    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;
 
    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;
 
    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;
    return 0;
    
}