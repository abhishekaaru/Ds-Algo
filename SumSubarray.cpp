#include<iostream>
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

    int current;
    cout<<"Sum of all Subarray "<<endl;
    for(int i=0;i<n;i++){
        current =0;
        for(int j=i;j<n;j++){

            current +=a[j];
            cout<<current<<" ";
        } 
        cout<<endl;
    }
    
  return 0;  
}
