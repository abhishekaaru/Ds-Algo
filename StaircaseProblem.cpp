#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
int dp[N];

int stairCase(int n){
    if(n==0){
        return 1;
    }
    if(n==1 || n==2){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = stairCase(n-1) + stairCase(n-2) + stairCase(n-3);

    return dp[n];
}

int main(){

    int n;
    cin>>n;

//Meomoization

    /* for(int i=0;i<N;i++){
        dp[i] = -1;
    }

    cout<<stairCase(n); */

//Tabulation

    vector<int> dp(n);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
    }

    cout<<dp[n];

    return 0;
}

int nthStair(int n)
{
    // order matter {1,2,1},{2,1,1},{1,1,2} are consider as same.
    
    int dp[n + 1] = {0};
    dp[0] = 1; // 1 way to reach 0 stair.
    dp[1] = 1; // 1 stair can be reached only by taking 1 stair.
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 2] + 1; // Number of ways to reach i stairs is formed by 1(number of ways by all 1 + ways to reach N-2th stair
    return dp[n];
}

int countWays(int n)
{
    //we use same algorithm as Fibonacci series to find the
    //number of ways to reach the nth stair.

    int mod = 1000000007;
    //base case
    if (n <= 1)
        return 1;

    //initializing base values for Fibonacci series.
    int a = 1, b = 1, temp;

    for (int i = 2; i <= n; i++)
    {
        temp = (a + b) % mod;

        //updating a as b and b as temp(sum of a and b).
        a = b;
        b = temp;
    }

    //returning the result.
    return b;
}