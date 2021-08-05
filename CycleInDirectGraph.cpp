#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visit, vector<int> &stack){

    stack[src] = true;

    if(!visit[src]){

        visit[src] = true;

        for(auto i : adj[src]){

            if(!visit[i] && isCycle(i,adj,visit,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }

    stack[src] = false;
    
    return false;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
    }
    
    bool cycle = false;
    vector<int> stack(n,0);
    vector<bool> visit(n,0);
    for(int i=0;i<n;i++){

        if(!visit[i] && isCycle(i,adj,visit,stack)){
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

bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[])
	{
        //if the current vertex is not visited.
	    if(visited[v] == false) 
		{ 
			//marking the current node as visited and part of recursion stack. 
			visited[v] = true; 
			recStack[v] = true; 

			//calling function recursively for all the vertices
			//adjacent to this vertex.
			for(int i = 0; i < (int)adj[v].size(); ++i) 
			{ 
				if ( !visited[adj[v][i]] && isCyclicUtil(adj[v][i], visited, recStack, adj)) 
					return true; 
				else if (recStack[adj[v][i]]) 
					return true; 
			} 

		} 
		//removing the vertex from recursion stack.
		recStack[v] = false; 
		return false;                                                                                                            
	}

	public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[])
	{
	   	//marking all vertices as not visited and not a part of recursion stack 
		vector<bool> visited(V, false); 
		vector<bool> recStack(V, false); 

		//calling the recursive helper function to detect cycle in  
		//different DFS trees.
		for(int i = 0; i < V; i++) 
			if (isCyclicUtil(i, visited, recStack, adj)) 
				return true; 

		return false;
	}