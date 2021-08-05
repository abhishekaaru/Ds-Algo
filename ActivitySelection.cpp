#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> a;
    for(int i=0;i<n;i++){
        int start;
        int end;

        cin>>start>>end;
        a.push_back({start,end});
    }

    sort(a.begin(),a.end(),[&](vector<int> &x, vector<int> &y){ 
        return x[1] < y[1];  //costom comparator (lammda)
    });

    int take = 1;
    int end = a[0][1]; // initialize

    for(int i=1;i<n;i++){

        if(a[i][0] >= end){   // if end is > then start

            take++;
            end = a[i][1];
        }
    }

    cout<<take;

    return 0;

}

// 3
// 10 20
// 12 15
// 20 30
// output = 2