#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int dp[100][100];

int solve(int i,int j){
    if(i==j){
        return a[i];
    }
    if(i>j){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    // A[i...j], remaining coins = A[1+1...j]
    int l = a[i] + min(solve(i+2,j),solve(i+1,j-1)); // choice 1
    // A[i...j], remaining coins = A[i...j-1]
    int r = a[j] + min(solve(i,j-2),solve(i+1,j-1)); // choice 2

    dp[i][j] = max(l,r);

    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    
    a = vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    memset(dp,-1,sizeof dp);

    cout<<solve(0,n-1);

    return 0;
}
