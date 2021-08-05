#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    int a[n];
    cout<<"enter the element of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    const int N=1e6+2;
    bool check[N];
    for(int i=0;i<N;i++){

        check[i] = false;

    }
    for(int i=0;i<n;i++){

        if(a[i] >= 0){

            check[a[i]] = true;

        }
    }

    int ans;
    for(int i=0;i<N;i++){

        if(check[i]==false){

            ans = i;
            break;

        }

    }

    cout<<ans<<endl;

    return 0;

}