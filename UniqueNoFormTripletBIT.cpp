#include<iostream>
using namespace std;

int GetBit(int n,int pos){
    return ((n & (1<<pos)) != 0); 
}

int SetBit(int n,int pos){
    return (n | (1<<pos)); 
}

int unique(int n,int a[]){

    int result = 0;

    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(GetBit(a[j],i)){
                sum++;
            }
        }

        if( sum%3 != 0 ){
            result = SetBit(result,i);
        } 

    }

    return result;
}


 
int main(){
    int a[7] = {1,1,1,2,2,2,3};

    cout<<unique(7,a)<<endl;

    return 0; 

} 