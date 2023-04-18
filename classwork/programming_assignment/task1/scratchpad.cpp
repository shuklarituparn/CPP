#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    T data[100];
    int topIndex;

public:
    Stack(): topIndex(-1) {} //initializing the stack with top=-1

    void push(const T& element) {
        if (topIndex == 99) {
            throw "Stack is full";
        }
        topIndex++;
        data[topIndex] = element;
    }

    void pop() {
        if (topIndex == -1) {
            throw "Stack is empty";
        }
        topIndex--;
    }

    T& top() {
        if (topIndex == -1) {
            throw "Stack is empty";
        }
        return data[topIndex];
    }

    bool empty() const {
        return topIndex == -1;
    }
};
int main() {
    //template <typename T>; //can't declare template in main and templates don't have semicolons

    Stack<int> s;
  std::string input;
  while (std::cin >> input) {
    if (input == "push") {
      int value;
      std::cin >> value;
      s.push(value);
    } 
    else if (input == "pop") {
            s.pop();
    }

    else if (input == "top") {

      s.top();

    } 
    else if (input == "empty") {
        std::cout<<s.empty();
    } else{
        std::cout<<"Invalid Input"<<std::endl;
        break;
    }
  }

    return 0;
}
