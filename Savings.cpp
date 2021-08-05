#include<iostream>
using namespace std;
int main() {
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

int savings;
cin>>savings;

if (savings<500){

    cout<<"Friends";

}
else if (savings<=1000){

    cout<<"In cafe with Sanya and Tanya";

}
else{
    if (savings<=2000)
    cout<<"Boating with Sidhi";

    else{
        cout<<"Roadtrip with Sidhi";
    }
}
}