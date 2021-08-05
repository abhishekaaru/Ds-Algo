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

    for(int i=1;i<n;i++){
        int current;
        current = a[i];

        int j = i-1 ;

        while(a[j]>current && j>=0){

            a[j+1]=a[j];
            j--;

        }
        a[j+1] = current; // Here we used j+1 because of that j-- in while loop
    }

    for(int i=0;i<n;i++){

        cout<<a[i]<<" ";
    }




    return 0;

}