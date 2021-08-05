#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter size of an array"<<endl;
    cin>>n;

    int a[n];
    cout<<"enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int s;
    cout<<"enter the continous sum required"<<endl;
    cin>>s;

    int st=-1,en=-1,sum,j=0,i;
    sum=0;

    while(j<n && sum+a[j]<=s){

        sum+=a[j];
        j++;
    }

    if(sum == s){
        cout<<i<<" "<<j<<endl;
        return 0;
    }

    while(j<n){

        sum+=a[j];

        while(sum>s){

            sum-=a[i];
            i++;

        }

        if(sum == s){
            st = i;
            en = j;
            break;
        }
        j++;
        
    }

    cout<<st<<" "<<en<<endl;

    return 0;

}