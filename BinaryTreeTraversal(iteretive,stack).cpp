#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

vector<int> preorder(Node* root)
{
    vector<int> r;
    stack<Node*> st;

    if (root) {
        st.push(root);
    }

    while (!st.empty()) {
        auto p = st.top();
        st.pop();
        r.push_back(p->data);
        if (p->right) {
            st.push(p->right);
        }
        if (p->left) {
            st.push(p->left);
        }
    }

    return r;
}

vector<int> inOrder(Node* root){

    vector<int> r;
         
    if (root == NULL) {
        return r;
    }
    stack<Node*> st;
    Node* p = root;
    while (p || !st.empty()) {

        while (p) {
            st.push(p);
            p = p->left;
        }

        p = st.top();
        st.pop();
        r.push_back(p->data);
        p = p->right;
    }

    return r;
}

vector<int> postorder(Node* root) {

    vector<int> r;
    stack<Node*> st;

    if (root) {
        st.push(root);
    }

    while (!st.empty()) {
        auto p = st.top();
        st.pop();
        r.insert(r.begin(), p->data);
        if (p->left) {
            st.push(p->left);
        }
        if (p->right) {
            st.push(p->right);
        }
    }

    return r;
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

    
    cout<<preorder(root)<<endl;

    
    cout<<inorder(root)<<endl;

    
    cout<<postorder(root)<<endl;

    return 0;
}
