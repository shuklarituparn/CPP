#include <iostream>
#include <string>

struct Node {
  char data;
  Node *next;
};

class List {
private:
  Node *head;

  Node *AddNodesRecursively(std::string str, int index);
  void DeleteNodesRecursively(Node *node);

public:
  explicit List(std::string str);
  ~List();
  // void DisplayLinkedList();
  Node *ReverseLinkedList(Node *current, Node *prev);
  void DisplayLinkedList(Node *node);
  Node *get_head() { return head; }
};

List::List(std::string str) {
  head = nullptr;
  AddNodesRecursively(str, 0);
}

List::~List() { DeleteNodesRecursively(head); }

Node *List::AddNodesRecursively(std::string str, int index) {
  if (index >= str.length()) {
    return nullptr;
  }
  Node *new_node = new Node;
  new_node->data = str[index];
  new_node->next = AddNodesRecursively(str, index + 1);
  head = new_node;
  return new_node;
}

void List::DisplayLinkedList(Node *head) {
  if (head != nullptr) {
    std::cout << head->data;
    DisplayLinkedList(head->next);
  }
}

Node *List::ReverseLinkedList(Node *current, Node *prev) {
  if (current == nullptr) {
    head = prev;
    return head;
  }
  Node *next = current->next;
  current->next = prev;
  ReverseLinkedList(next, current);
  return head;
}

void List::DeleteNodesRecursively(Node *node) {
  if (node == nullptr) {
    return;
  }
  DeleteNodesRecursively(node->next);
  delete node;
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  List myList{str};
  myList.ReverseLinkedList(myList.get_head(), nullptr);
  myList.DisplayLinkedList(myList.get_head());
  return 0;
}
