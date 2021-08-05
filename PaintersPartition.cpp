// Binary Search Problem
// A m no. of painters paints 1 unit of board(n = lengthf of n differet boards) in 1 unit of time & each painters will paint consecutive boards
// Find the minimum time that will be required to paint all boards.

#include<bits/stdc++.h>
using namespace std;

int isFeasible(int n,int boards[],int limit){
    
    int painters=1;
    int sum = 0;

    for(int i=0;i<n;i++){

        sum += boards[i];

        if(sum > limit){

            painters++;
            sum = boards[i];
        }
    }
    
    return painters;
}

int paintersPartition(int n,int boards[],int m){

    int totallength=0;
    int k = 0;

    for(int i=0;i<n;i++){

        k = max(k,boards[i]);
        totallength += boards[i];
    }

    int low = k;
    int high = totallength;

    while(low<high){

        int mid = 0;
        mid = (low+high)/2;

        int painters = isFeasible(n,boards,mid);
        if(painters <= m){

            high = mid;
        }
        else{
            low = mid+1;
        }
    }

    return low;
}

int main(){
    int boards[] = {10,20,30,40};
    int n = 4;
    int m = 2;

    cout<<"Minimum time to paint boards : "<<paintersPartition(n,boards,m);

    return 0;
}