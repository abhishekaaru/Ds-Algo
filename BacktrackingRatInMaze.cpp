#include<iostream>
using namespace std;

bool isSafe(int n,int** a,int x,int y){
    if(x<n && y<n && a[x][y]==1){
        return true;
    }
    return false;

}

bool ratinmaze(int n,int** a,int x,int y,int** sola){

    if(x==n-1 && y==n-1){
        sola[x][y]=1;
        return true;
    }

    if(isSafe(n,a,x,y)){

        sola[x][y]=1;

        if(ratinmaze(n,a,x+1,y,sola)){
            return true;
        }

        if(ratinmaze(n,a,x,y+1,sola)){
            return true;
        }
        sola[x][y]=0; // Bactracking
        return false;

    }

    return false;
}

int main(){

    int n;
    cin>>n;

    int** a = new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int [n];       
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int** sola = new int*[n];

    for(int i=0;i<n;i++){

        sola[i]=new int [n];    

        for(int j=0;j<n;j++){
           sola[i][j]=0;
        }
    }

    if(ratinmaze(n,a,0,0,sola)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sola[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;

}

// n = 5

/* 1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1 */

