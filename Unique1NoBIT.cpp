#include<iostream>
using namespace std;

int unique(int n,int a[]){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^a[i];
    }
    return xorsum;
}

int main(){
    int a[7]={1,2,3,5,1,2,3};
    cout<<unique(7,a);

    return 0;
}