// Sliding Window Challenge


#include<bits/stdc++.h>
using namespace std;

int minSubarrySumSize(int n,int a[],int x){

    int sum=0;
    int minlength=n+1;
    int start=0;
    int end=0;

    while(end<n){
        while(sum <= x && end < n){
            sum += a[end++];
        }

        while(sum > x  && start < n){
            if(end-start < minlength){
                minlength = end - start;
            }
            sum -= a[start++];
        }
    }

    return minlength;
}

int main(){
    int a[] = {1,4,15,6,9,2,3};
    int n = 7;
    int x = 20;

    int minlength = minSubarrySumSize(n,a,x);

    if(minlength > n){
        cout<<"no such subarray exist"<<endl;
    }
    else {
        cout<<"smallest subarray size : "<<minlength<<endl;
    }

    return 0;
}