#include<bits/stdc++.h>
#include<vector>

using namespace std;

bool myCompare(pair<int,int> p1,pair<int,int> p2){

    return p1.first<p2.first;

}

int main(){
    int a[]={10,16,7,14,5,3,2,9};
    vector < pair<int,int> > v;

    for(int i=0 ; i<(sizeof(a)/sizeof(a[0])) ; i++){

        /* pair<int,int> p;
        p.first = a[i];
        p.second = i; */

        v.push_back(make_pair(a[i],i));

    }

    sort(v.begin(), v.end(), myCompare);

    for(int i=0;i<v.size();i++){

        a[v[i].second] = i;

    }

    for(int i=0;i<v.size();i++){

        cout<<a[i]<<" ";
        
    }

    return 0;
}