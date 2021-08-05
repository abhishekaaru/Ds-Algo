// Median of 2 sorted array

double MedianOfArrays(vector<int> &a, vector<int> &b)
{

    if (b.size() < a.size())
    {
        // we need to or should apply binary search for smaller array
        return MedianOfArrays(b, a);
    }


    int n = a.size();
    int m = b.size();
    int l = 0, r = n;
    int partition = (n + m + 1) / 2; // for both even and odd

    while (l <= r)
    {
        int midA = (l + r) / 2;
        int midB = partition - midA;

        int l1 = midA == 0 ? INT_MIN : a[midA - 1];
        int l2 = midB == 0 ? INT_MIN : b[midB - 1];

        int r1 = midA == n ? INT_MAX : a[midA];
        int r2 = midB == m ? INT_MAX : b[midB];

        if (l1 <= r2 && l2 <= r1)
        {

            if ((n + m) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }

        else if (l1 > r2)
        {
            r = midA - 1;
        }
        else
        {
            l = midA + 1;
        }
    }

    return 0.0;
}