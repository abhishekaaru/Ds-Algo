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

// first Way
// Max path from any node

int maxPathUtil(Node* root,int &ans){

    if(root == NULL){
        return 0;
    }

    int L = maxPathUtil(root->left,ans);
    int R = maxPathUtil(root->right,ans);

    int nodeMax;
    nodeMax = max( max(root->data , root->data + L + R) , max(root->data + L , root->data + R) );

    ans = max(nodeMax,ans);

    int singlePathSum = max( root->data , max(root->data + L , root->data + R) );

    return singlePathSum;
}

int maxPathSum(Node* root){

    int ans=INT_MIN;

    maxPathUtil(root,ans);

    return ans;
}

// Second Way
// Max path btw two leaf nodes

int maxPathSumUtil(Node *root, int &res){
    // Base cases
    if (root==NULL){
        return 0;
    }

    if (!root->left && !root->right){ 

        return root->data;
    }
 
    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);
 
 
    if (root->left && root->right){

        res = max(res, ls + rs + root->data);
 
        return max(ls, rs) + root->data;
    }
 
    return (!root->left)? rs + root->data : ls + root->data;
}


int maxPathSum1(Node* root){

    int res = INT_MIN;
   
    int val = maxPathSumUtil(root, res);
           
   
    if(res == INT_MIN){
      return val;
    }
   
    return res;
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

    cout<<maxPathSum(root);

    return 0;
}