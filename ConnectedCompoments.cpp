#include<bits/stdc++.h>
using namespace std;

int getComponents(int src,vector<vector<int>> &adj,vector<bool> &visit){

    if(visit[src]){
        return 0;
    }

    visit[src] = true;
    int ans = 1;
    
    for(auto i : adj[src]){
        if(!visit[i]){
            ans += getComponents(i,adj,visit);
            visit[i] = true;
        }
    }

    return ans;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<bool> visit(n);
    vector<int> components;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0;i<n;i++){

        if(!visit[i]){
            components.push_back(getComponents(i,adj,visit));
        }
    }

    for(auto i : components){
        cout<<"Component size : "<<i<<endl;
    }

    cout<<endl;

    cout<<"no. of ways to choose that other member should not be from their component : ";

    long long ans = 0;
    for(auto i : components){
        ans += i*(n-1);
    }
    
    

    cout<<ans/2;
}