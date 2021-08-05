#include<iostream>
using namespace std;

void hanoi(int n,char src,char help,char des){
    if(n==0){
        return;
    }

    hanoi(n-1,src,des,help);
    cout<<"Move from "<<src<<" to "<<des<<endl;
    hanoi(n-1,help,src,des);

}

int main(){

    hanoi(3,'A','B','C');

    return 0;
}