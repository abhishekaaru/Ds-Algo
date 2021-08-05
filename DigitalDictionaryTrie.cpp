#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *next[24];
    bool end;

    node(){
        for(int i=0;i<24;i++){
            next[i] = NULL;
        }
        end = false;
    }

};

class Trie{
    public:
    node *root;

    Trie(){
        root = new node();
    }

    void insert(string &s){
        node* it = root;

        for(auto i : s){

            if(!it->next[i - 'a']){
                it->next[i - 'a'] = new node();
            }
            it = it->next[i-'a'];
        }
        it->end = true;
    }

    void find(string &s){
        node* it = root;

        for(auto i : s){
            
            if(!it->next[i - 'a']){
                cout<<"No suggestion"<<endl;
                insert(s);
                return;
            }
            it  = it->next[i - 'a'];
        }

        vector<string> res;
        print(it,s,res,"");

        for(auto i : res){
            cout<<s<<i<<endl;
        }
    }

    void print(node* it,string &s,vector<string> &res,string curr){

        if(it == NULL){
            return;
        }
        if(it->end){
            res.push_back(curr);
        }

        for(int i=0;i<24;i++){

            if(it->next[i]){
                print(it->next[i],s,res,curr + char('a'+i));
            }
        }
    }

};

int main(){

    Trie t;

    int n;
    cin>>n;

    vector<string> s(n);
    for(auto &i : s){
        cin>>i;
        t.insert(i);
    }

    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;

        t.find(s);
    }4
    

    return 0;
}

// input : 4 rack rat bat batman
// input : 3 
// input : r or bat or quick