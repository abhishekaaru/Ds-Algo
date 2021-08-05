#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visit, int parent){

    visit[src] = true;

    for(auto i: adj[src]){

        if(i != parent){
            if(visit[i]){
                return true;
            }
            if(!visit[i] && isCycle(i,adj,visit,src)){
                return true;
            }
        }
    }

    return false;

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++){
        
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool cycle = false;
    vector<bool> visit(n,0);
    for(int i=0;i<n;i++){

        if(!visit[i] && isCycle(i,adj,visit,-1)){
            cycle = true;
        }
    }

    if(cycle){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present"<<endl;
    }

    return 0;
}

bool isCycleUtil(int u, int par, vector<int>adj[], vector<bool>&vis)
	{
	    //marking the current vertex as visited.
		vis[u] = true;
		
		//iterating on all the adjacent vertices.
		for(auto v: adj[u])
		{
			if(v == par)
				continue;
				
			//if current vertex is visited, we return true else we 
			//call the function recursively to detect the cycle.
			if(vis[v])
				return true;
			if(isCycleUtil(v, u, adj, vis))
				return true;
		}
		return false;
	}
	
	//Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    //using a boolean list to mark all the vertices as not visited.
		vector<bool>vis(V, false);
		
		//iterating over all the vertices.
		for(int i = 0; i < V; i++)
		{
		    //if vertex is not visited, we call the function to detect cycle.
			if(!vis[i])
			{
				bool f = isCycleUtil(i, -1, adj, vis);
				//if cycle is found, we return true.
				if(f)
				    return true;
			}
		}
		return false;
	}