#include <iostream>

class Node {
public:
  int data;
  Node *leftchild;
  Node *rightchild;
};

class Queue {
private:
  int size;
  int front;
  int rear;
  Node **Q; // pointer to pointer to a node
public:
  Queue(int size);
  ~Queue();
  bool isfull();
  bool isempty();
  void enqueue(Node *element);
  Node *dequeue();
};

Queue::Queue(int size) {
  this->size = size;
  front = -1;
  rear = -1;
  Q = new Node *[size];
}

Queue::~Queue() { delete[] Q; }

bool Queue::isempty() {
  if (front == rear) {
    return true;
  }
  return false;
}

bool Queue::isfull() {
  if (rear == size - 1) {
    return true;
  }
  return false;
}

void Queue::enqueue(Node *element) {
  if (isfull()) {
    std::cout << "Queue overflow";
  } else {
    rear++;
    Q[rear] = element;
  }
}
Node *Queue::dequeue() {
  Node *element = nullptr;
  if (isempty()) {
    std::cout << "Queue Underflow";
  } else {
    front++;
    element = Q[front];
  }
  return element;
}

class Tree {
private:
  Node *head;

public:
  Tree() { head = nullptr; }
  ~Tree();
  void CreateTree();
  void Preorder() { Preorder(head); } // private field into a constructor
  void Preorder(Node *current);
  void Postorder() { Preorder(head); } // private field into a constructor
  void Postorder(Node *current);
  void Inorder() { Preorder(head); } // private field into a constructor
  void Inorder(Node *current);
  void Levelorder() { Preorder(head); } // private field into a constructor
  void Levelorder(Node *current);
  int Height(Node *current);
  int Height() { return Height(head); }
  Node *getRoot() { return head; }
};

void Tree::CreateTree() {
  Node *current;
  Node *temp;
  int element;

  Queue q(25);
  head = new Node;
  std::cout << "Enter the root value";
  std::cin >> element;
  head->data = element;
  head->leftchild = nullptr;
  head->rightchild = nullptr;
  q.enqueue(head);

  while (!q.isempty()) {
    current = q.dequeue();
    std::cout << "Enter the left child value of " << current->data << ":";
    std::cin >> element;
    if (element != -1) {
      temp = new Node;
      temp->data = element;
      temp->leftchild = nullptr;
      temp->rightchild = nullptr;
      current->leftchild = temp;
      q.enqueue(temp);
    }
    std::cout << "Enter the right child value of " << current->data << ":";
    std::cin >> element;
    if (element != -1) {
      temp = new Node;
      temp->data = element;
      temp->leftchild = nullptr;
      temp->rightchild = nullptr;
      current->rightchild = temp;
      q.enqueue(temp);
    }
  }
}

void Tree::Preorder(Node *current) {
  if (current) {
    std::cout << current->data << ",";
    Preorder(current->leftchild);
    Preorder(current->rightchild);
  }
}

void Tree::Inorder(Node *current) {
  if (current) {
    Inorder(current->leftchild);
    std::cout << current->data << ",";
    Inorder(current->rightchild);
  }
}

void Tree::Postorder(Node *current) {
  if (current) {
    Postorder(current->leftchild);
    Postorder(current->rightchild);
    std::cout << current->data << ",";
  }
}

void Tree::Levelorder(Node *current) {
  Queue q(100);
  std::cout << head->data << ",";
  q.enqueue(head);

  while (!q.isempty()) {
    current = q.dequeue();
    if (current->leftchild) {
      std::cout << current->leftchild->data << ",";
      q.enqueue(current->leftchild);
    }
    if (current->rightchild) {
      std::cout << current->rightchild->data << ",";
      q.enqueue(current->rightchild);
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

Tree::~Tree() {
  delete head->leftchild;
  delete head->rightchild;
  delete head;
}

int main() {

  Tree t;

  t.CreateTree();

  std::cout << "Preorder: ";
  t.Preorder(t.getRoot());
  std::cout << std::endl;

  std::cout << "Inorder: ";
  t.Inorder(t.getRoot());
  std::cout << std::endl;

  std::cout << "Postorder: ";
  t.Postorder(t.getRoot());
  std::cout << std::endl;

  std::cout << "Levelorder: ";
  t.Levelorder(t.getRoot());
  std::cout << std::endl;

  std::cout << "Height: " << t.Height(t.getRoot()) << std::endl;

  std::cout << "Recursive Passing Private Parameter in Constructor"
            << std::endl;

  std::cout << "Preorder: ";
  t.Preorder();
  std::cout << std::endl;

  std::cout << "Inorder: ";
  t.Inorder();
  std::cout << std::endl;

  std::cout << "Postorder: ";
  t.Postorder();
  std::cout << std::endl;

  std::cout << "Levelorder: ";
  t.Levelorder();
  std::cout << std::endl;

  std::cout << "Height: " << t.Height() << std::endl;
}