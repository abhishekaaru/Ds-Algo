//Geek and his friend bought a number each from the integer shop, Geek has number N and his friend has number M. 
//Geek wants that both their numbers should be co-primes. To achieve this, 
//Geek divides both the numbers by the largest number which can divide both the numbers 
//Geek wants to know the sum of numbers after doing this operation, help him find that sum.

// N=3,M=3 ==> 1+1 = 2  //GCD=3
// N=5,M=6 ==> 5+6 = 11 //GCD=1

// Hint divide both N,M with their GCD and add;

#include<bits/stdc++.h>
using namespace std;

long long sum(long long N, long long M){
        
    long long a = N;
    long long b = M;

    // GCD
    while(M != 0){
        long long rem = N%M;
        N=M;
        M = rem;
    }

    // co-prime
    // N is the GCD

    long long x = a/N;
    long long y = b/N;
        
    long long res = x+y;
        
    return res;
        
}

int main(){
    long long N,M;
    cin>>N>>M;

    cout<<sum(N,M);
    return 0;
}