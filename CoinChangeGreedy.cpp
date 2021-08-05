#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> a = {1,2,5,10,20,50,100,200,500,2000};

    int x;
    cin>>x;

    sort(a.begin(),a.end(),greater<int>());

    int ans=0;

    for(int i=0;i<10;i++){
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }

    cout<<ans;

    return 0;
}