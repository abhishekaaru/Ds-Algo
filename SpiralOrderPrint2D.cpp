#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter no. of row and column"<<endl;
    cin>>n>>m;

    int a[n][m];
    cout<<"Enter the element or row and column"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    int row_st = 0;
    int row_en = n-1;
    int column_st = 0;
    int column_en = m-1;

    while(row_st <= row_en && column_st <= column_en){

        for(int col=column_st ; col<=column_en ; col++){
            cout<<a[row_st][col]<<" ";
        }

        row_st++;

        for(int row=row_st ; row<=row_en ; row++){
            cout<<a[row][column_en]<<" ";

        }

        column_en--;
        
        if(row_st <= row_en){
            for(int col=column_en ; col>=column_st ; col--){
                cout<<a[row_en][col]<<" ";

            }
            row_en--;
        }

        if(column_st <= column_en){
            for(int row=row_en ; row>=row_st ; row--){
                cout<<a[row][column_st]<<" ";
            }
            column_st++;
        }
    }

    return 0;
}