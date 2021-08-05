#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 2;

int powerRecursive(int a,int n){
    if(n == 0){
        return 1;
    }

    int p = powerRecursive(a,n/2);
    
    //odd
    if(n&1){
        return ( ( (p*p) % MOD) * a )%MOD;
    }
    //even
    else{
        return (p*p)%MOD;
    }
}

int powerIteretive(int a,int n){
    
    a %= MOD;
    int ans=1;
    while(n>0){
        if(n&1){
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        n = n>>1;
    }
    return ans;
}

signed main(){
    int a,n;
    cin>>a>>n;

    a %= MOD;

    cout<<powerRecursive(a,n)<<endl;
    cout<<powerIteretive(a,n)<<endl;

    return 0;
}