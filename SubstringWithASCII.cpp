#include<iostream>
using namespace std;

void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    int c = ch;
    string ros;
    ros=s.substr(1);

    
    subseq(ros,ans);
    subseq(ros,ans+ch);
    subseq(ros,ans + to_string(c));
}

int main(){

    string s = "AB";
    
    subseq(s,"");

    return 0;
}