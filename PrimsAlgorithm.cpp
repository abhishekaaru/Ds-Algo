// Minimum spanning tree
#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N = 1e5+3;
vector<vector<int>> adj[N];
vector<bool> visit(N);
vector<int> parent(N), dist(N);
int cost = 0;
const int INF = 1e9;

void primsMST(int src){
    for(int i=0;i<n;i++){
        dist[i] = INF;
    }
    
    set<vector<int>> s;
    dist[src] = 0;
    s.insert({0,src});

    //{wt,vertex}
    while (!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        visit[x[1]] = true; // vertex
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];

        cout<<u<<" "<<v<<" "<<w<<endl;
        cost += w;

        for(auto i : adj[x[1]]){ // neighbours

            if(visit[i[0]]){
                continue;
            }
            if(dist[i[0]] > i[1]){

                s.erase({dist[i[0]], i[0]});

                dist[i[0]] = i[1];
                s.insert({dist[i[0]],i[0]});
                parent[i[0]] = x[1]; 
            }
        }
    }
    
}

int main(){

    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    primsMST(0);
    cout<<"Cost : "<<cost;

    return 0;
}