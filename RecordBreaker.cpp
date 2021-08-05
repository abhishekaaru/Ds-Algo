#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter size of an array "<<endl;
    cin>>n;

    int a[n]; // a[n+1]
    // a[n]=-1;

    cout<<"Enter elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

   /*  if(n == 1){
        cout<<"1"<<endl;
        return 0;
    } */

    int mx =-1;
    int ans = 0;

    for(int i=0;i<n;i++){
        if( a[i]>mx && a[i]>a[i+1] ){
            ans++;
        }
        
        mx = max(mx,a[i]);
    }
    cout<< ans <<endl;
    return 0;
}