#include<iostream>
#include<string>

struct Node{   //Struct that holds data and the pointer to the next element

    char data;  //making it as char so that we have each character as a seperate
    Node* next;  //pointer to the next element

};

class List{   //class List, basically condensing the operation on a string into-
                //-a simple collection 
  private:
    Node *head;   //private holds a node called head. private as we don't wan't-
                  //-anyone to change the head
  public:
    List(std::string str);  //default constructor that initialize the class  with string 
    void display_linked_list(Node *head); //function that takes the head and display the linked list
    Node* get_head() { return head; } //as we can't access the private member, so a getter that return a pointer of the type NODE*
};

class reversed_linked_list{   //a seperate class called reverse_linked_list
    private:  //private member of the class
    Node *head;    //head is private as we don't want anyone accessing it
    public:
    reversed_linked_list(List list); //we have a default constructor that's initialized with class list
    void display_linked_list(Node *head); //again the use of display_linked_list that is NODE*
    Node* get_head(){return head;} //getter to return the head value


};
void reversed_linked_list::display_linked_list(Node *head){ //definition of function outside the class
    Node*ptr= head;
    while (ptr!=nullptr){
        std::cout<<ptr->data;
        ptr=ptr->next;
    }
}

reversed_linked_list::reversed_linked_list(List list){ //definition of the default constructor of the class reversed_linked_list
    Node* current= list.get_head(); //getting the head of the list function
                                //one of the reason of memory leak, when List pointer goes out of scope we still are using it
    Node *forward= nullptr; //forward pointer as null
    Node* previous=nullptr; //previous pointer as null
    while (current!=nullptr)  //while head is not null we will iterate
    {
        forward=current->next; //in the forward pointer we'll store address of next element, which is stored in head or (current->next)
        current->next=previous; //in the first step we are initializing the next pointer to null and in the next iteration we're storing the address from the previous into head 
        previous=current; //making previous the current node
        current=forward; //making the current node, the forward
    }
    head=previous; //assigning head to the previous

    
}


void List::display_linked_list(Node *head){
    Node*ptr= head;
    while (ptr!=nullptr){
        std::cout<<ptr->data;
        ptr=ptr->next;
    }
}

List::List(std::string str){
    head = nullptr;  //initializing head as nullptr so that it doesn't gives any error
    Node* tail = nullptr; //initializing the tail as a nullptr too
    for (size_t i = 0; i < str.length(); i++){ //creating a new node for each of our input
        Node* new_node= new Node; //since new returns a pointer so returning NODE*
        new_node->data=str[i];// since we have have a pointer we can assign value using "->"
        new_node->next=nullptr;
        if (head==nullptr){  //if there's one element in the linked list then both the head and tail will point to the same element
            head=new_node; 
            tail=new_node;
        }
        else{
            tail->next=new_node;  //address of the tail to the new_node
            tail=new_node;  //moving the node to the next node
        }   
    }
}

int main(){
    std::string str;
    std::getline(std::cin, str); //getting the entire line of char and copying it to the string variable str
    List myList{str}; //creating a list called myList with string as the input
    //myList.display_linked_list(myList.get_head()); 
    //Node* reversed_head = myList.reverse_linked_list(myList.get_head());
    reversed_linked_list reversedList {myList}; //creating a class reversed linked list with our class 
    reversedList.display_linked_list(reversedList.get_head()); //displaying our reversed linked list



    return 0;
}


/*

In this program, I made a seperate class to reverse a link list.

FIrs





*/