// write a program to generate all possible subset
#include<iostream>
using namespace std;

int subset(int n,int a[]){
    for(int i=0;i< (1<<n);i++){  // 1<<n = 2^n
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
    }

}

int main(){

    int a[4]={1,2,3,4};
    cout<<subset(4,a)<<endl;

    return 0;

}