#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    int count=0;

    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);

    for(int i=0;i<m;i++){

        int x,y;  
        cin>>x>>y;

        // x --> y
        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<int> pq;

    for(int i=0;i<n;i++){

        // push all element whose indegree = 0
        if(indeg[i]==0){
            pq.push(i);
        }
    }

    while(!pq.empty()){

        count++;
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";

        for(auto it: adj[x]){

            indeg[it]--;

            // next level push (whose indegree  0)

            if(indeg[it]==0){

                pq.push(it);
            }
        }
    }

    return 0;
}