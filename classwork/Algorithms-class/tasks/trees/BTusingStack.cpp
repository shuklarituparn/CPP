#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
  Node *leftchild;
  Node *rightchild;
  int data;
};

class Tree {
private:
  Node *head;

public:
  Tree();
  ~Tree();
  void CreateTree();
  void Preorder(Node *current);
  void Preorder() {
    Preorder(head);
  } // Passing Private Parameter in Constructor
  void Inorder(Node *current);
  void Inorder() { Inorder(head); }
  void Postorder(Node *current);
  void Postorder() { Postorder(head); }
  void Levelorder(Node *current);
  void Levelorder() { Levelorder(head); }
  int Height(Node *current);
  int Height() { return Height(head); }
};

Tree::Tree() { head = nullptr; }

Tree::~Tree() {
  delete head->leftchild;
  delete head->rightchild;
  delete head;
}

void Tree::CreateTree() {
  Node *current;
  Node *temp;
  int element;
  queue<Node *> q;

  head = new Node;
  cout << "Enter head data: " << flush;
  cin >> element;
  head->data = element;
  head->leftchild = nullptr;
  head->rightchild = nullptr;
  q.emplace(head);

  while (!q.empty()) {
    current = q.front();
    q.pop();

    cout << "Enter left child data of " << current->data << ": " << flush;
    cin >> element;
    if (element != -1) {
      temp = new Node;
      temp->data = element;
      temp->leftchild = nullptr;
      temp->rightchild = nullptr;
      current->leftchild = temp;
      q.emplace(temp);
    }

    cout << "Enter right child data of " << current->data << ": " << flush;
    cin >> element;
    if (element != -1) {
      temp = new Node;
      temp->data = element;
      temp->leftchild = nullptr;
      temp->rightchild = nullptr;
      current->rightchild = temp;
      q.emplace(temp);
    }
  }
}

void Tree::Preorder(Node *current) {
  if (current) {
    cout << current->data << ", " << flush;
    Preorder(current->leftchild);
    Preorder(current->rightchild);
  }
}

void Tree::Inorder(Node *current) {
  if (current) {
    Inorder(current->leftchild);
    cout << current->data << ", " << flush;
    Inorder(current->rightchild);
  }
}

void Tree::Postorder(Node *current) {
  if (current) {
    Postorder(current->leftchild);
    Postorder(current->rightchild);
    cout << current->data << ", " << flush;
  }
}

void Tree::Levelorder(Node *current) {
  queue<Node *> q;
  cout << head->data << ", " << flush;
  q.emplace(head);

  while (!q.empty()) {
    current = q.front();
    q.pop();

    if (current->leftchild) {
      cout << current->leftchild->data << ", " << flush;
      q.emplace(current->leftchild);
    }

    if (current->rightchild) {
      cout << current->rightchild->data << ", " << flush;
      q.emplace(current->rightchild);
    }
  }
}

int Tree::Height(Node *current) {
  int left = 0;
  int right = 0;
  if (current == nullptr) {
    return 0;
  }

  left = Height(current->leftchild);
  right = Height(current->rightchild);

  if (left > right) {
    return left + 1;
  } else {
    return right + 1;
  }
}

int main() {

  Tree bt;

  bt.CreateTree();
  cout << endl;

  cout << "Preorder: " << flush;
  bt.Preorder();
  cout << endl;

  cout << "Inorder: " << flush;
  bt.Inorder();
  cout << endl;

  cout << "Postorder: " << flush;
  bt.Postorder();
  cout << endl;

  cout << "Levelorder: " << flush;
  bt.Levelorder();
  cout << endl;

  cout << "Height: " << bt.Height() << endl;

  return 0;
}