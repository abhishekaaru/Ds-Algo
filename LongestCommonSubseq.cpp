#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
int dp[N][N];

int lcs(int n,int m,string &s1,string &s2){

    if(n== 0 || m==0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(s1[n-1] == s2[m-1]){
        dp[n][m] = 1 + lcs(n-1,m-1,s1,s2);
    }
    else{
        dp[n][m] = max(lcs(n-1,m,s1,s2), lcs(n,m-1,s1,s2));
    }

    return dp[n][m];
}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

// Memoization

    /* for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }

    cout<<lcs(n,m,s1,s2); */

// Tabulation
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){

            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[n][m];

    return 0;
}

// longest common subarray

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int dp[1001][1001];
    // dp[i][j] stores the longest common substring length
    // in s1[0...i-1] and s2[0....j-1]

    // if one of strings have length zero, longest common substring
    // will also be of 0 length
    for (int i = 0; i < n; ++i)
        dp[i][0] = 0;

    for (int i = 0; i < m; ++i)
        dp[0][i] = 0;

    int res = 0; // ans
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // if current characters are same, we increase the length by 1
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            // else, there's no common substring ending at i - 1 and j - 1
            else
                dp[i][j] = 0;

            res = max(res, dp[i][j]); // storing the answer
        }
    }
    return res;
}