#include<bits/stdc++.h>
using namespace std;


int main() 
{
    int n;
    cin>>n; // 4
    
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];  // aba aba kk ss
    }
    
    int m;
    cin>>m; // 3 
    
    string q[m];
    for(int i=0;i<m;i++)
    {
        cin>>q[i]; // aba kk jj
    }
    
    
    for(int i=0;i<m;i++)
    {
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(q[i]==s[j]){
                flag++;
            }
                
        }
        cout<<flag<<endl;  // 2 1 0
    }
    return 0;
}

/* #include <bits/stdc++.h>

using namespace std;

void sparseArray(int n,int m,string s[],string q[]){

    
    for(int i=0;i<m;i++){
        int count=0;
        for(int j=0;j<n;j++){
            
            if(q[i]==s[j]){
                count++;
            }
            
        }
        
        cout<<count<<endl;
    }

    return;
}

int main(){
    int n;
    cin>>n;
    
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    
    int m;
    cin>>m;
    
    string q[m];
    for(int i=0;i<m;i++){
        cin>>q[m];
    }
    
    sparseArray(n,m,s,q);
    
    return 0;
    
} */