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

bool TreeIdentical(Node* root1,Node* root2){

    if(root1==NULL && root2==NULL){
        return true;
    }

    else if(root1==NULL || root2==NULL){
        return false;
    }

    else{
        bool cond1 = (root1->data == root2->data);
        bool cond2 = TreeIdentical(root1->left,root2->left);
        bool cond3 = TreeIdentical(root1->right,root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }

        return false;
    }
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


    if(TreeIdentical(root,root)){
        cout<<"BST's are Identical"<<endl;
    }
    else{
        cout<<"BST's are not Identical"<<endl;
    }

    return 0;
}