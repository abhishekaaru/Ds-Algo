#include<iostream>
using namespace std;

int nCr(int n){

    int f=1;
    for(int i=2;i<=n;i++){
        f*=i;
    }
    return f;
}

int main(){

    int n,r;
    cin>>n>>r;

    int ans;

    ans=nCr(n)/(nCr(n-r)*nCr(r));

    cout<<ans<<endl;

    return 0;
}