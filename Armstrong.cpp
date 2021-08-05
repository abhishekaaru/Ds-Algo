#include<iostream>
#include<math.h>
using namespace std;
int main() {

    int n,l,sum=0,ln;

    cin>>n;

    ln=n;

    while(n>0){

        l = n%10;
        sum+=l*l*l;
        n/=10;

    }
    if(sum==ln){
        cout<<ln<<" is an Armstrong no.";
    }
    else{
        cout<<ln<<" is not an Armstrong no.";
    }
    return 0;
}