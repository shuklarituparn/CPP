#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
private:
  vector<int> data;

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

  cout << data.back() << endl;
  data.pop_back();
}
void Stack::Back() { cout << data.back() << endl; }
void Stack::Size() { cout << data.size() << endl; }
void Stack::Clear() { data.clear(); }
int main() {
  Stack stack;

  string command;
  while (cin >> command) {
    if (command == "push") {
      int num;
      cin >> num;
      stack.Push(num);
      cout << "ok\n";
    } else if (command == "pop") {
      if (stack.IsEmpty() != 0) {
        cout << "error\n";
      }else {
        stack.Pop();
      }

    } else if (command == "back") {
      if (stack.IsEmpty() != 0) {
        cout << "error\n";
      }else {
        stack.Back();
      }

    } else if (command == "size") {
      stack.Size();
    } else if (command == "clear") {
      stack.Clear();
      cout << "ok\n";
    } else if (command == "exit") {
      cout << "bye\n";
      break;
    }
  }

  return 0;
}
