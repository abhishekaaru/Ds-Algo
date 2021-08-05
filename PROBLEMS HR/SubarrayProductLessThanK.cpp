int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{

    int count = 0;
    long long sum = 1;
    int i = 0, j = 0;
    int ws = 0; // window size

    while (j < n)
    {

        sum *= a[j];

        while (i <= j && sum >= k)
        {
            sum /= a[i++];
        }

        if (sum < k)
        {
            ws = j - i + 1;
            count += ws;
        }

        j++;
    }

    return count;
}