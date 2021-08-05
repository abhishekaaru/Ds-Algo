#include<bits/stdc++.h>
using namespace std;

int BinaryToDeci(int n){

    int ans=0;
    int x=1;
    int y;
    while(n>0){
        y=n%10;
        ans+=x*y;
        x*=2;
        n/=10;

    }
    return ans;

}

/* int OctaToDeci(int n){

}

int HexaToDeci(int n){

}
 */

int main(){
    int n;
    cin>n;

    cout<<BinaryToDeci(n)<<endl;
   /*  cout<<OctaToDeci(n)<<endl;
    cout<<HexaToDeci(n)<<endl;
     */
    return 0;
}