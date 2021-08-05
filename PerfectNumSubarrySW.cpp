// Sliding Window Challenge

#include<bits/stdc++.h>
using namespace std;

bool isPerfectNum(int n){
    int sum = 1;

    for(int i=2;i<sqrt(n);i++){
        if(n%i == 0){
            if(i == n/i){
                sum += i;
            }
            else{
                sum += i + n/i;
            }
        }
    }

    if(sum == n && n != 1){
        return true;
    }
    return false;
}

int maxsum(int n,int a[],int k){
    if(n<k){
        cout<<"invalid values"<<endl;
        return -1;
    }

    int res=0;
    for(int i=0;i<k;i++){
        res += a[i];
    }

    int sum = res;
    for(int i=k;i<n;i++){
        sum = sum - a[i-k] + a[i];
        res = max(res,sum);
    }

    return res;
}

int maxNumOfPerfect(int n,int a[],int k){
    for(int i=0;i<n;i++){
        if(isPerfectNum(a[i])){
            a[i] = 1;
        }
        else{
            a[i] = 0;
        }
    }

    return maxsum(n,a,k);
}

int main(){

    int a[] = {28,2,3,6,496,99,8128,24};
    int n = 8;
    int k = 4;

    cout<<maxNumOfPerfect(n,a,k)<<endl;

    return 0;
}