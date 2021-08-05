// Ugly no. are no. whose prime factors are 2,3,5.
// 1,2,3,4,5,6,8,9,10,12
// by convention, 1 is included

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int c2=0,c3=0,c5=0;
    vector<int> dp(n+1);

    dp[0] = 1;

    for(int i=1;i<=n;i++){

        dp[i] = min({2*dp[c2], 3*dp[c3], 5*dp[c5]});

        if(2*dp[c2] == dp[i]){
            c2++;
        }
        if(3*dp[c3] == dp[i]){
            c3++;
        }
        if(5*dp[c5] == dp[i]){
            c5++;
        }
    }

    cout<<dp[n-1];

    return 0;
}

