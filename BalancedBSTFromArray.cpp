// Build a BST from an sorted array

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

Node* buildBST(int a[],int st,int en){

    if(st>en){
        return NULL;
    }

    int mid = (st+en)/2;
    Node* root = new Node(a[mid]);

    root->left = buildBST(a,st,mid-1);
    root->right = buildBST(a,mid+1,en);

    return root;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int a[]={1,2,3,4,5,6,7};

    Node* root = buildBST(a,0,6);
    preorder(root);
    cout<<endl;

    return 0;
}