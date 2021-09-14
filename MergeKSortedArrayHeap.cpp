#include<bits/stdc++.h>
using namespace std;

// Another Way (GFG)
class ele
{
public:
    int value;
    int arrayNo;
    int index;

    ele(int v, int a, int i)
    {
        value = v;
        arrayNo = a;
        index = i;
    }
};

struct compare
{
    bool operator()(ele a, ele b)
    {
        return a.value > b.value;
    }
};

vector<int> mergeKArrays(vector<vector<int>> a, int k)
{

    priority_queue<ele, vector<ele>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        ele temp(a[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> ans;

    while (!pq.empty())
    {

        ele x = pq.top();
        pq.pop();

        ans.push_back(x.value);

        if (x.index < k - 1)
        {
            int array = x.arrayNo;
            int index = x.index + 1;
            int value = a[array][index];

            ele temp(value, array, index);
            pq.push(temp);
        }
    }

    return ans;
}

// One Way
int main(){
    int k;
    cin>>k;

    vector<vector<int>> a(k);

    for(int i=0;i<k;i++){

        int size;
        cin>>size;

        a[i] = vector<int>(size);

        for(int j=0;j<size;j++){
            cin>>a[i][j];
        }
    }

    vector<int> idx(k,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i=0;i<k;i++){

        pq.push({a[i][0], i});

    }

    vector<int> ans;

    while(!pq.empty()){

        pair<int,int> x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(idx[x.second]+1 < a[x.second].size()){
            pq.push({a[x.second][idx[x.second]+1], x.second});
        }

        idx[x.second]++;
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}