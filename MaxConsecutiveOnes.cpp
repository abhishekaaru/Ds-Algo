#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }

    int zerocount=0;
    int i=0;
    int ans=0;

    for(int j=0;j<a.size();j++){

        if(a[j]==0){
            zerocount++;
        }
        // a[i......j] window
        // a[i....j+1] window size increase
        // a[i+1....j] window size decrease 

        // window shirnk because zerocount>k

        while(zerocount>k){
            if(a[i]==0){
                zerocount--;   // Through out form the window
            }

            i++;    // window shirnk
        }
        
        ans=max(ans,j-i+1);
    }

    cout<<ans;

    return 0;
}