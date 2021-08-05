// flatten a BT into a LL. After flatten left node should point to NULL and right shold contain next node in preorder sequence

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void flatten(Node* root){

    if(root==NULL || (root->right==NULL && root->left==NULL)){
        return;
    }

    if(root->left != NULL){

        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right; // node which was left before
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }

    flatten(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //      1
    //    /   \
    //   2     3
    //  / \   / \
    // 4   5 6   7

    flatten(root);
    inorder(root);
    cout<<endl;

    return 0;
}