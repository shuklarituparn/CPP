#include <iostream>
#include <string>
#include <vector>
class Stack {
private:
  std::vector<int> data;

public:
  void Push(int n);
  void Pop();
  void Back();
  void Size();
  void Clear();
  int IsEmpty() { return data.empty(); }
};
void Stack::Push(int n) { data.push_back(n); }
void Stack::Pop() {

  std::cout << data.back() << std::endl;
  data.pop_back();
}
void Stack::Back() { std::cout << data.back() << std::endl; }
void Stack::Size() { std::cout << data.size() << std::endl; }
void Stack::Clear() { data.clear(); }
int main() {
  Stack stack;

  std::string command;
  while (std::cin >> command) {
    if (command == "push") {
      int num;
      std::cin >> num;
      stack.Push(num);
      std::cout << "ok\n";
    } else if (command == "pop") {
      if (stack.IsEmpty() != 0) {
        std::cout << "error\n";
      }else {
        stack.Pop();
      }

    } else if (command == "back") {
      if (stack.IsEmpty() != 0) {
        std::cout << "error\n";
      }else {
        stack.Back();
      }

    } else if (command == "size") {
      stack.Size();
    } else if (command == "clear") {
      stack.Clear();
      std::cout << "ok\n";
    } else if (command == "exit") {
      std::cout << "bye\n";
      break;
    }
  }

  return 0;
}

//copy the implementation of the stack and then change the output to print the element at the position 0

