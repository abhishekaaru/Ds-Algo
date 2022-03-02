#include<bits/stdc++.h>
using namespace std;

// kadene's
int maxSubArray(vector<int>& a) {
        int sum = 0;
        int n = a.size();
        int maxx = INT_MIN;
        
        for(int i=0;i<n;i++){
            sum = max(a[i],sum+a[i]);
            
            maxx = max(sum,maxx);
        }
        
        return maxx;
    }

int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

// Kadene's algorithum

    int currsum=0;
    int maxsum=INT_MIN;

    for(int i=0;i<n;i++){

        currsum+=a[i];

        if(currsum<0){
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }

    cout<<maxsum<<endl;

// Brute approch  
/*     int maxsum=INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){

                sum+=a[k];
            }
            maxsum=max(maxsum,sum);
        }
    }

    cout<<maxsum<<endl; */

    return 0;

}