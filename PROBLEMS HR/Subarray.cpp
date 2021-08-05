#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int a[6]={1,2,3,4,5,6};


    int currsum=0;
    int maxsum=INT_MIN;

    for(int i=0;i<6;i++){

        currsum=a[i]+a[i+1];
        maxsum=max(maxsum,currsum);
    }

        cout<<maxsum<<endl;

    return 0;

}