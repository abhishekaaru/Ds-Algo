// Print all possible words from phone digits
#include<iostream>
using namespace std;

string keypadarr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string code = keypadarr[ch-'0']; //char to int ASCII(ch)-ASCII(0)=Integer
    string ros;
    ros = s.substr(1);

    for(int i=0;i<code.length();i++){
        keypad(ros,ans + code[i]);
    }
}

int main(){
    keypad("23","");

    return 0;

}