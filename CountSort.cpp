#include<bits/stdc++.h>
using namespace std;

void countSort(int n,int a[]){

    int k=a[0];
    for(int i=0;i<n;i++){

        k=max(k,a[i]); // output 6
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[a[i]]++; // {0,2,1,3,2,0,1,0,0}
    }   

    for(int i=1;i<=k;i++){
        count[i]+=count[i-1]; // {0,2,3,6,8,8,9,0,0}
    }

    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[a[i]]] = a[i]; // {1,1,2,3,3,3,4,4,6}
    }

    for(int i=0;i<n;i++){
        a[i]=output[i];
    }


}

int main(){

    int a[9]={1,3,2,3,4,1,6,4,3};

    countSort(9,a);

    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";

    }

    return 0;

}