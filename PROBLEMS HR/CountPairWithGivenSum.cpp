// O(n)

int getPairsCount(int a[], int n, int k)
{

    unordered_map<int, int> mp;
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        int x = k - a[i];

        if (mp[x] == 0)
        {
            mp[a[i]]++;
        }
        else
        {
            count += mp[x];

            mp[a[i]]++;
        }
    }

    return count;
}

int getPairsCount(int a[], int n, int k)
{

    unordered_map<int, int> mp;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        count += mp[k - a[i]];

        if (a[i] == k - a[i])
        {
            count--;
        }
    }

    return count / 2;
}