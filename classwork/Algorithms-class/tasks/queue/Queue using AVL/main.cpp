#include <iostream>
#include <stdexcept> // Include the exception header

using namespace std;

// Node structure for AVL tree
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

class Queue {
private:
    Node* root; // Root node of the AVL tree

public:
    Queue() : root(nullptr) {}
    ~Queue() {
        // Clean up the AVL tree
        clear(root);
    }

    void enqueue(int x);
    int dequeue();
    int front();
    int size();
    bool empty();
    void clear(Node* node);

private:
    int getHeight(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* insert(Node* node, int x);
    Node* findMinValueNode(Node* node);
    Node* remove(Node* node, int x);
};

int Queue::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int Queue::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* Queue::rotateRight(Node* node) {
    Node* newRoot = node->left;
    Node* subtree = newRoot->right;

    newRoot->right = node;
    node->left = subtree;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

Node* Queue::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    Node* subtree = newRoot->left;

    newRoot->left = node;
    node->right = subtree;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

Node* Queue::insert(Node* node, int x) {
    if (node == nullptr) {
        return new Node(x);
    }

    if (x < node->data) {
        node->left = insert(node->left, x);
    } else {
        node->right = insert(node->right, x);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && x < node->left->data) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && x > node->right->data) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && x > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && x < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* Queue::findMinValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* Queue::remove(Node* node, int x) {
    if (node == nullptr) {
        return nullptr;
    }

    if (x < node->data) {
        node->left = remove(node->left, x);
    } else if (x > node->data) {
        node->right = remove(node->right, x);
    } else {
        // Node to be deleted is found

        // Case 1: Node with only one child or no child
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            // Case 2: Node with two children
            Node* temp = findMinValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (node == nullptr) {
        return nullptr;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0) {
        return rotateLeft(node);
    }

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void Queue::enqueue(int x) {
    root = insert(root, x);
}

int Queue::dequeue() {
    if (root == nullptr) {
        throw runtime_error("Queue is empty");
    }

    int frontValue = root->data;
    root = remove(root, frontValue);

    return frontValue;
}

int Queue::front() {
    if (root == nullptr) {
        throw runtime_error("Queue is empty");
    }
    return root->data;
}

int Queue::size() {
    return getHeight(root);
}

bool Queue::empty() {
    return (root == nullptr);
}

void Queue::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

int main() {
    Queue q;
    string cmd;
    while (cin >> cmd) {
        try {
            if (cmd == "enqueue") {
                int x;
                cin >> x;
                q.enqueue(x);
                cout << "ok" << endl;
            } else if (cmd == "dequeue") {
                cout << q.dequeue() << endl;
            } else if (cmd == "front") {
                cout << q.front() << endl;
            } else if (cmd == "size") {
                cout << q.size() << endl;
            } else if (cmd == "empty") {
                cout << (q.empty() ? "true" : "false") << endl;
            } else if (cmd == "clear") {
                q.clear(q.root);
                q.root = nullptr;
                cout << "ok" << endl;
            } else {
                break;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
