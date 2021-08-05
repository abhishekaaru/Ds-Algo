// Sliding Window Challenge

#include<bits/stdc++.h>
using namespace std;

void maxSumSubarray(int n,int a[],int k,int x){

    int sum = 0;
    int ans = 0;

    for(int i=0;i<k;i++){
        sum += a[i];
    }

    if(sum < x){
        ans = sum;
    }

    for(int i=k;i<n;i++){

        sum = sum - a[i-k];
        sum = sum + a[i];

        if(sum<x){
            ans = max(ans,sum);
        }
    }

    cout<<"Maximum subarry sum less than x is : "<<ans<<endl;
}

int main(){
    
    int a[] = {7,5,4,6,8,9};
    int n = 6;
    int k = 3;
    int x = 20;

    maxSumSubarray(n,a,k,x);

    return 0;
}