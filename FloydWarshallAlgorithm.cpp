#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    vector<vector<int>> graph = {  {0,5,INF,10},
                                    {INF,0,3,INF},
                                    {INF,INF,0,1},
                                    {INF,INF,INF,0}
                                };
    
    int n = graph.size();
    vector<vector<int>> dist = graph;

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(dist[i][k] + dist[k][j] < dist[i][j]){

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(dist[i][j] == INF){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}


void shortest_distance(vector<vector<int>>&matrix){
		int INF = INT_MAX;
		int n = matrix.size();
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == -1)
					matrix[i][j] = INF;
			}
		}
		
		for (int k = 0; k < n; ++k) {
		    for (int i = 0; i < n; ++i) {
		        for (int j = 0; j < n; ++j) {
		            if (matrix[i][k] < INF && matrix[k][j] < INF and matrix[i][k] + matrix[k][j] < INF)
		                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); 
		        }
		    }
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] >= INF)
					matrix[i][j] = -1;
			}
		}
	}