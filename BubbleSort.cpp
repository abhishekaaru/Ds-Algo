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

    int counter=1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){

            if(a[i]>a[i+1]){

                int temp;
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
        counter++;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;

}

    