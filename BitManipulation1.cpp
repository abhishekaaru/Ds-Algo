// Write a program to count the number of ones in binary representation of number

#include<iostream>
using namespace std;

int numberof1(int n){
    int count=0;
    while(n!=0){
        n = n & n-1;
        count++;
    }
    return count;
}

int main(){

    cout<<numberof1(19);
    
    return 0;

}