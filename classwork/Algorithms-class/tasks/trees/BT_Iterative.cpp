#include <iostream>
#include <queue>
#include <stack>

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
  void iterativePreorder(Node *current);
  void iterativePreorder() { iterativePreorder(head); }
  void iterativeInorder(Node *current);
  void iterativeInorder() { iterativeInorder(head); }
  void iterativePostorder(Node *current);
  void iterativePostorder() { iterativePostorder(head); }
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
  queue<Node *> q;
  int element;

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
  int l = 0;
  int r = 0;
  if (current == nullptr) {
    return 0;
  }

  l = Height(current->leftchild);
  r = Height(current->rightchild);

  if (l > r) {
    return l + 1;
  } else {
    return r + 1;
  }
}

void Tree::iterativePreorder(Node *current) {
  stack<Node *> stk;
  while (current != nullptr || !stk.empty()) {
    if (current != nullptr) {
      cout << current->data << ", " << flush;
      stk.emplace(current);
      current = current->leftchild;
    } else {
      current = stk.top();
      stk.pop();
      current = current->rightchild;
    }
  }
  cout << endl;
}

void Tree::iterativeInorder(Node *current) {
  stack<Node *> stk;
  while (current != nullptr || !stk.empty()) {
    if (current != nullptr) {
      stk.emplace(current);
      current = current->leftchild;
    } else {
      current = stk.top();
      stk.pop();
      cout << current->data << ", " << flush;
      current = current->rightchild;
    }
  }
  cout << endl;
}

void Tree::iterativePostorder(Node *current) {
  stack<long int> stk;
  long int temp;
  while (current != nullptr || !stk.empty()) {
    if (current != nullptr) {
      stk.emplace((long int)current);
      current = current->leftchild;
    } else {
      temp = stk.top();
      stk.pop();
      if (temp > 0) {
        stk.emplace(-temp);
        current = ((Node *)temp)->rightchild;
      } else {
        cout << ((Node *)(-1 * temp))->data << ", " << flush;
        current = nullptr;
      }
    }
  }
  cout << endl;
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

  cout << "Iterative Preorder: " << flush;
  bt.iterativePreorder();

  cout << "Iterative Inorder: " << flush;
  bt.iterativeInorder();

  cout << "Iterative Postorder: " << flush;
  bt.iterativePostorder();

  return 0;
}

/*
emplace() is a member function of the C++ STL (Standard Template Library) queue
container that is used to insert a new element into the queue. It constructs the
new element in place, directly in the memory of the container, using the
provided arguments. It is similar to the push() function of the queue container,
but emplace() constructs the element in place without creating a temporary
object, which can improve performance and reduce memory usage.
*/
