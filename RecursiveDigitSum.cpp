#include <bits/stdc++.h>

using namespace std;

int digsum(int n){
    if(n==0){
        return 0;
    }
    
    return ( n%9==0 ) ? 9 : n%9;
}

int repeatedSum(int n,int x){
    
    int sum;
    sum = x*digsum(n);
    
    return digsum(sum);
}

int main(){
    int n,x;
    cin>>n>>x;
    
    cout<<repeatedSum(n,x);
    
    return 0;
}