#include<bits/stdc++.h>
using namespace std;

//recursion

int sum(int n){
    int prevsum=0;

    if(n==0){
        return 0;
    }

    prevsum = sum(n-1);

    return n + prevsum;
}

//funtion

int naturalN(int a, int b){
    int sum=0;
    for(int i=a;i<=b;i++){
        sum+=i;
    }
    return sum;
}

int main(){

    
  /*   int a,b;
    cin>>a>>b;
    cout<<naturalN(a,b)<<endl; */

    cout<<sum(5);

}