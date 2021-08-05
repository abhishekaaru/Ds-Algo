#include<iostream>
using namespace std;

int countPath(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }

    int count = 0;
    for(int i=1;i<=6;i++){ // is for dice

        count += countPath(s+i,e);

    }

    return count;

}

int main(){
    int s,e;
    cout<<"Enter starting and ending point"<<endl;
    cin>>s>>e; 

    cout<<"Maximum no. of ways to reach the destination"<<endl;
    cout<<countPath(s,e)<<endl;

    return 0;
}