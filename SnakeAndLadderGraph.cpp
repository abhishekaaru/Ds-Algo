#include<bits/stdc++.h>
using namespace std;

int main(){

    int ladders;
    cin>>ladders;
    map<int,int> lad;
    for(int i=0;i<ladders;i++){
        int u,v;
        cin>>u>>v;

        lad[u] = v;
    }

    int snakes;
    cin>>snakes;
    map<int,int> snak;
    for(int i=0;i<snakes;i++){
        int u,v;
        cin>>u>>v;

        snak[u] = v;
    }

    int moves = 0;
    bool found = false;
    vector<bool> visit(101,false);

    queue<int> q;
    q.push(1);
    visit[1] = true;

    while(!q.empty() && !found){
        int size = q.size();

        while (size--){
            
            int t = q.front();
            q.pop();

            for(int die=0;die<=6;die++){

                if(t + die == 100){
                    found = true;
                }

                else if(t+die <= 100 && lad[t+die] && !visit[lad[t+die]]){
                    
                    visit[lad[t+die]] = true;

                    if(lad[t+die] == 100){
                        found = true;
                    }
                    q.push(lad[t+die]);
                }

                else if(t+die <= 100 && snak[t+die] && !visit[snak[t+die]]){

                    visit[snak[t+die]] = true;

                    if(snak[t+die] == 100){
                        found = true;
                    }
                    q.push(snak[t+die]);
                }

                else if(t+die <= 100 && !lad[t+die] && !snak[t+die] && !visit[t+die]){

                    visit[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }

    if(found){
        cout<<"Total moves : "<<moves;
    }
    else{
        cout<<"reaching 100 is not possible";
    }

    return 0;
}


int minThrow(int N, int arr[]){
        int moves[35];
        bool vis[35];
        memset(moves, -1, sizeof(moves));
        memset(vis, false, sizeof(vis));
        for(int i = 0;i < 2*N;i += 2)
            moves[arr[i]] = arr[i+1];
        
        queue<pair<int, int>> q;
        pair<int, int> p;
        q.push({1, 0});
        vis[1] = true;
        while(!q.empty()){
    		p = q.front();
    		int ii = p.first;
    		int ss = p.second;
    		if(ii == 30)
    		break;
    		q.pop();
    		for(int i = ii+1;i <= ii+6 && i <= 30;i++){
    			pair<int,int> pp;
    			if(!vis[i]){
    				pp.second = ss+1;
    				vis[i] = true;
    				if(moves[i] != -1)
    					pp.first = moves[i];
    				else
    				    pp.first = i;
    				q.push(pp);
    			}
    		}
    	}
    	return p.second;
    }