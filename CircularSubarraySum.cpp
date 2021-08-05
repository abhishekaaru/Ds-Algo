#include<bits/stdc++.h>
using namespace std;

int kadanes(int n,int a[]){

    int currsum=0 ;
    int maxsum = INT_MIN;

    for(int i=0;i<n;i++){

        currsum+=a[i];

        if(currsum<0){
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }
    return maxsum;
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

    // base case
    // if all element is less than 0
    int count = 0;
    int maxx = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        maxx = max(maxx, a[i]);

        if (a[i] < 0)
        {
            count++;
        }
    }

    if(count==n){
        return maxx;
    }

    int wrapsum;
    int nonwrapsum;
    int totalsum=0 ;

    nonwrapsum=kadanes(n,a);

    for(int i=0;i<n;i++){
        totalsum+=a[i];
        a[i] = -a[i];
    }
    wrapsum = totalsum + kadanes(n,a);

    cout<<max(wrapsum,nonwrapsum)<<endl;


    return 0;

}

int maxCircularSum(int a[], int n)
{
    // Corner Case
    if (n == 1)
        return a[0];

    // Initialize sum variable which store total sum of the array.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    // Initialize every variable with first value of array.
    int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];

    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++)
    {
        // Kadane's Algorithm to find Maximum subarray sum.
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);

        // Kadane's Algorithm to find Minimum subarray sum.
        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }

    if (min_so_far == sum)
        return max_so_far;

    // returning the maximum value
    return max(max_so_far, sum - min_so_far);
}