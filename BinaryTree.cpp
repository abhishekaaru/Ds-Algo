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

// count nodes

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int SumNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    return SumNodes(root->left) + SumNodes(root->right) + root->data;
    
}

// height of binary tree

int HeightBT(Node* root){

    if(root==NULL){
        return 0;
    }

    int lh,rh;

    lh = HeightBT(root->left);
    rh = HeightBT(root->right);

    return max(lh,rh) + 1;
}

// diameter of tree

int DiameterBT(Node* root){

    if(root==NULL){
        return 0;
    }

    int lh = HeightBT(root->left);
    int rh = HeightBT(root->right);
    int curr = lh + rh + 1;

    int ld = DiameterBT(root->left);
    int rd = DiameterBT(root->right);

    return max( curr , max(ld,rd) );
}

int DiameterBT1(Node* root,int* height){
    
    if(root==NULL){
        return 0;
    }

    int lh=0,rh=0;

    int ld = DiameterBT1(root->left , &lh);
    int rd = DiameterBT1(root->right , &rh);

    int currD = lh + rh + 1;
    *height = max(lh,rh) + 1;

    return max(currD , max(ld,rd));
}

// sum nodes

void SumReplaceNodes(Node* root){

    if(root==NULL){
        return;
    }
    
    SumReplaceNodes(root->left);
    SumReplaceNodes(root->right);

    if(root->left!=NULL){
        root->data += root->left->data;
    }

    if(root->right!=NULL){
        root->data += root->right->data;
    }
}

void printPre(Node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}

// Hieght Balanced or not

bool HeightBalanced(Node* root){

    if(root==NULL){
        return true;
    }

    if(HeightBalanced(root->left) == false){
        return false;
    }

    if(HeightBalanced(root->right) == false){
        return false;
    }

    int lh = HeightBT(root->left);
    int rh = HeightBT(root->right);

    if(abs(lh-rh) <= 1){
        return true;
    }
    else{
        return false;
    }
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

    cout<<countNodes(root)<<endl;

    cout<<SumNodes(root)<<endl;

    cout<<HeightBT(root)<<endl;

    cout<<DiameterBT(root)<<endl;

    int height=0;
    cout<<DiameterBT1(root,&height)<<endl;

    SumReplaceNodes(root);
    printPre(root);
    cout<<endl;

    if(HeightBalanced(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }



    return 0;
}
