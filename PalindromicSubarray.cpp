// Sliding Window challenge
// Subarray of size K with palindromic concatination

#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int n = s.size();
        
        if(n == 0){
            return "";
        }
        if(n == 1){
            return s;
        }
        
        int min_st=0;
        int max_len=1;
        
        for(int i=0;i<n;){
            if(n-i <= max_len/2){
                break;
            }
            
            int j=i,k=i;
            
            while(k<n-1 && s[k+1]==s[k]){
                k++;
            }
            
            i = k+1;
            
            while(k < n-1 && j>0 && s[k+1]==s[j-1]){
                k++;
                j--;
            }
            
            int new_len = k-j+1;
            
            if(new_len > max_len){
                min_st = j;
                max_len = new_len;
            }
        }
        
        return s.substr(min_st,max_len);
    }

 bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        if (n == 1)
            return s;

        string result = "";
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                if (isPalindrome(s.substr(i, j)))
                {
                    if (result.size() < j)
                        result = s.substr(i, j);
                }
            }
        }
        return result;
    }

bool isPalindrome(int n){
    int temp = n;
    int num = 0;

    // reverse no.

    while(temp>0){
        num = num*10 + temp%10;
        temp = temp/10;
    }

    if(num == n){
        return true;
    }
    return false;
}

int findPalindromeSubarry(vector<int> a,int k){

    int num = 0;

    for(int i=0;i<k;i++){
        num = num*10 + a[i];
    }

    if(isPalindrome(num)){
        return 0;
    }

    for(int i=k;i<a.size();i++){
        num = (num % (int)pow(10,k-1))*10 + a[i];

        if(isPalindrome(num)){
            return i-k+1;
        }
    }

    return -1;
}

int main(){
    vector<int> a = {2,3,5,1,1,5};
    int k = 4;

    int ans = findPalindromeSubarry(a,k);

    if(ans==-1){
        cout<<"Palindromic subarray doesn't exist"<<endl;
    }
    else{
        for(int i=ans;i<ans+k;i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}