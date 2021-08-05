#include<iostream>
using namespace std;

int GetBit(int n,int pos){
    return ((n & (1<<pos)) != 0); 
}

void unique2(int n,int a[]){
    int xorsum=0;
    for(int i=0;i<n;i++){  
     xorsum=xorsum^a[i];
    }

    int tempxor = xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit = xorsum & 1;
        xorsum = xorsum>>1;
        pos++;
    }

    int new1xor=0;
    for(int i=0;i<n;i++){
        if(GetBit(a[i],pos-1)){
            new1xor = new1xor^a[i];
        }
    }

    int new2xor=0;
    new2xor = tempxor^new1xor;
  
    cout<<new1xor<<endl;
    cout<<new2xor<<endl;

}

int main(){

    int a[8]={1,2,3,4,5,1,2,3};

    unique2(8,a);

    return 0;
}