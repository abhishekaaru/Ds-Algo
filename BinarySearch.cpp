#include<iostream>
using namespace std;

int BinarySearch(int n,int a[],int key){

    int s=0;
    int e=n;
    

    while(s<=e){
        int mid;
        mid=(s+e)/2;

        if(a[mid]==key){

            return mid;

        }
        else if(a[mid]<key){

            s=mid+1;
            
        }
        else{

            e=mid-1;

        }
    }

    return -1;

}

int main(){
    int n;
    cout<<"Enter array size "<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter elements of array "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int key;
    cout<<"Enter element to find "<<endl;
    cin>>key;

    cout<<BinarySearch(n,a,key)<<endl;
    
    return 0;
}