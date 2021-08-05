#include<bits/stdc++.h>
using namespace std;

int dp[200][200][200];

int lcs(string &s1,string &s2,string &s3,int i,int j,int k){

    if(i==0 || j==0 || k==0){
        return 0;
    }

    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
        
        dp[i][j][k] = 1 + lcs(s1,s2,s3,i-1,j-1,k-1);

        return dp[i][j][k];
    }

    int l = lcs(s1,s2,s3,i-1,j,k);
    int r = lcs(s1,s2,s3,i,j-1,k);
    int p = lcs(s1,s2,s3,i,j,k-1);

    dp[i][j][k] = max({l,r,p});

    return dp[i][j][k];
}

// O(i*j*k)

int main(){

    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    int i = s1.size();
    int j = s2.size();
    int k = s3.size();

    memset(dp,-1,sizeof(dp));

    cout<<lcs(s1,s2,s3,i,j,k);

    return 0;
}