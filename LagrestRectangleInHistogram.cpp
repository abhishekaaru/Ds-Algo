#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftSmall[n], rightSmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (st.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = st.top() + 1;
        st.push(i);
    }

    // clear the stack to be re-used
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (st.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = st.top() - 1;

        st.push(i);
    }

    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }
    return maxA;
}

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxA = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            // cout << i << " " << width << " " << height << endl;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int get_max_area(vector<int> a){

    stack<int> st;
    int n = a.size(),ans=0,i=0;

    a.push_back(0);

    while (i<n)
    {
        while(!st.empty() && a[st.top()] > a[i]){
            int t = st.top();
            int h = a[t];

            st.pop();

            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int b=i-st.top()-1; // because we pop an elment before
                ans=max(ans,h*b);
            }
        }
        st.push(i);
        i++;
    }

    return ans;
    
}

int main(){
    vector<int> a={2,1,5,6,2,3};

    cout<<get_max_area(a);

    return 0;
}