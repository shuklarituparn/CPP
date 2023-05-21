#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

class Node {
public:
  Node *leftchild_;
  Node *rightchild_;
  int data_;
};

class Tree {
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void CreateTree_();
  void PreorderTraversal_(Node *p);
  void PreorderTraversal_() { PreorderTraversal_(root); }
  void InorderTraversal_(Node *p);
  void InorderTraversal_() { InorderTraversal_(root); }
  void PostorderTraversal_(Node *p);
  void PostorderTraversal_() { PostorderTraversal_(root); }
  void LevelorderTraversal_(Node *p);
  void LevelorderTraversal_() { LevelorderTraversal_(root); }
  int height_(Node *p);
  int height_() { return height_(root); }
  void IterativePreorderTraversal_(Node *p);
  void IterativePreorderTraversal_() { IterativePreorderTraversal_(root); }
  void IterativePostorderTraversal_(Node *p);
  void IterativePostorderTraversal_() { IterativePostorderTraversal_(root); }
  void IterativeInorderTraversal_(Node *p);
  void IterativeInorderTraversal_() { IterativeInorderTraversal_(root); }
};

Tree::Tree() { // base case where the root is a nullptr and doesn't point
               // anywhere
  root = nullptr;
}

Tree::~Tree() { // default destructor
  if (root != nullptr) {
    delete root->leftchild_;
    delete root->rightchild_;
    delete root;
  }
}

void Tree::CreateTree_() {

  Node *temp1;     // pointer that'll be used to traverse the tree
  Node *temp2;     // pointer that'll be used to create new node
  int element;     // element input the user enters to the program
  queue<Node *> q; // a queue of the Node pointers

  root = new Node;
  cout << "Enter the root node data: " << flush;
  cin >> element;
  root->data_ = element;
  root->leftchild_ = nullptr;
  root->rightchild_ = nullptr;
  q.emplace(root);

  while (!q.empty()) { // checking if the the queue is empty

    temp1 = q.front(); // assigning the front of the queue to temp variable used
                       // to traverse
    q.pop(); // after assigning the address from the queue, popping the value

    cout << "Enter the left child data of " << temp1->data_ << ": " << flush;

    cin >> element;

    if (element != -1) {
      temp2 = new Node;
      temp2->data_ = element;
      temp2->leftchild_ = nullptr;
      temp2->rightchild_ = nullptr;
      temp1->leftchild_ = temp2;
      q.emplace(temp2);
    }

    cout << "Enter the right child data of " << temp1->data_ << ": " << flush;
    cin >> element;
    if (element != -1) {
      temp2 = new Node;
      temp2->data_ = element;
      temp2->leftchild_ = nullptr;
      temp2->rightchild_ = nullptr;
      temp1->rightchild_ = temp2;
      q.emplace(temp2);
    }
  }
}

void Tree::PreorderTraversal_(
    Node *p) { // here P is the temp pointer used for the tree traversal

  if (p) {
    cout << p->data_ << ", " << flush;
    PreorderTraversal_(p->leftchild_);
    PreorderTraversal_(p->rightchild_);
  }
}

void Tree::InorderTraversal_(
    Node *p) { // here P is the temp pointer used for the tree traversal
  if (p) {
    InorderTraversal_(p->leftchild_);
    cout << p->data_ << ", " << flush;
    InorderTraversal_(p->rightchild_);
  }
}

void Tree::PostorderTraversal_(
    Node *p) { // here P is the temp pointer used for the tree traversal
  if (p) {
    PostorderTraversal_(p->leftchild_);
    PostorderTraversal_(p->rightchild_);
    cout << p->data_ << ", " << flush;
  }
}

void Tree::LevelorderTraversal_(
    Node *p) { // here P is the temp pointer used for the tree traversal

  queue<Node *> q;
  cout << p->data_ << ", " << flush;
  q.emplace(p);

  while (!q.empty()) {
    p = q.front();
    q.pop();

    if (p->leftchild_) {
      cout << p->leftchild_->data_ << ", " << flush;
      q.emplace(p->leftchild_);
    }

    if (p->rightchild_) {
      cout << p->rightchild_->data_ << ", " << flush;
      q.emplace(p->rightchild_);
    }
  }
}

int Tree::height_(
    Node *p) { // here P is the temp pointer used for the tree traversal
  int left = 0;
  int right = 0;
  if (p == nullptr) {
    return 0; // for the empty tree
  }
  left = height_(p->leftchild_);   // recursively calling the height function on
                                   // left part of the tree
  right = height_(p->rightchild_); // recursively calling the height function on
                                   // right part of the tree
  if (left > right) // if left>right we need to consider right as based on it we
                    // can calculate the height of the tree
  {
    return left + 1; // returning the left height plus +1 for the root
  } else {
    return right + 1; // returning the right height plus +1 for the root
  }
}

void Tree::IterativePreorderTraversal_(
    Node *p) { // here P is the temp pointer used for the tree traversal

  stack<Node *> stk;

  while (p != nullptr ||
         !stk.empty()) { // checking if the current pointer is null

    if (p != nullptr) {
      cout << p->data_ << ", "
           << flush;     // printing the data of the current pointer
      stk.emplace(p);    // storing the current pointer in the stack
      p = p->leftchild_; // moving to the left child of the current pointer and
                         // then storing it in the stack if its not null
    } else {

      // We are on Else meaning that left tree is already empty
      p = stk.top();      // Now the last adress will be on top as it is stack
      stk.pop();          // remove the last element as it is in the process
      p = p->rightchild_; // move to the right child of the current pointer
    }
  }
  cout << endl;
}

void Tree::IterativeInorderTraversal_(
    Node *p) { // here P is the temp pointer used for the tree traversal

  stack<Node *> stk;

  while (p != nullptr || !stk.empty()) {

    if (p != nullptr) {
      stk.emplace(p);
      p = p->leftchild_;
    } else {
      p = stk.top();
      stk.pop();
      cout << p->data_ << ", " << flush;
      p = p->rightchild_;
    }
  }
  cout << endl;
}

void Tree::IterativePostorderTraversal_(Node *p) {
  stack<long int> stk; // to store the node pointers
  long int temp; // to store the temporary values during postorder traversal
  while (p != nullptr || !stk.empty()) {
    if (p != nullptr) {
      stk.emplace((long int)p); // adding pointer p to the top of stack by
                                // converting to long int
      p = p->leftchild_;        // moving the current pointer to the left child
    } else {            // meaning all nodes in left subtree are processed
      temp = stk.top(); // assigns the top eleement to the temporary values
      stk.pop(); // removes the top element as its processed or will be soon
      if (temp > 0) { // checking if there's a node to be processed by value of
                      // temp (as it holds a pointer)>0
        stk.emplace(-temp); // storing the unprocessed value in the stack. -ve
                            // value to denote that it's unprocessed
        p = ((Node *)temp)
                ->rightchild_; // moving the current pointer to the right child
                               // of the node represented by temp
      } else {
        cout << ((Node *)(-1 * temp))->data_ << ", "
             << flush; // prints the data of the node represented by -1*temp.
                       // -1*temp returns the original value
        p = nullptr;   // making the current pointer as nullptr to denote that
                       // current subtree is processed
      }
    }
  }
  cout << endl;
}

int main() {

  Tree bt;

  bt.CreateTree_();
  cout << endl;

  cout << "Preorder: " << flush;
  bt.PreorderTraversal_();
  cout << endl;

  cout << "Inorder: " << flush;
  bt.InorderTraversal_();
  cout << endl;

  cout << "Postorder: " << flush;
  bt.PostorderTraversal_();
  cout << endl;

  cout << "Levelorder: " << flush;
  bt.LevelorderTraversal_();
  cout << endl;

  cout << "Height: " << bt.height_() << endl;

  cout << "Iterative Preorder: " << flush;
  bt.IterativePreorderTraversal_();

  cout << "Iterative Inorder: " << flush;
  bt.IterativeInorderTraversal_();

  cout << "Iterative Postorder: " << flush;
  bt.IterativePostorderTraversal_();

  return 0;
}