#include<iostream>
using namespace std;

int LinearSearch(int n,int a[],int key){

    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
       
     }
     /* cout<<"INVALID INPUT"<<endl; */
     return -1;
}

int main(){

    int n;
    cout<<"Enter array size ";
    cin>>n;

    int a[n];
    cout<<"Enter elements of array ";

    for(int i=0;i<n;i++){   
        cin>>a[i];
    }

    int key;
    cout<<"Enter element to find ";
    cin>>key;

    cout<<LinearSearch(n,a,key)<<endl;

  

    

    return 0;

}