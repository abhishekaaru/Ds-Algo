#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int f,int mid,int l){

    int n1 = mid-f+1;
    int n2 = l-mid;

    int b[n1];
    int c[n2]; // temp arrays

    for(int i=0;i<n1;i++){

        b[i]=a[f+i];
    }

    for(int i=0;i<n2;i++){

        c[i]=a[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=f;

    while(i<n1 && j<n2){

        if(b[i]<c[j]){

            a[k] = b[i];

            i++;
            k++;
        }

        else{

            a[k] = c[j];

            j++;
            k++;
        }
    }

    while (i<n1){

        a[k] = b[i];

        i++;
        k++;
    }

    while(j<n2){

        a[k] = c[j];

        j++;
        k++;
    }
    

}

void mergesort(int a[],int f,int l){

    if(f<l){
        
        int mid;
        mid=(f+l)/2;

        mergesort(a,f,mid);
        mergesort(a,mid+1,l);

        merge(a,f,mid,l);
    }
}

int main(){

    int a[]={5,4,2,0,3,1};

    mergesort(a,0,5);

    for(int i=0;i<6;i++){

        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}