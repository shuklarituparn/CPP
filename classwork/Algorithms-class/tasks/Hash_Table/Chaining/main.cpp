//
// Created by rituparn on 02.05.23.
//

#include <iostream>

class Node{
    public:
     int data;
     Node *next;
};

class HashTable{
public:
    HashTable(); //default constructor
    Node **Hash_table_;
    int Hash(int key); //hash function to return a hash value
    void Insert(int key); //insert function to insert a key
    int Search(int key); //search function to return the position if key found
    ~HashTable();  //default destructor

};

HashTable::HashTable() {
        Hash_table_=new Node*[10]; //creating a new array of node pointers
    for (int i = 0; i < 10; ++i) {
        Hash_table_[i]=NULL;
    }
}

int HashTable::Hash(int key){
    return key%10;
}

void HashTable::Insert(int key) {
    int index= Hash(key);
    Node *new_node=new Node;
    Node *current=Hash_table_[index];
    Node *previous=Hash_table_[index];
    new_node->data=key;
    new_node->next=NULL;

    if (Hash_table_[index]==NULL){
        Hash_table_[index]=new_node;
    }
    else{
        while(current&&current->data<key){
            current=previous;
            current=current->next;

        }
        if (previous==Hash_table_[index]){
            new_node->next=Hash_table_[index];
            Hash_table_[index]=new_node;
        } else{
            new_node->next=previous->next;
            previous->next=new_node;
        }

    }

}

int HashTable::Search(int key) {
    int index= Hash(key);
    Node *current=Hash_table_[index];
    while (current){
        if (current->data==key){
            return current->data;
        }
        current=current->next;
    }
    return -1;
}

HashTable::~HashTable() {
    for (int i = 0; i < 10; i++) {
        Node* current=Hash_table_[i];
        while (Hash_table_[i]){
            Hash_table_[i]=Hash_table_[i]->next;
            delete current;
            current = Hash_table_[i];
        }
    }
    delete [] Hash_table_;
}

int main(){
    HashTable HT;
    HT.Insert(25);
    HT.Insert(55);
    HT.Insert(23);
    HT.Search(55);
    HT.Search(44);
    int value= HT.Search(44);
    std::cout<<value<<std::endl;
    value=HT.Search(55);
    std::cout<<value<<std::endl;

}