#include<bits/stdc++.h>
using namespace std;

/* int stockspanBrute(int a){

    int days=0;

    for(int i=0;i<a.size();i++){

        for(int j=i;i>=0;i--){
            
            if(a[i]>=a[j]){
                days++;
            }
            else{
                break;
            }
        }
    }

    return days;
} */

vector<int> stockspan(vector<int> price){

    vector<int> ans;
    stack<pair<int,int>> st;

    for(auto i:price){

        int days=1;

        while (!st.empty() && st.top().first <= i)
        {
            days += st.top().second;
            st.pop();
        }

        st.push(make_pair(i,days));      // st.push({price,days})
        ans.push_back(days);     
    }

    return ans;
}

int main(){

    vector<int> a = {100,80,60,70,60,75,85};

    vector<int> result;

    result = stockspan(a); 

    for(auto i:result){
        cout<<i<<" ";
    }

    return 0;
}