#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of an array"<<endl;
    cin>>n;
    cin.ignore();

    char a[n+1];
    cout<<"Enter the srntence"<<endl;
    cin.getline(a,n);
    cin.ignore(); // to clear the buffer

    int i=0;
    int currLen=0;
    int maxLen=0;
    int st=0;
    int maxst=0;

    while(1){
        if(a[i] == ' ' || a[i] == '\0'){

            if(currLen > maxLen){
                maxLen = currLen;
                maxst=st;  //st is a starting charecter
            }
            currLen=0;
            st = i+1;
        }

        else
        currLen++;

        if(a[i] == '\0'){
            break;
        }

        i++;

    }

    cout<<maxLen<<endl;
    for(int i=0;i<maxLen;i++)
    {
        cout<<a[i+maxst];
    }




    return 0;

}