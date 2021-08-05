#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool visit[N];
vector<int> adj[N];

void DFS(int node){

    // preorder
    visit[node] = true;
    cout<<node<<" ";

    // inorder

    for(int x: adj[node]){

        if(!visit[x]){
            DFS(x);
        }
    }

    //postorder

    // cout<<node<<" ";

}

int main(){

    for(int i=0;i<N;i++){
        visit[i] = 0;
    }

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS(1);


    return 0;
}