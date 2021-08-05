// Given a positive integer N, count  all the possible distinct binary strings of lenght N such that there are no cosecutive 1's
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> fib(n+2,0);
    fib[0] = 1;
    fib[1] = 1;

    for(int i=2;i<n+2;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout<<fib[n+1];

    return 0;
}

int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }
    return a[n - 1] + b[n - 1];
}