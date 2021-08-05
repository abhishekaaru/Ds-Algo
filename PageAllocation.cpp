// Binary Search Problem
// All the n books(accinding order) have to be divided among students m, consecutevily. 
// Allocate the pages in such a way that maximum pages allocated to student is minimum.

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int n,int a[],int m,int min){

    int studentRequired=1;
    int sum = 0;

    for(int i=0;i<n;i++){

        if(a[i]>min){
            return false;
        }

        if(sum + a[i] > min){

            studentRequired++;
            sum = a[i];

            if(studentRequired > m){
                return false;
            }
        }

        else{
            sum += a[i];
        }
    }

    return true;
}

int allocateMinPages(int n,int a[],int m){

    if(n<m){
        return -1;
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }

    int start = 0;
    int end = sum;
    int ans = INT_MAX;
    
    // Binary Search

    while(start <= end){

        int mid;
        mid = (start + end)/2;

        if(isFeasible(n,a,m,mid)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return ans;
}

int main(){

    int a[] = {12,34,67,90};
    int n = 4;
    int m = 2;

    cout<<"The minimum no. of pages : "<<allocateMinPages(n,a,m);

    return 0;
}