#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;
    vector<int> dist(n,INF);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }

    int src;
    cin>>src;
    
    dist[src] = 0;

    for(int it=0;it<n-1;it++){
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            dist[v] = min(dist[v], w + dist[u]);
        }
    }

    // OR

    /* for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            if (dis[edges[j][0]] != INF && dis[edges[j][0]] + edges[j][2] < dis[edges[j][1]]){

                dis[edges[j][1]] = dis[edges[j][0]] + edges[j][2];
            }
        }
    } */

    for(auto i : dist){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;

}


