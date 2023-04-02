#include <iostream>
#include <string>
struct Node {
    char data;
    Node* next;
};


Node* createLinkedList(std::string str) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < str.length(); i++) {
        Node* newNode = new Node;
        newNode->data = str[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
std::string reverseString(Node* head) {
    std::string reversedStr = "";
    Node* current = head;
    while (current != NULL) {
        reversedStr = current->data + reversedStr;
        current = current->next;
    }
    return reversedStr;
}

int main() {
    std::string str;
    std::getline(std::cin,str);
    Node* head = createLinkedList(str);
    std::string reversedStr = reverseString(head);
    std::cout << reversedStr <<std::endl;
    return 0;
}

