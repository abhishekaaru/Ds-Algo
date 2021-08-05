#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a,int en,int st){ //

    int maxIdx = st;
    int l = 2*st+1; // left child index
    int r = 2*st+2; // right child index

    if(l<en && a[l] > a[maxIdx]){

        maxIdx = l;
    }
    if(r<en && a[r] > a[maxIdx]){

        maxIdx = r;
    }

    // when parent is not the max index

    if(maxIdx != st){

        swap(a[st],a[maxIdx]);
        heapify(a,en,maxIdx);
    }

}

void heapsort(vector<int> &a){

    int n = a.size();

    // n/2-1 = first non leaf element

    // converting to maxHeap
    for(int i= n/2-1;i>=0;i--){

        heapify(a,n,i);
    }

    for(int i=n-1;i>0;i--){

        swap(a[0],a[i]);

        heapify(a,i,0);
    }
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    heapsort(a);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}