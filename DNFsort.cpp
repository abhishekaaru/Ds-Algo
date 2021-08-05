#include<bits/stdc++.h>
using namespace std;

void swap(int a[],int i,int j){

    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void dnfSort(int n,int a[]){

    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){

        if(a[mid]==0){

            swap(a,low,mid);
            mid++;
            low++;
        }

        else if(a[mid]==1){

            mid++;
        }

        else{

            swap(a,mid,high);
            high--;
        }
    }
}

int main(){

    int a[9]={1,0,2,1,0,1,2,1,2};

    dnfSort(9,a);

    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}