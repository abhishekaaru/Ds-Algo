#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *next[2];
    node(){
        for(int i=0;i<2;i++){
            next[i] = NULL;
        }
    }
};

node* trie;

void insert(int n){
    node *it = trie;
    for(int i=31;i>=0;i--){
        int bit = (n>>i) & 1;

        if(!it->next[bit]){

            it->next[bit] = new node();
        }
        it = it->next[bit];
    }
}

int query(int n){
    node* it = trie;
    int ans=0;
    
    for(int i=31;i>=0;i--){

        int bit = (n>>i) & 1;
        int op = bit xor 1;

        if(it->next[op]){
            it = it->next[op];
            ans |= 1<<i;
        }
        else{
            it = it->next[op xor 1];
        }
    }

    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    trie = new node();
    insert(0);
    vector<int> Rmax(n+1,0);
    int R = 0;
    for(int i=n-1;i>=0;i--){

        R = R xor a[i];

        if(i != n-1){
            Rmax[i] = max(Rmax[i],query(R));
            insert(R);
        }
        else{
            Rmax[i] = query(R);
            insert(R);
        }
    }

    free(trie);

    trie = new node();
    insert(0);
    int ans=0;
    int L = 0;
    for(int i=0;i<n;i++){
        
        L = L xor a[i];

        ans = max(ans,Rmax[i+1] + query(L));
        insert(L);
    }

    cout<<ans;

    return 0;
}