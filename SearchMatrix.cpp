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

    int target;
    cout<<"Enter the element to found"<<endl;
    cin>>target;

    int r = 0, c = m-1;
    bool found = false;
    while(r<n && c>=0){
        if(a[r][c]==target){
            found = true;
        }
        if(a[r][c] > target){
            c--;
        }
        else{
            r++;
        }
    }

    if(found){
        cout<<"Element Found"<<"\n"<<r<<" "<<c<<endl;
    }
    else{
        cout<<"Element Not Found"<<endl;
    }

    return 0;
}