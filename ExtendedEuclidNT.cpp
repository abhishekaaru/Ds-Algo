#include<bits/stdc++.h>
using namespace std;

// ax + by = gcd(a,b)
// gcd(a,b) = gcd(b,a%b)
// gcd(b,a%b) = bx1 + (a%b)y1
// a%b = a - (a/b)*b

// ax + by = bx1 + (a%b)y1
// ax + by = bx1 + (a - (a/b)*b)y1
// ax + by = ay1 + b(x1 - (a/b)*y1)

struct triplet{
    public:
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a,int b){
    
    // gcd(a,0) = a
    // ax + 0 = a ==> x=1
    // y=0
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallans = extendedEuclid(b,a%b);
    triplet ans;

    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a/b)*smallans.y;

    return ans;  
}

int main(){

    int a,b;
    cin>>a>>b;

    triplet ans = extendedEuclid(a,b);

    cout<<"GCD : "<<ans.gcd<<endl;
    cout<<"x : "<<ans.x<<endl;
    cout<<"y : "<<ans.y<<endl;

    return 0;
}