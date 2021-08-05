#include<iostream>

using namespace std;
//recursion
int fibr(int n){
    int prev=0;

    if(n==0 || n==1){
        return n;
    }

    prev=fibr(n-1)+fibr(n-2);

    return prev;
}
//funtion

void fib(int n){
    int t1=0;
    int t2=1;
    int nxt;

    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        nxt=t1+t2;
        t1=t2;
        t2=nxt;
    }
    
    return;
}


int main(){
    int n;
    cin>>n;
    
    cout<<fibr(n);

    return 0;
} 