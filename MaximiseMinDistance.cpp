// Binary Search Problem
// Given is an array with n elements that repersents n position along a stright line.
// Find K element such that the minimum distance b/w any 2 elements is the maximum possible.

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int n,int a[],int k,int mid){

    int pos=a[0];
    int ele=1;

    for(int i=1;i<n;i++){

        if(a[i]-pos >= mid){
            pos=a[i];
            ele++;

            if(ele==k){
                return true;
            }
        }
    }

    return false;
}

int largestMinDis(int n,int a[],int k){

    sort(a,a+n);

    int left = 1;
    int right = n-1;

    int result = 0;

    // Binary search

    while(left<right){

        int mid;
        mid = (left+right)/2;

        if(isFeasible(n,a,k,mid)){

            result = max(result,mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
    }

    return result;
}

int main(){

    int a[]={1,2,8,4,9};
    int n=5;
    int k=3;

    cout<<largestMinDis(n,a,k);

    return 0;
}