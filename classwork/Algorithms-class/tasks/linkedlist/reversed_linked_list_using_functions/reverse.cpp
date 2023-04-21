

#include<iostream>
#include<string>

struct Node{

    char data;
    Node* next;

};
class List{
  private:
    Node *head;
  public:
    explicit List(std::string);
    void display_linked_list();
    Node* get_head() { return head; }
    void reverse_linked_list();

};
void List::display_linked_list(){
    Node*ptr= head;
    while (ptr!=nullptr){
        std::cout<<ptr->data;
        ptr=ptr->next;
    }
}
List::List(std::string str){
    head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < str.length(); i++){
        Node* new_node= new Node;
        new_node->data=str[i];
        new_node->next=nullptr;
        if (head==nullptr){
            head=new_node;
            tail=new_node;
        }
        else{
            tail->next=new_node;
            tail=new_node;
        }   
    }
}
void List::reverse_linked_list() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

}
int main(){
    std::string str;
    std::getline(std::cin, str);
    List myList{str};
    myList.reverse_linked_list();
    myList.display_linked_list();
    return 0;
}
