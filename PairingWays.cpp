#include<iostream>
using namespace std;

int friendsPair(int n){

    if(n==0 || n==1 || n==2){
        return n;
    }

    return friendsPair(n-1)+friendsPair(n-2)*(n-1);

}

int main(){
    int n;
    cout<<"Enter no. friends"<<endl;
    cin>>n;

    cout<<"Total no. of ways to pair"<<endl;

    cout<<friendsPair(n);

    return 0;
}