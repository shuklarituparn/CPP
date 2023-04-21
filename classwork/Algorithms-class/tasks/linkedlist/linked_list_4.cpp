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
    List(std::string str);
    void display_linked_list(Node *head);
    Node* reversed_linked_list(Node *head);
    Node* get_head() { return head; }
};
void List::display_linked_list(Node *head){

    Node*ptr= head;
    while (ptr!=nullptr)
    {
        std::cout<<ptr->data;
        ptr=ptr->next;
    }
}

List::List(std::string str){
    head = nullptr;
    Node* tail = nullptr;
    for (size_t i = 0; i < str.length(); i++)
    {
        Node* new_node= new Node;
        new_node->data=str[i];
        new_node->next=nullptr;
        if (head==nullptr)
        {
            head=new_node;
            tail=new_node;
        }
        else{
            tail->next=new_node;
            tail=new_node;
        }   
    }
}

Node* reversed_linked_list(Node *head){
Node *forward= nullptr;
Node*prev=nullptr;
Node *curr= head;
while (curr!=NULL)
{
forward=curr->next;
curr->next=prev;
prev=curr;
curr=forward;
}
return curr;

}

int main(){
    std::string str;
    std::getline(std::cin, str);
    List myList{str}; 
    myList.display_linked_list(myList.get_head()); 


    return 0;
}
