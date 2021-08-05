#include<iostream>
using namespace std;

//recursion
int factorial(int n){
    int prev=0;

    if(n==0){
        return 1;
    }
    prev=factorial(n-1);

    return n*prev;
}

//funtion

int fctrl(int n){

    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
        
    }
    return f;
}

int main(){

    /* int n;
    cin>>n;
 
    fctrl(n);

    int ans;
    ans=fctrl(n);
    cout<<ans<<endl; */

    cout<<factorial(5);

    return 0;

}