#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of an array"<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter the element of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int N;
    int idx[N];
    for(int i=0;i<N;i++){
        idx[i] = -1;
    }

    int minidx;
    minidx = INT_MAX;
     for(int i=0;i<n;i++){

         if( idx[a[i]] != -1 ){

             minidx = min(minidx,idx[a[i]]);

         }

         else{

             idx[a[i]] = i;

         }
     }

     if(minidx == INT_MAX){
         cout<<"-1"<<endl;
     }
     else{
         cout<<minidx<<endl;
     }

     

     return 0;
}
