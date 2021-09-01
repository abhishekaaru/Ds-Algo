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

int search(int inorder[],int st,int en,int curr){

    for(int i=st;i<=en;i++){

        if(inorder[i]==curr){
            return i;
        }
    }

    return -1;
}

Node* BuildTreePreIn(int preorder[],int inorder[],int st,int en,int *idx){

    if(st>en){
        return NULL;
    }

    int curr = preorder[*idx];
    (*idx)++;

    Node* node=new Node(curr);

    if(st==en){
        return node;
    }

    int pos = search(inorder,st,en,curr);
    node->left = BuildTreePreIn(preorder,inorder,st,pos-1,idx);
    node->right = BuildTreePreIn(preorder,inorder,pos+1,en,idx);

    return node;
}

Node *BuildTreePostIn(int postorder[], int inorder[], int st, int en, int *idx)
{

    if (st > en){
        return NULL;
    }

    int curr = postorder[*idx];
    (*idx)--;

    Node *node = new Node(curr);

    if (st == en){
        return node;
    }

    int pos = search(inorder, st, en, curr);
    node->right = BuildTreePostIn(postorder, inorder, pos + 1, en, idx);
    node->left = BuildTreePostIn(postorder, inorder, st, pos - 1, idx);

    return node;
}

void Inorderprint(Node* root){

    if(root==NULL){
        return;
    }

    Inorderprint(root->left);
    cout<<(root->data)<<" ";
    Inorderprint(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    int postoder[]={4,2,5,3,1};

    int idxPost = 4;
    int idxPre = 0;

    // Node* root = BuildTreePreIn(preorder,inorder,0,4,&idxPre);

    Node* root = BuildTreePostIn(preorder,inorder,0,4,&idxPost);

    Inorderprint(root);

    return 0;
}