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

void printLevelOrder(Node* root){

    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node =q.front();
        q.pop();

        if(node != NULL){
            cout<<node->data<<" ";

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }

        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int maxLevelSum(Node *root)
{

    if (root == NULL)
        return 0;

    int result = root->data;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();

        int sum = 0;
        while (count--)
        {

            Node *temp = q.front();
            q.pop();

            sum = sum + temp->data;

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }

        result = max(sum, result);
    }

    return result;
}

int sumatKlevel(Node* root,int K){

    if(root==NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level=0;
    int sum=0;

    while(!q.empty()){
        Node* node =q.front();
        q.pop();

        if(node != NULL){
            
            if(level == K){
                sum += node->data;
            }

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }

        else if(!q.empty()){

            q.push(NULL);
            level++;
        }
    }

    return sum;
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

    printLevelOrder(root);
    cout<<endl;

    cout<<sumatKlevel(root,2)<<endl;

    return 0;
}