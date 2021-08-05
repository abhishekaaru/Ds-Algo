#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int w;
    cin>>w;

    vector<pair<int,int>> a(n);

    for(int i=0;i<n;i++){

        cin>>a[i].first >> a[i].second; // first total price ,second weight
    }

    sort(a.begin(),a.end(),[&](pair<int,int> p1, pair<int,int> p2){
        
        double v1 = (double) p1.first/p1.second;
        double v2 = (double) p2.first/p2.second;

        return v1>v2;
    });


    int ans=0;

    for(int i=0;i<n;i++){

        if(w >= a[i].second){

            ans += a[i].first;
            w -= a[i].second;
            continue;
        }

        double vw = (double) a[i].first/a[i].second;
        ans += vw*w;
        w = 0;
        break;
    }

    cout<<ans;

    return 0;
}

// n=5 weight=20
// 21 7, 24 4, 12 6, 40 5, 30 6
// output = 109