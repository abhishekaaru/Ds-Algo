#include<bits/stdc++.h>
using namespace std;

/* int main()
{

    int a[5] = {3, 10, 5, 15, 2};
    int ans = 0;
    

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            ans = max(ans, a[i] xor a[j]);
        }
    }

    cout << ans;

    return 0;
} */

class Tries{
    public:
    Tries *next[2];

    Tries(){
        next[0] = NULL;
        next[1] = NULL;
    }
};

Tries* buildTrie(vector<int> &a){
    Tries* root = new Tries();

    for(int i=0;i<a.size();i++){

        Tries *it = root;
        int num = a[i];

        for(int i=31;i>=0;i--){

            int bit = (num>>i) & 1;

            if(it->next[bit] == NULL){
                it->next[bit] = new Tries();
            }
            it = it->next[bit];
        }
    }
    return root;
}

int helper(Tries *root,vector<int> &a){
    int ans = 0;

    for(int i=0;i<a.size();i++){

        Tries *it = root;
        int maxx = 0;
        int num = a[i];

        for(int i=31;i>=0;i--){

            int bit = ((num>>i) & 1) ? 0 : 1; // go opposite

            if(it->next[bit]){
                maxx <<= 1;
                maxx |= 1;
                it = it->next[bit]; 
            }
            else{
                maxx <<=1;
                maxx |= 0;
                it = it->next[bit xor 1];
            }
        }
        ans = max(ans,maxx);
    }
    return ans;
}

int main(){

    vector<int> a = {3,10,5,15,2};
    Tries* root = buildTrie(a);
    
    cout<<helper(root,a);

    return 0;
}