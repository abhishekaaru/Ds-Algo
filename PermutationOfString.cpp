#include<iostream>
using namespace std;

void permutation(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch;
        ch=s[i];
        
        string ros;
        ros=s.substr(0,i)+s.substr(i+1);

        permutation(ros,ans+ch);
    }
}

int main(){

    string s ="ABC";
    permutation(s,"");

    return 0;

}