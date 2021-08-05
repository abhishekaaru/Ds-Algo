// Given a array of n no. Find the max length of bitonic subsequence. A subdequence is bitonic 
//if it is first strictly inc and  then strictly dec or entirely inc or dec.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> forward(n,1),backward(n,1);

    // longest Increasing

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                forward[i] = max(forward[i],1+forward[j]);
            }
        }
    }

    // longest Decreasing

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j]){ // i < j (decreaing)

                backward[i] = max(backward[i],1+backward[j]);
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans, forward[i] + backward[i]-1); // i counted 2 times
    }

    cout<<ans;

    return 0;
}

// Subarray

int bitonic(vector<int> arr, int n)
{
    // if arr is empty
    if (n == 0)
        return 0;

    // initializing max_len
    int maxLen = 1;

    int start = 0;
    int nextStart = 0;

    int j = 0;
    while (j < n - 1)
    {
        // look for end of ascent
        while (j < n - 1 && arr[j] <= arr[j + 1])
            j++;

        // look for end of descent
        while (j < n - 1 && arr[j] >= arr[j + 1])
        {

            // adjusting nextStart;
            // this will be necessarily executed at least once,
            // when we detect the start of the descent
            if (j < n - 1 && arr[j] > arr[j + 1])
                nextStart = j + 1;

            j++;
        }

        // updating maxLen, if required
        maxLen = max(maxLen, j - (start - 1));

        start = nextStart;
    }

    return maxLen;
}