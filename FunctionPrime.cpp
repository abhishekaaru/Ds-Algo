#include<iostream>
#include<math.h>
using namespace std;

bool PrimeF(int n){

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }

    return true;

}


    
int main(){

    int a,b,i;
    cin>>a>>b;

     for(i=a;i<=b;i++){

         if(PrimeF(i)){
             cout<<i<<endl;
         }
      }
      return 0;
}
    
