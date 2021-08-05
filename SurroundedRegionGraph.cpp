#include<bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &A,int x,int y){
    A[x][y] = '*';
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int cx = x + dx[i];
        int cy = y + dy[i];

        if(cx >= 0 && cx<A.size() && cy >= 0 && cy<A[0].size() && A[cx][cy] == '0'){
            change(A,cx,cy);
        }
    }  
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> A(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            cin>>A[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(i==0 || i==n-1 || j==0 || j==n-1){
                if(A[i][j] == 'O'){
                    change(A,i,j);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(A[i][j] == 'O'){
                A[i][j] = 'X';
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(A[i][j] == '*'){
                A[i][j] = 'O';
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// This work 100%

void change(vector<vector<char>> &board,int i,int j){

    if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]=='X'||board[i][j]=='*')
        return;
    board[i][j]='*';
    change(board,i+1,j);
    change(board,i-1,j);
    change(board,i,j+1);
    change(board,i,j-1);
}    

void solve(vector<vector<char>>& board) {

    for(int i=0;i<board.size();i++){
        if(board[i][0]=='O')
        {
            change(board,i,0);
        }
        if(board[i][board[0].size()-1]=='O'){
            change(board,i,board[0].size()-1);
        }
    }
    for(int i=0;i<board[0].size();i++){
        if(board[0][i]=='O')
            change(board,0,i);
        if(board[board.size()-1][i]=='O')
            change(board,board.size()-1,i);
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='O')
                board[i][j]='X';
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='*')
                board[i][j]='O';
        }
    }
}

    

    