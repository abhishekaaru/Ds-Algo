#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int> adj[N];

int main(){

// Adjency Matrix


    // n = no. of nodes
    // m = no. of edges

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adjM(n+1, vector<int>(n+1, 0));

    for(int i=0;i<m;i++){

        // edge btw x and y

        int x,y;

        cin>>x>>y;

        adjM[x][y] = 1;
        adjM[y][x] = 1;
    }

    cout<<"Adjanency matrix of above graph is given by :"<<endl;

    for(int i=1;i<n+1;i++){

        for(int j=1;j<n+1;j++){

            cout<<adjM[i][j]<<" ";
        }

        cout<<endl;
    }

    if(adjM[3][7] == 1){
        cout<<"There is a edge btw 3 and 7"<<endl;
    }
    else{
        cout<<"No edge"<<endl;
    }

    cout<<endl<<endl;

// Adjency List
    
    cin>>n>>m;

    for(int i=0;i<m;i++){

        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Adjacency list of above graph is given by :"<<endl;
    for(int i=1;i<n+1;i++){

        cout<<i<<"->";
        for(int x: adj[i]){ // iterator
            cout<<x<<" ";
        }
        cout<<endl;
    }
    

    return 0;

}