#include<iostream>
using namespace std;

int knapsack(int n,int wt[],int val[],int W){

    if(n==0 || W==0){
        return 0;
    }

    if(wt[n-1]>W){

        return knapsack(n-1,wt,val,W);

    }

    int maxn;
    maxn = max(knapsack(n-1,wt,val,W-wt[n-1]) + val[n-1] , knapsack(n-1,wt,val,W));

    return maxn;
}

int main(){

    int wt[]={10,20,30,40};
    int val[]={100,50,150,200};
    int W = 50;

    cout<<knapsack(4,wt,val,W)<<endl;

    return 0;
}