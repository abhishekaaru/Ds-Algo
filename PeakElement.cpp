// Binary Search Challenge
// find a given array,find the peak element in the array.
// Peak element is one which id greater than both, left and right neighbours of itself.

#include<bits/stdc++.h>
using namespace std;

int peakElement(int a[],int low,int high,int n){

    int mid;
    mid = low+(high-low)/2;

    if((mid == 0 || a[mid-1] <= a[mid]) && (mid == n-1 || a[mid+1] <= a[mid])){
        return mid;
    }
    
    else if(mid > 0 && a[mid-1] > a[mid]){
        return peakElement(a,low,mid-1,n);
    }

    else{
        return peakElement(a,mid+1,high,n);
    }
}

int main(){

    int a[] = {1,4,5,3,6,7,8};
    int n = 7;

    cout<<"Peak element index : "<<peakElement(a,0,n-1,n);

    return 0;

}