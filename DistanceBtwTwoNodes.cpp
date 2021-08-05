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

Node* LCA(Node* root,int n1,int n2){
    
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* l = LCA(root->left,n1,n2);
    Node* r = LCA(root->right,n1,n2);

    if(l==NULL && r==NULL){
        return NULL;
    }

    if(l != NULL && r != NULL){
        return root;
    }

    if(l != NULL){
        return LCA(root->left,n1,n2);
    }

    if(r != NULL){
        return LCA(root->right,n1,n2);
    }
}

int findDis(Node* root,int k,int dis){ // root=lca, k=n1,n2 , dis=distance traveled

    if(root==NULL){
        return -1;
    }

    if(root->data == k){
        return dis;
    }

    int l = findDis(root->left,k,dis+1);
    if(l != -1){
        return l;
    }

    int r = findDis(root->right,k,dis+1);
    if(r != -1){
        return r;
    }
}

int disBtwNodes(Node* root,int n1,int n2){

    Node* lca = LCA(root,n1,n2);

    int d1 = findDis(lca,n1,0);
    int d2 = findDis(lca,n2,0);

    return d1+d2;
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

    cout<<disBtwNodes(root,4,7)<<" ";
    return 0;
}