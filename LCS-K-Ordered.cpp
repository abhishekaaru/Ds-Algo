// Print the LCS of two sequences given thath you are allowed to change atmost k elements in the first sequence to any value you wish to.

#include<bits/stdc++.h>
using namespace std;

int dp[200][200][7];


int lcs(vector<int> &a,vector<int> &b,int i,int j,int k){
    if(i==0 || j==0){
        return 0;
    }

    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    int c1(0),c2(0),c3(0);

    if(a[i] == b[j]){
        c1 = 1 + lcs(a,b,i-1,j-1,k);
    }
    if(k>0){
        c2 = 1 + lcs(a,b,i-1,j-1,k-1);
    }

    c3 = max(lcs(a,b,i-1,j,k),lcs(a,b,i,j-1,k));

    dp[i][j][k] = max({c1,c2,c3});

    return dp[i][j][k];
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> a(n);
    vector<int> b(m);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<lcs(a,b,n,m,k);

    return 0;
}