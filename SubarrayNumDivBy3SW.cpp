// Sliding window challange
// Number formed from subarray of size K, is divisible by 3

#include<bits/stdc++.h>
using namespace std;

void computeNumberFormSubarray(vector<int> a,int k){

    pair<int,int> ans;
    int sum = 0;
    bool found = false;

    for(int i=0;i<k;i++){
        sum += a[i];
    }

    if(sum%3 == 0){
        ans = make_pair(0,k-1);
        found = true;
    }

    for(int i=k;i<a.size();i++){
        if(found){
            break;
        }

        sum = sum - a[i-k] + a[i];

        if(sum%3 == 0){
            ans = make_pair(i-k+1, i);
            found = true;
        }
    }

    if(!found){
        ans = make_pair(-1,0);
    }

    if(ans.first == -1){
        cout<<"no such subarray exists"<<endl;
    }
    else{
        for(int i=ans.first;i<=ans.second;i++){
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
}

int main(){

    vector<int> a = {84,23,45,12,56,82};
    int k = 3;

    computeNumberFormSubarray(a,k);

    return 0;
}