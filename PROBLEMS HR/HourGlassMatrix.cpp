#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n,m;
    
    int a[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    int maxsum = INT_MIN;
    
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            int sum = (a[i][j]+a[i][j+1]+a[i][j+2])+
                      (a[i+1][j+1])+(a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]);
                  
                  maxsum = max(maxsum,sum);
        }
    }
    
    cout<<maxsum;
    
    return 0;
}