#include<iostream>
using namespace std;

bool isSafe(int n,int** a,int x,int y){

    for(int row=0;row<x;row++){
        if(a[row][y]==1){
            return false;
        }
        
    }

    // Left dignol space check

    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(a[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    

    //Right dignol space check
    
    row = x;
    col = y;
    while(row>=0 && col<n){
        if(a[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(int n,int** a,int x){

    if(x>=n){
        return true;
    }

    for(int col=0;col<n;col++){

        if(isSafe(n,a,x,col)){

            a[x][col]=1;

            if(nQueen(n,a,x+1)){
                return true;
            }

            a[x][col]=0; //Backtracking

        }

    }

    return false;

}

int main(){
    int n;
    cin>>n;

    int** a=new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int [n];
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }

    if(nQueen(n,a,0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

// n = 4


class Solution {
public:
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &v,
               vector<int> &LeftRow,vector<int> &LowDig,vector<int> &UpDig){
        
        if(col == n){
            v.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(LeftRow[row]==0 && LowDig[row+col]==0 && UpDig[n-1+(col-row)]==0){
                
                board[row][col] = 'Q';
                LeftRow[row] = 1;
                LowDig[row+col] = 1;
                UpDig[n-1+(col-row)] = 1;
                
                solve(col+1,n,board,v,LeftRow,LowDig,UpDig);
                
                board[row][col] = '.';
                LeftRow[row] = 0;
                LowDig[row+col] = 0;
                UpDig[n-1+(col-row)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> v;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        
        vector<int> leftRow(n,0);
        vector<int> LowDig(2*n-1,0);
        vector<int> UpDig(2*n-1,0);
        
        solve(0,n,board,v,leftRow,LowDig,UpDig);
        
        return v;
        
    }
};
