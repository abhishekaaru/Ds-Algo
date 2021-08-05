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

// INSERT

Node* insertBST(Node* root,int val){

    if(root==NULL){
        return new Node(val);
    }
    
    if(val < root->data){
        root->left = insertBST(root->left,val);
    }

    else{
        // val < root->data
        root->right = insertBST(root->right,val);
    }

    return root;
}

// SEARCH

Node* SearchBST(Node *root,int key){

    if(root==NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    else if(root->data > key){

        return SearchBST(root->left,key);
    }

    else{

        return SearchBST(root->right,key);
    }

}

// DELETE

Node* inorderSucc(Node* root){

    Node *curr = root;

    while(curr && curr->left != NULL){
        curr = curr->left;
    }

    return curr;
}

Node* deleteBST(Node* root, int key){

    if(root==NULL){
        return NULL;
    }

    if(key < root->data){
        root->left = deleteBST(root->left,key);
    }

    else if(key > root->data){
        root->right = deleteBST(root->right,key);
    }

    else{
        // key == root->data

        // Case 1 and Case 2
        if(root->left == NULL){

            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL){

            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }

    return root;
}



void inorder(Node *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node* root = NULL;

    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,6);
    insertBST(root,8);

    //      5
    //   /    \
    //  1      7
    //   \    / \
    //    3  6   8
    //   / \
    //  2   4

    inorder(root);
    cout<<endl;

    if(SearchBST(root,8) == NULL){
        cout<<"Key Doesn't exist"<<endl;
    }
    else{
        cout<<"key exist"<<endl;
    }

    Node* d = deleteBST(root,3);
    inorder(d);

    return 0;

}