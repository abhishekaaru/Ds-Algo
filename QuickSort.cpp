#include<bits/stdc++.h>
using namespace std;

void swap(int a[],int i,int j){

    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

}

int partition(int a[],int f,int l){

    int pivot=a[l];
    int i = f-1;

    for(int j=f;j<l;j++){

        if(a[j] < pivot){

            i++;
            swap(a,i,j);
        }
    }

    swap(a,i+1,l);

    return i+1;
}

void quicksort(int a[],int f,int l){


    if(f<l){

        int pi = partition(a,f,l);

        quicksort(a,f,pi-1);
        quicksort(a,pi+1,l);
    }
}

int main(){

    int a[9] = {5,4,8,9,1,7,6,2,3};

    quicksort(a,0,8);

    for(int i=0;i<9;i++){

        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}