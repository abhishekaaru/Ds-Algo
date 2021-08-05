#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> graph(n+1);
    vector<int> dist(n+1,INF);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int src;
    cin>>src;

    dist[src] = 0;
    set<pair<int,int>> s;
    //{wt,vertex}
    s.insert({0,src});

    while(!s.empty()){
        auto x = *(s.begin()); // extract
        s.erase(x);
        
        for(auto i : graph[x.second]){

            if(dist[i.first] > dist[x.second] + i.second){
                s.erase({dist[i.first], i.first});

                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }

    for(int i=1;i<=n;i++){ 
        if(dist[i]<INF){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<"-1"<<" ";
        }
    }

    return 0;
    
}