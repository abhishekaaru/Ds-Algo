// Binary Search challenge
// we are given an ascending sorted array that has been rotated from pivot point (unknown) and an element X.
// Search for X in the array with complexity less than that linear search.

#include<bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int a[],int left,int right,int key){
    if(right<left){
        return -1;
    }

    int mid;
    mid = (left+right)/2;

    if(a[mid] == key){
        return mid;
    }

    if(a[left] <= a[mid]){

        if(key >= a[left] && key <= a[mid]){
            return searchInRotatedArray(a,left,mid-1,key);
        }
        return searchInRotatedArray(a,mid+1,right,key);
    }

    if(a[mid] <= a[right]){

        if(key >= a[mid] && key <= a[right]){
            return searchInRotatedArray(a,mid+1,right,key);
        }
        return searchInRotatedArray(a,left,mid-1,key);
    }
}

int main(){

    int a[] = {6,7,8,9,10,1,2,5};
    int n = 8;
    int key = 8;

    int i = searchInRotatedArray(a,0,n-1,key);

    if(i==-1){
        cout<<"key doesn't exist"<<endl;
    }
    else{
        cout<<"Key exist at : "<<i<<endl;
    }

    return 0;
}