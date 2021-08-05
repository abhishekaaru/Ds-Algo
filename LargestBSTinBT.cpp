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
// One way 

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node* root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }

    if(root->left == NULL && root->right == NULL ){
        return {1,root->data,root->data,1,true};
    }

    Info leftinfo = largestBST(root->left);
    Info rightinfo = largestBST(root->right);

    Info curr;
    curr.size = (1 + leftinfo.size + rightinfo.size);

    if(leftinfo.isBST && rightinfo.isBST && leftinfo.max < root->data && rightinfo.min > root->data){

        curr.min = min(leftinfo.min , min(rightinfo.min, root->data));
        curr.max = max(rightinfo.max , max(leftinfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftinfo.ans,rightinfo.ans);
    curr.isBST = false;
    return curr;
}

// Another way

int size2(Node* root){
    if(root==NULL){
        return 0;
    }
    
    return size2(root->left) + 1 + size2(root->right);
}

bool isBST2(Node* root,int min,int max){
    
    if(root==NULL){
        return true;
    }
    
    
    if(root->data < min || root->data > max){
        return false;
    }
    
    
    return isBST2(root->left,min,root->data) && isBST2(root->right,root->data,max);
}


int largestBST2(Node *root)
{
	if(isBST2(root,INT_MIN,INT_MAX)){
	    return size2(root);
	}
	
	return max(largestBST2(root->left),largestBST2(root->right));
}

int main(){

    struct Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(10);
    
    

    //     15
    //    /   \
    //  20     30
    //  /     
    // 10       

    cout<<"Largest BST in BT : "<<largestBST(root).ans<<endl;

    cout<<"Largest BST in BT : "<<largestBST2(root);

    return 0;
}