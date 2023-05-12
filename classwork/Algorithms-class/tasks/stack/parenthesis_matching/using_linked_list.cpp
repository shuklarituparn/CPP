#include <exception>
#include <iostream>
#include<cstring>
using namespace std;
 
class Node{
public:
    char data;
    Node* next;
};
 
class Stack{
private:
    Node* head;
public:
    Stack();
    ~Stack();
    void push(char x);
    char pop();
    char peek(int index);
    int isEmpty();
    int isFull();
    char stackTop();
};
 
Stack::Stack() {
    head = nullptr;
}
 
Stack::~Stack() {
    Node* current = head;
    while (head){
        head = head->next;
        delete current;
        current = head;
    }
}
 
void Stack::push(char element) {
    Node* new_node = new Node;
    if (new_node == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        new_node->data = element;
        new_node->next = head;
        head = new_node;
    }
}
 
char Stack::pop() {
    Node* p;
    char x = -1;
    if (head == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = head;
        x = p->data;
        head = head->next;
        delete p;
    }
    return x;
}
 
int Stack::isFull() {
    Node* new_node = new Node;
    int r = new_node ? 1 : 0;
    delete new_node;
    return r;
}
 
int Stack::isEmpty() {
    return head ? 0 : 1;
}
 
char Stack::stackTop() {
    if (head){
        return head->data;
    }
    return -1;
}
 
char Stack::peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = head;
 
        for (int i=0; p != nullptr && i<index-1; i++){
            p = p->next;
        }
 
        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}
 
 
int isBalanced(char* exp){
    Stack stk;
 
    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == '('){
            stk.push(exp[i]);
        } else if (exp[i] == ')'){
            if (stk.isEmpty()){
                return false;
            } else {
                stk.pop();
            }
        }
    }
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