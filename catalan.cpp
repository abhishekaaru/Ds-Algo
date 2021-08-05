// catalan no. are a sequence of natural numbers that occur in various counting problems,often involving recursively defined objects.
// sum(Ci*Cn-i)
#include<bits/stdc++.h>
using namespace std;

int catalan(int n){

    if(n<=1){
        return 1;
    }

    int result=0;

    for(int i=0;i<n;i++){

        result += catalan(i) * catalan(n-i-1);
    }

    return result;
}

int main(){
    
    int n = 10;

    for(int i=0;i<n;i++){
        cout<<catalan(i)<<" ";
    }
    cout<<endl;

    return 0;
}