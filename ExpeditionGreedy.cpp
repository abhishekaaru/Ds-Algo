#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n; // no of stops
        cin>>n;

        vector<pair<int,int>> a(n);

        for(int i=0;i<n;i++){

            // first = distance of stop from truck
            // second = fuel at that stop

            cin>> a[i].first >> a[i].second; 
        }
        
        // p = unit of fuel at initial
        // l = total distance from truck to town
        int l,p;
        cin>>l>>p;

        for(int i=0;i<n;i++){
            
            a[i].first = l - a[i].first; // distance from the truck
        }

        sort(a.begin(),a.end());

        int ans = 0;
        int curr = p; // current fuel

        priority_queue<int,vector<int>> pq;
        bool flag = 0;
        
        for(int i=0;i<n;i++){

            if(curr>=l){
                break;
            }

            while(curr<a[i].first){

                if(pq.empty()){
                    flag = 1;
                    break;
                }

                ans++;
                curr += pq.top();
                pq.pop();
            }
            
            if(flag){
                break;
            }

            pq.push(a[i].second);
        }

        if(flag){
            cout<<"-1"<<endl;
            continue;
        }

        while(!pq.empty() && curr<l){

            curr += pq.top();
            pq.pop();
            ans++;
        }

        if(curr<l){

            cout<<"-1"<<endl;
            continue;
        }

        cout<<ans<<endl;
    }

    return 0;
}