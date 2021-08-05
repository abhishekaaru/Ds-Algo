// Maximum subbary sum
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int curr=0;
    int ans=0;

    for(int i=0;i<n;i++){

        curr += a[i];
        ans = max(ans,curr);

        if(curr<0){
            curr=0;
        }
    }

    cout<<ans;

    return 0;
}