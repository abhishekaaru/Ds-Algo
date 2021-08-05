// LONGEST INCREASING SUBSEQUENCE
#include<bits/stdc++.h>
using namespace std;

const int N=1e3+2;
int dp[N];

int lis(int n,vector<int> &a){

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = 1; // single element is also a lis

    for(int i=0;i<n;i++){

        if(a[n]>a[i]){
            dp[n] = max(dp[n],1+lis(i,a)); 
        }
    }

    return dp[n];
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

// Memoization

    /* for(int i=0;i<N;i++){
        dp[i] = -1;
    }

    cout<<lis(n-1,a); */

// Tabulation

    vector<int> dp(n,1);
    int ans=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){

            if(a[i]>a[j]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
        ans = max(ans,dp[i]);
    }

    cout<<ans;  

    return 0;
}