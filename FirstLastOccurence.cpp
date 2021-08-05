#include<iostream>
using namespace std;

int firstocc(int n,int a[],int key,int i){
    if(i==n){
        return -1;
    }

    if(a[i]==key){
        return i;
    }

    return firstocc(n,a,key,i+1);
}

int lastocc(int n,int a[],int key,int i){
    if(i==n){
        return -1;
    }

    int restarray;

    restarray = lastocc(n,a,key,i+1);

    if(restarray != -1){
        return restarray;
    }

    if(a[i]==key){
        return i;
    } 

    return -1;

}


int main(){
    int key;
    cin>>key;

    int a[8]={4,2,7,1,2,5,2,7};

    cout<<"First occurence"<<endl;
    cout<<firstocc(8,a,key,0)<<endl;

    cout<<"Last occurence"<<endl;
    cout<<lastocc(8,a,key,0)<<endl;

    return 0;

    
}