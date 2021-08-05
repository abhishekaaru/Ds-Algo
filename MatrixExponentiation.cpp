// nth term of Fibonacci no.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b)
{

    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<vector<int>> matrixExponentiate(vector<vector<int>> &a, int n)
{

    if (n == 0)
    {
        int size = a.size();
        vector<vector<int>> ans(size, vector<int>(size, 0));

        for (int i = 0; i < size; i++)
        {
            a[i][i] = 1;
        }

        return ans;
    }

    if (n == 1)
    {
        return a;
    }

    vector<vector<int>> temp = matrixExponentiate(a, n / 2);

    vector<vector<int>> ans = multiply(temp, temp);

    if (n & 1)
    {
        ans = multiply(ans, a);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(2, vector<int>(2, 0));
    a[0][0] = a[0][1] = 1;
    a[1][0] = 1;


    vector<vector<int>> ans = matrixExponentiate(a, n);

    int size = ans.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Fib : " << ans[0][1] << endl;

    return 0;
}


// GFG
// f(1)=1 and f(0)=1

class Solution
{
    using ll = long long int;
    ll mod = 1e9 + 7;

public:
    int FindNthTerm(ll n)
    {
        if (n < 2)
            return n;
        vector<ll> fibs = {1, 1, 1, 0};
        vector<ll> ans = fibPower(fibs, n);
        return (int)ans[0];
    }

private:
    vector<ll> matrixProd(vector<ll> &l, vector<ll> &r)
    {
        vector<ll> ans(4, 0);
        ans[0] = add(mul(l[0], r[0]), mul(l[1], r[2]));
        ans[1] = add(mul(l[0], r[1]), mul(l[1], r[3]));
        ans[2] = add(mul(l[2], r[0]), mul(l[3], r[2]));
        ans[3] = add(mul(l[2], r[1]), mul(l[3], r[3]));
        return ans;
    }
    vector<ll> fibPower(vector<ll> &fibs, int n)
    {
        if (n == 1)
            return fibs;
        vector<ll> half = fibPower(fibs, n / 2);
        vector<ll> ans = matrixProd(half, half);
        if (n % 2 == 0)
            return ans;
        ans[0] = add(ans[0], ans[1]);
        ans[2] = add(ans[2], ans[3]);
        ans[1] = (ans[0] - ans[1] + mod) % mod;
        ans[3] = (ans[2] - ans[3] + mod) % mod;
        return ans;
    }
    ll add(ll a, ll b)
    {
        return (((a % mod) + (b % mod))) % mod;
    }
    ll mul(ll a, ll b)
    {
        return ((a % mod) * (b % mod)) % mod;
    }
};