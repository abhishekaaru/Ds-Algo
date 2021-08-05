#include<iostream>
using namespace std;

string movex(string s){

    if(s.length()==0){
        return "";
    
    }

    char ch=s[0];
    string ans;

    ans = movex(s.substr(1));

    if(ch=='x'){
        return ans + ch;
    }
    return ch + ans;
}

int main(){
    string s="abcxxdxxdxxee";

    cout<<movex(s);

    return 0;

}