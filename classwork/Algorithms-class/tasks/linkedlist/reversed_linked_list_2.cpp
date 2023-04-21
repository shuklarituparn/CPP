#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void add(char data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {
    string input = "ka 1 b 2 c 31";
    LinkedList list;
    for (int i = 0; i < input.size(); i += 2) {
        list.add(input[i]);
    }
    list.reverse();
    Node* current = list.head;
    while (current != NULL) {
        cout << current->data;
        current = current->next;
        if (current != NULL && current->data >= '0' && current->data <= '9') {
            cout << current->data;
            current = current->next;
        }
        if (current != NULL) {
            cout << " ";
        }
    }
    return 0;
}
