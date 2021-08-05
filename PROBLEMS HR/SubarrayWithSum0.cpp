// Largest subarray with sum 0

int maxLen(int a[], int n)
{
    map<int, int> m;
    int sum = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {

        sum += a[i];

        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (m.find(sum) != m.end())
            {
                // if sum is already in map
                // then differnce of index where sum firstly ouccr (m[sum])
                // and till now will be zero
                maxi = max(maxi, i - m[sum]);
            }
            else
            {
                // if sum was not occured before then store (sum,i) in map.
                m[sum] = i;
            }
        }
    }
    return maxi;
}