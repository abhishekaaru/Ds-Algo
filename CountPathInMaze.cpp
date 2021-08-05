#include<iostream>
using namespace std;

int countPathMaze(int n,int i,int j){

    if(i==n-1 && i==n-1){
        return 1;
    }

    if(i>=n || j>=n){
        return 0;
    }  

    return countPathMaze(n,i+1,j) + countPathMaze(n,i,j+1);

}

int main(){
    int n;
    cout<<"Enter MAZE NO."<<endl;
    cin>>n; 

    cout<<"Maximum no. of ways to reach the destination"<<endl;
    cout<<countPathMaze(n,0,0)<<endl;

    return 0;
}