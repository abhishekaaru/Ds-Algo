#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k;
    cout<<"Enter the sum to find "<<endl;
    cin>>k;

    // Array should be sorted

    int low = 0;
    int high = n-1;

    while (low<high)
    {
        if(a[low]+a[high] == k){
            cout<<low<<" "<<high<<endl;
            break;

        }
        else if(a[low]+a[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    


/*     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]+a[j]==k){

                cout<<i<<" "<<j<<endl;
                break;
            }
            
        }
        
    } */

    
    return 0;

}