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

Node* ConstructBST(int n,int preorder[],int *preidx,int key,int min,int max){

    if(*preidx >= n){
        return NULL;
    }

    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preidx += 1;

        if(*preidx<n){
            root->left = ConstructBST(n,preorder,preidx,preorder[*preidx],min,key);
        }

        if(*preidx<n){
            root->right = ConstructBST(n,preorder,preidx,preorder[*preidx],key,max);
        }
    }

    return root;
}

void Preorder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

int main(){

    int preorder[]={10,2,1,13,11};
    int n = 5;
    int preidx=0;
    int key = preorder[0];

    Node* root=ConstructBST(n,preorder,&preidx,key,INT_MIN,INT_MAX);

    Preorder(root);

    return 0;
}