#include<bits/stdc++.h>
using namespace std;

const int N=102, MOD = 1e9+2;
int dp[N][N];

int mcm(int i,int j,int a[]){

    if(i==j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    dp[i][j] = MOD;

    for(int k=i;k<j;k++){
        dp[i][j] = min(dp[i][j], mcm(i,k,a) + mcm(k+1,j,a) + a[i-1]*a[k]*a[j]);
    }

    return dp[i][j];
}

int main(){

    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
// Memoization

    // memset(dp,-1,sizeof dp);

    // cout<<mcm(1,n-1,a);

// Tabulation

    memset(dp, 0, sizeof dp);

    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j = i+l-1;
            dp[i][j] = MOD;
            for(int k=i;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i - 1] * a[k] * a[j]);
            }
        }
    }

    cout<<dp[1][n-1];

    return 0;
}