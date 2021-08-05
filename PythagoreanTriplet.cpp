#include<bits/stdc++.h>
using namespace std;

bool Pyth(int a,int b,int c){

    int x = max(a, max(b,c));
    int y,z;

    if(x==a){
        y=b;
        z=c;
    }
    else if(x==b){
        y=a;
        z=c;
    }
    else  {
        y=a;
        z=b;
    }
    if(x*x == y*y + z*z){
        return true;
    }

    return false;
}

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    if (Pyth(a,b,c)) {
        cout<<a<<b<<c<<" is an Pythagorean Triplet"<<endl;
    }
    else{
        cout<<a<<b<<c<<" is not an Pythagorean Triplet"<<endl;
    }

    return 0;

}
