#include<bits/stdc++.h>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st,int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    
    st.push(topele);

}

void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);

}

// Reverse a stack in O(1)
void clonestack(stack<int> st, stack<int> &cloned)
{
    int k = 0;
    int n = st.size();

    while (k != n - 1)
    {
        int top = st.top();
        st.pop();

        while (k < st.size())
        {
            cloned.push(st.top());
            st.pop();
        }

        st.push(top);

        while (!cloned.empty())
        {
            st.push(cloned.top());
            cloned.pop();
        }

        k++;
    }

    // clone
    while (!st.empty())
    {
        cloned.push(st.top());
        st.pop();
    }
}

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}