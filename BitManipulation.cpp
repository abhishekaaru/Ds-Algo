  // Write a program to check if a given number is power of 2?
  
#include<iostream>
using namespace std;

bool powerof2(int n){

    return (n && !(n & n-1));

}

int main(){

    cout<<powerof2(16);

    return 0;

}
  