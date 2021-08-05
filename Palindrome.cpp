#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    int temp = n;
    int num = 0;

    // reverse no.

    while(temp>0){
        num = num*10 + temp%10;
        temp = temp/10;
    }

    if(num == n){
        return true;
    }
    return false;
}


int main(){


    int n;
    cout<<"Enter the size of an array"<<endl;
    cin>>n;

    char a[n+1];
    cout<<"Enter the elements of array"<<endl;
    cin>>a;

    bool check=1;

    for(int i=0;i<n;i++){
        if(a[i] != a[n-1-i]){
            check = 0;
            break;
        }
    }

    if(check==true){
        cout<<"Word is a palindrome"<<endl;
    }
    else{
        cout<<"Word is not a palindrome"<<endl;
    }

    return 0;

}