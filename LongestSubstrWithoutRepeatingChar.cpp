#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string str){
        
        int n = str.size();
 
    int res = 0; // result
 
    // last index of all characters is initialized
    // as -1
    vector<int> lastIndex(256, -1);
 
    // Initialize start of current window
    int i = 0;
 
    // Move end of current window
    for (int j = 0; j < n; j++) {
 
        // Find the last index of str[j]
        // Update i (starting index of current window)
        // as maximum of current value of i and last
        // index plus 1
        i = max(i, lastIndex[str[j]] + 1);
 
        // Update result if we get a larger window
        res = max(res, j - i + 1);
 
        // Update last index of j.
        lastIndex[str[j]] = j;
    }
    return res;
        
    }

int main(){
    string s;
    cin>>s;

    vector<char>  dict(256,-1); // ASCII=256
    int maxlen=0;
    int start=-1;

    for(int i=0;i<s.size();i++){

        if(dict[s[i]] > start){
            
            start = dict[s[i]];
        }
        dict[s[i]] = i;

        maxlen=max(maxlen,i-start);
    }

    cout<<maxlen;

    return 0;
}

// pewwek = pew ,wek = 3
// pekwwek = pekw = 4
// bbbbbbb = b = 1