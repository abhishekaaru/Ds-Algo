#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool checkBST(Node* root,Node* minAllow, Node* maxAllow){

    if(root==NULL){
        return true;
    }

    if(minAllow != NULL && minAllow->data >= root->data){
        return false;
    }

    if(maxAllow != NULL && maxAllow->data <= root->data){
        return false;
    }

    bool leftValid,rightValid;
    leftValid = checkBST(root->left,minAllow,root);
    rightValid = checkBST(root->right,root,maxAllow);

    return leftValid && rightValid;
}

int main(){

    struct Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    //      5
    //    /   \
    //   2     7
    //  / \   / \
    // 1   3 6   8

    if(checkBST(root,NULL,NULL)){
        cout<<"BST is Valid"<<endl;
    }
    else{
        cout<<"BST is Invalid"<<endl;
    }

    return 0;
}