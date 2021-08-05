// Input: 
// N=5
// Arr[] = {3, 1, 5, 2, 4}
// Output : 3 -1 4 -1 -1
// Explanation:
// Arr[3] is the farthest smallest element to the right of Arr[0].
// Arr[4] is the farthest smallest element to the right of Arr[2].
// And for the rest of the elements, there is no smaller element to their right.


vector<int> farthestNumber(int n, vector<int> a)
{

    vector<int> suffix_min(n);
    vector<int> result;
    suffix_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_min[i] = min(suffix_min[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int low = i + 1, high = n - 1, ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If currnet element in the suffix_min
            // is less than a[i] then move right
            if (suffix_min[mid] < a[i])
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        // Print the required answer
        result.push_back(ans);
    }
    return result;
}