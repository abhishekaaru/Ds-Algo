#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the row and column size"<<endl;
    cin>>n>>m;

    int a[n][m];
    cout<<"Enter the element of row and column"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    int temp;
    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}