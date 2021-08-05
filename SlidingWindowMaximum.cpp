#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }

    multiset<int,greater<int>> s;   // maximum element will be at top (greater)
    vector<int> ans;

    for(int i=0;i<k;i++){

        s.insert(a[i]); 
    }
    ans.push_back(*s.begin());  // *s is value

    for(int i=k;i<n;i++){

        // in multiset if we do s.erase(a[i-x]) it will delete all the element which are equal to a[i-x]
        // lower_bound will delete only one element

        s.erase(s.lower_bound(a[i-k]));

        s.insert(a[i]);
        ans.push_back(*s.begin());
    }

    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}

/* #include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }

    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++){

        while(!q.empty() && a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    for(int i=k;i<n;i++){

        if(q.front() == i-k){
            q.pop_front();
        }

        while(!q.empty() && a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for(auto i:ans){
        cout<<i<<" ";
    }


    return 0;

} */