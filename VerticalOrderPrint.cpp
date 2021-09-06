#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    
    int data;
    Node* left;
    Node* right; 

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};



void getVerticalOrder(Node* root,int Hdis,map<int,vector<int>> &m){
    if(root==NULL){
        return;
    }

    m[Hdis].push_back(root->data);
    getVerticalOrder(root->left,Hdis-1,m);
    getVerticalOrder(root->right,Hdis+1,m);
}

// GFG
vector<int> verticalOrder(Node *root)
{
    vector<int> res;
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *temp_root = temp.first;
        int distance = temp.second;
        mp[distance].push_back(temp_root->data);
        q.pop();
        if (temp_root->left)
        {
            q.push({temp_root->left, distance - 1});
        }

        if (temp_root->right)
        {
            q.push({temp_root->right, distance + 1});
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        vector<int> ans = it->second;

        for (auto x : ans)
            res.push_back(x);
    }
    return res;
}

int main(){

    Node* root = new Node(1);
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

    map<int,vector<int>> m;
    int Hdis = 0;

    getVerticalOrder(root,Hdis,m);

    map<int,vector<int>> :: iterator it;

    for(it=m.begin(); it!=m.end(); it++){

        for(int i=0; i<(it->second).size(); i++){
            cout<<(it->second)[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}