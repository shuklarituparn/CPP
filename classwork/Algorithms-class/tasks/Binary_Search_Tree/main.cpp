//
// Created by rituparn on 09.06.23.
//

#include <iostream>

class Node{
public:
    Node* left_child;
    Node* right_child;
    int data;
};

class BinarySearchTree{
private:
    Node* root;
public:
    BinarySearchTree();
    Node* GetRoot();
    void Insert(int key);
    void Inorder(Node* p);
    Node* Search(int key);
    Node* RecursiveInsert(Node* p, int key);
    Node* RecursiveSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
};
BinarySearchTree::BinarySearchTree(){
    root= nullptr;
}
Node* BinarySearchTree::GetRoot(){
    return root;
}
void BinarySearchTree::Insert(int key){
    Node *t=root;
    Node* p;
    Node* r; //Temporary Node used to traverse the tree to get to a final location

    if (root== nullptr){
        p= new Node;
        p->data=key;
        p->left_child= nullptr;
        p->right_child= nullptr;
        root=p;
        return;
    }

    while (t!= nullptr){  //we get to the place where we want to insert our key
        r=t;
        if (key<t->data){
            t=t->left_child;
        }else if (key>t->data){
            t=t->right_child;
        }else{
            return;
        }
    }  //after the end of this loop our R points to the Node at desired place

    p= new Node;
    p->data= key;
    p->left_child= nullptr;
    p->right_child= nullptr;

    if (key<r->data){
        r->left_child=p;
    }else{
        r->right_child=p;
    }
}
void BinarySearchTree::Inorder(Node* p){
    if (p){
        Inorder(p->left_child);
        std::cout<<p->data<<std::endl;
        Inorder(p->right_child);
    }
}
Node* BinarySearchTree::Search(int key){
    Node *t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        }
        if (key < t->data) {
            t = t->left_child;
        } else {
            t = t->right_child;
        }
    }
    return nullptr;
}

Node* BinarySearchTree::RecursiveInsert(Node* p, int key){
    Node* t;
    if (p== nullptr){
        t=new Node;
        t->data=key;
        t->left_child= nullptr;
        t->right_child= nullptr;
        return t;
    }
    if (key<p->data){
        p->left_child= RecursiveInsert(p->left_child, key);
    }else{
        p->right_child= RecursiveInsert(p->right_child, key);
    }
}
Node* BinarySearchTree::RecursiveSearch(Node* p, int key){
    if (p== nullptr){
        return nullptr;
    }
    if (key==p->data){
        return p;
    }
    if (key<p->data){
        RecursiveSearch(p->left_child, key);
    }else {
        RecursiveSearch(p->right_child, key);
    }
}
Node* BinarySearchTree::Delete(Node* p, int key){
    Node* q;
    if (p== nullptr){
        return nullptr;
    }
    if ((p->left_child= nullptr) && (p->right_child== nullptr)){
        if (p==root){
            root= nullptr;
        }
        delete p;
        return nullptr;
    }
    if (key<p->data){
        p->left_child= Delete(p->left_child, key);
    }else if(key>p->data){
        p->right_child= Delete(p->right_child, key);
    }else{
        if (Height(p->left_child) > Height(p->right_child)){
            q = InPre(p->left_child);
            p->data = q->data;
            p->left_child = Delete(p->left_child, q->data);
        } else {
            q = InSucc(p->right_child);
            p->data = q->data;
            p->right_child = Delete(p->right_child, q->data);
        }
    }
    return p;
}
int BinarySearchTree::Height(Node* p){
    int height_left;
    int height_right;
    if (p== nullptr){
        return 0;
    }
    height_left= Height(p->left_child);
    height_right= Height(p->right_child);

    return height_left>height_right?height_left+1:height_right+1;
}
Node* BinarySearchTree::InPre(Node* p){
    while (p&&p->right_child!=nullptr){
        p=p->right_child;
    }
    return p;
}
Node* BinarySearchTree::InSucc(Node* p){
    while (p&&p->left_child!= nullptr){
        p=p->left_child;
    }
    return p;
}

int main(){
    BinarySearchTree BST;

    //Iterative Insert

    BST.Insert(10);
    BST.Insert(5);
    BST.Insert(20);
    BST.Insert(8);
    BST.Insert(30);

    //Inorder Traversal

    BST.Inorder(BST.GetRoot());
    std::cout<<std::endl;

    //Iterative Search

    Node* temp= BST.Search(2);
    if (temp!= nullptr){
        std::cout<<temp->data;
    }
    else{
        std::cout<<"Element not found"<<std::endl;
    }

    //Recursive Insert

    BST.RecursiveInsert(BST.GetRoot(),50);
    BST.RecursiveInsert(BST.GetRoot(),70);
    BST.RecursiveInsert(BST.GetRoot(),10);
    BST.Inorder(BST.GetRoot());
    std::cout<<"\n"<<std::endl;

    //Inorder Predecessor and Inorder Successor


    BST.Insert(5);
    BST.Insert(2);
    BST.Insert(8);
    BST.Insert(7);
    BST.Insert(9);
    BST.Insert(1);

    temp=BST.InPre(BST.GetRoot());
    std::cout<<"InPre: "<<temp->data<<std::endl;


    temp=BST.InSucc(BST.GetRoot());
    std::cout<<"InSucc: "<<temp->data<<std::endl;

    BST.Inorder(BST.GetRoot());
    std::cout<<std::endl;

    //DELETE

    BST.Delete(BST.GetRoot(),7);
    BST.Inorder(BST.GetRoot());

    return 0;
}