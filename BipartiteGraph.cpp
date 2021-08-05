#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> col;
bool bipart;

void color(int src, int curr){

    if(col[src] != -1 && col[src] != curr){
        bipart = false;
        return;
    }

    col[src] = curr;

    if(visit[src]){
        return;
    }
    visit[src] = true;

    for(auto i : adj[src]){
        color(i, curr xor 1);
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    adj = vector<vector<int>>(n);
    visit = vector<bool>(n,false);
    col = vector<int>(n,-1);
    bipart = true;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0;i<n;i++){
        if(!visit[i]){
            color(i,0);
            
        }
    }

    if(bipart){
        cout<<"Graph is Bipartite";
    }
    else{
        cout<<"Graph is no Bipartite";
    }

    return 0;

}

bool isBipartite(int V, vector<int>adj[]){
		vector<int>color(V, -1);
		queue<int>q;
		bool is_Bipratite = true;
		for(int i = 0; i < V; i++){
			if(color[i] == -1){
				q.push(i);
				color[i] = 0;
				while(!q.empty()){
					int u = q.front();
					q.pop();
					for(auto v: adj[u]){
						if(color[v] == -1){
							color[v] = color[u] ^ 1;
							q.push(v);
						}
						else is_Bipratite = is_Bipratite & (color[u] != color[v]);
					}

				}
			}
		}
		return is_Bipratite;
	}