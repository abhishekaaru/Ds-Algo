#include<bits/stdc++.h>
using namespace std;

int rainWater(vector<int> a){
    stack<int> st;
    int ans=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] < a[i]){
            int curr;
            curr=st.top();
            st.pop();

            if(st.empty()){ 
                break;
            }

            int diff;
            diff = i-st.top()-1;
            ans += (min(a[st.top()],a[i]) - a[curr]) * diff;
        }
        st.push(i);
    }

    return ans;
}

int maxArea(vector<int>&a) {
        int i=0;
        int j=a.size()-1;
        
        int ans=0;
        
        while(i<j){
            int h = min(a[i],a[j]);
            ans = max(ans,(j-i)*h);
            
            while(a[i]<=h && i<j){
                i++;
            }
            while(a[j]<=h && i<j){
                j--;
            }
        }
        return ans;
    }

int main(){
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<rainWater(a);

    return 0;
}