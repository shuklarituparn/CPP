#include <iostream>
#include <string>

struct Node {
  char data;
  Node *next;
};

class List {
private:
  Node *head;

  Node* RecursivelyAddingElement(std::string, int index);
  void DeletingNodeRecursively(Node*);

public:
  explicit List(std::string);
  ~List(); // destructor added
  void DisplayLinkedList(Node *node);
  // void ReverseLinkedList();
  Node *get_head() { return head; }
};

List::List(std::string str) {
  int index = 0;
  RecursivelyAddingElement(str, 0);
}

// destructor implementation

List::~List() { 
    DeletingNodeRecursively(head); 
}

void List::DisplayLinkedList(Node *node) {
  Node *ptr = head;
  if (ptr != nullptr) {
    std::cout << ptr->data;
    DisplayLinkedList(ptr->next);
  }
}

Node* List::RecursivelyAddingElement(std::string str, int index) {
  if (index > str.length()){
    return nullptr;
  }
    Node* new_node= new Node;
    new_node->data=str[index];
    new_node->next=RecursivelyAddingElement(str, index+1);
    head=new_node;
    return new_node;

}
void List::DeletingNodeRecursively(Node* node) {
  if (node == nullptr) {
    return;
  } else {
    DeletingNodeRecursively(node->next);
    delete (node);
  }
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  List myList{str};
  // myList.ReverseLinkedList();
  myList.DisplayLinkedList(myList.get_head());
  return 0;
}
