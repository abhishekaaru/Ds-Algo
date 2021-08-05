#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<int,int> count;
    int prefixSum = 0;

    for(int i=0;i<n;i++){

        prefixSum += a[i];
        count[prefixSum]++;
    }

    int ans = 0;

    map<int,int> :: iterator it;
    for(it = count.begin(); it != count.end(); it++){
        
        int c = it->second;

        ans += (c*(c-1))/2; //For every key,chooseing 2 value

        if(it->first==0){
            ans += it->second;
        }
    }

    cout<<ans<<endl;

    return 0;
}