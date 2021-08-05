#include<bits/stdc++.h>
using namespace std;

// try to solve with greedy

const int INF = 1e9+2;

// o(n^2)

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> jumps(n,INF);

    if(a[0] == 0){
        cout<<INF<<" ";
        return 0;
    }

    jumps[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){

            if(i <= (j + a[j])){
                jumps[i] = min(jumps[i],jumps[j] + 1);
            }
        }
    }

    cout<<jumps[n-1];

    return 0;
}

// O(n)

int minJumps(int arr[], int n)
{

    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];

    // stores the number of steps
    // we can still take
    int step = arr[0];

    // stores the number of jumps
    // necessary to reach that maximal
    // reachable position.
    int jump = 1;

    // Start traversing array
    int i = 1;
    for (i = 1; i < n; i++)
    {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index
        step--;

        // If no further steps left
        if (step == 0)
        {
            // we must have used a jump
            jump++;

            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;

            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }

    return -1;
}