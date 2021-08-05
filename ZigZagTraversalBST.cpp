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

void ZigZag(Node* root){

    if(root==NULL){
        return;
    }

    stack<Node*> currlevel;
    stack<Node*> nextlevel;

    bool LeftToRight = true;
    
    currlevel.push(root);

    while(!currlevel.empty()){

        Node* temp = currlevel.top();
        currlevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(LeftToRight){

                if(temp->left){
                    nextlevel.push(temp->left);
                }

                if(temp->right){
                    nextlevel.push(temp->right);
                }
            }

            else{

                if(temp->right){
                    nextlevel.push(temp->right);
                }

                if(temp->left){
                    nextlevel.push(temp->left);
                }
            }
        }

        if(currlevel.empty()){

            LeftToRight = !LeftToRight;
            swap(currlevel,nextlevel);
        }
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

    ZigZag(root);

    return 0;
}