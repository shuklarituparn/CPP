#include <iostream>
#include <stdexcept>

template <typename T> class Stack {
private:
  T data[100];
  int topIndex;

public:
  Stack() : topIndex(-1) {}

  ~Stack() {}

  void push(const T &element) {
    if (topIndex == 99) {
      throw std::overflow_error("Stack is full");
    }
    topIndex++;
    data[topIndex] = element;
  }

  void pop() {
    if (topIndex == -1) {
      throw std::underflow_error("Stack is empty");
    }
    topIndex--;
  }

  T &top() {
    if (topIndex == -1) {
      throw std::underflow_error("Stack is empty");
    }
    return data[topIndex];
  }

  bool empty() const { return topIndex == -1; }
};

int main() {
  

  Stack<int> stack;
  std::string input;

  while (std::cin >> input) {
    try {
      if (input == "push") {
        int value;
        std::cin >> value;
        stack.push(value);
      } else if (input == "pop") {
        stack.pop();
      } else if (input == "top") {
        std::cout << stack.top() << std::endl;
      } else if (input == "empty") {
        std::cout << std::boolalpha << stack.empty() << std::endl;
      } else if (input == "exit") {
        std::cout << "bye" << std::endl;
        break;
      } else {
        std::cout << "Invalid input" << std::endl;
      }
    } catch (const std::exception &exception) {
      std::cerr << "Error: " << exception.what() << std::endl;
    }
  }

  return 0;
}
