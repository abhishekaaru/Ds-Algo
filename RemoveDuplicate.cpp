#include<iostream>
using namespace std;

string removedup(string s){
    if(s.length() == 0){
        return "";
    }

    char ch=s[0];
    string ans;
    ans = removedup(s.substr(1));

    if(ch==ans[0]){
        return ans;
    }

    return ch+ans;
}

int main(){
    string s ="aabcccdddeeeeee";
    cout<<removedup(s);

    return 0;
}