#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
int wt[N],val[N];
int dp[N][N];

int knapsack(int n,int w){

    if(w<=0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }

    if(wt[n-1] > w){
        dp[n][w] = knapsack(n-1,w);
    }
    else{
        dp[n][w] = max(knapsack(n-1,w), knapsack(n-1, w-wt[n-1]) + val[n-1]);
    }

    return dp[n][w];
}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    int w;
    cin>>w;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }

    cout<<knapsack(n,w);

    return 0;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    //building table K[][] in bottom up manner.
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            //base case
            if (i == 0 || w == 0)
                K[i][w] = 0;

            //if weight of current item is more than Knapsack capacity W
            //then this item cannot be included in the optimal solution.
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);

            //else updating K[i][w] as K[i-1][w].
            else
                K[i][w] = K[i - 1][w];
        }
    }
    //returning the result.
    return K[n][W];
}