#include <bits/stdc++.h>
using namespace std;

void leftrotationbyOne(int n,int a[]){
    
    int temp = a[0];
    for(int i=0;i<n-1;i++){
        a[i]=a[i+1];
        
    }
    
    a[n-1]=temp;
    
}

void leftrotation(int n,int a[],int d){
    
    for(int i=0;i<d;i++){
        leftrotationbyOne(n,a);
    }
}


int main(){
    int n;
    int d;
    cin>>n>>d; // 5 2
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];  // 1 2 3 4 5
    }
    
    leftrotation(n,a,d);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "; // 3 4 5 1 2 
    }
    
    return 0;
    
    
}