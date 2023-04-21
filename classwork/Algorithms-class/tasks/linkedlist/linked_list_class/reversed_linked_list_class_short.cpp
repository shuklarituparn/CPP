#include<iostream>
#include<string>

struct Node {
    char data;
    Node* next = nullptr;
};

class List {
private:
    Node* head = nullptr;
public:
    List(std::string str) {
        Node* tail = nullptr;
        for (char c : str) {
            Node* new_node = new Node{ c };
            if (!head) {
                head = new_node;
                tail = new_node;
            }
            else {
                tail->next = new_node;
                tail = new_node;
            }
        }
    }
    Node* get_head() const { return head; }
};
/*
By declaring a member function as const, you are telling the compiler that this function will not modify any of the member variables of the class. In this case, the function get_head() does not modify the head member variable of the List class, and so it can be declared as const.

Declaring a function as const also allows you to call that function on const objects of the class. For example, if you have a const List object, you can call the const member function get_head() on it to retrieve the head pointer without worrying about accidentally modifying the object.


*/
class reversed_linked_list {
private:
    Node* head = nullptr;
public:
    reversed_linked_list(const List& list) {
        Node* current = list.get_head();
        while (current) {
            Node* next = current->next;
            current->next = head;
            head = current;
            current = next;
        }
    }
    Node* get_head() const { return head; }
};

void display_linked_list(const Node* head) {
    while (head) {
        std::cout << head->data;
        head = head->next;
    }
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    List myList{ str };
    reversed_linked_list reversedList{ myList };
    display_linked_list(reversedList.get_head());
    return 0;
}
