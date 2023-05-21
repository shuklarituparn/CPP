#include<iostream>
#include <queue>
#include <stack>

using namespace std;

class Node{
public: 
    Node* leftchild_;
    Node* rightchild_;
    int data_;

};

class Tree{
    private:
        Node* root;
    public:
        Tree();
        ~Tree();
        void CreateTree_();
        void PreorderTraversal_(Node* p);
        void PreorderTraversal_(){PreorderTraversal_(root);}
        void InorderTraversal_(Node* p);
        void InorderTraversal_(){InorderTraversal_(root);}
        void PostorderTraversal_(Node* p);
        void PostorderTraversal_(){PostorderTraversal_(root);}
        void LevelorderTraversal_(Node* p);
        void LevelorderTraversal_(){LevelorderTraversal_(root);}
        int height_(Node* p);
        int height(){return height_(root);}
        void IterativePreorderTraversal_(Node* p);
        void IterativePreorderTraversal_(){IterativePreorderTraversal_(root);}
        void IterativePostorderTraversal_(Node *p);
        void IterativePostorderTraversal_(){IterativePostorderTraversal_(root);}
        void IterativeInorderTraversal_(Node *p);
        void IterativeInorderTraversal_(){IterativeInorderTraversal_(root);}

};

Tree::Tree(){   //base case where the root is a nullptr and doesn't point anywhere
    root=nullptr;
}