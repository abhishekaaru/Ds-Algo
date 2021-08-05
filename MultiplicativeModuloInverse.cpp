// Number Theory
#include<bits/stdc++.h>
using namespace std;

// (a*b) % m = 1 
// find b?

// a*b = 1 (over mod m)
// a*b - 1 = 0 (over mod m)
// a*b - 1 = mQ
// a*b - mQ = 1 (Extended Euclid) b=x,Q=y

struct triplet{
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a, int b)
{

    // gcd(a,0) = a
    // ax + 0 = a ==> x=1
    // y=0
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallans = extendedEuclid(b, a % b);
    triplet ans;

    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a / b) * smallans.y;

    return ans;
}

int MMI(int a,int m){

    triplet temp = extendedEuclid(a,m);
    return temp.x;
}

int main(){

    int a,m;
    cin>>a>>m;

    int ans = m + MMI(a,m);

    //cout<<MMI(a,m);

    cout<<ans;

    return 0;
}

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
    {
        if (((a % m) * (x % m)) % m == 1)
        {
            return x;
        }
    }
    return -1;
}