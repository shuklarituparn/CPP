#include <iostream>

// Node structure for 2-3 tree
struct Node {
    int keys[2];         // Array to hold keys
    Node* children[3];   // Array to hold child pointers
    bool isLeaf;         // Flag to indicate leaf node
    int numKeys;         // Number of keys stored in the node

    // Constructor
    Node() {
        for (int i = 0; i < 3; ++i)
            children[i] = nullptr;
        isLeaf = true;
        numKeys = 0;
    }

    // Destructor
    ~Node() {
        for (int i = 0; i < numKeys + 1; ++i)
            delete children[i];
    }
};

// 2-3 Tree class
class TwoThreeTree {
private:
    Node* root;

    // Helper function to search for a key in the tree
    bool searchHelper(Node* node, int key) {
        if (node == nullptr)
            return false;

        int i = 0;
        while (i < node->numKeys && key > node->keys[i])
            ++i;

        if (i < node->numKeys && key == node->keys[i])
            return true;

        if (node->isLeaf)
            return false;

        return searchHelper(node->children[i], key);
    }

    // Helper function to insert a key into the tree
    void insertHelper(Node* node, int key) {
        if (node->isLeaf) {
            // Insert key into the leaf node
            int i = node->numKeys - 1;
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                --i;
            }
            node->keys[i + 1] = key;
            ++node->numKeys;
        } else {
            // Find the appropriate child to insert the key
            int i = 0;
            while (i < node->numKeys && node->keys[i] < key)
                ++i;

            // Recursively insert into the child node
            if (node->children[i]->numKeys == 2) {
                // Split the full child node before inserting
                splitNode(node, i);
                if (key > node->keys[i])
                    ++i;
            }
            insertHelper(node->children[i], key);
        }
    }

    // Helper function to split a full node during insertion
    void splitNode(Node* parent, int childIndex) {
        Node* splitNode = parent->children[childIndex];
        Node* newNode = new Node();

        // Move the second key and child to the new node
        newNode->keys[0] = splitNode->keys[1];
        newNode->children[0] = splitNode->children[2];
        newNode->children[1] = splitNode->children[3];
        newNode->numKeys = 1;
        newNode->isLeaf = splitNode->isLeaf;

        // Adjust the original node
        splitNode->numKeys = 1;
        splitNode->children[2] = nullptr;
        splitNode->children[3] = nullptr;

        // Rearrange the parent node
        int i = parent->numKeys - 1;
        while (i >= childIndex) {
            parent->keys[i + 1] = parent->keys[i];
            parent->children[i + 2] = parent->children[i + 1];
            --i;
        }
        parent->keys[childIndex] = splitNode->keys[0];
        parent->children[childIndex + 1] = newNode;
        ++parent->numKeys;
    }

    // Helper function to perform the delete operation
    void deleteHelper(Node* node, int key) {
        if (node->isLeaf) {
            // Delete the key from the leaf node
            int i = 0;
            while (i < node->numKeys && node->keys[i] != key)
                ++i;

            if (i == node->numKeys) {
                std::cout << "Key not found!" << std::endl;
                return;
            }

            while (i < node->numKeys - 1) {
                node->keys[i] = node->keys[i + 1];
                ++i;
            }
            --node->numKeys;
        } else {
            // Find the child to continue the delete operation
            int i = 0;
            while (i < node->numKeys && node->keys[i] < key)
                ++i;

            // Recursively delete from the child node
            Node* child = node->children[i];
            if (child->numKeys == 1) {
                // Check if the child has only one key
                Node* sibling = node->children[i == 0 ? 1 : i - 1];
                if (sibling->numKeys > 1) {
                    // Borrow a key from the sibling
                    // Borrow a key from the sibling
                    if (i == 0) {
                        // Borrow from right sibling
                        child->keys[1] = child->keys[0];
                        child->keys[0] = node->keys[0];
                        node->keys[0] = sibling->keys[sibling->numKeys - 1];
                        child->children[2] = child->children[1];
                        child->children[1] = sibling->children[sibling->numKeys];
                        --sibling->numKeys;
                        ++child->numKeys;
                    } else {
                        // Borrow from left sibling
                        child->keys[1] = node->keys[i - 1];
                        node->keys[i - 1] = sibling->keys[sibling->numKeys - 1];
                        child->children[2] = sibling->children[sibling->numKeys];
                        --sibling->numKeys;
                        ++child->numKeys;
                    }

                } else {
                    // Merge the child and sibling
                    // Merge the child and sibling
                    if (i == 0) {
                        // Merge with right sibling
                        sibling->keys[1] = node->keys[0];
                        sibling->children[2] = child->children[1];
                        sibling->numKeys = 2;
                        delete child;
                        node->children[i] = sibling;
                        --node->numKeys;
                    } else {
                        // Merge with left sibling
                        sibling->keys[1] = node->keys[i - 1];
                        sibling->children[2] = child->children[0];
                        sibling->numKeys = 2;
                        delete child;
                        node->children[i - 1] = sibling;
                        --node->numKeys;
                    }

                }
            } else {
                // Continue deletion in the child node
                deleteHelper(child, key);
            }
        }
    }

public:
    // Constructor
    TwoThreeTree() {
        root = nullptr;
    }

    // Public search operation
    bool search(int key) {
        return searchHelper(root, key);
    }

    // Public insert operation
    void insert(int key) {
        if (root == nullptr) {
            // Tree is empty, create a new root node
            root = new Node();
            root->keys[0] = key;
            root->numKeys = 1;
        } else if (root->numKeys == 2) {
            // Root node is full, create a new root and split the current root
            Node* newRoot = new Node();
            newRoot->children[0] = root;
            root = newRoot;
            splitNode(newRoot, 0);
            insertHelper(newRoot, key);
        } else {
            // Insert into the tree
            insertHelper(root, key);
        }
    }

    // Public delete operation
    void remove(int key) {
        if (root == nullptr) {
            std::cout << "Tree is empty!" << std::endl;
        } else {
            deleteHelper(root, key);
        }
    }
};

int main() {
    TwoThreeTree tree;

    tree.insert(5);
    tree.insert(8);
    tree.insert(10);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(2);
    tree.insert(9);
    tree.insert(7);

    std::cout << tree.search(8) << std::endl;  // Output: 1 (true)
    std::cout << tree.search(2) << std::endl;  // Output: 1 (true)
    std::cout << tree.search(11) << std::endl; // Output: 0 (false)

    tree.remove(6);
    std::cout << tree.search(6) << std::endl;  // Output: 0 (false)

    return 0;
}
