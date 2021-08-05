#include <bits/stdc++.h>

using namespace std;

void leftrotate(int n,int a[],int key){
    
    int mod = key%n; // to get starting point of the rotated array
    
    for(int i=0;i<n;i++){
        
        cout<<a[(mod+i)%n]<<" ";
    }
    
    cout<<endl;
}

void leftrotateF(int n,int a[],int key){

    // Stl function rotates takes three parameters - the beginning,the position by which it should be rotated ,the end address of the array

    rotate(a, a + (key % n), a + n);
    
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    
    int key;
    cin>>key;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    leftrotate(n,a,key);
    
    leftrotateF(n,a,key);

    
    return 0;
}