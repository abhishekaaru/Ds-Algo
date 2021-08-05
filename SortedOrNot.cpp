#include<iostream>
using namespace std;

bool check(int n,int a[]){

    bool restarray;
    if(n==1){
        return 1;
    }
    restarray = check(n-1,a+1);
    
    return (a[0]<a[1] && restarray);

}
int main(){
    int a[]={1,2,3,3,5,6,7};
    cout<<check(7,a);

    return 0;
     
}