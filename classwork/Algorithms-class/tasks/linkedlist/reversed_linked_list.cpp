#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node* head = NULL;  //Initializing it as NUll to not create any garbage
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        Node* new_node = new Node;  //creating a new struct called node and saving its ptr
        new_node->data = num;   
        new_node->next = NULL;   
        
        if (head == NULL) {    
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;  //
            tail = tail->next;
        }
    }

    //From this point onwards in our program we have the linked list

Node* prev= NULL;
Node*forward= NULL;
Node*curr =head;

//cout << "\nThe reversed linked list is: ";

while (curr!=NULL)
{
forward=curr->next;
curr->next=prev;
prev=curr;
curr=forward;
}

Node*ptr= tail;

while (ptr!= NULL)
{
    cout << ptr->data;
    ptr = ptr->next;
}
return 0;
}
