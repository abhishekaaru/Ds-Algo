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

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node* root, Node** first,Node** mid,Node** last,Node** prev){

    if(root==NULL){
        return;
    }

    calcPointers(root->left,first,mid,last,prev);

    if(*prev && root->data < (*prev)->data){

        if(!*first){
            // adjecent case

            *first = *prev;
            *mid = root;
        }
        else{
            // not adejcent case (because first is already assigned)

            *last = root;
        }
    }
    *prev = root; // for next step
    calcPointers(root->right,first,mid,last,prev);
}

void restore(Node* root){
    if(root==NULL){
        return;
    }

    Node* first = NULL;
    Node* mid = NULL;
    Node* last = NULL;
    Node* prev = NULL;

    calcPointers(root,&first,&mid,&last,&prev);

    // Non-adjecent case

    if(first && last){
        swap( &(first->data) , &(last->data) );
    }

    // adjecent case

    else if(first && mid){
        swap( &(first->data) , &(mid->data) );
    }
    
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    struct Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(3);

    //      5
    //    /   \
    //   2     7
    //  / \   / \
    // 1   3 6   8

    inorder(root);
    cout<<endl;

    restore(root);
    inorder(root);

    return 0;
}