#include<iostream>
#include<climits>
using namespace std;


int main(){
    int n;
    cout<<"Enter array size "<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter elements of array "<<endl;
    for(int i=0;i<n;i++){
        
        cin>>a[i];
    }

    int maxn=INT_MIN;
    int minn=INT_MAX;

    for(int i=0;i<n;i++){

        maxn=max(a[i],maxn);
        minn=min(a[i],minn);

    /*     if(a[i]>maxn){
            maxn=a[i];
        }
        if(a[i]<minn){
            minn=a[i];
        } */
    }

    cout<<"Minimum no. of this array is "<<minn<<endl;
    cout<<"Maximum no. of this array is "<<maxn<<endl;

    return 0;
}




/* int  main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    } */


