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

vector<Node*> condtructTrees(int st,int en){

    vector<Node*> tree;

    if(st>en){
        tree.push_back(NULL);
        return tree;
    }

    for(int i=st;i<=en;i++){
        vector<Node*> leftsubtree = condtructTrees(st,i-1);
        vector<Node*> rightsubtree = condtructTrees(i+1,en);

        for(int j=0;j<leftsubtree.size();j++){
            Node* l = leftsubtree[j];

            for(int k=0;k<rightsubtree.size();k++){
                Node* r = rightsubtree[k];

                Node* node = new Node(i);
                node->left = l;
                node->right = r;
                tree.push_back(node);
            }
        }
    }
    return tree;
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

    vector<Node*> totaltree = condtructTrees(1,3);
    for(int i=0;i<totaltree.size();i++){
        cout<<i+1<<" : ";
        preorder(totaltree[i]);
        cout<<endl;
    }

    return 0;
}